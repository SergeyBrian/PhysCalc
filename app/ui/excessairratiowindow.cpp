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

void ExcessAirRatioWindow::openCalculator(Calculators::Calculator c) {

}

void ExcessAirRatioWindow::loadTable(QString key) {

}

void ExcessAirRatioWindow::on_toolButton_2_clicked()
{
    ui->lineEdit_3->setText(QString::number(CalculatorInterface::calculate(Calculators::HEATING_VALUE, storage_)));
}

void ExcessAirRatioWindow::on_toolButton_3_clicked()
{
    ui->lineEdit_7->setText(QString::number(CalculatorInterface::calculate(Calculators::HEAT_CAPACITY, storage_)));
}

void ExcessAirRatioWindow::on_toolButton_4_clicked()
{
    ui->lineEdit_8->setText(QString::number(CalculatorInterface::calculate(Calculators::HEAT_CAPACITY, storage_)));
}

void ExcessAirRatioWindow::on_toolButton_5_clicked()
{
    ui->lineEdit_2->setText(QString::number(CalculatorInterface::calculate(Calculators::HEAT_CAPACITY, storage_)));
}
