//
// Created by suspe on 9/16/2022.
//

#ifndef INC_236PROJECT_1_UNDEFINEDAUTOMATON_H
#define INC_236PROJECT_1_UNDEFINEDAUTOMATON_H

#include "Automaton.h"
class UndefinedAutomaton : public Automaton
{
public:
    UndefinedAutomaton() : Automaton(TokenType::UNDEFINED) {}  // Call the base constructor

    void S0(const std::string& input);
};



#endif //INC_236PROJECT_1_UNDEFINEDAUTOMATON_H
