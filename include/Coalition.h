#pragma once

#include <map>
#include "Party.h"

using std::map;

class Coalition{
    public:
        Coalition(int id);
        const int getTotalMandates() const;
        void addParty(Party& p);
    private:
        int mId;
        int mTotalMandates;
        map<int, Party> mParties;
};