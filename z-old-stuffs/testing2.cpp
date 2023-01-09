#include "dfa_initiator.h"
#include<fstream>
#include<set>
#include "../utils.h"

// function to clear output file
void clearOutputFile(){
    ofstream file;
	file.open("output.txt");
    file<<"";
    file.close();
}


bool isAlphabet(char ch){
    if((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122)){
        return true;
    }
    return false;
}

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

vector<char> alphabets;
vector<char> alphabets_2;

// utility vectors for storing alphabets, digits, operators and other characters to
// determine state-reset of the dfa
void init_vectors(){

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
    alphabets.push_back('.');

    alphabets_2.push_back('<');
    alphabets_2.push_back('>');
    alphabets_2.push_back('!');
    alphabets_2.push_back('=');
}

// get tokens functions for a particulat input syntax
void parseInputLine(DFA* dfa, Tokens* tokens_object, string inputLine, int lineNumber){
    string currentWord = "";
    int currentStateID = dfa->getStartID();
    int oldStateID;
    char currentChar;
    char lastChar='\0';
    char inputToDFA;

    inputLine = inputLine + " ";

    for(int i=0; i<inputLine.length(); i++){
        currentChar = inputLine[i];
//|| (currentChar == '\'' || lastChar== '\'')?false : (isAlphabet(lastChar) ^ isAlphabet(currentChar))|| (currentChar == '\'' || lastChar== '\'')?false :(isValidInteger(currentChar) ^ isValidInteger(lastChar))
        // resetting the current state to start state on encountering following conditions
        if(lastChar != '\0' && currentWord.length() > 0 && ( (contains(alphabets, currentChar) ^ contains(alphabets, lastChar)) || (lastChar == '(' && currentChar == ')') || (lastChar == '{' && currentChar == ')') || (currentChar == ';') || (currentChar == ' ' || currentChar == '\t' || currentChar == '\n') || (lastChar == ')' && currentChar == '{') || (contains(alphabets_2, currentChar) ^ contains(alphabets_2, lastChar)) || ((currentChar == '\'' || lastChar== '\'')?false : (isAlphabet(lastChar) ^ isAlphabet(currentChar)))  )){
            string tokenClass = dfa->getStateById(currentStateID)->getTokenClassForFinalStates();
            
            // cout<<currentWord<<" "<<currentStateID<<" "<<tokenClass<<endl;
            (*tokens_object).addPair(tokenClass, currentWord, lineNumber);
            
            currentStateID = dfa->getStartID();
            currentWord = "";
            i--;

        } else{                             // else transitioning through next states of current state
            inputToDFA = currentChar;
            if(inputToDFA >= 48 && inputToDFA <= 57)
            {
              inputToDFA = '#';
            }

            if(dfa->isNextStatePresentForGivenInput(currentStateID, inputToDFA)){
                currentWord += currentChar;
                currentStateID = dfa->getStateById(currentStateID)->next(inputToDFA).getId();
            }
        }
        lastChar = currentChar;
    }
}

int main(){
    string filename = "";
    cout<<"Enter File Name: ";
    cin>>filename;
    ifstream file(filename);

    for(char v='a'; v<='z'; v++)
      dollar.push_back(v);
    for(char v='A'; v<='Z'; v++)
      dollar.push_back(v);

    string inputLine = "";
    int lineNumber = 1;
    Tokens tokens_object = Tokens();
    int flag = 0;

    init_vectors();

    DFA* dfa = new DFA();
    initDFA(dfa);

    while(getline(file, inputLine)){

        parseInputLine(dfa, &tokens_object, inputLine, lineNumber);
        lineNumber++;
    }

    tokens_object.isErrorTokenPresent();
}
