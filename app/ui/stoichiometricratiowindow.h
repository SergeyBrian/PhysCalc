#ifndef STOICHIOMETRICRATIOWINDOW_H
#define STOICHIOMETRICRATIOWINDOW_H

#include <QDialog>

#include "../data/datastorage.h"

namespace Ui {
class StoichiometricRatioWindow;
}

class StoichiometricRatioWindow : public QDialog
{
    Q_OBJECT

public:
    explicit StoichiometricRatioWindow(QWidget *parent = nullptr);
    ~StoichiometricRatioWindow();

private:
    Ui::StoichiometricRatioWindow *ui;
    void openCalculator(Calculators::Calculator c);
    void loadTable(QString filename);
};

#endif // STOICHIOMETRICRATIOWINDOW_H
