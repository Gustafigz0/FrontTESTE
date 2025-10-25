#include "ReportDialog.h"
#include "utils/Style.h"
#include <QLabel>
#include <QFileDialog>
#include <QMessageBox>
#include <map>

ReportDialog::ReportDialog(ProductsManager &manager, QWidget *parent)
    : QDialog(parent), manager(manager)
{
    setupUI();
    generateReport();
}

ReportDialog::~ReportDialog()
{
}

void ReportDialog::setupUI()
{
    setWindowTitle("Product Report");
    resize(700, 500);
    setStyleSheet(Style::getMainStyle());
    
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    
    QLabel *titleLabel = new QLabel("Product Statistics Report", this);
    titleLabel->setStyleSheet("font-size: 18px; font-weight: bold; margin-bottom: 10px;");
    
    reportTextEdit = new QTextEdit(this);
    reportTextEdit->setReadOnly(true);
    
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    exportButton = new QPushButton("Export to File", this);
    closeButton = new QPushButton("Close", this);
    
    buttonLayout->addWidget(exportButton);
    buttonLayout->addWidget(closeButton);
    
    mainLayout->addWidget(titleLabel);
    mainLayout->addWidget(reportTextEdit);
    mainLayout->addLayout(buttonLayout);
    
    connect(exportButton, &QPushButton::clicked, [this]() {
        QString filename = QFileDialog::getSaveFileName(this, "Export Report", "", "Text Files (*.txt)");
        if (!filename.isEmpty()) {
            QFile file(filename);
            if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QTextStream out(&file);
                out << reportTextEdit->toPlainText();
                file.close();
                QMessageBox::information(this, "Success", "Report exported successfully!");
            }
        }
    });
    
    connect(closeButton, &QPushButton::clicked, this, &QDialog::accept);
}

void ReportDialog::generateReport()
{
    auto products = manager.getAllProducts();
    
    // Calculate statistics
    int totalProducts = products.size();
    double totalValue = 0;
    std::map<std::string, int> categoryCount;
    std::map<std::string, int> regionCount;
    
    for (const auto &product : products) {
        totalValue += product.getPrice();
        categoryCount[product.getCategory()]++;
        regionCount[product.getRegion()]++;
    }
    
    double avgPrice = totalProducts > 0 ? totalValue / totalProducts : 0;
    
    // Build report
    QString report;
    report += "=== PRODUCT STATISTICS REPORT ===\n\n";
    report += QString("Total Products: %1\n").arg(totalProducts);
    report += QString("Total Value: $%1\n").arg(totalValue, 0, 'f', 2);
    report += QString("Average Price: $%1\n\n").arg(avgPrice, 0, 'f', 2);
    
    report += "--- Products by Category ---\n";
    for (const auto &pair : categoryCount) {
        report += QString("%1: %2 products\n").arg(QString::fromStdString(pair.first)).arg(pair.second);
    }
    
    report += "\n--- Products by Region ---\n";
    for (const auto &pair : regionCount) {
        report += QString("%1: %2 products\n").arg(QString::fromStdString(pair.first)).arg(pair.second);
    }
    
    reportTextEdit->setPlainText(report);
}