#include "tablemanager.h"

TableManager::~TableManager()
{
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
    tables.remove(tablename);
}

Table *TableManager::getTable(QString tablename)
{
    return tables[tablename];
}
