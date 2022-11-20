#include "Simulation.h"

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents)
{
    // create a Coalition for each agent and save all Coalitions in a vector
    for(int i = 0; i < agents.size(); i++){
        Coalition c(i);
        int partyId = agents[i].getPartyId();
        c.addParty(partyId, mGraph.getParty(partyId).getMandates());

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
    // TODO implement this method
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

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    // TODO: you MUST implement this method for getting proper output, read the documentation above.
    return vector<vector<int>>();
}
