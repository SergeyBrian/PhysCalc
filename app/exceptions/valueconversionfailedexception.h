#ifndef VALUECONVERSIONFAILEDEXCEPTION_H
#define VALUECONVERSIONFAILEDEXCEPTION_H

#include "datastorageexception.h"

class ValueConversionFailedException : public DataStorageException
{
public:
    ValueConversionFailedException(DataStorage * storage, std::string requestedType, std::string realType);
    std::string requestedType;
    std::string realType;

};

#endif // VALUECONVERSIONFAILEDEXCEPTION_H
