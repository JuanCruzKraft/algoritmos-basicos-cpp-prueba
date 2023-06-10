/*
"censura" subcadenas o frase prohibida dentro de la frase principal
*/

#include <iostream>
#include <string>
using namespace std;
void fraseProhibida(string &cad, string prohib); //el problema estaba en que cad debe pasarse por referencia

int main(int argc, char *argv[]) {
	string frase, prohibida;
	cout<<"Introduce una frase: ";
	getline(cin,frase);
	cout<<"Introduce la palabra prohibida: ";
	getline(cin,prohibida);
	fraseProhibida(frase,prohibida);
	cout<<"La frase resultante es: "<<frase<<endl;
		
	
	return 0;
}
void fraseProhibida(string &cad, string prohib){
	
	string x="X";
	for(unsigned int i=1; i<prohib.length(); i++)
		x+="X";
	size_t ind=0; //  result of sizeof similar a un unsigned int
	while(ind += prohib.length()){ 
		ind=cad.find(prohib,ind);
		if(ind== string::npos) break;
		cad.erase(ind, prohib.length());
		cad.insert(ind,x);
	}
}

