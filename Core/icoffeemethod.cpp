#include "ICoffeeMethod.h"
QString ICoffeeMethod::GetMailBody()
{
    QString retVal = "Parzenie metodą grawitacyjną: \r\n";
    foreach (auto foo, GetParams())
    {
        retVal += "\t " + foo->GetParamName() + ": \t" + foo->ToString() + "\r\n";

    }
    return retVal;
}
