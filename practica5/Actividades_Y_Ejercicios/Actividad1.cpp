#include <iostream>
#include <string>
using namespace std;
int main() {
    string cadena;
    int estado = 0;
        cout << "Ingrese cadena binaria (terminada en 10): ";
    cin >> cadena;
    for(char c : cadena) {
        switch(estado) {
            case 0:
                if(c == '0') estado = 0;
                else if(c == '1') estado = 1;
                else { cout << "Simbolo invalido\n"; return 0; }
                break;
            case 1:
                if(c == '0') estado = 2;
                else if(c == '1') estado = 1;
                else { cout << "Simbolo invalido\n"; return 0; }
                break;
            case 2:
                if(c == '0') estado = 0;
                else if(c == '1') estado = 1;
                else { cout << "Simbolo invalido\n"; return 0; }
                break;
        }
    }
    
    if(estado == 2) cout << "Cadena aceptada" << endl;
    else cout << "Cadena rechazada" << endl;
    
    return 0;
}
