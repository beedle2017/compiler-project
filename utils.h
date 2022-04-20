#include<string>
#include<iostream>
#include<vector>
#include<regex>
using namespace std;

void writeOutputToFile(vector<pair<pair<string, string>, int>> tokens);

// class to store the tokens which are outputed as a file
class Tokens {
    vector<pair<pair<string, string>, int>> tokensDictionary;
    vector<string> tokens;

    public:
        Tokens(){

        }

        void addPair(string key, string value, int line){
            tokensDictionary.push_back(make_pair(make_pair(key, value), line));
        }

        void displayTokensList(){
            for(auto item : tokensDictionary){
                cout<<item.first.first<<" -> "<<item.first.second<<"@"<<item.second<<endl;
            }
        }

        vector<pair<pair<string, string>, int>> getTokenDictionary() {
            return tokensDictionary;
        }

        void isErrorTokenPresent(){
            int flag = 0;
            cout<<endl;

            for(auto item:tokensDictionary){
                if(item.first.first == "null"){
                    flag = 1;
                    cout<<"Lexical Error at line "<<item.second<<".\n";
                }
            }
            if(flag == 0){
                writeOutputToFile(tokensDictionary);
                cout<<"\nLexical Tokens Generated Successfully in output.txt\n";
            } else {
                cout<<"\nTerminating analyser with errors...\n";
            }
        }
};


// function to log the output token stream to file
void writeOutputToFile(vector<pair<pair<string, string>, int>> tokens){
	ofstream file;
	file.open("output.txt");
    file<<"***TOKENS AFTER SCANNING INPUT FILE***"<<endl<<endl;
	for(auto item : tokens){
        if(item.first.first != "VALUE"){
            file<<item.first.first<<" -> "<<item.first.second<<"@"<<item.second<<endl;
        } else {
            file<<item.first.first<<" -> "<<item.first.first<<"@"<<item.second<<endl;
        }
	}
	file.close();
}


bool isSpecialCharacter(char ch){
    if((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122)){
        return false;
    }
    return true;
}

bool isValidInteger(char integer) {
    if(integer >= 48 && integer <=57){
        return true;
    }
    return false;
}

bool isConstant(string token) {
    if(isValidInteger(token[0]) || token[0] == '\''){
        return true;
    }
    return false;
}

bool isValidID(string token) {
    string pattern = "^[A-Za-z0-9_]+$";
    return regex_match(token, regex(pattern));
}

