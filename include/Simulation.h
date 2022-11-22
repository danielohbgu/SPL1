#pragma once

#include <vector>

#include "Agent.h"
#include "Graph.h"
#include "Coalition.h"

using std::string;
using std::vector;

//class Agent;
class Party;
class Simulation
{
public:
    Simulation(Graph g, vector<Agent> agents);

    void step();
    bool shouldTerminate() const;
    const Graph &getGraph() const;
    const vector<Agent> &getAgents() const;
    const Party &getParty(int partyId) const;
    const vector<vector<int>> getPartiesByCoalitions() const;
    const int getCoalitionMandates(const int coalitionId) const;
    void addPartyToCoalition(int partyId, int partyMandates, int coalitionId);
    void addAgent(Agent &&newAgent);
    void offerParty(int partyId, int coalitionId);

private:
    Graph mGraph;
    vector<Agent> mAgents;
    vector<Coalition> mCoalitions;
};
