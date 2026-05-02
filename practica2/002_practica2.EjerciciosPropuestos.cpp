#include <iostream>
#include <regex>

using namespace std;

int main() {
    string texto = "suma = 100 + valor_2";
    
    regex patron1("([a-zA-Z_]\\w*)");
    regex patron2("(\\d+)");
    regex patron3("([+\\-*/=])");
    
    regex patron4("([a-zA-Z_]\\w+|\\d+|[+\\-*/=])");
    
    auto it = sregex_iterator(texto.begin(), texto.end(), patron4);
    auto end = sregex_iterator();
    
    for (; it != end; ++it) {
        string token = it->str();
        
        if (regex_match(token, patron1)) {
            cout << "Identificador :" << token << endl;
        } 
        else if (regex_match(token, patron2)) {
            cout << "Numero        :" << token << endl;
        } 
        else if (regex_match(token, patron3)) {
            cout << "Operador      :" << token << endl;
        }
    }
    
    return 0;
}