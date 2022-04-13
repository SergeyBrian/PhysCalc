#include "keynotfoundexception.h"

std::string KeyNotFoundException::message = "No value with given key was found";

KeyNotFoundException::KeyNotFoundException(DataStorage * storage, std::string key) : DataStorageException(storage)
{
    this->key = key;
}

std::string KeyNotFoundException::what()
{
    return this->message;
}
