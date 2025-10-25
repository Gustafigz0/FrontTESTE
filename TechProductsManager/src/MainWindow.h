#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "ProductsManager.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addProduct();
    void editProduct();
    void removeProduct();
    void filterByRegion();
    void generateReport();
    void showCharts();

private:
    void setupUI();
    void loadProducts();
    
    QTableWidget *tableWidget;
    ProductsManager manager;
    
    QPushButton *addButton;
    QPushButton *editButton;
    QPushButton *removeButton;
    QPushButton *filterButton;
    QPushButton *reportButton;
    QPushButton *chartButton;
};

#endif // MAINWINDOW_H