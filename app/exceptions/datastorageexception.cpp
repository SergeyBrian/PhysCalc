#include "datastorageexception.h"

DataStorageException::DataStorageException(DataStorage * storage)
{
    this->storage = storage;
}
