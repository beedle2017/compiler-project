#include<string>
using namespace std;

#define MAIN

bool isValidDelimeter(string ch){
    if (ch == " " || ch == "+" || ch == "-" || ch == "*" || ch == "%" ||
        ch == "," || ch == ";" || ch == ">" || ch == "<" || ch == "==" || ch == "!=" ||
        ch == "?" || ch == ":" || ch == ">>" || ch == "<<" || ch == "=" || 
        ch == "(" || ch == ")" || ch == "{" || ch == "}" || 
        ch == "\n" ) {

            return true;
    }

    return false;
}

bool isValidOperator(char ch){
    if (ch == '+' || ch == '-' || ch == '*' || ch == '%' ||
        ch == '>' || ch == '<' || ch == '=' || 
        ch == '?' || ch == ':') {
        return true;
    }

    return false;
}

bool isValidIdentifier(string identifier){
    string s(1, identifier[0]);

    if (identifier[0] == '0' || identifier[0] == '1' || identifier[0] == '2' || identifier[0] == '3' || identifier[0] == '4' || 
        identifier[0] == '5' || identifier[0] == '6' || identifier[0] == '7' || identifier[0] == '8' || identifier[0] == '9' ||
        identifier[0] == '\'' || isValidDelimeter(s) == true) {
            
        return false;
    }

    return true;
}

bool isValidCharacter(string character) {
    if (character[0] == '\'' && character[2] == '\'') {
        return true;
    }
    return false;
}

bool isValidInteger(string str) {
    int len = str.length();

    if (len == 0)
        return false;

    for (int i = 0; i < len; i++) {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' &&
            str[i] != '5' && str[i] != '6' && str[i] != '7' && 
            str[i] != '8' && str[i] != '9' || (str[i] == '-' && i > 0))
        return false;
    }

    return true;
}

bool isValidReal(string str){
    int length = str.length();
    bool hasDecimal = false;

    if (length == 0)
        return false;

    for (int i = 0; i < length; i++) {
        
        if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' &&
            str[i] != '5' && str[i] != '6' && str[i] != '7' && 
            str[i] != '8' && str[i] != '9' && str[i] != '.' || (str[i] == '-' && i > 0))
                return false;

        if (str[i] == '.')
            hasDecimal = true;
    }

    return hasDecimal;
}

bool is_valid_keyword(char* str) {

    if (!strcmp(str, "void") || !strcmp(str, "int") || !strcmp(str, "float") || 
        !strcmp(str, "return") || !strcmp(str, "char") || !strcmp(str, "get") || !strcmp(str, "put")) 
        return true;

    return false;
}