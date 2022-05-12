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

void ExcessAirRatioWindow::on_toolButton_clicked()
{
     this->openCalculator(Calculators::EXCESS_AIR_RATIO);
}

void ExcessAirRatioWindow::on_toolButton_2_clicked()
{
    this->openCalculator(Calculators::HEATING_VALUE);
}

void ExcessAirRatioWindow::on_toolButton_3_clicked()
{
    this->openCalculator(Calculators::HEAT_CAPACITY);
}

void ExcessAirRatioWindow::on_toolButton_4_clicked()
{
    this->openCalculator(Calculators::HEAT_CAPACITY);
}

void ExcessAirRatioWindow::on_toolButton_5_clicked()
{
    this->openCalculator(Calculators::HEATING_VALUE);
}



void ExcessAirRatioWindow::on_pushButton_clicked()
{
     this->loadTable("a");
}

void ExcessAirRatioWindow::on_pushButton_2_clicked()
{
    this->loadTable("Q_l_");
}

void ExcessAirRatioWindow::on_pushButton_3_clicked()
{
    this->loadTable("L_0");
}

void ExcessAirRatioWindow::on_pushButton_4_clicked()
{
    this->loadTable("k_cc");
}

void ExcessAirRatioWindow::on_pushButton_5_clicked()
{
    this->loadTable("e_cc");
}

void ExcessAirRatioWindow::on_pushButton_6_clicked()
{
    this->loadTable("t");
}

void ExcessAirRatioWindow::on_pushButton_7_clicked()
{
    this->loadTable("C_pmi_A");
}

void ExcessAirRatioWindow::on_pushButton_8_clicked()
{
    this->loadTable("C_pmi");
}
