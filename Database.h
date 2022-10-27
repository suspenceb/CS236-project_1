//
// Created by suspe on 10/26/2022.
//

#ifndef INC_236PROJECT_1_DATABASE_H
#define INC_236PROJECT_1_DATABASE_H
#include <string>
#include <vector>
#include <map>
#include "Relation.h"

using namespace std;
class Database {
private:

public:
    map<string, Relation*> mapboi;
    void createRelation(string, vector<string>);
};


#endif //INC_236PROJECT_1_DATABASE_H
