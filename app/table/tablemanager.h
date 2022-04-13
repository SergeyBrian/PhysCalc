#ifndef TABLEMANAGER_H
#define TABLEMANAGER_H

#include <map>

#include "table.h"

class TableManager
{
public:
    TableManager();
    ~TableManager();

    void openTable(std::string tablename, std::string filename);
    void openTable(std::string tablename);

    void closeTable(std::string tablename);

    Table * getTable(std::string tablename);
private:
    std::map<std::string, Table *> tables;
};

#endif // TABLEMANAGER_H
