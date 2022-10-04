//
// Created by suspe on 10/3/2022.
//

#ifndef INC_236PROJECT_1_PARSER_H
#define INC_236PROJECT_1_PARSER_H
#include "Token.h"
#include <vector>

class Parser{
private:
    int tokenCounter = 0;
    std::vector<Token*> parserTokens;
    void match(TokenType typeToMatch);
    void parseDatalogProgram();
public:
    Parser();
    Parser(vector<Token*> tokens);
    ~Parser();

};


#endif //INC_236PROJECT_1_PARSER_H
