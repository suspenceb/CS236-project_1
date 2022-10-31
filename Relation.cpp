//
// Created by suspe on 10/26/2022.
//

#include "Relation.h"
#include <iostream>

Relation::Relation(string s, vector<string> v) {
    name = s;
    auto* heads = new Header;
    heads->makeHeader(v);
    header = heads;
}

void Relation::tostring() {
    cout << "Name: " << name << "\n header info:";
    header->tostring();
}
