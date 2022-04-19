#include<string>
#include<iostream>
#include<vector>
#include<regex>
using namespace std;

bool isValidKeyWord(string token){
    if(token == "main" || token == "(" || token == ")" || token == "{" || token == "}" ||
        token == "+" || token == "-" || token == "*" || token == "/" || token == "%" ||
        token == "int" || token == "real" || token == "char" ||
        token == "<" || token == ">" || token == "<=" || token == "<=" || token == "==" || token == "!=" || token == "=" ||
        token == "<<" || token == ">>" || token == "," || token == ";" || token == "and" || token == "or" ||
        token == "cout" || token == "cin")

            return true;

    return false;
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

string getKeyFromGrammar(string value){
    if(value == "main"){
        return "MAIN";
    } else if(value == "+" || value == "-"){
        return "add_op";
    } else if(value == "*" || value == "/" || value == "%"){
        return "mul_op";
    } else if(value == "int" || value == "real" || value == "char"){
        return "d_type";
    } else if(value == "<" || value == ">" || value == ">=" ||
                value == "<=" || value == "==" || value == "!="){
        return "comp_op";
    } else if(value == "("){
        return "open_first_bracket";
    } else if(value == ")"){
        return "close_first_bracket";
    } else if(value == "{"){
        return "open_second_bracket";
    } else if(value == "}"){
        return "close_second_bracket";
    } else if(value == "="){
        return "equals";
    } else if(value == ">>"){
        return "i_cas";
    } else if(value == "<<"){
        return "o_cas";
    } else if(value == "cin"){
        return "input";
    } else if(value == "cout"){
        return "output";
    } else if(value == "if"){
        return "if_token";
    } else if(value == "else"){
        return "else_token";
    } else if(value == "then"){
        return "then_token";
    } else if(value == "and" || value == "or" || value == "not"){
        return "relational_op";
    } else if(isConstant(value)){
        return "VALUE";
    } else if(value == ";"){
        return "EOL";
    } else if(value == ","){
        return "COMMA";
    } else if(isValidID(value)) {
        return "ID";
    } else {
        return "invalid";
    }
}

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

};
