//
// Created by suspe on 9/15/2022.
//

#include "LeftParenAutomaton.h"
void LeftParenAutomaton::S0(const std::string& input) {
    if (input[index] == '(') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}