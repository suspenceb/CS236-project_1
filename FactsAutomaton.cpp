//
// Created by suspe on 9/15/2022.
//

#include "FactsAutomaton.h"
void FactsAutomaton::S0(const std::string& input) {
    if (input.substr(index,5) == "Facts") {
        inputRead = 5;
    }
    else {
        Serr();
    }
}