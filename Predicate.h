#pragma once

#include <vector>
#include <string>
#include "Parameter.h"


using namespace std;
//SNAP(S, N, A, P)
class Predicate {
    public:
        string id;
        vector<Parameter> parameter_set;

        void setId(string id) {
            this -> id = id;
        }

        void addParameter(Parameter para) {
            parameter_set.push_back();
        }
        


};