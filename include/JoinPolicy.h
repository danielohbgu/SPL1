#pragma once

class JoinPolicy {
    public:
        Party& join()
};

class MandatesJoinPolicy : public JoinPolicy {};

class LastOfferJoinPolicy : public JoinPolicy {};