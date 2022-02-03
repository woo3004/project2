#pragma once

#include <vector>
#include <string>
#include "Parameter.h"


using namespace std;
//SNAP(S, N, A, P)
class Predicate {
    public:
        string id;
        vector<Parameter> parameters;

        void setId(string id) {
            this -> id = id;
        }

};