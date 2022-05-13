#include "calculatorwindow.h"
#include "ui_calculatorwindow.h"

CalculatorWindow::CalculatorWindow(DataStorage * storage, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CalculatorWindow)
{
    this->storage_ = storage;
    ui->setupUi(this);


    for (auto const & variable : storage_->values) {
        QHBoxLayout * layout = new QHBoxLayout();

        QLabel * label = new QLabel(variable.second.first->name());
        label->setToolTip(variable.second.first->desc());
        layout->addWidget(label);

        QLineEdit * lineEdit = new QLineEdit();
        QString value = variable.second.first->value<QString>();
        if (!value.isEmpty()) {
            lineEdit->setText(value);
        }
        lineEdit->setProperty("key", variable.first);
        connect(lineEdit, SIGNAL(textChanged(QString)), SLOT(onLineEdit(QString)));
        layout->addWidget(lineEdit);

        if (variable.second.first->calc() != Calculators::NONE) {
            QPushButton * button = new QPushButton("Вычислить");
            button->setProperty("calc", (int)variable.second.first->calc());
            button->setProperty("field", lineEdit->objectName());
            connect(button, SIGNAL(clicked()), SLOT(onCalculatorRequest()));
            layout->addWidget(button);
        }

        ui->verticalLayout->addLayout(layout);
    }
}

CalculatorWindow::~CalculatorWindow()
{
    delete ui;
}

void CalculatorWindow::onLineEdit(QString text) {
    QString key = sender()->property("key").value<QString>();
    storage_->setValue(key, text.toDouble());
}

void CalculatorWindow::onCalculatorRequest() {
    Calculators::Calculator c = (Calculators::Calculator)sender()->property("calc").value<int>();
    QLineEdit * field = this->findChild<QLineEdit *>(sender()->property("field").value<QString>());
    CalculatorInterface::getValueFromOtherCalculator(c, storage_, field);
}
