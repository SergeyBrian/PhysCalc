#include "keynotfoundexception.h"

QString KeyNotFoundException::message = "No value with given key was found";

KeyNotFoundException::KeyNotFoundException(DataStorage * storage, QString key) : DataStorageException(storage)
{
    this->key = key;
}

QString KeyNotFoundException::what()
{
    return this->message;
}
