//
// Created by suspe on 9/15/2022.
//

#include "RightParenAutomaton.h"
void RightParenAutomaton::S0(const std::string& input) {
    if (input[index] == ')') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}