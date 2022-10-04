//
// Created by suspe on 9/19/2022.
//
#include "stringErrorAutomaton.h"

void stringErrorAutomaton::S0(const string &input) {
    if(input[index] == '\''){
        inputRead++;
        index++;
        S1(input);
    }
    else Serr();
}

void stringErrorAutomaton::S1(const string &input) {
    if(input[index] == '\''){
        inputRead++;
        index++;
        S2(input);
    }
    else if(int(input.size()) == index){
    }
    else{
        if(input[index] == '\n') newLines++;
        index++;
        inputRead++;
        S1(input);
    }
}

void stringErrorAutomaton::S2(const string &input) {
    if (input[index] == '\'') {
        index++;
        inputRead++;
        S1(input);
    } else if (input[index] != '\'') {
        Serr();
    }
}