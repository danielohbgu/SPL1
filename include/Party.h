#pragma once
#include <string>

using std::string;

#include "JoinPolicy.h"

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Simulation;
class Party
{
public:
    Party(int id, string name, int mandates, JoinPolicy *); 

    State getState() const;
    void setState(State state);
    int getMandates() const;
    void step(Simulation &s);
    const string &getName() const;
    const int getId() const;
    void setCoalition(int coalitionId);
    void addOffer(int coalitionId);
    const int getCoalition() const;
    const bool isAlreadyConsidering(int coalitionId) const;

private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    int mTimer;
    int mCoalitionId;
    vector<int> mOffers;
};
