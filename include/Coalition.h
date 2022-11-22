#pragma once

#include <vector>
using std::vector;

class Coalition{
    public:
        Coalition(int id);
        const int getTotalMandates() const;
        void addParty(int partyId, int partyMandates);
        const vector<int> getParties() const;
        
    private:
        int mId;
        int mTotalMandates;
        vector<int> mParties;
};