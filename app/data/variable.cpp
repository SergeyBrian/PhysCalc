#include "variable.h"

QVariant * Variable::value()
{
    return this->value_;
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
