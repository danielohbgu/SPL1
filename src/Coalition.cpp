#include "Coalition.h"

Coalition::Coalition(int id): mId(id), mTotalMandates(0) , mParties(new vector<int>)
{
}

Coalition::Coalition(const Coalition& other) : mId(other.mId), mTotalMandates(other.mTotalMandates), mParties(new vector<int>(*other.mParties))
{}

Coalition::~Coalition()
{
    if(mParties!=nullptr){
        delete mParties;
    }
}

Coalition& Coalition::operator=(const Coalition& other)
{
    if(this != &other){
        delete mParties;
        mParties=new vector<int>(*other.mParties);
        mId=other.mId;
        mTotalMandates=other.mTotalMandates;
    }
    return *this;
}

Coalition::Coalition(Coalition&& other) : mId(other.mId), mTotalMandates(other.mTotalMandates), mParties(other.mParties)
{
    other.mParties=nullptr;
}

Coalition& Coalition::operator=(Coalition&& other)
{
    if(this != &other){
        delete mParties;
        mParties=other.mParties;
        mId=other.mId;
        mTotalMandates=other.mTotalMandates;
        other.mParties=nullptr;
    }
    return *this;
}

void Coalition::addParty(int partyId, int partyMandates)
{
    // assumes party not in the coalition yet
    mParties->push_back(partyId);
    mTotalMandates += partyMandates;
}

const int Coalition::getTotalMandates() const
{
    return mTotalMandates;
}

const vector<int>& Coalition::getParties() const
{
    return *mParties;
}