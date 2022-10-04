//
// Created by suspe on 9/16/2022.
//

#ifndef INC_236PROJECT_1_COMMENTAUTOMATON_H
#define INC_236PROJECT_1_COMMENTAUTOMATON_H

#include "Automaton.h"
class commentAutomaton : public Automaton
{
public:
    commentAutomaton() : Automaton(TokenType::COMMENT) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //INC_236PROJECT_1_COMMENTAUTOMATON_H
