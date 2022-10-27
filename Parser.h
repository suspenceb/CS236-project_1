//
// Created by suspe on 10/3/2022.
//

#ifndef INC_236PROJECT_1_PARSER_H
#define INC_236PROJECT_1_PARSER_H
#include "Token.h"
#include <vector>
#include "Predicate.h"
#include "Rule.h"
#include "DatalogProgram.h"
class Parser{

private:
    int tokenCounter = 0;
    std::vector<Token*> parserTokens;
    std::vector<Predicate*> schemesVector;
    std::vector<Predicate*> factVector;
    std::vector<Predicate*> queryVector;
    std::vector<Rule*> ruleVector;
    void match(TokenType typeToMatch);
     void parseDatalogProgram();
    void parseScheme();
    void parseIDlist();

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

    const vector<Predicate *> &getSchemesVector() const;

    const vector<Predicate *> &getFactVector() const;

    const vector<Predicate *> &getQueryVector() const;

    const vector<Rule *> &getRuleVector() const;

    vector<Parameter*> schemeParamVec;
    vector<Parameter*> factParamVec;
    vector<Parameter*> queryParamVec;
    vector<Parameter*> ruleHeadParamVec;
    vector<Parameter*> ruleBodyParamVec;
    vector<Predicate*> ruleBodyPredVec;
};


#endif //INC_236PROJECT_1_PARSER_H
