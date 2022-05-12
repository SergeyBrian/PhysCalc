#ifndef HEATINGVALUEWINDOW_H
#define HEATINGVALUEWINDOW_H

#include <QDialog>

#include "../data/datastorage.h"

namespace Ui {
class HeatingValueWindow;
}

class HeatingValueWindow : public QDialog
{
    Q_OBJECT

public:
    explicit HeatingValueWindow(QWidget *parent = nullptr);
    ~HeatingValueWindow();

private slots:
    void on_toolButton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::HeatingValueWindow *ui;
    void openCalculator(Calculators::Calculator c);
    void loadTable(QString filename);
};

#endif // HEATINGVALUEWINDOW_H
