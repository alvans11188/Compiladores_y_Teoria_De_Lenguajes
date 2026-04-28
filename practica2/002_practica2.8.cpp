#include <iostream>
#include <regex>
using namespace std;
//VALIDAR CONTRASEÑA SEGURA
int main(){
	string texto ="A1bcdefg";
	regex patron("^(?=.*[A-Z])(?=.*\\d).{8,}$");
	
	if(regex_match(texto,patron)){
		cout<<"Es una CONTRASEÑA VALIDA valido";
	}else { 
        cout << "No es valido"; 
    } 
 
    return 0;
}
