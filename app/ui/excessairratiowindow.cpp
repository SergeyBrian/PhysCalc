#include "excessairratiowindow.h"
#include "ui_excessairratiowindow.h"


ExcessAirRatioWindow::ExcessAirRatioWindow(DataStorage * storage, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExcessAirRatioWindow)
{
    ui->setupUi(this);
    this->storage_ = storage;
}

ExcessAirRatioWindow::~ExcessAirRatioWindow()
{
    delete ui;
}

void ExcessAirRatioWindow::on_toolButton_2_clicked()
{
    CalculatorInterface::getValueFromOtherCalculator(Calculators::HEATING_VALUE, storage_, ui->lineEdit_3);
}

void ExcessAirRatioWindow::on_toolButton_3_clicked()
{
    CalculatorInterface::getValueFromOtherCalculator(Calculators::HEAT_CAPACITY, storage_, ui->lineEdit_7);
}

void ExcessAirRatioWindow::on_toolButton_4_clicked()
{
    CalculatorInterface::getValueFromOtherCalculator(Calculators::HEAT_CAPACITY, storage_, ui->lineEdit_8);
}

void ExcessAirRatioWindow::on_toolButton_5_clicked()
{
    CalculatorInterface::getValueFromOtherCalculator(Calculators::HEAT_CAPACITY, storage_, ui->lineEdit_2);
}
