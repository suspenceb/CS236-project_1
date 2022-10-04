//
// Created by suspe on 10/3/2022.
//

#include "Parser.h"
#include <iostream>
#include <utility>
#include "vector"

using namespace std;
Parser::Parser(vector<Token *> inputTokens) {
    parserTokens = std::move(inputTokens);
    parseDatalogProgram();
}

Parser::Parser() {

}

Parser::~Parser() {
}

void Parser::match(TokenType typeToMatch) {
    if(parserTokens[tokenCounter]->getSetType() == typeToMatch){
        cout << "yay" << endl;
        tokenCounter++;
    }
    else cout << "no :(" << endl;
}

void Parser::parseDatalogProgram() {
    //datalogProgram->SCHEMES COLON scheme schemeList FACTS COLON factList RULES COLON ruleList QUERIES COLON query queryList EOF

    match(TokenType::SCHEMES);
    match(TokenType::COLON);
}
