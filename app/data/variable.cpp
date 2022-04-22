#include "variable.h"

#include "../exceptions/variableexceptions.h"

QVariant * Variable::value()
{
    return this->value_;
}

void Variable::checkConst()
{
    if (this->const_) {
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

bool Variable::bConst()
{
    return this->const_;
}
