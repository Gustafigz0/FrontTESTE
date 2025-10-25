#include "ChartWidget.h"
#include "utils/Style.h"
#include <QtCharts/QChart>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <map>

ChartWidget::ChartWidget(ProductsManager &manager, QWidget *parent)
    : QWidget(parent), manager(manager)
{
    setupUI();
    createCategoryChart();
}

ChartWidget::~ChartWidget()
{
}

void ChartWidget::setupUI()
{
    setWindowTitle("Product Charts");
    resize(800, 600);
    setStyleSheet(Style::getMainStyle());
    
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    
    chartTypeCombo = new QComboBox(this);
    chartTypeCombo->addItem("Products by Category");
    chartTypeCombo->addItem("Products by Region");
    
    chartView = new QChartView(this);
    chartView->setRenderHint(QPainter::Antialiasing);
    
    mainLayout->addWidget(chartTypeCombo);
    mainLayout->addWidget(chartView);
    
    connect(chartTypeCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &ChartWidget::updateChart);
}

void ChartWidget::updateChart(int index)
{
    if (index == 0) {
        createCategoryChart();
    } else if (index == 1) {
        createRegionChart();
    }
}

void ChartWidget::createCategoryChart()
{
    auto products = manager.getAllProducts();
    std::map<std::string, int> categoryCount;
    
    for (const auto &product : products) {
        categoryCount[product.getCategory()]++;
    }
    
    QPieSeries *series = new QPieSeries();
    for (const auto &pair : categoryCount) {
        series->append(QString::fromStdString(pair.first), pair.second);
    }
    
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Products by Category");
    chart->legend()->setAlignment(Qt::AlignRight);
    
    chartView->setChart(chart);
}

void ChartWidget::createRegionChart()
{
    auto products = manager.getAllProducts();
    std::map<std::string, int> regionCount;
    
    for (const auto &product : products) {
        regionCount[product.getRegion()]++;
    }
    
    QPieSeries *series = new QPieSeries();
    for (const auto &pair : regionCount) {
        series->append(QString::fromStdString(pair.first), pair.second);
    }
    
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Products by Region");
    chart->legend()->setAlignment(Qt::AlignRight);
    
    chartView->setChart(chart);
}