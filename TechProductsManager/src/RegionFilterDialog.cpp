#include "RegionFilterDialog.h"
#include "utils/Style.h"
#include <QLabel>

RegionFilterDialog::RegionFilterDialog(QWidget *parent)
    : QDialog(parent)
{
    setupUI();
    loadRegions();
}

RegionFilterDialog::~RegionFilterDialog()
{
}

void RegionFilterDialog::setupUI()
{
    setWindowTitle("Filter by Region");
    setFixedSize(350, 200);
    setStyleSheet(Style::getMainStyle());
    
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    
    QLabel *label = new QLabel("Select Region:", this);
    regionCombo = new QComboBox(this);
    
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    applyButton = new QPushButton("Apply", this);
    cancelButton = new QPushButton("Cancel", this);
    
    buttonLayout->addWidget(applyButton);
    buttonLayout->addWidget(cancelButton);
    
    mainLayout->addWidget(label);
    mainLayout->addWidget(regionCombo);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addStretch();
    
    connect(applyButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);
}

void RegionFilterDialog::loadRegions()
{
    regionCombo->addItem("All");
    regionCombo->addItem("North America");
    regionCombo->addItem("Europe");
    regionCombo->addItem("Asia");
    regionCombo->addItem("South America");
    regionCombo->addItem("Africa");
    regionCombo->addItem("Oceania");
}

QString RegionFilterDialog::getSelectedRegion() const
{
    return regionCombo->currentText();
}