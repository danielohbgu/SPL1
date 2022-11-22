#pragma once

#include <vector>
using std::vector;

class Simulation;

class SelectionPolicy {
    public:
        const virtual int chooseParty(Simulation& s, int agentPartyId)=0;
        virtual SelectionPolicy* clone() const=0;
};

class MandatesSelectionPolicy: public SelectionPolicy{ 
    public:
        const int chooseParty(Simulation& s, int agentPartyId) override;
        SelectionPolicy*  clone() const override;
};

class EdgeWeightSelectionPolicy: public SelectionPolicy{ 
    public:
        const int chooseParty(Simulation& s, int agentPartyId) override;
        SelectionPolicy*  clone() const override;
};