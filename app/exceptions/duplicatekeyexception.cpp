#include "duplicatekeyexception.h"

std::string DuplicateKeyException::message = "Value with given key already exsists";

DuplicateKeyException::DuplicateKeyException(DataStorage * storage, std::string key) : DataStorageException(storage)
{
    this->key = key;
}

std::string DuplicateKeyException::what()
{
    return this->message;
}
