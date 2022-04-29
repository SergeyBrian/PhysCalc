#include "variable.h"

#include "../exceptions/variableexceptions.h"

Variable::Variable(QString name, QString description, QString sourceCalculator)
{
    this->value_ = new QVariant();
    this->name_ = name;
    this->desc_ = description;
    this->calc_ = sourceCalculator;
    this->state_ = REQUIRED;
}

QVariant * Variable::value()
{
    return this->value_;
}

void Variable::checkConst()
{
    if (this->state_ == CONST) {
        throw ConstVariableValueChangeException(this);
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

QString Variable::calc()
{
    return this->calc_;
}

VariableState Variable::state()
{
    return this->state_;
}
