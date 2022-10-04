//
// Created by suspe on 9/19/2022.
//

#include "stringAutomaton.h"

void stringAutomaton::S0(const string &input) {
    inputRead = 0;
    index = 0;
    if(input[index] == '\''){
        inputRead++;
        index++;
        S1(input);
    }
    else Serr();
}

void stringAutomaton::S1(const string &input) {
    if (index == int(input.size())) Serr();
    else if(input[index] == '\''){
        inputRead++;
        index++;
        S2(input);
    }
    else if(input[index] != '\''){
        if(input[index] == '\n') newLines++;
        index++;
        inputRead++;
        S1(input);
    }
    else Serr();
}

void stringAutomaton::S2(const string &input) {
    if (input[index] == '\''){
        index++;
        inputRead++;
        S1(input);
    }
}
