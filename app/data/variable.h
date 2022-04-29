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

#include "variable.inl"

#endif // VARIABLE_H
