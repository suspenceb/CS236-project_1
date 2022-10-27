//
// Created by suspe on 10/26/2022.
//

#ifndef INC_236PROJECT_1_RELATION_H
#define INC_236PROJECT_1_RELATION_H
#include <string>
#include <vector>
#include "Header.h"
using namespace std;

class Relation {
private:
    string name;
    Header* header;

public:
    Relation(string, vector<string>);
    void tostring();
};


#endif //INC_236PROJECT_1_RELATION_H
