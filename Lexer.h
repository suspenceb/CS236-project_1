#ifndef LEXER_H
#define LEXER_H
#include <vector>
#include "Automaton.h"
#include "Token.h"


class Lexer
{
private:
    std::vector<Automaton*> automata;
    std::vector<Token*> tokens;
    int lineNumber;
    int maxRead;
    int inputread;
    Automaton* maxAuT;

    void CreateAutomata();

public:
    Lexer();
    ~Lexer();

    const vector<Token *> &getTokens() const;

    void Run(std::string& input);


};

#endif // LEXER_H

