//
// Created by suspe on 10/4/2022.
//

#include "Rule.h"
#include "sstream"
#include "iostream"
std::string Rule::toString() {
    std::stringstream s;
    s << "  " << this->headPredicate->getId() << "(";
    int i = 1;
    for (auto param : this->headPredicate->parameters){
        s << param->getP();
        if(i < int(this->headPredicate->parameters.size())){
            s << ",";
            i++;
        }
    }
    s << ") :- ";

    i = 1;
    int j = 1;
    int k = int(this->bodyPredicates.size());
    for(auto* body : this->bodyPredicates){

        s << body->getId() << "(";
        for(auto param : body->parameters){
            s << param->getP();
            if(i < int(body->parameters.size()))
            {
                s << ",";
                i++;
            }
        }
        if(j < k) {
            s << "),";
            j++;
            i = 1;
        }
    }
    s << ")." << endl;
    return s.str();
}
