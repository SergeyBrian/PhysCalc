#include "calculatorwindow.h"
#include "ui_calculatorwindow.h"

CalculatorWindow::CalculatorWindow(Calculators::Calculator c, DataStorage * storage, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CalculatorWindow)
{
    this->storage_ = storage;
    this->calculator_ = c;
    ui->setupUi(this);


    for (auto const & variable : storage_->values) {
        if (variable.second.first->calc() == this->calculator_) {
            continue;
        }

        auto v = CalculatorInterface::getVariablesList(calculator_);
        if (std::find(v.begin(), v.end(), variable.first) == v.end()) {
            continue;
        }

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
        this->lineEdits_.insert({variable.first, lineEdit});
        connect(lineEdit, SIGNAL(textChanged(QString)), SLOT(onLineEdit(QString)));
        layout->addWidget(lineEdit);

        if (variable.second.first->calc() != Calculators::NONE) {
            QPushButton * button = new QPushButton("Вычислить");
            button->setProperty("calc", (int)variable.second.first->calc());
            button->setProperty("key", variable.first);
            lineEdit->setObjectName(variable.first);
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
    QString key = sender()->property("key").value<QString>();
    QLineEdit * field = this->lineEdits_[key];
    CalculatorInterface::getValueFromOtherCalculator(c, storage_, field);
    for (auto const & lineEdit : lineEdits_) {
        lineEdit.second->setText(storage_->getValue<QString>(lineEdit.first));
    }
}
