#pragma once

#include <set>

using std::set;

class Coalition{
    public:
        Coalition(int id);
        const int getTotalMandates() const;
        void addParty(int partyId, int partyMandates);
        
    private:
        int mId;
        int mTotalMandates;
        set<int> mParties;
};