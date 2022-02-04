#pragma onece

#include "Predicate.h"
#include "Rule.h"

class Datalog {
    private:
        vector<Predicate> scheme_set;
        vector<Predicate> fact_set;
        vector<Predicate> query_set;

    public:
        void addScheme(Predicate pre) {
            scheme_set.push_back(pre);
        }


        
        void addFact(Predicate pre) {
            fact_set.push_back(pre);
        }


        void addQuery(Predicate pre) {
            querie_set.push_back(pre);
        }

        vector<Predicate>& getSchemeSet() {
            return scheme_set;
        }

        vector<Predicate>& getFactSet() {
            return fact_set;
        }

        vector<Predicate>& getQuerySet() {
            return query_set;
        }
        

};