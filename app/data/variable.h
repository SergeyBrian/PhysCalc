#ifndef VARIABLE_H
#define VARIABLE_H

#include <QVariant>

#include <string>

class Variable
{
public:
    template<typename T>
    Variable(T value, QString name, QString description);

    template<typename T>
    void value(T value);

    template<typename T>
    T value();

    QString type();
    QString name();
    QString desc();
private:
    Variable(QVariant * value, QString name, QString description);
    QVariant * value();

    QString name_;
    QString desc_;
    QVariant * value_;
};

// Tamplate methods implementation

template<typename T>
Variable::Variable(T value, QString name, QString description)
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
