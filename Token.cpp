#include "Token.h"

using namespace std;

Token::Token(TokenType type, string description, int line) {
    setType = type;
    tokenDescrip = description;
    setLine = to_string(line);
}

string Token::autoToString(TokenType type) {
    switch(type){
        case TokenType::COLON: return "COLON";
        case TokenType::COLON_DASH: return "COLON_DASH";
        case TokenType::COMMA: return "COMMA";
        case TokenType::PERIOD: return "PERIOD";
        case TokenType::Q_MARK: return "Q_MARK";
        case TokenType::LEFT_PAREN: return "LEFT_PAREN";
        case TokenType::RIGHT_PAREN: return "RIGHT_PAREN";
        case TokenType::MULTIPLY: return "MULTIPLY";
        case TokenType::ADD: return "ADD";
        case TokenType::SCHEMES: return "SCHEMES";
        case TokenType::FACTS: return "FACTS";
        case TokenType::RULES: return "RULES";
        case TokenType::QUERIES: return "QUERIES";
        case TokenType::UNDEFINED: return "UNDEFINED";
        case TokenType::EOF_ENUM: return "EOF";
        case TokenType::ID: return "ID";
        case TokenType::STRING: return "STRING";
        case TokenType::COMMENT: return "COMMENT";
        case TokenType::BLOCK_COMMENT: return "COMMENT";
        case TokenType::BLOCK_COMMENT_UND: return "UNDEFINED";
        case TokenType::STRING_UND: return "UNDEFINED";
    }
    return "ERROR";
}

string Token::tokenToString() {
    return std::string("(" + autoToString(this->setType) + ",\"" + this->tokenDescrip + "\"," + this->setLine + ")\n");
}

TokenType Token::getSetType() const {
    return setType;
}

const string &Token::getTokenDescrip() const {
    return tokenDescrip;
}
