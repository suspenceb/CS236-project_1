#include "Lexer.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "CommaAutomaton.h"
#include "PeriodAutomaton.h"
#include "Q_MarkAutomaton.h"
#include "LeftParenAutomaton.h"
#include "RightParenAutomaton.h"
#include "MultiplyAutomaton.h"
#include "AddAutomaton.h"
#include "SchemesAutomaton.h"
#include "FactsAutomaton.h"
#include "RulesAutomaton.h"
#include "QueriesAutomaton.h"
#include "UndefinedAutomaton.h"
#include "eofAutomaton.h"
#include "idAutomaton.h"
#include "commentAutomaton.h"
#include "blockCommentErrorAutomaton.h"

#include "stringAutomaton.h"
#include "stringErrorAutomaton.h"
#include "blockCommentAutomaton.h"
#include <iostream>
using namespace std;
Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    // TODO: need to clean up the memory in `automata` and `tokens`
}

void Lexer::CreateAutomata() {
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new CommaAutomaton());
    automata.push_back(new PeriodAutomaton());
    automata.push_back(new Q_MarkAutomaton());
    automata.push_back(new LeftParenAutomaton());
    automata.push_back(new RightParenAutomaton());
    automata.push_back(new MultiplyAutomaton());
    automata.push_back(new AddAutomaton());
    automata.push_back(new SchemesAutomaton);
    automata.push_back(new FactsAutomaton());
    automata.push_back(new RulesAutomaton());
    automata.push_back(new QueriesAutomaton());
    automata.push_back(new idAutomaton());
    automata.push_back(new commentAutomaton());
    automata.push_back(new blockCommentAutomaton());
    automata.push_back(new stringAutomaton());
    automata.push_back(new UndefinedAutomaton());
    automata.push_back(new blockCommentErrorAutomaton());
    automata.push_back(new stringErrorAutomaton());

    // TODO: Add the other needed automata here
}

void Lexer::Run(std::string& input) {
    lineNumber = 1;
    while (!input.empty()) {
        maxRead = 0;
        maxAuT = automata[0];
        //clearing space
        while (input[0] == ' ' || input[0] == '\t' || input[0] == '\n') {
            if (input[0] == ' ') input.erase(0, 1);
            if (input[0] == '\t') input.erase(0, 1);
            if (input[0] == '\n') {
                input.erase(0, 1);
                lineNumber++;
            }
        }
        //Parelel
        for (Automaton *AuT: automata) {
            inputread = AuT->Start(input);
            if (inputread > maxRead) {
                maxRead = inputread;
                maxAuT = AuT;
            }
        }
        /*// Here is the "Parallel" part of the algorithm
            //   Each automaton runs with the same input
            foreach automaton in automata {
                inputRead = automaton.Start(input)
                if (inputRead > maxRead) {
                    set maxRead to inputRead
                    set maxAutomaton to automaton
                }
            }*/
        //Max
        if (!input.empty()) {
            if (maxRead > 0) {

                string sentInput = input.substr(0, maxRead);
                Token* newToken = maxAuT->CreateToken(sentInput, lineNumber);
                //
                // not adding any comment tokens for project 2!!!
                //
                if(newToken->getSetType() != TokenType::COMMENT)tokens.push_back(newToken);
                lineNumber += maxAuT->NewLinesRead();
               }
            input.erase(0, maxRead);
        }
    }
    //add end of file token to all tokens
    maxAuT = new eofAutomaton();
    Token* newToken = maxAuT->CreateToken(input,lineNumber);

    tokens.push_back(newToken);
    /*int i = 0;
    for(Token* tokes:tokens) {
        //cout << tokes->tokenToString();
        i++;
    }
    //cout << "Total Tokens = " << i;*/
}

const vector<Token *> &Lexer::getTokens() const {
    return tokens;
}
