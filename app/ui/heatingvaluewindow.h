#ifndef HEATINGVALUEWINDOW_H
#define HEATINGVALUEWINDOW_H

#include <QDialog>

#include "../data/datastorage.h"
#include "calculatorinterface.h"

namespace Ui {
class HeatingValueWindow;
}

class HeatingValueWindow : public QDialog
{
    Q_OBJECT

public:
    explicit HeatingValueWindow(DataStorage * storage, QWidget *parent = nullptr);
    ~HeatingValueWindow();

private slots:
    void on_toolButton_clicked();

private:
    Ui::HeatingValueWindow *ui;
    DataStorage * storage_;
};

#endif // HEATINGVALUEWINDOW_H
