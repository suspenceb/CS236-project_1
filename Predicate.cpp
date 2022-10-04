//
// Created by suspe on 10/4/2022.
//

#include "Predicate.h"

const string &Predicate::getId() const {
    return id;
}

void Predicate::setId(const string &id) {
    Predicate::id = id;
}
