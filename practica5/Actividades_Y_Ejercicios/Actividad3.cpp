#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main() {
    string num;
    int estado = 0;
     cout << "Ingrese un numero real: ";
    cin >> num;
    for(char c : num) {
        switch(estado) {
            case 0:
                if(c == '+' || c == '-') estado = 1;
                else if(isdigit(c)) estado = 2;
                else { cout << "Numero invalido\n"; return 0; }
                break;
            case 1:
                if(isdigit(c)) estado = 2;
                else { cout << "Numero invalido\n"; return 0; }
                break;
            case 2:
                if(isdigit(c)) estado = 2;
                else if(c == '.') estado = 3;
                else { cout << "Numero invalido\n"; return 0; }
                break;
            case 3:
            case 4:
                if(isdigit(c)) estado = 4;
                else { cout << "Numero invalido\n"; return 0; }
                break;
        }
    }
    if(estado == 4) cout << "Numero real valido" << endl;
    else cout << "Numero real invalido" << endl;
    return 0;
}
