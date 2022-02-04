# pragma once
# include "Predicate.h"

class Rule {
    private:
        Predicate predicate;
        vector<Predicate> rule_set;

    public:
        void addRule(Predicate pre) {
            rule_set.push_back(pre);
        }

        vector<Predicate>& getRuleSet() {
            return rule_set;
        }
};