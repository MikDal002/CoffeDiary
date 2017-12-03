#ifndef ICOFFEEMETHOD_H
#define ICOFFEEMETHOD_H
#include <QString>
#include "ICoffeeParam.h"
class ICoffeeMethod
{
public:
    virtual QString GetName() = 0;
    virtual QList<ICoffeeParam *> GetParams() = 0;
    virtual QString GetMailBody();
	virtual QList<ICoffeeParam *> GetParamsForRecording() = 0;
protected:
    virtual ~ICoffeeMethod() {}
};

#endif // ICOFFEEMETHOD_H


