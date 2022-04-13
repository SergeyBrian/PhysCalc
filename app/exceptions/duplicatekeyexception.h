#ifndef DUPLICATEKEYEXCEPTION_H
#define DUPLICATEKEYEXCEPTION_H

#include "datastorageexception.h"

class DuplicateKeyException : public DataStorageException
{
public:
    DuplicateKeyException(DataStorage * storage, std::string key);
    std::string what();
    std::string key;
    static std::string message;
};


#endif // DUPLICATEKEYEXCEPTION_H
