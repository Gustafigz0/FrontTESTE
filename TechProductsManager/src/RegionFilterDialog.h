#ifndef REGIONFILTERDIALOG_H
#define REGIONFILTERDIALOG_H

#include <QDialog>
#include <QComboBox>
#include <QPushButton>
#include <QVBoxLayout>

class RegionFilterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegionFilterDialog(QWidget *parent = nullptr);
    ~RegionFilterDialog();
    
    QString getSelectedRegion() const;

private:
    void setupUI();
    void loadRegions();
    
    QComboBox *regionCombo;
    QPushButton *applyButton;
    QPushButton *cancelButton;
};

#endif // REGIONFILTERDIALOG_H