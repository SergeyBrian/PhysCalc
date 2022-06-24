#ifndef TABLEEXCEPTION_H
#define TABLEEXCEPTION_H

#include <QString>
#include <QMap>

class TableException
{
public:
    TableException();
    virtual QString what();
    virtual QMap<QString, QString> details();
};

#endif // TABLEEXCEPTION_H
