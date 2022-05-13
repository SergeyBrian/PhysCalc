#ifndef EXCESSAIRRATIOWINDOW_H
#define EXCESSAIRRATIOWINDOW_H

#include <QDialog>

#include "../data/datastorage.h"
#include "calculatorinterface.h"

namespace Ui {
class ExcessAirRatioWindow;
}

class ExcessAirRatioWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ExcessAirRatioWindow(DataStorage * storage, QWidget *parent = nullptr);
    ~ExcessAirRatioWindow();

private slots:

    void on_toolButton_2_clicked();

    void on_toolButton_3_clicked();

    void on_toolButton_4_clicked();

    void on_toolButton_5_clicked();
private:
    Ui::ExcessAirRatioWindow *ui;
    DataStorage * storage_;

};

#endif // EXCESSAIRRATIOWINDOW_H
