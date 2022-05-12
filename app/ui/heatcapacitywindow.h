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
    void on_toolButton_clicked();

    void on_pushButton_clicked();

    void on_toolButton_3_clicked();

    void on_toolButton_2_clicked();

    void on_toolButton_4_clicked();

    void on_toolButton_5_clicked();

    void on_toolButton_6_clicked();

    void on_toolButton_7_clicked();

    void on_toolButton_8_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

private:
    Ui::HeatCapacityCalculatorWindow *ui;
    void openCalculator(Calculators::Calculator c);
    void loadTable(QString filename);
};

#endif // HEATCAPACITYCALCULATORWINDOW_H
