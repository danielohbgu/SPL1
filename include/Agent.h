#pragma once

#include <vector>
//#include "Graph.h"

#include "SelectionPolicy.h"
class Simulation;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);

    // rule of 5
    Agent(const Agent& other);
    Agent(Agent&& other);
    Agent& operator=(const Agent& other);
    Agent& operator=(Agent&& other);
    virtual ~Agent();

    // getters
    int getPartyId() const;
    int getId() const;
    int getAgentId() const;

    SelectionPolicy*  cloneSelectionPolicy() const;
    void step(Simulation &);

private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
};
