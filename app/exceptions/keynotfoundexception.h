#ifndef KEYNOTFOUNDEXCEPTION_H
#define KEYNOTFOUNDEXCEPTION_H

#include "datastorageexception.h"

class KeyNotFoundException : public DataStorageException
{
public:
    KeyNotFoundException(DataStorage * storage, QString key);
    QString what();
    QString key;
    static QString message;
};

#endif // KEYNOTFOUNDEXCEPTION_H
