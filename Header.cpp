//
// Created by suspe on 10/26/2022.
//

#include "Header.h"
#include <iostream>
void Header::makeHeader(vector<string> v) {
    rows = v;
}

void Header::tostring() {
    for (auto s:rows){
        cout << s << ",";
    }
    cout << endl;
}
