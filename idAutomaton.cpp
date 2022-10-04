//
// Created by suspe on 9/16/2022.
//

#include "idAutomaton.h"
void idAutomaton::S0(const std::string& input) {
    inputRead = 0;
    if (isalpha(input[index])) {
        inputRead++;
        index++;
        while(isalnum(input[index])){
            inputRead++;
            index++;
        }
    }
    else {
        Serr();
    }
}