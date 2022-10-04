//
// Created by suspe on 9/15/2022.
//

#ifndef INC_236PROJECT_1_Q_MARKAUTOMATON_H
#define INC_236PROJECT_1_Q_MARKAUTOMATON_H


#include "Automaton.h"

class Q_MarkAutomaton : public Automaton
{
public:
    Q_MarkAutomaton() : Automaton(TokenType::Q_MARK) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //INC_236PROJECT_1_Q_MARKAUTOMATON_H
