#ifndef CHARTWIDGET_H
#define CHARTWIDGET_H

#include <QWidget>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QBarSeries>
#include <QVBoxLayout>
#include <QComboBox>
#include "ProductsManager.h"

class ChartWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ChartWidget(ProductsManager &manager, QWidget *parent = nullptr);
    ~ChartWidget();

private slots:
    void updateChart(int index);

private:
    void setupUI();
    void createCategoryChart();
    void createRegionChart();
    
    QComboBox *chartTypeCombo;
    QChartView *chartView;
    ProductsManager &manager;
};

#endif // CHARTWIDGET_H