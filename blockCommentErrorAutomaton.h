//
// Created by suspe on 9/19/2022.
//

#ifndef INC_236PROJECT_1_BLOCKCOMMENTERRORAUTOMATON_H
#define INC_236PROJECT_1_BLOCKCOMMENTERRORAUTOMATON_H


#include "Automaton.h"
class blockCommentErrorAutomaton : public Automaton
{
public:
    blockCommentErrorAutomaton() : Automaton(TokenType::BLOCK_COMMENT_UND) {}  // Call the base constructor

    void S0(const std::string& input);
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);
};


#endif //INC_236PROJECT_1_BLOCKCOMMENTERRORAUTOMATON_H
