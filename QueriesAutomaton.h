//
// Created by suspe on 9/15/2022.
//

#ifndef INC_236PROJECT_1_QUERIESAUTOMATON_H
#define INC_236PROJECT_1_QUERIESAUTOMATON_H

#include "Automaton.h"
class QueriesAutomaton : public Automaton
{
public:
    QueriesAutomaton() : Automaton(TokenType::QUERIES) {}  // Call the base constructor

    void S0(const std::string& input);
};



#endif //INC_236PROJECT_1_QUERIESAUTOMATON_H
