#ifndef STOICHIOMETRICRATIOWINDOW_H
#define STOICHIOMETRICRATIOWINDOW_H

#include <QDialog>

#include "../data/datastorage.h"
#include "calculatorinterface.h"

namespace Ui {
class StoichiometricRatioWindow;
}

class StoichiometricRatioWindow : public QDialog
{
    Q_OBJECT

public:
    StoichiometricRatioWindow(DataStorage * storage, QWidget *parent = nullptr);
    ~StoichiometricRatioWindow();

private:
    Ui::StoichiometricRatioWindow *ui;
    void openCalculator(Calculators::Calculator c);
    void loadTable(QString filename);
    DataStorage * storage_;
};

#endif // STOICHIOMETRICRATIOWINDOW_H
