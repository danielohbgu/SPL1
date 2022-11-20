#include "Coalition.h"

Coalition::Coalition(int id): mId(id) 
{
}

void Coalition::addParty(int partyId, int partyMandates)
{
    // assumes party not in the coalition yet
    mParties.insert(partyId);
    mTotalMandates += partyMandates;
}

const int Coalition::getTotalMandates() const
{
    return mTotalMandates;
}