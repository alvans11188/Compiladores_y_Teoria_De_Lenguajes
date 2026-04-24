#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

using namespace std;

//definicion de tipos de categorias que se usaran para el compilador
typedef enum { 
    KEYWORD,	//palabra reservadas int,if,while
    IDENTIFIER, //nombres de variables o funciones
    NUMBER,		//valores de numeros
    OPERATOR,	// operadores como *,/,+,-
    DELIMITER,	// delimitador ; 
    STRING,		// texto entre comilla
    UNKNOWN		//caracteres desconocidos
} TokenType;

//funcion de deteccion de caracteres individuales LETRAS
bool isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
//funcion de deteccion de caracteres individuales numeros enteros y con decimales
bool isDigitChar(char c) {
    return (c >= '0' && c <= '9'||c=='.'); //TAREA identificacion de numeros con decimales
}
//funcion de comparacion de palabras con palabras reservadas
bool isKeyword(char *str) {
    const char *keywords[] = {"int", "float", "if", "else", "while", "return"};
    int n = 6;
    
    for (int i = 0; i < n; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return true;
        }
    }
    return false;
}
bool esUnString(char c){
	if(c=='"'){
		return true;
	}else{
		return false;
	}
}

bool esUnComentario(char c){
	if(c=='/'){
		return true;
	}else{
		return false;
	}
}
//funcion de analizador lector de caracter por caracter 
void lexer(ifstream &file) {
	int ide=0;
	int key=0;
	int num=0;
	int errores=0;
	int strin=0;
	int ope=0;
	int deli=0;
	
    char c;
    
    while (file.get(c)) {
        if (isspace(c)) continue; //ignora saltos de espacios, lineas y tabulados
        
        //1. logica de busqueda de identificadores y palabras reservadas (KEYWORD)
        if (isLetter(c)) {
            char buffer[100]={0};
            int i = 0;
            do {
                buffer[i++] = c;
                file.get(c);
            } while (file && (isLetter(c) || isDigitChar(c))); //lectura completa de la linea para encontrar numero
            
            buffer[i] = '\0';
            
            if (file) {
                file.unget(); //retorna el ultimo caracter leido que no es letra ni numero
            }
            
            if (isKeyword(buffer)) {
                cout << "[KEYWORD: " << buffer << "]\n";
                key++;
            } else {
                cout << "[IDENTIFICADOR: " << buffer << "]\n";
                ide++;
            }
        //2. logica de identificacion de numeros     
        } else if (isDigitChar(c)) {
            char buffer[100]={0}; 
            int i = 0;
            do {
                buffer[i++] = c;
                file.get(c);
            } while (file && isDigitChar(c)); 
            
            buffer[i] = '\0';
            
            if (file) {
                file.unget();
            }
            
            cout << "[NUMERO: " << buffer << "]\n";
            num++;
        //3. TAREA logica de identificacion de string    
        } else if(esUnString(c)){
        	char buffer[100]={0};
        	int i=0;
        	while(file.get(c)&&!esUnString(c)){
        		buffer[i++] = c;
			}
        	
        	/*do{
                file.get(c);
				buffer[i++] = c;
                
            } while (file && !esUnString(c)); //lectura hasta no encontrar sgte comilla 
            */
			
			buffer[i] = '\0';           
            cout << "[STRING: " << buffer << "]\n";
            strin++;
        //5. TAREA lectura de un comentario simples y multilinea  
		}else if (esUnComentario(c)){
			char buffer[100] = {0}; //el {0} limpia el buffer , empezando a llenar el arreglo denuevo
			int i=0;
			char primero=c;
			if(file.get(c)){
				if(c=='/'){
					
						buffer[i++] = primero;	
						buffer[i++] = '/';	
						
						while(file.get(c)&&c!='\n'){
							buffer[i++]=c;
						}
						/*
						do{
							file.get(c);
							buffer[i++] = c;	
						}while(c!='\n');
						*/
						buffer[i] = '\0'; 
						cout << "[COMENTARIO SIMPLE: " << buffer << "]\n";
					
					
				}else if(c=='*'){
					
					buffer[i++] = primero;
					buffer[i++] = c;
					bool a=true;					
					while(file.get(c)){
						buffer[i++] = c;
						if(c=='*'){
							file.get(c);
							if(c=='/'){
								buffer[i++] = c;
								a=false;
								break;
							}else{
								file.unget();
							}		
						}
					}
					//file.get(c);
					//buffer[i++] = c;
					buffer[i] = '\0'; 
					if(!a){
						cout << "[COMENTARIO MULTILINEA: " << buffer << "]\n";
					}else{
						cout<< "ERROR LEXICO , NO OCURRE UN CIERRE DEL COMENTARIO MULTILINEA"<<endl;
					}
					
				}else{
					file.unget();
					cout<<"[OPERADOR: /]\n";
					ope++;
					
				}
			}else{
				file.unget();
				cout<<"[OPERADOR: /]\n";
				ope++;
			}
			continue; //para que no cuente doble un operador /
        //4. Logica de deteccion directa de operadores y limitadores
		}else if (c == '+' || c == '-' || c == '*' || /*c == '/' ||*/ c == '=') {
            cout << "[OPERADOR: " << c << "]\n";
            ope++;
        } else if (c == ';' || c == ',' || c == '(' || c == ')') {
            cout << "[DELIMITADOR: " << c << "]\n";
            deli++;
        } else {
            cout << "[DESCONOCIDO: " << c << "]\n";
            errores++;
        }
		
    }
    cout<<"=== RESUMEN DE VALORES LEIDOS ==="<<endl;
	cout<<"Total de Identificadores: "<< ide <<endl;
	cout<<"Total de Keywords: "<<key<<endl;
	cout<<"Total de Numeros: "<<num<<endl;
	cout<<"Total de Operadores: "<<ope<<endl;
	cout << " Delimitadores: " << deli << endl;
    cout << " ERRORES: " << errores << endl;
	//cout<<"Errores encontrados: "<<erro<<endl;

}

int main() {
    ifstream file("input.c");
    
    if (!file.is_open()) {
        cout << "Error al abrir archivo\n";
        return 1;
    }
    
    lexer(file);
    file.close();
    
    return 0;
}
