#include "Coalition.h"

Coalition::Coalition(int id): mId(id), mTotalMandates(0) 
{
}

void Coalition::addParty(int partyId, int partyMandates)
{
    // assumes party not in the coalition yet
    mParties.push_back(partyId);
    mTotalMandates += partyMandates;
}

const int Coalition::getTotalMandates() const
{
    return mTotalMandates;
}

const vector<int> Coalition::getParties() const
{
    return mParties;
}