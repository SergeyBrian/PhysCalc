#include "duplicatekeyexception.h"

DuplicateKeyException::DuplicateKeyException(QString key) : DataStorageException()
{
    this->key = key;
}

QString DuplicateKeyException::what()
{
    return "Value with given key already exsists";
}

QMap<QString, QString> DuplicateKeyException::details()
{
    return QMap<QString, QString> {{"key", key}};
}
