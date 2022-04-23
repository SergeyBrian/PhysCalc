#ifndef VARIABLE_H
#define VARIABLE_H

#include <QVariant>

#include <string>

enum VariableState {
    VARIABLE,
    CONST
};

class Variable
{
public:
    Variable(QString name, QString description, QString sourceCalculator = QString(""));
    template<typename T>
    Variable(T value, QString name, QString description, QString sourceCalculator = QString(""), VariableState state = VARIABLE);

    template<typename T>
    void value(T value);

    template<typename T>
    T value();

    QString type();
    QString name();
    QString desc();
    QString calc();
    bool bConst();
private:
    QVariant * value();

    QString name_;
    QString desc_;
    QString calc_;
    bool const_;
    QVariant * value_;

    void checkConst();
};

// Tamplate methods implementation


template<typename T>
Variable::Variable(T value, QString name, QString description, QString sourceCalculator, VariableState state)
{
    this->value_ = new QVariant(value);
    this->name_ = name;
    this->desc_ = description;
    this->calc_ = sourceCalculator;
    this->const_ = state == CONST;
}

template<typename T>
void Variable::value(T value) {
    this->checkConst();
    this->value_ = new QVariant(value);
}

template<typename T>
T Variable::value() {
    return this->value_->value<T>();
}

#endif // VARIABLE_H
