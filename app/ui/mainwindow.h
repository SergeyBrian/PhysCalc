#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>
#include <QPushButton>


#include "../enums.h"
#include "../data/datastorage.h"
#include "../calculator/calculatorfactory.h"
#include "calculatorinterface.h"
#include "../table/tablemanager.h"

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
