#include "Party.h"
#include "Simulation.h"
#include "Agent.h"
#include <iostream>

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : 
    mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting), mCoalitionId(-1), mTimer(0)
{}

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
        std::cout << "choosing coalition for Party#" << mId << std::endl;
        // add party to coalition
        mCoalitionId = mJoinPolicy->chooseOffer(s, mOffers);
        std::cout << "joining Party#" << mId << " to Coalition#" << mCoalitionId << std::endl;
        s.addPartyToCoalition(mId, mMandates, mCoalitionId);

        // clone agent
        int lastId = s.getAgents().size();
        std::cout << "All agents: ";
        for (Agent agent : s.getAgents())
            std::cout << "[" << agent.getId() << ", " << agent.getPartyId() << "], ";
        std::cout << std::endl;
        std::cout << "Creating Agent#" << lastId << std::endl;
        Agent clone(lastId, mId, s.getAgents()[mCoalitionId].cloneSelectionPolicy());
        std::cout << "Adding Agent#" << lastId << " to the simulation" << std::endl;
        s.addAgent(clone);
        std::cout << "All agents after adding: ";
        for (Agent agent : s.getAgents())
            std::cout << "[" << agent.getId() << ", " << agent.getPartyId() << "], ";
        std::cout << std::endl;
        
        // change state to Joined
        mState = Joined;
        
        mTimer++;
    }
}

void Party::addOffer(int coalitionId)
{
    for(int i=0; i<mOffers.size(); i++)
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
