#ifndef VARIABLE_H
#define VARIABLE_H

#include <QVariant>

#include <string>
#include "../enums.h"

namespace Variables {
    enum VariableState {
        REQUIRED,
        CONST,
        OPTIONAL
    };
}
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
    Variable(T value, QString name, QString description, Calculators::Calculator sourceCalculator = Calculators::NONE, Variables::VariableState state = Variables::REQUIRED);

    template<typename T>
    void value(T value);

    template<typename T>
    T value();

    bool isEmpty();

    void setState(Variables::VariableState state);

    QString type();
    QString name();
    QString desc();
    Calculators::Calculator calc();
    Variables::VariableState state();
private:
    QVariant * value();

    QString name_;
    QString desc_;
    Calculators::Calculator calc_;
    Variables::VariableState state_;
    QVariant * value_;

    void checkConst();
};

#include "variable.inl"

#endif // VARIABLE_H
