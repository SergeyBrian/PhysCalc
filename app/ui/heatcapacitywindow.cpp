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

void HeatCapacityCalculatorWindow::on_toolButton_clicked()
{
    this->openCalculator(Calculators::HEAT_CAPACITY);
}

void HeatCapacityCalculatorWindow::on_toolButton_2_clicked()
{
    this->openCalculator(Calculators::HEAT_CAPACITY);
}

void HeatCapacityCalculatorWindow::on_toolButton_3_clicked()
{
    this->openCalculator(Calculators::HEAT_CAPACITY);
}

void HeatCapacityCalculatorWindow::on_toolButton_4_clicked()
{
     this->openCalculator(Calculators::HEAT_CAPACITY);
}

void HeatCapacityCalculatorWindow::on_toolButton_5_clicked()
{
     this->openCalculator(Calculators::HEAT_CAPACITY);
}

void HeatCapacityCalculatorWindow::on_toolButton_6_clicked()
{
    this->openCalculator(Calculators::HEAT_CAPACITY);
}

void HeatCapacityCalculatorWindow::on_toolButton_7_clicked()
{
    this->openCalculator(Calculators::EXCESS_AIR_RATIO);
}

void HeatCapacityCalculatorWindow::on_toolButton_8_clicked()
{
    this->openCalculator(Calculators::HEATING_VALUE);
}




void HeatCapacityCalculatorWindow::on_pushButton_8_clicked()
{
    this->loadTable("t");
}

void HeatCapacityCalculatorWindow::on_pushButton_7_clicked()
{
    this->loadTable("T");
}

void HeatCapacityCalculatorWindow::on_pushButton_clicked()
{
    this->loadTable("C_pmi_A");
}

void HeatCapacityCalculatorWindow::on_pushButton_2_clicked()
{
    this->loadTable("C_pms_A");
}

void HeatCapacityCalculatorWindow::on_pushButton_3_clicked()
{
    this->loadTable("C_pmi");
}

void HeatCapacityCalculatorWindow::on_pushButton_4_clicked()
{
    this->loadTable("C_pms");
}

void HeatCapacityCalculatorWindow::on_pushButton_5_clicked()
{
    this->loadTable("C_pmi_G");
}

void HeatCapacityCalculatorWindow::on_pushButton_6_clicked()
{
    this->loadTable("C_pms_G");
}

void HeatCapacityCalculatorWindow::on_pushButton_9_clicked()
{
    this->loadTable("C_p");
}

void HeatCapacityCalculatorWindow::on_pushButton_10_clicked()
{
    this->loadTable("R");
}

void HeatCapacityCalculatorWindow::on_pushButton_11_clicked()
{
    this->loadTable("a");
}

void HeatCapacityCalculatorWindow::on_pushButton_12_clicked()
{
    this->loadTable("L_0");
}

void HeatCapacityCalculatorWindow::on_pushButton_13_clicked()
{
    this->loadTable("E_A");
}

void HeatCapacityCalculatorWindow::on_pushButton_14_clicked()
{
     this->loadTable("H");
}

void HeatCapacityCalculatorWindow::on_pushButton_15_clicked()
{
    this->loadTable("E");
}
