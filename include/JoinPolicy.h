#pragma once
#include <vector>
//#include "Simulation.h"
using std::vector;
class Simulation;
class JoinPolicy {
    public:
        const virtual int chooseOffer(Simulation& s, vector<int> offers)=0;
};

class MandatesJoinPolicy : public JoinPolicy {
    public:
        const int chooseOffer(Simulation& s, vector<int> offers) override;
};

class LastOfferJoinPolicy : public JoinPolicy {
    public:
        const int chooseOffer(Simulation& s, vector<int> offers) override;
};