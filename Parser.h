//
// Created by suspe on 10/3/2022.
//

#ifndef INC_236PROJECT_1_PARSER_H
#define INC_236PROJECT_1_PARSER_H
#include "Token.h"
#include <vector>
#include "Predicate.h"

class Parser{
private:
    int tokenCounter = 0;
    std::vector<Token*> parserTokens;
    std::vector<Predicate*> schemesVector;
    void match(TokenType typeToMatch);
    void parseDatalogProgram();
    void parseScheme();
    void parseIDlist(Parameter *pParameter, vector<struct Parameter *> vector);
    void parseSchemeList();
    void parseFactList();
    void parseFact();
    void parseStringList();
    void parseRulesList();
    void parseRules();
    void parseHeadPred();
    void parsePred();
    void parsePredList();
    void parseParameter();
    void parseParameterList();
    void parseQuery();
    void parseQueryList();

public:
    Parser();
    explicit Parser(vector<Token*> tokens);
    ~Parser();

};


#endif //INC_236PROJECT_1_PARSER_H
