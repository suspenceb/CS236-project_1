//
// Created by suspe on 10/4/2022.
//

#ifndef INC_236PROJECT_1_DATALOGPROGRAM_H
#define INC_236PROJECT_1_DATALOGPROGRAM_H
#include "Parser.h"
#include "iostream"
#include "set"
class DatalogProgram {
private:
    vector<Predicate*> schemeVector;
    vector<Predicate*> factVector;
    vector<Predicate*> queryVector;
    vector<Rule*> ruleVector;
    set<string> factSet;

public:
    const vector<Predicate *> &getSchemeVector() const;

    const vector<Predicate *> &getFactVector() const;

    const vector<Predicate *> &getQueryVector() const;

    const vector<Rule *> &getRuleVector() const;

    string toString();
    void fillTheFactSet();
    string factSetToString();
    DatalogProgram(vector<Predicate*>, vector<Predicate*>,vector<Predicate*>,vector<Rule*>);
    virtual ~DatalogProgram();
};


#endif //INC_236PROJECT_1_DATALOGPROGRAM_H
