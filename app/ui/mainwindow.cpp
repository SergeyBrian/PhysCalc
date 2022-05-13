#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "../exceptions/uiexceptions.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QButtonGroup * buttonGroup = new QButtonGroup();
    std::map<Calculators::Calculator, QString> buttons = {{Calculators::HEAT_CAPACITY, "Теплоёмкость"}, {Calculators::HEATING_VALUE, "Теплотворная способность"}, {Calculators::STOICHIOMETRIC_RATIO, "Стехиометрическое соотношение"}, {Calculators::EXCESS_AIR_RATIO, "Коэффицент избытка воздуха"}};

    this->storage = new DataStorage();
    storage->addValue<int>("x", "name1", "desc1");
    storage->addValue<int>("y", "name2", "desc2");
    storage->addValue<int>("z", "name3", "desc3", Calculators::HEATING_VALUE);

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
    try {
        double result = CalculatorInterface::calculate((Calculators::Calculator)id, storage);
        ui->statusbar->showMessage(QString::number(result));
    } catch (DialogCanceledException) {
    }

}
