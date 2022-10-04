//
// Created by suspe on 9/15/2022.
//

#include "RulesAutomaton.h"
void RulesAutomaton::S0(const std::string& input) {
    if (input.substr(index,5) == "Rules") {
        inputRead = 5;
    }
    else {
        Serr();
    }
}