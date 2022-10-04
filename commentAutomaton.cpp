//
// Created by suspe on 9/16/2022.
//

#include "commentAutomaton.h"
void commentAutomaton::S0(const std::string& input) {
    if (input[index] == '#' && input[index+1] != '|') {
        inputRead = 1;
        index++;
        while(input[index] != '\n' && input[index] != EOF){
            inputRead++;
            index++;
        }
    }
    else {
        Serr();
    }
}