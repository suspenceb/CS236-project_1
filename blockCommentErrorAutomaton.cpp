//
// Created by suspe on 9/16/2022.
//

#include "blockCommentErrorAutomaton.h"
void blockCommentErrorAutomaton::S0(const std::string& input) {
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

void blockCommentErrorAutomaton::S1(const string &input) {
    if (input[index] == '|'){
        index++;
        inputRead++;
        S2(input);
    }
    else{
        Serr();
    }
}

void blockCommentErrorAutomaton::S2(const string &input) {
    if(int(input.size()) == index){
        //yay
    }
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

void blockCommentErrorAutomaton::S3(const string &input) {
    if(int(input.size()) == index){
        //yay
    }
    else if(input[index] == '#'){
        Serr();
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
    //else Serr();
}