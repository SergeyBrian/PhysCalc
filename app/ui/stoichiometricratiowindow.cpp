#include "stoichiometricratiowindow.h"
#include "ui_stoichiometricratiowindow.h"

StoichiometricRatioWindow::StoichiometricRatioWindow(DataStorage * storage, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StoichiometricRatioWindow)
{
    ui->setupUi(this);
    this->storage_ = storage;
}

StoichiometricRatioWindow::~StoichiometricRatioWindow()
{
    delete ui;
}
