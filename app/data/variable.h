#ifndef VARIABLE_H
#define VARIABLE_H

#include <QVariant>

#include <string>
#include "../enums.h"
#include "../exceptions/dataexceptions.h"

enum VariableState {
    REQUIRED,
    CONST,
    OPTIONAL
};

class Variable
{
public:
    Variable(QString name, QString description, Calculators::Calculator sourceCalculator = Calculators::NONE);
    template<typename T>
    Variable(T value, QString name, QString description, Calculators::Calculator sourceCalculator = Calculators::NONE, VariableState state = REQUIRED);

    template<typename T>
    void value(T value);

    template<typename T>
    T value();

    void setState(VariableState state);

    QString type();
    QString name();
    QString desc();
    Calculators::Calculator calc();
    VariableState state();
private:
    QVariant * value();

    QString name_;
    QString desc_;
    Calculators::Calculator calc_;
    VariableState state_;
    QVariant * value_;

    void checkConst();
};

#include "variable.inl"

#endif // VARIABLE_H
