#include "dfa.h"
#include<set>

#define TOTAL_STATES 61

vector <char> dollar;

vector <char> operator-(vector <char> v1, vector <char> v2)
{
    set <char> s;
    for(char x:v1) s.insert(x);
    for(char x:v2) s.erase(x);
    vector <char> r;
    for(char x:s)
    r.push_back(x);
    return r;
}

// # -> any digit from 0-9
// $ -> any alphabet

void initDFA(DFA* dfa){

    // initializing util vector used in transitions
    for(char v='a'; v<='z'; v++)
        dollar.push_back(v);
    for(char v='A'; v<='Z'; v++)
        dollar.push_back(v);

    // token-class list for final states of dfa
    vector<string> tokenClassList = {"add_op", "add_op", "mul_op", "mul_op", "mul_op", "comp_op", "o_cas", "comp_op", "comp_op",
                                     "i_cas", "comp_op", "equals", "comp_op", "comp_op", "open_first_bracket", "close_first_bracket",
                                     "open_second_bracket", "close_second_bracket", "relational_op", "input", "output", "d_type",
                                     "else_token", "if_token", "d_type", "MAIN", "then_token", "INTEGER", "INTEGER", "REAL", "CHARACTER", "ID", "semicolon", "d_type",
                                   "ID","ID","ID","ID","ID","ID","ID","ID","ID","ID","ID","ID","ID","ID","ID","ID","ID","ID","ID","ID","ID","ID"};

    // final state ids from dfa
    vector<int> finalStateIds = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 15, 16, 17, 18, 19,
                           22, 25, 28, 31, 35, 37, 39, 43, 47, 48, 49, 51, 54, 55, 60, 59, 20,
                           21, 23, 24, 26, 27, 29, 30, 32, 33, 34, 36, 38, 40, 41, 42, 44, 45, 46, 56, 57, 58};

    // non-final state ids from dfa - unused, but provided here for reference
    vector<int> nonFinalStateIds = {0, 14, 50, 52, 53 };

    // adding all the states to the dfa as non-final and null
    for(int i=0; i<TOTAL_STATES; i++){
        dfa->addNewStateToDFA(0, "null");
    }

    // setting final states and providing corresponding token class
    for(int i=0; i<finalStateIds.size(); i++){
        dfa->getStateById(finalStateIds[i])->setFinal();
        dfa->getStateById(finalStateIds[i])->setTokenClassForFinalState(tokenClassList[i]);
    }

    // manually adding all the transitions in dfa for 61 states
    dfa->addNextStateForAState(0, 1, '+');
    dfa->addNextStateForAState(0, 2, '-');
    dfa->addNextStateForAState(0, 3, '/');
    dfa->addNextStateForAState(0, 4, '*');
    dfa->addNextStateForAState(0, 5, '%');

    dfa->addNextStateForAState(0, 6, '<');
    dfa->addNextStateForAState(0, 9, '>');
    dfa->addNextStateForAState(0, 12, '=');
    dfa->addNextStateForAState(0, 14, '!');
    dfa->addNextStateForAState(0, 16, '(');
    dfa->addNextStateForAState(0, 17, ')');
    dfa->addNextStateForAState(0, 18, '{');
    dfa->addNextStateForAState(0, 19, '}');

    dfa->addNextStateForAState(0, 20, 'a');
    dfa->addNextStateForAState(0, 23, 'c');
    dfa->addNextStateForAState(0, 32, 'e');
    dfa->addNextStateForAState(0, 36, 'i');
    dfa->addNextStateForAState(0, 40, 'm');
    dfa->addNextStateForAState(0, 44, 't');
    dfa->addNextStateForAState(0, 48, '#');
    dfa->addNextStateForAState(0, 52, '\'');
    dfa->addNextStateForAState(0, 60, ';');
    dfa->addNextStateForAState(0, 56, 'r');
    dfa->addNextStateForAState(56, 57, 'e');
    dfa->addNextStateForAState(57, 58, 'a');
    dfa->addNextStateForAState(58, 59, 'l');


    dfa->addNextStateForAState(6, 7, '<');
    dfa->addNextStateForAState(6, 8, '=');
    dfa->addNextStateForAState(9, 10, '>');
    dfa->addNextStateForAState(9, 11, '=');
    dfa->addNextStateForAState(12, 13, '=');
    dfa->addNextStateForAState(14, 15, '=');
    dfa->addNextStateForAState(20, 21, 'n');
    dfa->addNextStateForAState(21, 22, 'd');
    dfa->addNextStateForAState(23, 24, 'i');

    dfa->addNextStateForAState(24, 25, 'n');
    dfa->addNextStateForAState(23, 26, 'o');
    dfa->addNextStateForAState(26, 27, 'u');
    dfa->addNextStateForAState(27, 28, 't');
    dfa->addNextStateForAState(23, 29, 'h');
    dfa->addNextStateForAState(29, 30, 'a');
    dfa->addNextStateForAState(30, 31, 'r');
    dfa->addNextStateForAState(32, 33, 'l');

    dfa->addNextStateForAState(33, 34, 's');
    dfa->addNextStateForAState(34, 35, 'e');
    dfa->addNextStateForAState(36, 37, 'f');
    dfa->addNextStateForAState(36, 38, 'n');
    dfa->addNextStateForAState(38, 39, 't');
    dfa->addNextStateForAState(44, 45, 'h');
    dfa->addNextStateForAState(45, 46, 'e');
    dfa->addNextStateForAState(46, 47, 'n');
    dfa->addNextStateForAState(40, 41, 'a');
    dfa->addNextStateForAState(41, 42, 'i');
    dfa->addNextStateForAState(42, 43, 'n');

    dfa->addNextStateForAState(48, 49, '#');
    dfa->addNextStateForAState(49, 49, '#');
    dfa->addNextStateForAState(48, 50, '.');
    dfa->addNextStateForAState(49, 50, '.');
    dfa->addNextStateForAState(50, 51, '#');
    dfa->addNextStateForAState(51, 51, '#');
    dfa->addNextStateForAState(52, 53, dollar);
    dfa->addNextStateForAState(53, 54, '\'');
    dfa->addNextStateForAState(55, 55, dollar);
    
    
    dfa->addNextStateForAState(0, 55, dollar- vector <char> ({'a','c','e', 'i','m','t','r'}));
    dfa->addNextStateForAState(59, 55, dollar);
    dfa->addNextStateForAState(43, 55, dollar);
    dfa->addNextStateForAState(22, 55, dollar);
    dfa->addNextStateForAState(25, 55, dollar);
    dfa->addNextStateForAState(28, 55, dollar);
    dfa->addNextStateForAState(31, 55, dollar);
    dfa->addNextStateForAState(35, 55, dollar);
    dfa->addNextStateForAState(37, 55, dollar);
    dfa->addNextStateForAState(39, 55, dollar);
    dfa->addNextStateForAState(47, 55, dollar);
    dfa->addNextStateForAState(56, 55, dollar - vector <char> ({'e'}));
    dfa->addNextStateForAState(57, 55, dollar - vector <char> ({'a'}));
    dfa->addNextStateForAState(58, 55, dollar - vector <char> ({'l'}));

    dfa->addNextStateForAState(40, 55, dollar - vector <char> ({'a'}));
    dfa->addNextStateForAState(41, 55, dollar - vector <char> ({'i'}));
    dfa->addNextStateForAState(42, 55, dollar - vector <char> ({'n'}));
    dfa->addNextStateForAState(20, 55, dollar - vector <char> ({'n'}));
    dfa->addNextStateForAState(21, 55, dollar - vector <char> ({'d'}));
    dfa->addNextStateForAState(23, 55, dollar - vector <char> ({'i','o','h'}));
    dfa->addNextStateForAState(24, 55, dollar - vector <char> ({'n'}));
    dfa->addNextStateForAState(26, 55, dollar - vector <char> ({'u'}));
    dfa->addNextStateForAState(27, 55, dollar - vector <char> ({'t'}));
    dfa->addNextStateForAState(29, 55, dollar - vector <char> ({'a'}));
    dfa->addNextStateForAState(30, 55, dollar - vector <char> ({'r'}));
    dfa->addNextStateForAState(32, 55, dollar - vector <char> ({'l'}));
    dfa->addNextStateForAState(33, 55, dollar - vector <char> ({'s'}));
    dfa->addNextStateForAState(34, 55, dollar - vector <char> ({'e'}));
    dfa->addNextStateForAState(36, 55, dollar - vector <char> ({'f','n'}));
    dfa->addNextStateForAState(38, 55, dollar - vector <char> ({'t'}));
    dfa->addNextStateForAState(44, 55, dollar - vector <char> ({'h'}));
    dfa->addNextStateForAState(45, 55, dollar - vector <char> ({'e'}));
    dfa->addNextStateForAState(46, 55, dollar - vector <char> ({'n'}));

}
