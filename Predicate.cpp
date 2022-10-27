//
// Created by suspe on 10/4/2022.
//

#include "Predicate.h"
#include "sstream"
const string &Predicate::getId() const {
    return id;
}

void Predicate::setId(const string &id) {
    Predicate::id = id;
}

std::string Predicate::toString() {
    std::stringstream s;
    s << "  " << this->getId() << "(";
    int i = 1;
    for(auto param: this->parameters){
        s << param->getP();
        if(i < int(this->parameters.size())){
            s << ",";
            i++;
        }
    }
    s << ")" << endl;
    return s.str();
}

std::string Predicate::factString() {
    std::stringstream s;
    s << "  " << this->getId() << "(";
    int i = 1;
    for(auto param: this->parameters){
        s << param->getP();
        if(i < int(this->parameters.size())){
            s << ",";
            i++;
        }
    }
    s << ")." << endl;
    return s.str();
}

std::string Predicate::queryString() {
    std::stringstream s;
    s << "  " << this->getId() << "(";
    int i = 1;
    for(auto param: this->parameters){
        s << param->getP();
        if(i < int(this->parameters.size())){
            s << ",";
            i++;
        }
    }
    s << ")?" << endl;
    return s.str();
}
