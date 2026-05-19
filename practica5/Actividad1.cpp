/*
Actividad 1 
Construir un autómata que acepte cadenas binarias terminadas en 10.
Estado  0 1 
	q0 q1 q1 
	q1 q2 q2 
	q2 q1 q0
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string cadena;
    int estado = 0;
    cout << "Ingrese cadena binaria: ";
    cin >> cadena;
    
    for(char c: cadena) {
        switch(estado) {
            case 0:
                if(c == '0') estado = 1;
                else if(c == '1') estado = 0;
                else { cout << "Simbolo invalido\n"; return 0; }
                break;
            case 1:
                if(c == '0') estado = 1;
                else if(c == '1') estado = 2;
                else { cout << "Simbolo invalido\n"; return 0; }
                break;
            case 2:
                if(c == '0') estado = 1;
                else if(c == '1') estado = 0;
                else { cout << "Simbolo invalido\n"; return 0; }
                break;
        }
    }
    
    if(estado == 2) cout << "Cadena aceptada\n";
    else cout << "Cadena rechazada\n";
    
    return 0;
}
