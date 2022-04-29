// Template functions implementation

template<typename T>
void DataStorage::setValue(QString key, T value) {
    Variable * var = this->getValue(key);
    var->value(value);
}

template<typename T>
void DataStorage::addValue(QString key, T value, QString name, QString description, VariableState state, QString sourceCalculator) {
    Variable * var = new Variable(value, name, description, sourceCalculator, state);
    this->addValue(key, var);
}

template<typename T>
T DataStorage::value(QString key) {
    return this->getValue(key)->value<T>();
}

