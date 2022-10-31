#include "Lexer.h"
#include "Parser.h"
#include "Interpreter.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {

    auto* lexer = new Lexer();


    if (argc != 2) {
        cout << "usage: " << argv[0] << " input_file" << endl;
        return 1;
    }

    // open file
    string fileName = argv[1];
    ifstream input(fileName);
    if (!input.is_open()) {
        cout << "File " << fileName << " could not be found or opened." << endl;
        return 1;
    }

    string fileboi = string((istreambuf_iterator<char>(input)), std::istreambuf_iterator<char>());
    string test1 = "Schemes:\n"
                   "  snap(S,N,A,P)\n"
                   "  HasSameAddress(X,Y)\n"
                   "\n"
                   "Facts:\n"
                   "  snap('12345','C. Brown','12 Apple','555-1234').\n"
                   "  snap('33333','Snoopy','12 Apple','555-1234').\n"
                   "\n"
                   "Rules:\n"
                   "  HasSameAddress(X,Y) :- snap(A,X,B,C),snap(D,Y,B,E).\n"
                   "\n"
                   "Queries:\n"
                   "  HasSameAddress('Snoopy',Who)?";
    lexer->Run(test1);
    auto* parser = new Parser(lexer->getTokens());


    auto* interpret = new Interpreter(parser->getSchemesVector(),parser->getFactVector(), parser->getQueryVector(), parser->getRuleVector());
    delete lexer;
    delete parser;
    delete interpret;
    return 0;
}