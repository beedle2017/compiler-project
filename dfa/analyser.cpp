#include "dfa_initiator.h"
#include<fstream>
#include "../utils.h"

// main(){
//      int a=5;
//      cout<<a;
// }

void parseInputLine(DFA* dfa, Tokens* tokens_object, string inputLine, int lineNumber){
    string currentLexemme = "";
}

int main(){
    string filename = "";
    cout<<"Enter File Name: ";
    cin>>filename;
    ifstream file(filename);

    string inputLine = "";
    int lineNumber = 1;
    Tokens tokens_object = Tokens();

    DFA* dfa = new DFA();
    initDFA(dfa);
    vector<State> list = dfa->getStateList();
    for(auto item:list){
        cout<<item<<endl;
    }

    while(getline(file, inputLine)){
        parseInputLine(dfa, &tokens_object, inputLine, lineNumber);
        lineNumber++;
    }
    
    // tokens_object.displayTokensList();
    // vector<pair<pair<string, string>, int>> tokensDictionary = tokens_object.getTokenDictionary();
    // writeOutputToFile(tokensDictionary);
}