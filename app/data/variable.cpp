#include "variable.h"

#include "../exceptions/variableexceptions.h"

Variable::Variable(QString name, QString description, Calculators::Calculator sourceCalculator)
{
    this->value_ = new QVariant();
    this->name_ = name;
    this->desc_ = description;
    this->calc_ = sourceCalculator;
    this->state_ = REQUIRED;
}

bool Variable::isEmpty()
{
    return !(this->value_->isNull());
}

void Variable::setState(VariableState state)
{
    this->state_ = state;
}

QVariant * Variable::value()
{
    return this->value_;
}

void Variable::checkConst()
{
    if (this->state_ == CONST) {
        throw new ConstVariableValueChangeException();
    }
}

QString Variable::type()
{
    return this->value_->typeName();
}

QString Variable::name()
{
    return this->name_;
}

QString Variable::desc()
{
    return this->desc_;
}

Calculators::Calculator Variable::calc()
{
    return this->calc_;
}

VariableState Variable::state()
{
    return this->state_;
}
