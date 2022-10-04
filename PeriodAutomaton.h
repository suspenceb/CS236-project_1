//
// Created by suspe on 9/15/2022.
//

#ifndef INC_236PROJECT_1_PERIODAUTOMATON_H
#define INC_236PROJECT_1_PERIODAUTOMATON_H

#include "Automaton.h"

class PeriodAutomaton : public Automaton
{
public:
    PeriodAutomaton() : Automaton(TokenType::PERIOD) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //INC_236PROJECT_1_PERIODAUTOMATON_H
