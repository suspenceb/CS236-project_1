//
// Created by suspe on 10/4/2022.
//

#include "DatalogProgram.h"
#include "sstream"
#include "iostream"

DatalogProgram::~DatalogProgram() {

}

DatalogProgram::DatalogProgram(vector<Predicate *> scheme, vector<Predicate *> fact, vector<Predicate *> query, vector<Rule *> rule) {
    //cout << "hi" << endl;
    schemeVector = scheme;
    factVector = fact;
    queryVector = query;
    ruleVector = rule;
}

string DatalogProgram::toString() {
    stringstream s;
    s << "Schemes(" << schemeVector.size() << "):" << endl;
    for(auto scheme : schemeVector){
        s << scheme->toString();
    }
    s << "Facts("<< factVector.size() << "):" << endl;
    for(auto fact : factVector){
        s << fact->factString();
    }

    s << "Rules(" << ruleVector.size() << "):"<<endl;
    for(auto rule : ruleVector){
        s << rule->toString();
    }

    s << "Queries("<< queryVector.size() << "):" << endl;
    for(auto query : queryVector){
        s << query->queryString();
    }
    fillTheFactSet();
    s << "Domain(" << factSet.size() << "):" << endl;
    s << factSetToString();
    return s.str();
}

void DatalogProgram::fillTheFactSet() {
    for(auto string : factVector){
        for (auto param : string->parameters){
            factSet.insert(param->getP());
        }
    }

}

string DatalogProgram::factSetToString() {
    stringstream s;
    for (auto strings : factSet) {
        s << strings<<endl;
    }
    return s.str();
}

const vector<Predicate *> &DatalogProgram::getSchemeVector() const {
    return schemeVector;
}

const vector<Predicate *> &DatalogProgram::getFactVector() const {
    return factVector;
}

const vector<Predicate *> &DatalogProgram::getQueryVector() const {
    return queryVector;
}

const vector<Rule *> &DatalogProgram::getRuleVector() const {
    return ruleVector;
}
