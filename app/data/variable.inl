// Tamplate methods implementation


template<typename T>
Variable::Variable(T value, QString name, QString description, QString sourceCalculator, VariableState state)
{
    this->value_ = new QVariant(value);
    this->name_ = name;
    this->desc_ = description;
    this->calc_ = sourceCalculator;
    this->const_ = state == CONST;
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
