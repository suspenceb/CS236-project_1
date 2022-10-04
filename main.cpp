#include "Lexer.h"
#include "Parser.h"
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
    string test1 = "Schemes:";
    lexer->Run(test1);
    auto* parser = new Parser(lexer->getTokens());
    delete lexer;
    delete parser;
    return 0;
}