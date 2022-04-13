#ifndef DATASTORAGE_H
#define DATASTORAGE_H

#include <QVariant>

#include <map>
#include <string>



class DataStorage
{
public:
    DataStorage();
    void addValue(std::string key, QVariant * value);
    QVariant * getValue(std::string key);
private:
    bool hasKey(std::string key);
    std::map<std::string, QVariant *> values;
};

#endif // DATASTORAGE_H
