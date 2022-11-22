#pragma once
#include <vector>
//#include "Simulation.h"
using std::vector;
class Simulation;
class JoinPolicy {
    public:
        const virtual int chooseOffer(Simulation& s, const vector<int>& offers) const=0;
};

class MandatesJoinPolicy : public JoinPolicy {
    public:
        const int chooseOffer(Simulation& s, const vector<int>& offers) const override;
};

class LastOfferJoinPolicy : public JoinPolicy {
    public:
        const int chooseOffer(Simulation& s, const vector<int>& offers) const override;
};