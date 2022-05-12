#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>
#include <QPushButton>

#include "heatcapacitywindow.h"
#include "heatingvaluewindow.h"
#include "excessairratiowindow.h"
#include "stoichiometricratiowindow.h"

#include "../enums.h"
#include "../data/datastorage.h"
#include "../calculator/calculatorfactory.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void onClick(int id);

private:
    Ui::MainWindow *ui;
    DataStorage * storage;
};
#endif // MAINWINDOW_H
