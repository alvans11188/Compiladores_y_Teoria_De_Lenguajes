#include <iostream>
#include <regex>
using namespace std;
//VALIDAR CORREO ELECTRONICO
int main(){
	string texto ="sander@unjbg.edu.pe";
	regex patron("^[\\w.-]+@[\\w.-]+\\.\\w+$");
	
	if(regex_match(texto,patron)){
		cout<<"Es un correo valido";
	}else { 
        cout << "No es valido"; 
    } 
 
    return 0;
}
