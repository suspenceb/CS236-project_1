//
// Created by suspe on 9/16/2022.
//

#ifndef INC_236PROJECT_1_BLOCKCOMMENTAUTOMATON_H
#define INC_236PROJECT_1_BLOCKCOMMENTAUTOMATON_H

#include "Automaton.h"
class blockCommentAutomaton : public Automaton
{
public:
    blockCommentAutomaton() : Automaton(TokenType::BLOCK_COMMENT) {}  // Call the base constructor

    void S0(const std::string& input);
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);
};



#endif //INC_236PROJECT_1_BLOCKCOMMENTAUTOMATON_H
