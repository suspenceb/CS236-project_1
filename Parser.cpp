//
// Created by suspe on 10/3/2022.
//

#include "Parser.h"
#include "Parameter.h"
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
        //cout << "yay" << endl;
        tokenCounter++;
    }
    else throw parserTokens[tokenCounter];
}

void Parser::parseDatalogProgram() {
    try {
        //datalogProgram->SCHEMES COLON scheme schemeList FACTS COLON factList RULES COLON ruleList QUERIES COLON query queryList EOF
        match(TokenType::SCHEMES);
        match(TokenType::COLON);
        parseScheme();
        parseSchemeList();
        match(TokenType::FACTS);
        match(TokenType::COLON);
        parseFactList();
        match(TokenType::RULES);
        match(TokenType::COLON);
        parseRulesList();
        match(TokenType::QUERIES);
        match(TokenType::COLON);
        parseQuery();
        parseQueryList();
        match(TokenType::EOF_ENUM);
        cout << "Success!" << endl;
    }
    catch (Token* caughtToken) {
        cout << "Failure!\n  " << caughtToken->tokenToString() << endl;
    }
    catch(string input){
        cout << input << endl;
    }
}

void Parser::parseScheme() {
//scheme   	-> 	ID LEFT_PAREN ID idList RIGHT_PAREN

    auto* schemePred = new Predicate;
    auto* schemeParam = new Parameter;
    vector<Parameter*> schemeParamVec;

    match(TokenType::ID);
    //cout << parserTokens[tokenCounter - 1]->getTokenDescrip() << endl;
    schemePred->setId(parserTokens[tokenCounter - 1]->getTokenDescrip());//just the name

    match(TokenType::LEFT_PAREN);
    match(TokenType::ID);
    schemeParam->setP(parserTokens[tokenCounter - 1]->getTokenDescrip());
    schemeParamVec.push_back(schemeParam);

    parseIDlist(schemeParam, schemeParamVec);
    match(TokenType::RIGHT_PAREN);

    schemePred->parameters = schemeParamVec;
    schemesVector.push_back(schemePred);
    cout << schemesVector[0]->parameters[0]->getP();
}

void Parser::parseIDlist(Parameter* schemeParam, vector<Parameter *> schemeParamVec) {
    //idList->COMMA ID idList | lambda

    if(parserTokens[tokenCounter]->getSetType() == TokenType::COMMA) {
        match(TokenType::COMMA);
        match(TokenType::ID);

        schemeParam->setP(parserTokens[tokenCounter - 1]->getTokenDescrip());
cout<<'a';
        schemeParamVec.push_back(schemeParam);

        parseIDlist(schemeParam, schemeParamVec);
    }
    else if (parserTokens[tokenCounter]->getSetType() == TokenType::RIGHT_PAREN) {} //intentionally blank
    else throw (parserTokens[tokenCounter]);
}

void Parser::parseSchemeList() {
//schemeList	->	scheme schemeList | lambda

    if(parserTokens[tokenCounter]->getSetType() == TokenType::ID){
        parseScheme();
        parseSchemeList();

    }
    else if (parserTokens[tokenCounter]->getSetType() == TokenType::FACTS){}//intentionally blank
    else throw(parserTokens[tokenCounter]);
}

void Parser::parseFactList() {
//factList	->	fact factList | lambda
    if(parserTokens[tokenCounter]->getSetType() == TokenType::ID){
        parseFact();
        parseFactList();
    }else if(parserTokens[tokenCounter]->getSetType() == TokenType::RULES){}//intentionally blank
    else throw(parserTokens[tokenCounter]);
}

void Parser::parseFact() {
    //fact    	->	ID LEFT_PAREN STRING stringList RIGHT_PAREN PERIOD
    match(TokenType::ID);
    match(TokenType::LEFT_PAREN);
    match(TokenType::STRING);
    parseStringList();
    match(TokenType::RIGHT_PAREN);
    match(TokenType::PERIOD);
}

void Parser::parseStringList() {
    //fact    	->	ID LEFT_PAREN STRING stringList RIGHT_PAREN PERIOD
    if(parserTokens[tokenCounter]->getSetType() == TokenType::COMMA){
        match(TokenType::COMMA);
        match(TokenType::STRING);
        parseStringList();
    }else if(parserTokens[tokenCounter]->getSetType() == TokenType::RIGHT_PAREN){}//Intentionally blank
    else throw(parserTokens[tokenCounter]);
}

void Parser::parseRulesList() {
    //ruleList	->	rule ruleList | lambda
    if(parserTokens[tokenCounter]->getSetType() == TokenType::ID){
        parseRules();
        parseRulesList();
    }else if (parserTokens[tokenCounter]->getSetType() == TokenType::QUERIES){}//intentionally blank
    else throw(parserTokens[tokenCounter]);
}

void Parser::parseRules() {
    //rule    	->	headPredicate COLON_DASH predicate predicateList PERIOD
    parseHeadPred();
    match(TokenType::COLON_DASH);
    parsePred();
    parsePredList();
    match(TokenType::PERIOD);
}

void Parser::parseHeadPred() {
//headPredicate	->	ID LEFT_PAREN ID idList RIGHT_PAREN
    match(TokenType::ID);
    match(TokenType::LEFT_PAREN);
    match(TokenType::ID);
    parseIDlist(nullptr, vector<struct Parameter *>());
    match(TokenType::RIGHT_PAREN);
}

void Parser::parsePred() {
    //predicate	->	ID LEFT_PAREN parameter parameterList RIGHT_PAREN
    match(TokenType::ID);
    match(TokenType::LEFT_PAREN);
    parseParameter();
    parseParameterList();
    match(TokenType::RIGHT_PAREN);
}

void Parser::parsePredList() {
    //predicateList	->	COMMA predicate predicateList | lambda
    if(parserTokens[tokenCounter]->getSetType() == TokenType::COMMA){
        match(TokenType::COMMA);
        parsePred();
        parsePredList();
    }else if(parserTokens[tokenCounter]->getSetType() == TokenType::PERIOD){}//intentionally blank
    else throw(parserTokens[tokenCounter]);
}

void Parser::parseParameter() {
    //parameter	->	STRING | ID
    if(parserTokens[tokenCounter]->getSetType() == TokenType::STRING){
        match(TokenType::STRING);
    }else if (parserTokens[tokenCounter]->getSetType() == TokenType::ID){
        match(TokenType::ID);
    }else throw(parserTokens[tokenCounter]);
}

void Parser::parseParameterList() {
    //parameterList	-> 	COMMA parameter parameterList | lambda
    if(parserTokens[tokenCounter]->getSetType() == TokenType::COMMA){
        match(TokenType::COMMA);
        parseParameter();
        parseParameterList();
    }else if(parserTokens[tokenCounter]->getSetType() == TokenType::RIGHT_PAREN){}//intentionally blank
    else throw(parserTokens[tokenCounter]);
}

void Parser::parseQuery() {
    //query	        ->      predicate Q_MARK
    parsePred();
    match(TokenType::Q_MARK);
}

void Parser::parseQueryList() {
    //queryList	->	query queryList | lambda
    if(parserTokens[tokenCounter]->getSetType() == TokenType::ID){
        parseQuery();
        parseQueryList();
    }else if(parserTokens[tokenCounter]->getSetType() == TokenType::EOF_ENUM){}//intentionally blank
    else throw(parserTokens[tokenCounter]);
}
