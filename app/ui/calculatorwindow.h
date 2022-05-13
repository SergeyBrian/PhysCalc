#ifndef CALCULATORWINDOW_H
#define CALCULATORWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>

#include "../data/datastorage.h"
#include "calculatorinterface.h"

namespace Ui {
class CalculatorWindow;
}

class CalculatorWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CalculatorWindow(Calculators::Calculator c, DataStorage * storage, QWidget *parent = nullptr);
    ~CalculatorWindow();

private slots:
    void onLineEdit(QString text);
    void onCalculatorRequest();

private:
    Ui::CalculatorWindow *ui;
    DataStorage * storage_;
    std::map<QString, QLineEdit *> lineEdits_;
    Calculators::Calculator calculator_;
};

#endif // CALCULATORWINDOW_H
