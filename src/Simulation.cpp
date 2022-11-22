#include "Simulation.h"
#include "Party.h"
#include <iostream>

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents)
{
    // create a Coalition for each agent and save all Coalitions in a vector
    for(int i = 0; i < agents.size(); i++){
        Coalition c(i);
        int partyId = agents[i].getPartyId();
        Party& p = mGraph.getNonConstParty(partyId);

        c.addParty(partyId, p.getMandates());
        p.setCoalition(i);
        p.setState(Joined);
        mCoalitions.push_back(c);
    }
    
}

void Simulation::step()
{
    for(int i = 0; i < mGraph.getNumVertices(); i++)
        mGraph.partyStep(*this, i);
    

    for(int i = 0; i < mAgents.size(); i++)
        mAgents[i].step(*this);
}

bool Simulation::shouldTerminate() const
{
    for (int i = 0; i < mCoalitions.size(); i++){
        if (mCoalitions[i].getTotalMandates() > 60)
            return true;
    }

    for(int i = 0; i < mGraph.getNumVertices(); i++){
        if (mGraph.getParty(i).getState() != Joined)
            return false;
    }

    return true;
}

const Graph &Simulation::getGraph() const
{
    return mGraph;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

void Simulation::addAgent(Agent &&newAgent)
{
    mAgents.push_back(newAgent);
}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}

const int Simulation::getCoalitionMandates(const int coalitionId) const
{
    return mCoalitions[coalitionId].getTotalMandates();
}

void Simulation::addPartyToCoalition(int partyId, int partyMandates, int coalitionId)
{
    mCoalitions[coalitionId].addParty(partyId, partyMandates);
}

void Simulation::offerParty(int partyId, int coalitionId)
{
    mGraph.getNonConstParty(partyId).addOffer(coalitionId);
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    vector<vector<int>> coalitions;

    for (int i = 0; i < mCoalitions.size(); i++)
        coalitions.push_back(mCoalitions[i].getParties());
        
    return coalitions;
}
