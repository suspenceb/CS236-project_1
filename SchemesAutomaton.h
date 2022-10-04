//
// Created by suspe on 9/15/2022.
//

#ifndef INC_236PROJECT_1_SCHEMESAUTOMATON_H
#define INC_236PROJECT_1_SCHEMESAUTOMATON_H

#include "Automaton.h"
class SchemesAutomaton : public Automaton
{
public:
    SchemesAutomaton() : Automaton(TokenType::SCHEMES) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //INC_236PROJECT_1_SCHEMESAUTOMATON_H
