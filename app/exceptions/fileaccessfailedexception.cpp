#include "fileaccessfailedexception.h"

FileAccessFailedException::FileAccessFailedException(QString filename)
{
    this->filename = filename;
}

QString FileAccessFailedException::what()
{
    return "Can't open file";
}

QMap<QString, QString> FileAccessFailedException::details()
{
    return QMap<QString, QString> {{"filename", filename}};
}
