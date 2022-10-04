//
// Created by suspe on 9/16/2022.
//

#ifndef INC_236PROJECT_1_EOFAUTOMATON_H
#define INC_236PROJECT_1_EOFAUTOMATON_H

#include "Automaton.h"
class eofAutomaton : public Automaton
{
public:
    eofAutomaton() : Automaton(TokenType::EOF_ENUM) {}  // Call the base constructor

    void S0(const std::string& input);
};



#endif //INC_236PROJECT_1_EOFAUTOMATON_H
