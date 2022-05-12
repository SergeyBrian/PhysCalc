#ifndef HEATCAPACITYCALCULATORWINDOW_H
#define HEATCAPACITYCALCULATORWINDOW_H

#include <QDialog>

#include "../data/datastorage.h"

namespace Ui {
class HeatCapacityCalculatorWindow;
}

class HeatCapacityCalculatorWindow : public QDialog
{
    Q_OBJECT

public:
    explicit HeatCapacityCalculatorWindow(QWidget *parent = nullptr);
    ~HeatCapacityCalculatorWindow();

private slots:
    void on_toolButton_7_clicked();

    void on_toolButton_8_clicked();

private:
    Ui::HeatCapacityCalculatorWindow *ui;
    void openCalculator(Calculators::Calculator c);
    void loadTable(QString filename);
};

#endif // HEATCAPACITYCALCULATORWINDOW_H
