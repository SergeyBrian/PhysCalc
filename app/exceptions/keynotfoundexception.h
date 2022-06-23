#ifndef KEYNOTFOUNDEXCEPTION_H
#define KEYNOTFOUNDEXCEPTION_H

#include "datastorageexception.h"

class KeyNotFoundException : public DataStorageException
{
public:
    KeyNotFoundException(QString key);
    QString what();
    QMap<QString, QString> details();
private:
    QString key;
};

#endif // KEYNOTFOUNDEXCEPTION_H
