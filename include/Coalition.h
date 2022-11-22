#pragma once

#include <vector>
using std::vector;

class Coalition{
    public:
        Coalition(int id);
        Coalition (const Coalition& other);
        virtual ~Coalition();
        Coalition& operator=(const Coalition& other);
        Coalition (Coalition&& other);
        Coalition& operator=(Coalition&& other);
        const int getTotalMandates() const;
        void addParty(int partyId, int partyMandates);
        const vector<int>& getParties() const;
        
    private:
        int mId;
        int mTotalMandates;
        vector<int>* mParties;
};