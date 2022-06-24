#ifndef FILEACCESSFAILEDEXCEPTION_H
#define FILEACCESSFAILEDEXCEPTION_H

#include "tableexception.h"

class FileAccessFailedException : public TableException
{
public:
    FileAccessFailedException(QString filename);
    QString what();
    QMap<QString, QString> details();
private:
    QString filename;
};

#endif // FILEACCESSFAILEDEXCEPTION_H
