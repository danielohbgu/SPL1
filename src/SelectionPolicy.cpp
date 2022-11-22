#include "SelectionPolicy.h"
#include "Simulation.h"
#include <iostream>

const int MandatesSelectionPolicy::chooseParty(Simulation& s, int agentId)
{
    int maxMandatesIdx = 0;
    int agentPartyId=s.getAgents()[agentId].getPartyId();
    vector<int> parties = s.getGraph().getNotJoinedNeighbourParties(agentPartyId);

    // remove parties that already considering joining my coalition
    int myCoalition = s.getParty(agentPartyId).getCoalition();
    vector<int> filterParties;
    for(int i = 0; i < parties.size(); i++)
        if(!s.getParty(parties[i]).isAlreadyConsidering(myCoalition)){
            filterParties.push_back(parties[i]);
        }
    
    std::cout << "[";
    for (int partyId : filterParties)
        std::cout << partyId << ", ";
    std::cout << "]" << std::endl;

    if(filterParties.empty())
        return -1;

    for (int i = 1; i < filterParties.size(); i++)
        if (s.getParty(filterParties[i]).getMandates() > s.getParty(filterParties[maxMandatesIdx]).getMandates())
            maxMandatesIdx = i;
    
    return filterParties[maxMandatesIdx];
}

SelectionPolicy* MandatesSelectionPolicy::clone() const
{
    return new MandatesSelectionPolicy;
}

const int EdgeWeightSelectionPolicy::chooseParty(Simulation& s, int agentId)
{
    int  maxWeightIdx = 0;
    int agentPartyId=s.getAgents()[agentId].getPartyId();
    vector<int> parties = s.getGraph().getNotJoinedNeighbourParties(agentPartyId);
    vector<int> filterParties;
    // remove parties that already considering joining my coalition
    int myCoalition = s.getParty(agentPartyId).getCoalition();
    for(int i = 0; i < parties.size(); i++)
        if(!s.getParty(parties[i]).isAlreadyConsidering(myCoalition)){
            filterParties.push_back(parties[i]);
        }
    
    std::cout << "[";
    for (int partyId : filterParties)
        std::cout << partyId << ", ";
    std::cout << "]" << std::endl;
    
    if(filterParties.empty())
        return -1;

    for (int i = 1; i < filterParties.size(); i++)
        if(s.getGraph().getEdgeWeight(agentPartyId, filterParties[i]) > s.getGraph().getEdgeWeight(agentPartyId, filterParties[maxWeightIdx]))
            maxWeightIdx = i;

    return filterParties[maxWeightIdx];
}

SelectionPolicy* EdgeWeightSelectionPolicy::clone() const
{
    return new EdgeWeightSelectionPolicy;
}