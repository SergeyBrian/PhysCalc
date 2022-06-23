#ifndef DUPLICATEKEYEXCEPTION_H
#define DUPLICATEKEYEXCEPTION_H

#include "datastorageexception.h"

class DuplicateKeyException : public DataStorageException
{
public:
    DuplicateKeyException(QString key);
    QString what();
    QString key;
    static QString message;
};


#endif // DUPLICATEKEYEXCEPTION_H
