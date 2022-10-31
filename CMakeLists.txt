cmake_minimum_required(VERSION 3.21)
project(236project_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(236project_1
        Automaton.h
        ColonAutomaton.cpp
        ColonAutomaton.h
        ColonDashAutomaton.cpp
        ColonDashAutomaton.h
        Lexer.cpp
        Lexer.h
        main.cpp
        Token.cpp
        Token.h CommaAutomaton.cpp CommaAutomaton.h PeriodAutomaton.cpp PeriodAutomaton.h Q_MarkAutomaton.cpp Q_MarkAutomaton.h LeftParenAutomaton.cpp LeftParenAutomaton.h RightParenAutomaton.cpp RightParenAutomaton.h MultiplyAutomaton.cpp MultiplyAutomaton.h AddAutomaton.cpp AddAutomaton.h SchemesAutomaton.cpp SchemesAutomaton.h FactsAutomaton.cpp FactsAutomaton.h RulesAutomaton.cpp RulesAutomaton.h QueriesAutomaton.cpp QueriesAutomaton.h UndefinedAutomaton.cpp UndefinedAutomaton.h eofAutomaton.cpp eofAutomaton.h idAutomaton.cpp idAutomaton.h commentAutomaton.cpp commentAutomaton.h blockCommentAutomaton.cpp blockCommentAutomaton.h blockCommentErrorAutomaton.cpp blockCommentErrorAutomaton.h stringAutomaton.cpp stringAutomaton.h stringErrorAutomaton.cpp stringErrorAutomaton.h Parser.cpp Parser.h DatalogProgram.cpp DatalogProgram.h Predicate.cpp Predicate.h Rule.cpp Rule.h Parameter.cpp Parameter.h Tuple.cpp Tuple.h Header.cpp Header.h Relation.cpp Relation.h Database.cpp Database.h Interpreter.cpp Interpreter.h)
