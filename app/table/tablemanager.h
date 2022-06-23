#ifndef TABLEMANAGER_H
#define TABLEMANAGER_H

#include "table.h"

class TableManager
{
public:
    TableManager();
    ~TableManager();

    Table * openTable(QString tablename, QString filename);
    Table * getTable(QString tablename);
    void closeTable(QString tablename);
private:
    QMap<QString, Table *> tables;
};

#endif // TABLEMANAGER_H
