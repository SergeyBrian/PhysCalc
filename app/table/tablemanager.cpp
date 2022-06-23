#include "tablemanager.h"

TableManager::~TableManager()
{
    qDeleteAll(tables);
    tables.clear();
}

Table * TableManager::openTable(QString tablename, QString filename)
{
    Table * table = new Table(filename);
    tables.insert(tablename, table);
    return table;
}

void TableManager::closeTable(QString tablename)
{
    Table * table = getTable(tablename);
    tables.remove(tablename);
    delete table;
}

Table *TableManager::getTable(QString tablename)
{
    return tables[tablename];
}
