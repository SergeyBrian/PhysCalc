#ifndef VARIABLE_H
#define VARIABLE_H

#include <QVariant>

#include <string>

enum VariableState {
    REQUIRED,
    CONST,
    OPTIONAL
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

    void setState(VariableState state);

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
