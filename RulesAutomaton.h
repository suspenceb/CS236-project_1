//
// Created by suspe on 9/15/2022.
//

#ifndef INC_236PROJECT_1_RULESAUTOMATON_H
#define INC_236PROJECT_1_RULESAUTOMATON_H

#include "Automaton.h"
class RulesAutomaton : public Automaton
{
public:
    RulesAutomaton() : Automaton(TokenType::RULES) {}  // Call the base constructor

    void S0(const std::string& input);
};



#endif //INC_236PROJECT_1_RULESAUTOMATON_H
