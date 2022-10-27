//
// Created by suspe on 10/26/2022.
//

#ifndef INC_236PROJECT_1_INTERPRETER_H
#define INC_236PROJECT_1_INTERPRETER_H
#include "DatalogProgram.h"
#include "Database.h"
#include "Token.h"
#include <vector>
#include "Predicate.h"

using namespace std;
class Interpreter {
private:
    std::vector<Predicate*> schemesVector;
    std::vector<Predicate*> factVector;
    std::vector<Predicate*> queryVector;
    std::vector<Rule*> ruleVector;
    vector<string> predStrings;
    void interpretSchemes();
    Database* debator = new Database;
    vector<string> converetParams(vector<Parameter*>);
public:
    Interpreter(vector<Predicate*>, vector<Predicate*>, vector<Predicate*>, vector<Rule*>);
    ~Interpreter() = default;

};


#endif //INC_236PROJECT_1_INTERPRETER_H
