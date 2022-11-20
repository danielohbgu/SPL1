#include "Coalition.h"

Coalition::Coalition(int id): mId(id) 
{
}

void Coalition::addParty(Party& p)
{
    mParties[p.getId()] = p;
}

const int Coalition::getTotalMandates() const
{
    return mTotalMandates;
}