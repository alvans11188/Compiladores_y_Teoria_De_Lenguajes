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
    char c;
    
    while (file.get(c)) {
        if (isspace(c)) continue; //ignora saltos de espacios, lineas y tabulados
        
        //1. logica de busqueda de identificadores y palabras reservadas (KEYWORD)
        if (isLetter(c)) {
            char buffer[100];
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
            } else {
                cout << "[IDENTIFICADOR: " << buffer << "]\n";
            }
        //2. logica de identificacion de numeros     
        } else if (isDigitChar(c)) {
            char buffer[100];
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
        //3. TAREA logica de identificacion de string    
        } else if(esUnString(c)){
        	char buffer[100];
        	int i=0;
        	do{
                file.get(c);
				buffer[i++] = c;
                
            } while (file && !esUnString(c)); //lectura hasta no encontrar sgte comilla 
			
			buffer[i] = '\0';           
            cout << "[STRING: " << buffer << "]\n";
        //5. TAREA lectura de un comentario simples y multilinea  
		}else if (esUnComentario(c)){
			char buffer[100];
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
					
					
					while(file.get(c)){
						//buffer[i++] = c;
						if(c=='*'){
							buffer[i++] = c;
							break;
						}else{
							buffer[i++] = c;
						}
						
					}
					file.get(c);
					buffer[i++] = c;
					buffer[i] = '\0'; 
					cout << "[COMENTARIO MULTILINEA: " << buffer << "]\n";
				}else{
					file.unget();
					cout<<"[OPERADOR: /]\n";
				}
			}else{
				file.unget();
				cout<<"[OPERADOR: /]\n";
			}
			
		
		
		
		 
        //4. Logica de deteccion directa de operadores y limitadores
		}else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '=') {
            cout << "[OPERADOR: " << c << "]\n";
        } else if (c == ';' || c == ',' || c == '(' || c == ')') {
            cout << "[DELIMITADOR: " << c << "]\n";
        } else {
            cout << "[DESCONOCIDO: " << c << "]\n";
        }
		
    }
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
