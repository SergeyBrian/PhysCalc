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

void HeatingValueWindow::on_toolButton_clicked()
{
    CalculatorInterface::getValueFromOtherCalculator(Calculators::EXCESS_AIR_RATIO, this->storage_, ui->lineEdit_7);
}
