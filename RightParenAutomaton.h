//
// Created by suspe on 9/15/2022.
//

#ifndef INC_236PROJECT_1_RIGHTPARENAUTOMATON_H
#define INC_236PROJECT_1_RIGHTPARENAUTOMATON_H

#include "Automaton.h"
class RightParenAutomaton : public Automaton
{
public:
    RightParenAutomaton() : Automaton(TokenType::RIGHT_PAREN) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //INC_236PROJECT_1_RIGHTPARENAUTOMATON_H
