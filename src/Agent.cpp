#include "Agent.h"
#include "Simulation.h"
#include <iostream>

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy)
{
    // You can change the implementation of the constructor, but not the signature!
}

int Agent::getId() const
{
    return mAgentId;
}

int Agent::getPartyId() const
{
    return mPartyId;
}

SelectionPolicy* Agent::cloneSelectionPolicy() const
{
    return mSelectionPolicy->clone();
}

void Agent::step(Simulation &sim)
{
    std::cout << "Agent#" << mAgentId <<" is choosing party" << std::endl;
    int chosenParty = mSelectionPolicy->chooseParty(sim, mAgentId);
    if (chosenParty != -1){
        std::cout << "Agent#" << mAgentId << " chose Party#" << chosenParty << std::endl;
        sim.offerParty(chosenParty,sim.getParty(mPartyId).getCoalition());
    }
    else
        std::cout << "Agent#" << mAgentId << " has no party to choose from!" << std::endl;
}
