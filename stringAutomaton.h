//
// Created by suspe on 9/19/2022.
//

#ifndef INC_236PROJECT_1_STRINGAUTOMATON_H
#define INC_236PROJECT_1_STRINGAUTOMATON_H

#include "Automaton.h"
class stringAutomaton : public Automaton {
public:
    stringAutomaton() : Automaton(TokenType::STRING){}

    void S0(const std::string& input);
    void S1(const std::string& input);
    void S2(const std::string& input);
};


#endif //INC_236PROJECT_1_STRINGAUTOMATON_H
