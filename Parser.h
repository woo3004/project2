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
    Datalog date;
    Rule r;
    bool err = true;

    public:
    Parser(const vector<Token>& tokens) : tokens(tokens) { }

    void setError() {
        err = false;
    }

    TokenType tokenType() const {
        return tokens.at(0).getType();
    }
    void advanceToken() {
        tokens.erase(tokens.begin());
    }
    void throwError() {
        cout << "Failure!" << endl;
        setError();
        cout << "  " << tokens.at(0).toString() << endl;
    }

    void match(TokenType t) {
        cout << "match: " << typeName(t) << endl;
        if (tokenType() == t)
            advanceToken();
        else
            throwError();
    }

    void idList() {
        if (tokenType() == COMMA) {
            match(COMMA);
            para.setParameter(tokens.at(0).getValue());
            pred.addParameter(para);
            match(ID);
            idList();
        } else {
            // lambda
        }
    }

    void stringList() {
        if (tokenType() == COMMA) {
            match(COMMA);
            para.setParameter(tokens.at(0).getValue());
            pred.addParameter(para);
            match(STRING);
            stringList();
        }
        else {
            // lambda
        }
    }

    void schemeList() {
        if (tokenType() == ID) {
            scheme();
            schemeList();
        }
        else {
            // lambda
        }
    }

    void factList() {
        if (tokenType() == ID) {
            fact();
            factList();
        }
        else {
            // lambda
        }
    }


    void ruleList() {
        if (tokenType() == ID) {
            rule();
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
            predicate();
            predicateList();
        }
        else {
            // lambda
        }
    }

    void parameterList() {
        if (tokenType() == COMMA) {
            match(COMMA);
            parameter();
            parameterList();
        }
        else {
            // lambda
        }
    }

    


    void scheme() {
        if (tokenType() == ID) {
            pred.setId(tokens.at(0).getValue());
            match(ID);
            match(LEFT_PAREN);
            para.setParameter(tokens.at(0).getValue());
            pred.addParameter(para);
            match(ID);
            idList();
            match(RIGHT_PAREN);
            date.addScheme(pred);
            pred.getParameter().clear();
        } else {
            throwError();
        }
    }

    void fact() {
        if (tokenType() == ID) {
            pred.setId(tokens.at(0).getValue());
            match(ID);
            match(LEFT_PAREN);
            para.setParameter(tokens.at(0).getValue());
            pred.addParameter(para);
            match(STRING);
            stringList();
            match(RIGHT_PAREN);
            match(PERIOD);
            date.addFact(pred);
            pred.getParameter().clear();
        } else {
            throwError();
        }
    }

    void rule() {
        if (tokenType() == ID) {
            headPredicate();
            match(COLON_DASH);
            predicate();
            r.addRule(pred);
            pred.getParameter().clear();
            predicateList();
            match(PERIOD);
            r.addRuleVec(r);
            pred.getParameter().clear();
            r.getRuleSet().clear();
        } else {
            throwError();
        }
    }

    void headPredicate() {
        pred.setId(tokens.at(0).getValue());
        match(ID);
        match(LEFT_PAREN);
        para.setParameter(tokens.at(0).getValue());
        pred.addParameter(para);
        match(ID);
        idList();
        match(RIGHT_PAREN);
        r.addRule(pred);
        pred.getParameter().clear();
    }

    void predicate() {
        pred.setId(tokens.at(0).getValue());
        match(ID);
        match(LEFT_PAREN);
        parameter();
        parameterList();
        match(RIGHT_PAREN);
        
    }

    void parameter() {
        if(tokenType() == ID) {
            para.setParameter(tokens.at(0).getValue());
            pred.addParameter(para);
            match(ID);
        }
        if(tokenType() == STRING) {
            para.setParameter(tokens.at(0).getValue());
            pred.addParameter(para);
            match(STRING);
        }
    }

    void query() {
        if (tokenType() == ID) {
            predicate();
            match(Q_MARK);
            date.addQuery(pred);
            pred.getParameter().clear();
        } else {
            throwError();
        }
    }

    void datalogProgram() {
        match(SCHEMES);
        match(COLON);
        scheme();
        schemeList();

        if (err) {
            match(FACTS);
            match(COLON);
            factList();
        }

        if (err) {
            match(RULES);
            match(COLON);
            ruleList();
        }

        if (err) {            
            match(QUERIES);
            match(COLON);
            query();
            queryList();
        }


        if(tokenType() == END_FILE) {
            cout << "Success!" << endl;
        }

        if (err) {            
            cout << date.schemeString();
            cout << date.factString();
            cout << r.ruleString();
            cout << date.queryString();
        }





        // Function to check END OF FILE ????


        //
    }
    
};

