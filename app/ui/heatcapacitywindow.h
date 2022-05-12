#ifndef HEATCAPACITYCALCULATORWINDOW_H
#define HEATCAPACITYCALCULATORWINDOW_H

#include <QDialog>

#include "../data/datastorage.h"
#include "calculatorinterface.h"

namespace Ui {
class HeatCapacityCalculatorWindow;
}

class HeatCapacityCalculatorWindow : public QDialog
{
    Q_OBJECT

public:
    explicit HeatCapacityCalculatorWindow(DataStorage * storage, QWidget *parent = nullptr);
    ~HeatCapacityCalculatorWindow();

private slots:
    void on_toolButton_7_clicked();

    void on_toolButton_8_clicked();

private:
    Ui::HeatCapacityCalculatorWindow *ui;
    void openCalculator(Calculators::Calculator c);
    void loadTable(QString filename);
    DataStorage * storage_;
};

#endif // HEATCAPACITYCALCULATORWINDOW_H
