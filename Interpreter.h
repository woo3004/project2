#pragma once
#include "Database.h"
#include "Datalog.h"

class Interpreter
{
private:
    Datalog program;
    Database database;
public:
    Interpreter(Datalog program) : program(program)
    {}

    void run() {
        //Schemes
        evalSchemes();
        //Facts
        evalFacts();
        //Rules(Project 4)
        //Queries
        evalQueries();
    }

    void evalSchemes() {
        for (Predicate p : program.getSchemeSet()) {
            Relation newRelation;
            vector<string> contents;
            for (Parameter param : p.getParameter()) {
                contents.push_back(param.getParaVal());
            }
            newRelation.setScheme(Scheme(contents));
            newRelation.setName(p.getID());
            database.insert(newRelation);
        }
    }

    void evalFacts() {
        for (Predicate p : program.getFactSet()) {
            Relation r = database.getRelationReference(p.getID());
            vector<string> contents;
            for (Parameter param : p.getParameter()) {
                contents.push_back(param.getParaVal());
            }
            r.addTuple(Tuple(contents));
            // database.insert(r);

        }
    }

    void evalQueries() {
        for (Predicate p : program.getQuerySet()) {
            Relation r = evaluatePredicate(p);

            cout << r.toString();
        }
    }

    Relation evaluatePredicate(Predicate predicate) {
        Relation currRel = database.getRelationCopy(predicate.getID());
        vector<unsigned int> colsToKeep;
        vector<string> names;

        for (unsigned int i = 0; i < predicate.getParameter().size(); i++) {
            Parameter currParam = predicate.getParameter().at(i);

            if(currParam.getParaVal().at(0) == '\'') {
                currRel = currRel.select(i, currParam.getParaVal());
            }
            else {
                bool seenBefore = false;
                int j = 0;
                //loop that checks through names and if currParam is found set seen before to true


                if(seenBefore) {
                    currRel = currRel.select(i, colsToKeep.at(j));
                }
                else {
                    colsToKeep.push_back(i);
                    names.push_back(currParam.getParaVal());
                }
            }
        }
        //project(cols to keep)
        //rename(names)
        return currRel;
    }

    Database getDataBase() {
        return database;
    }

    

};
