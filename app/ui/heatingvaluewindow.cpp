#include "heatingvaluewindow.h"
#include "ui_heatingvaluewindow.h"

HeatingValueWindow::HeatingValueWindow(DataStorage * storage, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HeatingValueWindow)
{
    ui->setupUi(this);
    this->storage_ = storage;
}

HeatingValueWindow::~HeatingValueWindow()
{
    delete ui;
}

void HeatingValueWindow::loadTable(QString key) {

}

void HeatingValueWindow::openCalculator(Calculators::Calculator c) {

}

void HeatingValueWindow::on_toolButton_clicked()
{
     this->openCalculator(Calculators::HEATING_VALUE);
}




void HeatingValueWindow::on_pushButton_clicked()
{
     this->loadTable("Q_l");
}

void HeatingValueWindow::on_pushButton_2_clicked()
{
     this->loadTable("C");
}

void HeatingValueWindow::on_pushButton_3_clicked()
{
    this->loadTable("M");
}

void HeatingValueWindow::on_pushButton_4_clicked()
{
    this->loadTable("n");
}

void HeatingValueWindow::on_pushButton_5_clicked()
{
    this->loadTable("m");
}

void HeatingValueWindow::on_pushButton_6_clicked()
{
    this->loadTable("p");
}

void HeatingValueWindow::on_pushButton_7_clicked()
{
    this->loadTable("L_0");
}

void HeatingValueWindow::on_pushButton_8_clicked()
{
    this->loadTable("K");
}
