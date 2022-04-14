#ifndef DATASTORAGEEXCEPTION_H
#define DATASTORAGEEXCEPTION_H

#include "../data/datastorage.h"

class DataStorageException
{
public:
    DataStorageException(DataStorage * storage);
    std::string what();
    DataStorage * storage;
};

#endif // DATASTORAGEEXCEPTION_H
