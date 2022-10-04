//
// Created by suspe on 9/16/2022.
//

#ifndef INC_236PROJECT_1_IDAUTOMATON_H
#define INC_236PROJECT_1_IDAUTOMATON_H

#include "Automaton.h"

class idAutomaton : public Automaton
{
public:
    idAutomaton() : Automaton(TokenType::ID) {}  // Call the base constructor

    void S0(const std::string& input);
};



#endif //INC_236PROJECT_1_IDAUTOMATON_H
