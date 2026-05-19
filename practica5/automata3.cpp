//AUTOMATA RECONOCER DE IDENTIFICADORES
/*IDENTIFICA LETRA Y NUMERO , SINO ES PRIMERO LETRA DA UN ERROR */
#include <iostream>
#include <cctype> 
#include <string> 
using namespace std; 
 
int main() { 
 
    string palabra; 
    cout << "Ingrese identificador: "; 
    cin >> palabra; 
 
    if(!isalpha(palabra[0])) { 
        cout << "Identificador invalido" << endl; 
        return 0; 
    } 
 
    for(int i = 1; i < palabra.length(); i++) { 
 
        if(!isalnum(palabra[i])) { 
            cout << "Identificador invalido" << endl; 
            return 0; 
        } 
    } 
    cout << "Identificador valido" << endl; 
    return 0; 
} 
