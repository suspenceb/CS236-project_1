//
// Created by suspe on 9/15/2022.
//

#ifndef INC_236PROJECT_1_FACTSAUTOMATON_H
#define INC_236PROJECT_1_FACTSAUTOMATON_H

#include "Automaton.h"
class FactsAutomaton : public Automaton
{
public:
    FactsAutomaton() : Automaton(TokenType::FACTS) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //INC_236PROJECT_1_FACTSAUTOMATON_H
