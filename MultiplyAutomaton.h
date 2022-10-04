//
// Created by suspe on 9/15/2022.
//

#ifndef INC_236PROJECT_1_MULTIPLYAUTOMATON_H
#define INC_236PROJECT_1_MULTIPLYAUTOMATON_H

#include "Automaton.h"

class MultiplyAutomaton : public Automaton
{
public:
    MultiplyAutomaton() : Automaton(TokenType::MULTIPLY) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //INC_236PROJECT_1_MULTIPLYAUTOMATON_H
