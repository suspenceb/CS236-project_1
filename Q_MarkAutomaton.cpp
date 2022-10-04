//
// Created by suspe on 9/15/2022.
//

#include "Q_MarkAutomaton.h"
#include <iostream>
using namespace std;
void Q_MarkAutomaton::S0(const std::string& input) {
    if (input[index] == '?') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}