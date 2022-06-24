#ifndef DUPLICATEKEYEXCEPTION_H
#define DUPLICATEKEYEXCEPTION_H

#include "datastorageexception.h"

class DuplicateKeyException : public DataStorageException
{
public:
    DuplicateKeyException(QString key);
    QString what();
    QMap<QString, QString> details();
private:
    QString key;
};


#endif // DUPLICATEKEYEXCEPTION_H
