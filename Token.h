#ifndef TOKEN_H
#define TOKEN_H
#include <string>
using namespace std;
enum class TokenType {
    COLON,COLON_DASH,COMMA,PERIOD,Q_MARK,LEFT_PAREN,RIGHT_PAREN,MULTIPLY,ADD,SCHEMES,FACTS,RULES,QUERIES,EOF_ENUM,ID,STRING,COMMENT,BLOCK_COMMENT,BLOCK_COMMENT_UND,STRING_UND,
    // TODO: add the other types of tokens
    UNDEFINED
};

class Token
{
private:
    TokenType setType;
    string setDescrip;
    string setLine;
    // TODO: add member variables for information needed by Token

public:

    Token(TokenType type, std::string description, int line);
    string autoToString(TokenType);
    string tokenToString();

    TokenType getSetType() const;
    // TODO: add other needed methods
};

#endif // TOKEN_H

