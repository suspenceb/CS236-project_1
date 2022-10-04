//
// Created by suspe on 9/16/2022.
//

#include "blockCommentAutomaton.h"
void blockCommentAutomaton::S0(const std::string& input) {
    inputRead = 0;
    if (input[index] == '#'){
        index++;
        inputRead++;
        S1(input);
    }
    else {
        Serr();
    }
}

void blockCommentAutomaton::S1(const string &input) {
    if (input[index] == '|'){
        index++;
        inputRead++;
        S2(input);
    }
    else{
        Serr();
    }
}

void blockCommentAutomaton::S2(const string &input) {
    if(int(input.size()) == index) Serr();
    else if(input[index] != '|'){
        if(input[index] == '\n'){
            newLines++;
        }
        index++;
        inputRead++;
        S2(input);
    }
    else if(input[index] == '|'){
        index++;
        inputRead++;
        S3(input);
    }
    else Serr();
}

void blockCommentAutomaton::S3(const string &input) {
    if(int(input.size()) == index) Serr();
    else if(input[index] == '#'){
        index++;
        inputRead++;
    }
    else if(input[index] == '|'){
        index++;
        inputRead++;
        S3(input);
    }
    else if(input[index] != '|'){
        if(input[index] == '\n'){
            newLines++;
        }
        index++;
        inputRead++;
        S2(input);
    }
    else Serr();
}