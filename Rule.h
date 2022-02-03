# pragma once
# include "Predicate.h"

class Rule {
    private:
        Predicate predicate;
        vector<Predicate> userPred;
};