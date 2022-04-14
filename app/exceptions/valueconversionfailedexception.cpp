#include "valueconversionfailedexception.h"

ValueConversionFailedException::ValueConversionFailedException(DataStorage * storage, QString requestedType, QString realType) : DataStorageException(storage)
{
    this->requestedType = requestedType;
    this->realType = realType;
}
