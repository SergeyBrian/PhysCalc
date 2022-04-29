// Tamplate methods implementation

#include "variable.h"

template<typename T>
Variable::Variable(T value, QString name, QString description, QString sourceCalculator, VariableState state)
{
    this->value_ = new QVariant(value);
    this->name_ = name;
    this->desc_ = description;
    this->calc_ = sourceCalculator;
    this->state_ = state;
}

template<typename T>
void Variable::value(T value) {
    this->checkConst();
    this->value_ = new QVariant(value);
}

template<typename T>
T Variable::value() {
    return this->value_->value<T>();
}
