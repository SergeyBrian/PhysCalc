#ifndef VARIABLE_H
#define VARIABLE_H

#include <QVariant>

#include <string>

enum VariableState {
    REQUIRED,
    CONST,
    OPTIONAL_A,
    OPTIONAL_B,
    OPTIONAL_C,
    OPTIONAL_D,
    OPTIONAL_E,
    OPTIONAL_F,
    OPTIONAL_G,
    OPTIONAL_H
};

class Variable
{
public:
    Variable(QString name, QString description, QString sourceCalculator = QString(""));
    template<typename T>
    Variable(T value, QString name, QString description, QString sourceCalculator = QString(""), VariableState state = REQUIRED);

    template<typename T>
    void value(T value);

    template<typename T>
    T value();

    QString type();
    QString name();
    QString desc();
    QString calc();
    VariableState state();
private:
    QVariant * value();

    QString name_;
    QString desc_;
    QString calc_;
    VariableState state_;
    QVariant * value_;

    void checkConst();
};

#include "variable.inl"

#endif // VARIABLE_H
