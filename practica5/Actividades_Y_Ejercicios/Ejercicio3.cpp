#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string clave;
    cout << "Ingrese la contrasenia a validar: ";
    cin >> clave;
    
    bool tieneMayuscula = false;
    bool tieneNumero = false;
    
    if(clave.length() < 8) {
        cout << "Contrasenia Invalida (Menos de 8 caracteres)" << endl;
        return 0;
    }
    
    for(char c : clave) {
        if(isupper(c)) tieneMayuscula = true;
        if(isdigit(c)) tieneNumero = true;
    }
    
    if(tieneMayuscula && tieneNumero) {
        cout << "Contrasenia Valida y Aceptada" << endl;
    } else {
        cout << "Contrasenia Rechazada (Falta mayuscula o numero)" << endl;
    }
    
    return 0;
}
