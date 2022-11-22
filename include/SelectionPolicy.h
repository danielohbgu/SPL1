#pragma once

#include <vector>
using std::vector;

class Simulation;

class SelectionPolicy {
    public:
        virtual ~SelectionPolicy();
        const virtual int chooseParty(Simulation& s, int agentPartyId) const=0;
        virtual SelectionPolicy* clone() const=0;
};

class MandatesSelectionPolicy: public SelectionPolicy{ 
    public:
        ~MandatesSelectionPolicy();
        const int chooseParty(Simulation& s, int agentPartyId) const override;
        SelectionPolicy*  clone() const override;
};

class EdgeWeightSelectionPolicy: public SelectionPolicy{ 
    public:
        ~EdgeWeightSelectionPolicy();
        const int chooseParty(Simulation& s, int agentPartyId) const override;
        SelectionPolicy*  clone() const override;
};