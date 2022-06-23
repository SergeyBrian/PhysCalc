#include "keynotfoundexception.h"

KeyNotFoundException::KeyNotFoundException(QString key)
{
    this->key = key;
}

QString KeyNotFoundException::what()
{
    return "There is no value with given key";
}

QMap<QString, QString> KeyNotFoundException::details()
{
    return QMap<QString, QString> {{"key", key}};
}
