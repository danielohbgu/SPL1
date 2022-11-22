#pragma once
#include <vector>
#include "Party.h"

using std::vector;

class Simulation;
class Graph
{
public:
    Graph(vector<Party> vertices, vector<vector<int>> edges);
    int getMandates(int partyId) const;
    int getEdgeWeight(int v1, int v2) const;
    int getNumVertices() const;
    const Party &getParty(int partyId) const;
    void partyStep(Simulation& sim, int partyId);
    Party& getNonConstParty(int partyId);
    const vector<int>* getNotJoinedNeighbourParties(int partyId) const;

private:
    vector<Party> mVertices;
    vector<vector<int>> mEdges;
};
