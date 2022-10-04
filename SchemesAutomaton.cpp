//
// Created by suspe on 9/15/2022.
//

#include "SchemesAutomaton.h"
void SchemesAutomaton::S0(const std::string& input) {
    if (input.substr(index,7) == "Schemes") {
        inputRead = 7;
    }
    else {
        Serr();
    }
}