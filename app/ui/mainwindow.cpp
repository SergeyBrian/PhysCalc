#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "enums.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QButtonGroup * buttonGroup = new QButtonGroup();
    std::map<Calculators::Calculator, QString> buttons = {{Calculators::HEAT_CAPACITY, "Теплоёмкость"}, {Calculators::HEATING_VALUE, "Теплотворная способность"}, {Calculators::STOICHIOMETRIC_RATIO, "Стехиометрическое соотношение"}, {Calculators::EXCESS_AIR_RATIO, "Коэффицент избытка воздуха"}};

    for (auto const & button : buttons)
    {
        QPushButton * tmpButton = new QPushButton(button.second);
        buttonGroup->addButton(tmpButton, (int)button.first);
        ui->verticalLayout->addWidget(tmpButton);
    }
    connect(buttonGroup, SIGNAL(idClicked(int)), SLOT(onClick(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onClick(int id)
{
    ui->statusbar->showMessage(QString::number(id));
}

