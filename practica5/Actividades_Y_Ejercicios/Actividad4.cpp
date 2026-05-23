#include <iostream>
#include <string>

using namespace std;

int main() {
	while(true){
		string token;
	    cout << "Ingrese token a evaluar: ";
	    cin >> token;
	    
	    if (token == "while" || token == "if" || token == "else" || token == "for") {
	        cout << "Token reconocido: PALABRA RESERVADA [" << token << "]" << endl;
	    } else {
	        cout << "Token rechazado o no pertenece a las palabras reservadas." << endl;
	    }
	}
    
    return 0;
}
