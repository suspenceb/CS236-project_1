//
// Created by suspe on 10/26/2022.
//

#include "Interpreter.h"
#include "Database.h"
#include <utility>

Interpreter::Interpreter(vector<Predicate *>s, vector<Predicate *>f, vector<Predicate *>q, vector<Rule *>r) {
    schemesVector = std::move(s);
    factVector = std::move(f);
    queryVector = std::move(q);
    ruleVector = std::move(r);

    interpretSchemes();
}

void Interpreter::interpretSchemes() {


    for (auto* s:schemesVector){
        predStrings = converetParams(s->parameters);
        debator->createRelation(s->getId(), predStrings);
    }
}

vector<string> Interpreter::converetParams(vector<Parameter*> vecs) {
    vector<string> returner;
    for (auto* s:vecs){
        returner.push_back(s->getP());
    }
    return returner;
}
