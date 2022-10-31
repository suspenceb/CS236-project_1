//
// Created by suspe on 10/3/2022.
//

#include "Parser.h"
#include "Parameter.h"
#include "Rule.h"
#include <iostream>
#include <utility>
#include "vector"
#include "DatalogProgram.h"

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
        //cout << "Success!" << endl;
        auto * databoi = new DatalogProgram(schemesVector,factVector,queryVector,ruleVector);
        //cout << databoi->toString();
    }
    catch (Token* caughtToken) {
        cout << "Failure!\n  " << caughtToken->tokenToString();
    }
    catch(string input){
        cout << input << endl;
    }
}

void Parser::parseScheme() {
//scheme   	-> 	ID LEFT_PAREN ID idList RIGHT_PAREN
    auto* schemeParam = new Parameter;
    auto* schemePred = new Predicate;
    schemeParamVec.clear();
    match(TokenType::ID);
    //cout << parserTokens[tokenCounter - 1]->getTokenDescrip() << endl;
    schemePred->setId(parserTokens[tokenCounter - 1]->getTokenDescrip());//just the name
    //cout << schemePred->getId() <<endl;
    match(TokenType::LEFT_PAREN);
    match(TokenType::ID);
    schemeParam->setP(parserTokens[tokenCounter - 1]->getTokenDescrip());
    schemeParamVec.push_back(schemeParam);
    //cout << schemeParamVec.at(0)->getP() << endl;

    parseIDlist();
    match(TokenType::RIGHT_PAREN);

    schemePred->parameters = schemeParamVec;
    schemesVector.push_back(schemePred);
    //cout << schemesVector[schemesVector.size()-1]->parameters[0]->getP();
}

void Parser::parseIDlist() {
    //idList->COMMA ID idList | lambda
    auto* idParam = new Parameter;
    if(parserTokens[tokenCounter]->getSetType() == TokenType::COMMA) {
        match(TokenType::COMMA);
        match(TokenType::ID);

        idParam->setP(parserTokens[tokenCounter - 1]->getTokenDescrip());
        schemeParamVec.push_back(idParam);
        ruleHeadParamVec.push_back(idParam);
        parseIDlist();
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
    auto* factParam = new Parameter;
    auto* factPred = new Predicate;
    factParamVec.clear();
    //fact    	->	ID LEFT_PAREN STRING stringList RIGHT_PAREN PERIOD
    match(TokenType::ID);
    factPred->setId(parserTokens[tokenCounter - 1]->getTokenDescrip());
    match(TokenType::LEFT_PAREN);
    match(TokenType::STRING);
    factParam->setP(parserTokens[tokenCounter - 1]->getTokenDescrip());
    factParamVec.push_back(factParam);
    parseStringList();
    match(TokenType::RIGHT_PAREN);
    match(TokenType::PERIOD);

    factPred->parameters = factParamVec;
    factVector.push_back(factPred);
    //cout << factVector[factVector.size()-1]->parameters[0]->getP();
}

void Parser::parseStringList() {
    auto* stringParam = new Parameter;
    //fact    	->	ID LEFT_PAREN STRING stringList RIGHT_PAREN PERIOD
    if(parserTokens[tokenCounter]->getSetType() == TokenType::COMMA){
        match(TokenType::COMMA);
        match(TokenType::STRING);
        stringParam->setP(parserTokens[tokenCounter - 1]->getTokenDescrip());
        factParamVec.push_back(stringParam);
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
    auto* ruler = new Rule;
    auto* ruleHeadPred = new Predicate;
    ruleHeadParamVec.clear();
    ruleBodyParamVec.clear();
    ruleBodyPredVec.clear();
    ruleHeadPred->setId(parserTokens[tokenCounter]->getTokenDescrip());
    ruler->headPredicate = ruleHeadPred;
    parseHeadPred();
    ruler->headPredicate->parameters = ruleHeadParamVec;
    match(TokenType::COLON_DASH);
    ruleBodyParamVec.clear();
    parsePred();
    parsePredList();
    ruler->bodyPredicates = ruleBodyPredVec;
    ruleVector.push_back(ruler);
    match(TokenType::PERIOD);
}

void Parser::parseHeadPred() {
    auto* ruleHeadParam = new Parameter;
//headPredicate	->	ID LEFT_PAREN ID idList RIGHT_PAREN
    match(TokenType::ID);
    match(TokenType::LEFT_PAREN);
    ruleHeadParam->setP(parserTokens[tokenCounter]->getTokenDescrip());
    ruleHeadParamVec.push_back(ruleHeadParam);
    match(TokenType::ID);

    parseIDlist();
    match(TokenType::RIGHT_PAREN);
}

void Parser::parsePred() {
    //predicate	->	ID LEFT_PAREN parameter parameterList RIGHT_PAREN
    auto* ruleBodyPred = new Predicate;
    auto* predParam = new Parameter;
    ruleBodyPred->setId(parserTokens[tokenCounter]->getTokenDescrip());
    match(TokenType::ID);
    match(TokenType::LEFT_PAREN);
    parseParameter();
    predParam->setP(parserTokens[tokenCounter-1]->getTokenDescrip());
    //queryParamVec.push_back(predParam);


    parseParameterList();
    ruleBodyPred->parameters = ruleBodyParamVec;
    ruleBodyPredVec.push_back(ruleBodyPred);
    ruleBodyParamVec.clear();
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
    auto* Param = new Parameter;
    if(parserTokens[tokenCounter]->getSetType() == TokenType::STRING){
        Param->setP(parserTokens[tokenCounter]->getTokenDescrip());
        queryParamVec.push_back(Param);
        ruleBodyParamVec.push_back(Param);
        match(TokenType::STRING);
    }else if (parserTokens[tokenCounter]->getSetType() == TokenType::ID){
        Param->setP(parserTokens[tokenCounter]->getTokenDescrip());
        queryParamVec.push_back(Param);
        ruleBodyParamVec.push_back(Param);
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

    auto* queryPred = new Predicate;
    queryParamVec.clear();
    if(parserTokens[tokenCounter]->getSetType() == TokenType::ID) {
        queryPred->setId(parserTokens[tokenCounter]->getTokenDescrip());
    }
    parsePred();
    match(TokenType::Q_MARK);
    queryPred->parameters = queryParamVec;
    queryVector.push_back(queryPred);
    //cout << queryVector[queryVector.size()-1]->parameters[0]->getP()<<endl;
}

void Parser::parseQueryList() {
    //queryList	->	query queryList | lambda
    if(parserTokens[tokenCounter]->getSetType() == TokenType::ID){
        parseQuery();
        parseQueryList();
    }else if(parserTokens[tokenCounter]->getSetType() == TokenType::EOF_ENUM){}//intentionally blank
    else throw(parserTokens[tokenCounter]);
}

const vector<Predicate *> &Parser::getSchemesVector() const {
    return schemesVector;
}

const vector<Predicate *> &Parser::getFactVector() const {
    return factVector;
}

const vector<Predicate *> &Parser::getQueryVector() const {
    return queryVector;
}

const vector<Rule *> &Parser::getRuleVector() const {
    return ruleVector;
}
