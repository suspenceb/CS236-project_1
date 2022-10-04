//
// Created by suspe on 9/15/2022.
//

#ifndef INC_236PROJECT_1_ADDAUTOMATON_H
#define INC_236PROJECT_1_ADDAUTOMATON_H

#include "Automaton.h"
class AddAutomaton : public Automaton
{
public:
    AddAutomaton() : Automaton(TokenType::ADD) {}  // Call the base constructor

    void S0(const std::string& input);
};



#endif //INC_236PROJECT_1_ADDAUTOMATON_H
