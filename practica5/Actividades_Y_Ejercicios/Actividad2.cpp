#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main() {
    string correo;
    int estado = 0;
    cout << "Ingrese correo electronico simple: ";
    cin >> correo;
    for(char c : correo) {
        switch(estado) {
            case 0:
            case 1:
                if(isalnum(c)) estado = 1;
                else if(c == '@' && estado == 1) estado = 2;
                else { cout << "Estructura invalida\n"; return 0; }
                break;
            case 2:
                if(isalnum(c)) estado = 3;
                else { cout << "Estructura invalida\n"; return 0; }
                break;
            case 3:
                if(isalnum(c)) estado = 3;
                else if(c == '.') estado = 4;
                else { cout << "Estructura invalida\n"; return 0; }
                break;
            case 4:
            case 5:
                if(isalpha(c)) estado = 5;
                else { cout << "Estructura invalida\n"; return 0; }
                break;
        }
    }
        if(estado == 5) cout << "Correo aceptado" << endl;
    else cout << "Correo rechazado" << endl;
        return 0;
}
