#include "Party.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting), mCoalition(-1)
{}

State Party::getState() const
{
    return mState;
}

void Party::setState(State state)
{
    mState = state;
}

int Party::getMandates() const
{
    return mMandates;
}

const string & Party::getName() const
{
    return mName;
}

const int Party::getId() const
{
    return mId;
}

void Party::step(Simulation &s)
{
    if (mTimer == 3)
    {

        mState = Joined;
        
    }
    if (mState == CollectingOffers)
    {

    }
}
