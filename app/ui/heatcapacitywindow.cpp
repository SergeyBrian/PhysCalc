#include "heatcapacitywindow.h"
#include "ui_heatcapacitycalculatorwindow.h"

HeatCapacityCalculatorWindow::HeatCapacityCalculatorWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HeatCapacityCalculatorWindow)
{
    ui->setupUi(this);
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
    this->openCalculator(Calculators::EXCESS_AIR_RATIO);
}

void HeatCapacityCalculatorWindow::on_toolButton_8_clicked()
{
    this->openCalculator(Calculators::HEATING_VALUE);
}

