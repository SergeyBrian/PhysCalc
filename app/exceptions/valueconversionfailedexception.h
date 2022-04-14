#ifndef VALUECONVERSIONFAILEDEXCEPTION_H
#define VALUECONVERSIONFAILEDEXCEPTION_H

#include "datastorageexception.h"

class ValueConversionFailedException : public DataStorageException
{
public:
    ValueConversionFailedException(DataStorage * storage, QString requestedType, QString realType);
    QString requestedType;
    QString realType;

};

#endif // VALUECONVERSIONFAILEDEXCEPTION_H
