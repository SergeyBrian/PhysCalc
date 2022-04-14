#include "variable.h"

Variable::Variable(QVariant * value, QString name, QString description)
{
    this->value_ = value;
    this->name_ = name;
    this->desc_ = description;
}

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
