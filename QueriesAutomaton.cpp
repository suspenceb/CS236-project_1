//
// Created by suspe on 9/15/2022.
//

#include "QueriesAutomaton.h"
void QueriesAutomaton::S0(const std::string& input) {
    if (input.substr(index,7) == "Queries") {
        inputRead = 7;
    }
    else {
        Serr();
    }
}