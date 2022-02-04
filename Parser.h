#pragma once
#include "Scanner.h"
#include "Datalog.h"
#include <vector>
#include <iostream>

class Parser {
    private:
    vector<Token> tokens;
    Predicate pred;
    Parameter para;
    vector<Parameter> paraV;
    Datalog Date;

    public:
    Parser(const vector<Token>& tokens) : tokens(tokens) { }

    TokenType tokenType() const {
        return tokens.at(0).getType();
    }
    void advanceToken() {
        tokens.erase(tokens.begin());
    }
    void throwError() {
        cout << "error" << endl;
    }

    void match(TokenType t) {
        cout << "match: " << t << endl;
        if (tokenType() == t)
        advanceToken();
        else
        throwError();
    }

    void idList() {
        if (tokenType() == COMMA) {
        match(COMMA);
        match(ID);
        idList();
        } else {
            // lambda
        }
    }

    void schemeList() {
        if (tokenType() == SCHEMES) {
        match(SCHEMES);
        schemeList();
        }
        else {
            // lambda
        }
    }

    void factList() {
        if (tokenType() == FACTS) {
        match(FACTS);
        factList();
        }
        else {
            // lambda
        }
    }


    void ruleList() {
        if (tokenType() == RULES) {
        match(RULES);
        ruleList();
        }
        else {
            // lambda
        }
    }

    void queryList() {
        if (tokenType() == QUERIES) {
        match(QUERIES);
        queryList();
        }
        else {
            // lambda
        }
    }

    void predicateList() {
        if (tokenType() == COMMA) {
        match(COMMA);
        // predicate();
        predicateList();
        }
        else {
            // lambda
        }
    }

    void parameterList() {
        if (tokenType() == COMMA) {
        match(COMMA);
        // parameter();
        parameterList();
        }
        else {
            // lambda
        }
    }

    void stringList() {
        if (tokenType() == COMMA) {
        match(COMMA);
        match(STRING);
        stringList();
        }
        else {
            // lambda
        }
    }


    void scheme() {
        if (tokenType() == ID) {
        match(ID);
        match(LEFT_PAREN);
        match(ID);
        idList();
        match(RIGHT_PAREN);
        } else {
        throwError();
        }
    }

    void fact() {
        if (tokenType() == ID) {
            match(ID);
            match(LEFT_PAREN);
            match(STRING);
            stringList();
            match(RIGHT_PAREN);
            match(PERIOD);
        } else {
            throwError();
        }
    }

    void rule() {
    }

    void query() {
    }

    void dataLogProgram() {
        if(tokenType() == SCHEMES) {
            
        }
    }

};

