#include "stoichiometricratiowindow.h"
#include "ui_stoichiometricratiowindow.h"

StoichiometricRatioWindow::StoichiometricRatioWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StoichiometricRatioWindow)
{
    ui->setupUi(this);
}

StoichiometricRatioWindow::~StoichiometricRatioWindow()
{
    delete ui;
}
