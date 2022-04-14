#include "duplicatekeyexception.h"

QString DuplicateKeyException::message = "Value with given key already exsists";

DuplicateKeyException::DuplicateKeyException(DataStorage * storage, QString key) : DataStorageException(storage)
{
    this->key = key;
}

QString DuplicateKeyException::what()
{
    return this->message;
}
