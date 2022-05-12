#ifndef EXCESSAIRRATIOWINDOW_H
#define EXCESSAIRRATIOWINDOW_H

#include <QDialog>

#include "../data/datastorage.h"

namespace Ui {
class ExcessAirRatioWindow;
}

class ExcessAirRatioWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ExcessAirRatioWindow(QWidget *parent = nullptr);
    ~ExcessAirRatioWindow();

private slots:
    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

    void on_toolButton_3_clicked();

    void on_toolButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_toolButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::ExcessAirRatioWindow *ui;
    void openCalculator(Calculators::Calculator c);
    void loadTable(QString key);
};

#endif // EXCESSAIRRATIOWINDOW_H
