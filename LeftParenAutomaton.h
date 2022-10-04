//
// Created by suspe on 9/15/2022.
//

#ifndef INC_236PROJECT_1_LEFTPARENAUTOMATON_H
#define INC_236PROJECT_1_LEFTPARENAUTOMATON_H
#include "Automaton.h"

class LeftParenAutomaton : public Automaton
{
public:
    LeftParenAutomaton() : Automaton(TokenType::LEFT_PAREN) {}  // Call the base constructor

    void S0(const std::string& input);
};



#endif //INC_236PROJECT_1_LEFTPARENAUTOMATON_H
