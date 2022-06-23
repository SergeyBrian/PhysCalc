#ifndef DATASTORAGEEXCEPTION_H
#define DATASTORAGEEXCEPTION_H

#include "../data/datastorage.h"

class DataStorageException
{
public:
    DataStorageException();
    virtual QString what();
    virtual QMap<QString, QString> details();
};

#endif // DATASTORAGEEXCEPTION_H
