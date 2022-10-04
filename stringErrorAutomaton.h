#ifndef INC_236PROJECT_1_STRINGERRORAUTOMATON_H
#define INC_236PROJECT_1_STRINGERRORAUTOMATON_H
#include "Automaton.h"
class stringErrorAutomaton : public Automaton
{
public:
    stringErrorAutomaton() : Automaton(TokenType::STRING_UND){}

    void S0(const std::string& input);
    void S1(const std::string& input);
    void S2(const std::string& input);
};


#endif //INC_236PROJECT_1_STRINGERRORAUTOMATON_H