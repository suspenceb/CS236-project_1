//
// Created by suspe on 10/4/2022.
//

#ifndef INC_236PROJECT_1_RULE_H
#define INC_236PROJECT_1_RULE_H
#include "Predicate.h"
#include "vector"
class Rule {
public:
    Predicate* headPredicate;
    vector<Predicate*> bodyPredicates;
    std::string toString();
};


#endif //INC_236PROJECT_1_RULE_H
