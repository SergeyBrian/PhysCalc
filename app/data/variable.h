#ifndef VARIABLE_H
#define VARIABLE_H

#include <QVariant>

#include <string>

class Variable
{
public:
    template<typename T>
    Variable(T value, std::string name, std::string description);

    template<typename T>
    void value(T value);

    template<typename T>
    T value();

    std::string type();
    std::string name();
    std::string desc();
private:
    Variable(QVariant * value, std::string name, std::string description);
    QVariant * value();

    std::string name_;
    std::string desc_;
    QVariant * value_;
};

// Tamplate methods implementation

template<typename T>
Variable::Variable(T value, std::string name, std::string description)
{
    this->value_ = new QVariant(value);
    this->name_ = name;
    this->desc_ = description;
}

template<typename T>
void Variable::value(T value) {
    this->value(new QVariant(value));
}

template<typename T>
T Variable::value() {
    return this->value_->value<T>();
}

#endif // VARIABLE_H
