#ifndef DIALOGCANCELEDEXCEPTION_H
#define DIALOGCANCELEDEXCEPTION_H

#include "uiexception.h"

class DialogCanceledException : public UiException
{
public:
    DialogCanceledException();
};

#endif // DIALOGCANCELEDEXCEPTION_H
