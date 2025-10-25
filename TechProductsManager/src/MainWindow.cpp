#include "MainWindow.h"
#include "RegionFilterDialog.h"
#include "ReportDialog.h"
#include "ChartWidget.h"
#include "utils/Style.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QHeaderView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUI();
    loadProducts();
}

MainWindow::~MainWindow()
{
}

void MainWindow::setupUI()
{
    setWindowTitle("Tech Products Manager");
    resize(900, 600);
    setStyleSheet(Style::getMainStyle());
    
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    
    // Create table
    tableWidget = new QTableWidget(this);
    tableWidget->setColumnCount(4);
    tableWidget->setHorizontalHeaderLabels({"Name", "Category", "Price", "Region"});
    tableWidget->horizontalHeader()->setStretchLastSection(true);
    tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    
    // Create buttons
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    
    addButton = new QPushButton("Add Product", this);
    editButton = new QPushButton("Edit Product", this);
    removeButton = new QPushButton("Remove Product", this);
    filterButton = new QPushButton("Filter by Region", this);
    reportButton = new QPushButton("Generate Report", this);
    chartButton = new QPushButton("Show Charts", this);
    
    buttonLayout->addWidget(addButton);
    buttonLayout->addWidget(editButton);
    buttonLayout->addWidget(removeButton);
    buttonLayout->addWidget(filterButton);
    buttonLayout->addWidget(reportButton);
    buttonLayout->addWidget(chartButton);
    
    mainLayout->addWidget(tableWidget);
    mainLayout->addLayout(buttonLayout);
    
    setCentralWidget(centralWidget);
    
    // Connect signals
    connect(addButton, &QPushButton::clicked, this, &MainWindow::addProduct);
    connect(editButton, &QPushButton::clicked, this, &MainWindow::editProduct);
    connect(removeButton, &QPushButton::clicked, this, &MainWindow::removeProduct);
    connect(filterButton, &QPushButton::clicked, this, &MainWindow::filterByRegion);
    connect(reportButton, &QPushButton::clicked, this, &MainWindow::generateReport);
    connect(chartButton, &QPushButton::clicked, this, &MainWindow::showCharts);
}

void MainWindow::loadProducts()
{
    tableWidget->setRowCount(0);
    auto products = manager.getAllProducts();
    
    for (const auto &product : products) {
        int row = tableWidget->rowCount();
        tableWidget->insertRow(row);
        tableWidget->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(product.getName())));
        tableWidget->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(product.getCategory())));
        tableWidget->setItem(row, 2, new QTableWidgetItem(QString::number(product.getPrice(), 'f', 2)));
        tableWidget->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(product.getRegion())));
    }
}

void MainWindow::addProduct()
{
    QString name = QInputDialog::getText(this, "Add Product", "Product Name:");
    if (name.isEmpty()) return;
    
    QString category = QInputDialog::getText(this, "Add Product", "Category:");
    if (category.isEmpty()) return;
    
    double price = QInputDialog::getDouble(this, "Add Product", "Price:", 0, 0, 999999, 2);
    QString region = QInputDialog::getText(this, "Add Product", "Region:");
    if (region.isEmpty()) return;
    
    Product product(name.toStdString(), category.toStdString(), price, region.toStdString());
    manager.addProduct(product);
    loadProducts();
}

void MainWindow::editProduct()
{
    int row = tableWidget->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "Warning", "Please select a product to edit.");
        return;
    }
    
    QString name = tableWidget->item(row, 0)->text();
    QString newCategory = QInputDialog::getText(this, "Edit Product", "New Category:", QLineEdit::Normal, tableWidget->item(row, 1)->text());
    if (newCategory.isEmpty()) return;
    
    double newPrice = QInputDialog::getDouble(this, "Edit Product", "New Price:", tableWidget->item(row, 2)->text().toDouble(), 0, 999999, 2);
    QString newRegion = QInputDialog::getText(this, "Edit Product", "New Region:", QLineEdit::Normal, tableWidget->item(row, 3)->text());
    if (newRegion.isEmpty()) return;
    
    Product updatedProduct(name.toStdString(), newCategory.toStdString(), newPrice, newRegion.toStdString());
    manager.updateProduct(name.toStdString(), updatedProduct);
    loadProducts();
}

void MainWindow::removeProduct()
{
    int row = tableWidget->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "Warning", "Please select a product to remove.");
        return;
    }
    
    QString name = tableWidget->item(row, 0)->text();
    manager.removeProduct(name.toStdString());
    loadProducts();
}

void MainWindow::filterByRegion()
{
    RegionFilterDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString region = dialog.getSelectedRegion();
        auto filtered = manager.getProductsByRegion(region.toStdString());
        
        tableWidget->setRowCount(0);
        for (const auto &product : filtered) {
            int row = tableWidget->rowCount();
            tableWidget->insertRow(row);
            tableWidget->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(product.getName())));
            tableWidget->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(product.getCategory())));
            tableWidget->setItem(row, 2, new QTableWidgetItem(QString::number(product.getPrice(), 'f', 2)));
            tableWidget->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(product.getRegion())));
        }
    }
}

void MainWindow::generateReport()
{
    ReportDialog dialog(manager, this);
    dialog.exec();
}

void MainWindow::showCharts()
{
    ChartWidget *chartWidget = new ChartWidget(manager, this);
    chartWidget->show();
}