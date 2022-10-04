#include "Lexer.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {

    Lexer* lexer = new Lexer();

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
    string test1 = "#|";
    lexer->Run(fileboi);
    delete lexer;

    return 0;
}