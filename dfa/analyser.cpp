#include "dfa_initiator.h"
#include<fstream>
#include "../utils.h"

// main(){
//      int a=5;
//      cout<<a;
// }

template <typename T>
bool contains(vector<T> vec, const T & elem)
{
    bool result = false;
    if( find(vec.begin(), vec.end(), elem) != vec.end() )
    {
        result = true;
    }
    return result;
}

bool goBackToStartState(string currentWord, char nextChar){
    if(nextChar == ' '){

    }
}

vector<char> alphabets;
void init_vectors(){
    vector<char> reservedChars = {'a', 'm', 'i', 'o', 'e', 't', 'r', 'c'};
    vector<char> digits = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    for(int i=97; i<=122; i++){
        alphabets.push_back((char)i);
    }
    for(int i=65; i<=90; i++){
        alphabets.push_back((char)i);
    }
    for(int i=48; i<=57; i++){
        alphabets.push_back((char)i);
    }
    alphabets.push_back('\'');
}

void parseInputLine(DFA* dfa, Tokens* tokens_object, string inputLine, int lineNumber){
    string currentWord = "";
    int currentStateID = dfa->getStartID();
    char currentChar;
    char lastChar='\0';
    char inputToDFA;

    inputLine = inputLine + " ";
    // cout<<inputLine<<endl;

    for(int i=0; i<inputLine.length(); i++){
        currentChar = inputLine[i];
        // cout<<currentChar<<endl;
        if(lastChar != '\0' && (contains(alphabets, currentChar) ^ contains(alphabets, lastChar))){
            currentStateID = dfa->getStartID();
        } else{
            inputToDFA = currentChar;

            // cout<<inputToDFA<<endl;

            if(dfa->isNextStatePresentForGivenInput(currentStateID, inputToDFA)){
                currentWord += currentChar;
                currentStateID = dfa->getStateById(currentStateID)->next(currentChar).getId();

                // cout<<currentWord<<endl;
                // cout<<currentStateID<<endl;
            } else if(currentWord.length() > 0){
                string tokenClass = dfa->getStateById(currentStateID)->getTokenClassForFinalStates();
                // if(tokenClass != "null"){
                    cout<<currentWord<<" "<<currentStateID<<" "<<tokenClass<<endl;    
                // }
                currentStateID = dfa->getStartID();
                currentWord = "";
                i--;
            }
        }
    }
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
    // vector<State> list = dfa->getStateList();
    // for(auto item:list){
    //     cout<<item<<endl;
    // }

    while(getline(file, inputLine)){
        parseInputLine(dfa, &tokens_object, inputLine, lineNumber);
        lineNumber++;
    }
    
    // tokens_object.displayTokensList();
    // vector<pair<pair<string, string>, int>> tokensDictionary = tokens_object.getTokenDictionary();
    // writeOutputToFile(tokensDictionary);
}