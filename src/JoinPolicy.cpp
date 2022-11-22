#include "JoinPolicy.h"
#include "Simulation.h"
const int MandatesJoinPolicy::chooseOffer(Simulation& s, const vector<int>& offers) const
{
    int maxMandatesIdx = 0;

    for (unsigned int i = 1; i < offers.size(); i++)
        if (s.getCoalitionMandates(offers[i]) > s.getCoalitionMandates(offers[maxMandatesIdx]))
            maxMandatesIdx = i;
    
    return offers[maxMandatesIdx];
}

JoinPolicy* MandatesJoinPolicy::clone() const
{
    return new MandatesJoinPolicy;
}

MandatesJoinPolicy::~MandatesJoinPolicy(){

}

const int LastOfferJoinPolicy::chooseOffer(Simulation& s, const vector<int>& offers) const
{
    return offers[offers.size() -1];
}

JoinPolicy* LastOfferJoinPolicy::clone() const
{
    return new LastOfferJoinPolicy;
}

LastOfferJoinPolicy::~LastOfferJoinPolicy(){}

JoinPolicy::~JoinPolicy(){}