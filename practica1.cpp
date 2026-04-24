#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

using namespace std;

typedef enum {
    KEYWORD,
    IDENTIFIER,
    NUMBER,
    OPERATOR,
    DELIMITER,
    STRING,
    UNKNOWN
} TokenType;

bool isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool isDigitChar(char c) {
    return (c >= '0' && c <= '9'||c=='.');
}

bool isKeyword(char *str) {
    const char *keywords[] = {"int", "float", "if", "else", "while", "return"};
    int n = 6;
    
    for (int i = 0; i < n; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return true;
        }
    }
    return false;
}
bool esUnString(char c){
	if(c=='"'){
		return true;
	}else{
		return false;
	}
}
void lexer(ifstream &file) {
    char c;
    
    while (file.get(c)) {
        if (isspace(c)) continue;
        
        if (isLetter(c)) {
            char buffer[100];
            int i = 0;
            do {
                buffer[i++] = c;
                file.get(c);
            } while (file && (isLetter(c) || isDigitChar(c)));
            
            buffer[i] = '\0';
            
            if (file) {
                file.unget();
            }
            
            if (isKeyword(buffer)) {
                cout << "[KEYWORD: " << buffer << "]\n";
            } else {
                cout << "[IDENTIFIER: " << buffer << "]\n";
            }
            
        } else if (isDigitChar(c)) {
            char buffer[100];
            int i = 0;
            do {
                buffer[i++] = c;
                file.get(c);
            } while (file && isDigitChar(c));
            
            buffer[i] = '\0';
            
            if (file) {
                file.unget();
            }
            
            cout << "[NUMBER: " << buffer << "]\n";
            
        } else if(esUnString(c)){
        	char buffer[100];
        	int i=0;
        	do{
                buffer[i++] = c;
                file.get(c);
            } while (file && esUnString(c));
           
            
            cout << "[STRING: " << buffer << "]\n";
		}else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '=') {
            cout << "[OPERATOR: " << c << "]\n";
        } else if (c == ';' || c == ',' || c == '(' || c == ')') {
            cout << "[DELIMITER: " << c << "]\n";
        } else {
            cout << "[UNKNOWN: " << c << "]\n";
        }
		
    }
}

int main() {
    ifstream file("input.c");
    
    if (!file.is_open()) {
        cout << "Error al abrir archivo\n";
        return 1;
    }
    
    lexer(file);
    file.close();
    
    return 0;
}
