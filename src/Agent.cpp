#include "Agent.h"
#include "Simulation.h"

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy)
{}

Agent::Agent(const Agent& other) : Agent(other.mAgentId, other.mPartyId, other.cloneSelectionPolicy())
{}

Agent::Agent(Agent&& other) : Agent(other.mAgentId, other.mPartyId, other.mSelectionPolicy)
{
    other.mSelectionPolicy = nullptr;
}

Agent& Agent::operator=(const Agent& other)
{
    if (&other != this){
        mAgentId = other.mAgentId;
        mPartyId = other.mPartyId;

        delete mSelectionPolicy;
        mSelectionPolicy = other.cloneSelectionPolicy();
    }

    return *this;
}

Agent& Agent::operator=(Agent&& other)
{
    if (&other != this){
        mAgentId = other.mAgentId;
        mPartyId = other.mPartyId;

        delete mSelectionPolicy;
        mSelectionPolicy = other.mSelectionPolicy;
        other.mSelectionPolicy = nullptr;
    }

    return *this;
}

Agent::~Agent()
{
    if(mSelectionPolicy != nullptr)
        delete mSelectionPolicy;
}

int Agent::getId() const
{
    return mAgentId;
}

int Agent::getPartyId() const
{
    return mPartyId;
}

int Agent::getAgentId() const
{
    return mAgentId;
}

SelectionPolicy* Agent::cloneSelectionPolicy() const
{
    return mSelectionPolicy->clone();
}

void Agent::step(Simulation &sim)
{
    int chosenParty = mSelectionPolicy->chooseParty(sim, mAgentId);
    if (chosenParty != -1)
        sim.offerParty(chosenParty,sim.getParty(mPartyId).getCoalition());
}
