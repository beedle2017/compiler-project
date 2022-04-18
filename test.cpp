#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include "utils.h"

using namespace std;

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

void parseInputLine(Tokens *tokens_object, string inputLine, int lineNumber){
    inputLine = inputLine + " ";
    
    int left = 0;
    string current_token = "";
    string temp_token = "";

    bool isValidKeyword = false;

    bool wasSpecial = false, isSpecial = false;

    while(left < inputLine.length()){
        char current_character = inputLine[left];

        isValidKeyword = isValidKeyWord(current_token);
        isSpecial = isSpecialCharacter(current_character);

        if(current_character == ' ' || current_character == '\n'){
            if(current_token == ""){
                left++;
                continue;
            } else {
                // add current_token to list of tokens
                // commit current_token
                (*tokens_object).addToken(current_token, lineNumber);
                current_token = "";
            }
        } else {
            if(!wasSpecial && isSpecial){
                // commit current_token
                (*tokens_object).addToken(current_token, lineNumber);
                current_token = "";
            } else if(wasSpecial){
                temp_token = current_token + current_character;
                if(!isValidKeyWord(temp_token) && isValidKeyWord(current_token)){
                    // commit current token
                    (*tokens_object).addToken(current_token, lineNumber);
                    current_token = "";
                }
            }
            if(current_character == '\''){
                string charConstant = inputLine.substr(left,3);
                (*tokens_object).addToken(charConstant, lineNumber);

                left += 3;
                current_character = inputLine[left];
            }
            current_token += current_character;
        }

        wasSpecial = isSpecial;
        left++;
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

    while(getline(file, inputLine)){
        parseInputLine(&tokens_object, inputLine, lineNumber);
        lineNumber++;
    }
    
    // tokens_object.displayTokensList();
    vector<pair<pair<string, string>, int>> tokensDictionary = tokens_object.getTokenDictionary();
    writeOutputToFile(tokensDictionary);
}