#include "heatcapacitywindow.h"
#include "ui_heatcapacitywindow.h"

HeatCapacityCalculatorWindow::HeatCapacityCalculatorWindow(DataStorage * storage, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HeatCapacityCalculatorWindow)
{
    ui->setupUi(this);
    this->storage_ = storage;
}

HeatCapacityCalculatorWindow::~HeatCapacityCalculatorWindow()
{
    delete ui;
}

void HeatCapacityCalculatorWindow::on_toolButton_7_clicked()
{
    CalculatorInterface::getValueFromOtherCalculator(Calculators::EXCESS_AIR_RATIO, this->storage_, ui->lineEdit_11);
}

void HeatCapacityCalculatorWindow::on_toolButton_8_clicked()
{
    CalculatorInterface::getValueFromOtherCalculator(Calculators::HEATING_VALUE, this->storage_, ui->lineEdit_12);
}

