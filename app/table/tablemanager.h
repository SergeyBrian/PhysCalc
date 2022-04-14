#ifndef TABLEMANAGER_H
#define TABLEMANAGER_H

#include <map>

#include "table.h"

class TableManager
{
public:
    TableManager();
    ~TableManager();

    void openTable(QString tablename, QString filename);
    void openTable(QString tablename);

    void closeTable(QString tablename);

    Table * getTable(QString tablename);
private:
    std::map<QString, Table *> tables;
};

#endif // TABLEMANAGER_H
