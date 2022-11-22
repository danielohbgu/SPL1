#pragma once
#include <vector>
//#include "Simulation.h"
using std::vector;
class Simulation;
class JoinPolicy {
    public:
        virtual ~JoinPolicy();
        const virtual int chooseOffer(Simulation& s, const vector<int>& offers) const=0;
        virtual JoinPolicy* clone() const=0;
};

class MandatesJoinPolicy : public JoinPolicy {
    public:
        ~MandatesJoinPolicy();
        const int chooseOffer(Simulation& s, const vector<int>& offers) const override;
        JoinPolicy* clone() const;
};

class LastOfferJoinPolicy : public JoinPolicy {
    public:
        ~LastOfferJoinPolicy();
        const int chooseOffer(Simulation& s, const vector<int>& offers) const override;
        JoinPolicy* clone() const;
};