#include "Party.h"
#include "Simulation.h"
#include "Agent.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : 
    mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting), mCoalitionId(-1), mTimer(0), mOffers(vector<int>())
{}

Party::Party(const Party& other) :
    mId(other.mId), 
    mName(other.mName), 
    mMandates(other.mMandates), 
    mJoinPolicy(other.mJoinPolicy->clone()), 
    mState(other.mState), 
    mCoalitionId(other.mCoalitionId),
    mTimer(other.mTimer),
    mOffers(other.mOffers)
{}

Party::Party(Party&& other) :
    mId(other.mId), 
    mName(other.mName), 
    mMandates(other.mMandates), 
    mJoinPolicy(other.mJoinPolicy), 
    mState(other.mState), 
    mCoalitionId(other.mCoalitionId),
    mTimer(other.mTimer),
    mOffers(other.mOffers)
{
    other.mJoinPolicy = nullptr;
}

Party& Party::operator=(const Party& other)
{
    if (this != &other){
        mId = other.mId;
        mName = other.mName;
        mMandates = other.mMandates;

        delete mJoinPolicy;
        mJoinPolicy = other.mJoinPolicy->clone();

        mState = other.mState;
        mCoalitionId = other.mCoalitionId;
        mTimer = other.mTimer;
        mOffers=other.mOffers;
    }

    return *this;
}

Party& Party::operator=(Party&& other)
{
    if (this != &other){
        mId = other.mId;
        mName = other.mName;
        mMandates = other.mMandates;

        delete mJoinPolicy;
        mJoinPolicy = other.mJoinPolicy;
        other.mJoinPolicy = nullptr;

        mState = other.mState;
        mCoalitionId = other.mCoalitionId;
        mTimer = other.mTimer;
        mOffers=other.mOffers;
    }

    return *this;
}

Party::~Party()
{
    if(mJoinPolicy != nullptr)
        delete mJoinPolicy;
}

State Party::getState() const
{
    return mState;
}

void Party::setState(State state)
{
    mState = state;
}

void Party::setCoalition(int coalitionId){
    mCoalitionId = coalitionId;
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
    if (mState == CollectingOffers)
        mTimer++;

    if (mTimer == 3)
    {
        // add party to coalition
        mCoalitionId = mJoinPolicy->chooseOffer(s, mOffers);
        s.addPartyToCoalition(mId, mMandates, mCoalitionId);

        // clone agent
        int lastId = s.getAgents().size();
        s.addAgent(Agent(lastId, mId, s.getAgents()[mCoalitionId].cloneSelectionPolicy()));
        
        // change state to Joined
        mState = Joined;
        
        mTimer++;
    }
}

void Party::addOffer(int coalitionId)
{
    for(unsigned int i=0; i<mOffers.size(); i++)
        if(mOffers[i]==coalitionId)
            return;

    mOffers.push_back(coalitionId);
    mState = CollectingOffers;
}

const int Party::getCoalition() const
{
    return mCoalitionId;
}

const bool Party::isAlreadyConsidering(int coalitionId) const
{
    for(int curCoalition : mOffers)
        if(curCoalition == coalitionId)
            return true;
    
    return false;
}
