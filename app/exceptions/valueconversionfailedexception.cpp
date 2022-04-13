#include "valueconversionfailedexception.h"

ValueConversionFailedException::ValueConversionFailedException(DataStorage * storage, std::string requestedType, std::string realType) : DataStorageException(storage)
{
    this->requestedType = requestedType;
    this->realType = realType;
}
