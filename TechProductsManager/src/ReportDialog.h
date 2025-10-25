#ifndef REPORTDIALOG_H
#define REPORTDIALOG_H

#include <QDialog>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include "ProductsManager.h"

class ReportDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReportDialog(ProductsManager &manager, QWidget *parent = nullptr);
    ~ReportDialog();

private:
    void setupUI();
    void generateReport();
    
    QTextEdit *reportTextEdit;
    QPushButton *exportButton;
    QPushButton *closeButton;
    ProductsManager &manager;
};

#endif // REPORTDIALOG_H