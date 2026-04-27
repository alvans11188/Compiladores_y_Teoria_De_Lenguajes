#include <iostream>
#include <regex>
using namespace std;
// 2- ENCONTRAR UN NUMERO EN UN TEXTO
int main(){
	string texto ="Edad: 25 anios";
	regex patron("\\d+");
	smatch resultado;
	
	if(regex_search(texto,resultado,patron)){
		cout<<"Numero encontrado "<<resultado[0];
	}else { 
        cout << "No es valido"; 
    } 
 
    return 0;
}
