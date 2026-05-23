#include <iostream>
#include <string>
#include <cctype>
using namespace std;
bool esEntero(string s) {
    int i = (s[0] == '+' || s[0] == '-') ? 1 : 0;
    if(i == s.length()) return false;
    for(; i < s.length(); i++) {
        if(!isdigit(s[i])) return false;
    }
    return true;
}

bool esReal(string s) {
    int estado = 0;
    for(char c : s) {
        switch(estado) {
            case 0:
                if(c == '+' || c == '-') estado = 1;
                else if(isdigit(c)) estado = 2;
                else return false;
                break;
            case 1:
                if(isdigit(c)) estado = 2;
                else return false;
                break;
            case 2:
                if(isdigit(c)) estado = 2;
                else if(c == '.') estado = 3;
                else return false;
                break;
            case 3:
            case 4:
                if(isdigit(c)) estado = 4;
                else return false;
                break;
        }
    }
    return estado == 4;
}
int main() {
    string entrada;
    cout << "Ingrese expresion o token a analizar: ";
    while( cin >> entrada){
    	if(entrada.length() == 1 && (entrada[0] == '+' || entrada[0] == '-' || entrada[0] == '*' || entrada[0] == '/')) {
	        cout << "Token: OPERADOR ARITMETICO" << endl;
	    } else if(esEntero(entrada)) {
	        cout << "Token: NUMERO ENTERO" << endl;
	    } else if(esReal(entrada)) {
	        cout << "Token: NUMERO REAL" << endl;
	    } else {
	        cout << "Token NO reconocido" << endl;
	    }
	}
        return 0;
}
