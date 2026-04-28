#include <iostream>
#include <regex>
using namespace std;
//VALIDAR NUMERO TELEFONICO
int main(){
	string texto ="910850037";
	regex patron("^9\\d{8}$");
	
	if(regex_match(texto,patron)){
		cout<<"Es un NUMERO TELEFONICO valido";
	}else { 
        cout << "No es valido"; 
    } 
 
    return 0;
}
