#ifndef KEYNOTFOUNDEXCEPTION_H
#define KEYNOTFOUNDEXCEPTION_H

#include "datastorageexception.h"

class KeyNotFoundException : public DataStorageException
{
public:
    KeyNotFoundException(DataStorage * storage, std::string key);
    std::string what();
    std::string key;
    static std::string message;
};

#endif // KEYNOTFOUNDEXCEPTION_H
