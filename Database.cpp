//
// Created by suspe on 10/26/2022.
//

#include "Database.h"
#include <iostream>
void Database::createRelation(string s, vector<string> v) {
    auto* relator = new Relation(s,v);
    mapboi[s] = relator;
    relator->tostring();

}
