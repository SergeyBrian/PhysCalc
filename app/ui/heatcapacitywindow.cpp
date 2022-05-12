#include "heatcapacitywindow.h"
#include "ui_heatcapacitycalculatorwindow.h"

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

void HeatCapacityCalculatorWindow::openCalculator(Calculators::Calculator c)
{
    qDebug((char*)c);
}

void HeatCapacityCalculatorWindow::loadTable(QString filename)
{

}


void HeatCapacityCalculatorWindow::on_toolButton_7_clicked()
{
    ui->lineEdit_11->setText(QString::number(CalculatorInterface::calculate(Calculators::EXCESS_AIR_RATIO, this->storage_)));
}

void HeatCapacityCalculatorWindow::on_toolButton_8_clicked()
{
    ui->lineEdit_12->setText(QString::number(CalculatorInterface::calculate(Calculators::HEATING_VALUE, this->storage_)));
}

