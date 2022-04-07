#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

class Tokens {
    vector<pair<string, string>> tokensDictionary;
    vector<string> tokens;

    public:
        Tokens(){
            
        }

        void addPair(string key, string value){
            tokensDictionary.push_back(make_pair(key, value));
        }

        void addToken(string token){
            tokens.push_back(token);
        }

        void displayTokensList(){
            for(string token : tokens){
                cout<<token<<"\n";
            }
        }

};

bool isValidToken(string token){
    if(token == "main" || token == "(" || token == ")" || token == "{" || token == "}" ||
       token == "+" || token == "-" || token == "*" || token == "/" || token == "%" ||
       token == "int" || token == "real" || token == "char" ||
       token == "<" || token == ">" || token == "<=" || token == "<=" || token == "==" || token == "!=" ||
       token == "=" || token == "<<" || token == ">>" || token == "," || token == ";" || token == "and" || token == "or" ||
       token == "cout" || token == "cin")

            return true;

    return false;
}


void parseInputLine(Tokens *tokens_object, string inputLine){
    int left = 0, right = 0;
    while(right < inputLine.length()){
        string token = inputLine.substr(left, right - left + 1);
        // cout<<left<<","<<right<<endl;

        if(token == " "){
            left = right + 1;
        }

        if(isValidToken(token)){
            (*tokens_object).addToken(token);
            left = right + 1;
            // cout<<left<<","<<right<<endl;
        }
        right++;
        // cout<<left<<","<<right<<endl<<endl;
    }
}

int main(){
    string filename = "test.txt";
    ifstream file(filename);

    string inputLine = "";
    Tokens tokens_object = Tokens();

    while(getline(file, inputLine)){
        // cout<<inputLine<<endl;
        parseInputLine(&tokens_object, inputLine);
    }
    
    tokens_object.displayTokensList();

}