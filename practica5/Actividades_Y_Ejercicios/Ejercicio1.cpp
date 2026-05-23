#include <iostream>
#include <string>

using namespace std;

int main() {
    string cadena;
    int estado = 0;
    
    cout << "Ingrese cadena binaria: ";
    cin >> cadena;
    
    for(char c : cadena) {
        switch(estado) {
            case 0:
                if(c == '0') estado = 0;
                else if(c == '1') estado = 1;
                break;
            case 1:
                if(c == '0') estado = 2;
                else if(c == '1') estado = 1;
                break;
            case 2:
                if(c == '0') estado = 0;
                else if(c == '1') estado = 3;
                break;
            case 3:
                if(c == '0' || c == '1') estado = 3;
                break;
        }
    }
    
    if(estado == 3) cout << "Cadena contiene '101' (Aceptada)" << endl;
    else cout << "Cadena NO contiene '101' (Rechazada)" << endl;
    
    return 0;
}
