#pragma once

#include <vector>
//#include "Graph.h"

#include "SelectionPolicy.h"
class Simulation;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    int getPartyId() const;
    int getId() const;
    SelectionPolicy*  cloneSelectionPolicy() const;
    void step(Simulation &);

private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
};
