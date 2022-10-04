#include "CommaAutomaton.h"
#include <iostream>
using namespace std;
void CommaAutomaton::S0(const std::string& input) {
    if (input[index] == ',') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}
