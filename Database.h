#pragma once

#include "Relation.h"
#include <map>

class Database
{
private:
    map<string, Relation> relations;

public:
    void insert(Relation r)
    {
        relations.insert({r.getName(),r});
    }

    Relation getRelationCopy(string name) {
        return relations.at(name);
    }

    Relation& getRelationReference(string name){
        return relations.at(name);
    }

    unsigned int size() {
        unsigned int count = 0;
        for(auto pairP : relations) {
            count += pairP.second.size();
        }
        return count;
    }

    string toString() {
        stringstream out;
        for (auto pairP : relations) {
            out << pairP.first << endl;
            out << pairP.second.toString() << endl;
        }
        return out.str();
    } 
}; 

