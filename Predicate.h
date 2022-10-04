//
// Created by suspe on 10/4/2022.
//

#ifndef INC_236PROJECT_1_PREDICATE_H
#define INC_236PROJECT_1_PREDICATE_H
#include "string"
#include "vector"
#include "Parameter.h"
using namespace std;


class Predicate {
private:
    string id;
public:
    const string &getId() const;

    void setId(const string &id);

public:
    vector<Parameter*> parameters;
};


#endif //INC_236PROJECT_1_PREDICATE_H
