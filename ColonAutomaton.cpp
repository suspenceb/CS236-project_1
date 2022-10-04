#include "ColonAutomaton.h"
#include <iostream>
using namespace std;
void ColonAutomaton::S0(const std::string& input) {
    if (input[index] == ':') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}
