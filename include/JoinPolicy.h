#pragma once
#include <vector>
//#include "Simulation.h"
using std::vector;
class Simulation;
class JoinPolicy {
    public:
        const virtual int chooseOffer(Simulation& s, const vector<int>& offers) const=0;
        virtual JoinPolicy* clone() const=0;
};

class MandatesJoinPolicy : public JoinPolicy {
    public:
        const int chooseOffer(Simulation& s, const vector<int>& offers) const override;
        JoinPolicy* clone() const;
};

class LastOfferJoinPolicy : public JoinPolicy {
    public:
        const int chooseOffer(Simulation& s, const vector<int>& offers) const override;
        JoinPolicy* clone() const;
};