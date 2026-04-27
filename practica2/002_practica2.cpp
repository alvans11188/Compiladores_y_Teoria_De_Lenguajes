#include <iostream>
#include <regex>
using namespace std;
//UN PATRON ES UN ESQUEMA
//NECESITAMOS UN PROGRAMA QUE NOS AYUDE A DETERMINAR UN PATRON ES CORRECTO O NO
/* 1- VALIDAR UN NUMERO ENTERO
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
// 3- REEMPLAZAR TEXTO , permite sustituir coincidencias
int main(){
	string texto ="Mi edad es 25";
	regex patron("\\d+");
	string nuevo=regex_replace(texto,patron,"X");
	
	cout<<nuevo;
 
    return 0;
}

//4- ANALIZADOR SIMPLE DE TOKENS
int main(){
	string texto ="var=1=100 + total2";
	regex patron("\\d+|\\w+");
	
	auto it=sregex_iterator(texto.begin(),texto.end(),patron);
	auto end=sregex_iterator();

	for(;it!=end;++it){
		cout<<"token: "<<it->str()<<endl;
	}
 
    return 0;
}
*/
//5- EXTRACTOR DE PALABRAS
int main(){
	string texto = "Hola mundo C++ regex"; 
	regex patron("\\w+"); 
	auto palabras_inicio = sregex_iterator(texto.begin(), texto.end(), patron); 
	auto palabras_fin = sregex_iterator(); 
	for (auto i = palabras_inicio; i != palabras_fin; i++) { 
		cout << i->str() << endl; 
	}
 
    return 0;
}
