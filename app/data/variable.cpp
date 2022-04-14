#include "variable.h"

Variable::Variable(QVariant * value, std::string name, std::string description)
{
    this->value_ = value;
    this->name_ = name;
    this->desc_ = description;
}

QVariant * Variable::value()
{
    return this->value_;
}

std::string Variable::type()
{
    return this->value_->typeName();
}

std::string Variable::name()
{
    return this->name_;
}

std::string Variable::desc()
{
    return this->desc_;
}
