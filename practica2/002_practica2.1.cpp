#include <iostream>
#include <regex>
using namespace std;
//UN PATRON ES UN ESQUEMA
//NECESITAMOS UN PROGRAMA QUE NOS AYUDE A DETERMINAR UN PATRON ES CORRECTO O NO
 1- VALIDAR UN NUMERO ENTERO
int main(){
	string texto ="12345";
	regex patron("\\d+");
	
	if(regex_match(texto,patron)){
		cout<<"Es un numero valido";
	}else { 
        cout << "No es valido"; 
    } 
 
    return 0;
}
