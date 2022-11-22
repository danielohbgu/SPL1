#include "Graph.h"
#include "Simulation.h"

Graph::Graph(vector<Party> vertices, vector<vector<int>> edges) : mVertices(vertices), mEdges(edges) 
{
    // You can change the implementation of the constructor, but not the signature!
}

int Graph::getMandates(int partyId) const
{
    return mVertices[partyId].getMandates();
}

int Graph::getEdgeWeight(int v1, int v2) const
{
    return mEdges[v1][v2];
}

int Graph::getNumVertices() const
{
    return mVertices.size();
}

const Party &Graph::getParty(int partyId) const
{
    return mVertices[partyId];
}

Party &Graph::getNonConstParty(int partyId)
{
    return mVertices[partyId];
}


void Graph::partyStep(Simulation& sim, int partyId)
{
    mVertices[partyId].step(sim);
}

const vector<int>* Graph::getNotJoinedNeighbourParties(int partyId) const
{
    vector<int>* parties = new vector<int>;

    for (int i = 0; i < mEdges.size(); i++)
        if (mEdges[partyId][i] > 0 && mVertices[i].getState() != Joined)
            parties->push_back(i);
    
    return parties;
}