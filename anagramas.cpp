/*
COMPRUEBA SI DOS PALABRAS SON ANAGRAMAS
NO ES SENSIBLE A MAYUSCULAS Y MINUSCULAS
*/

#include <iostream>
#include <string>
using namespace std;

bool compruebaAnagrama(string , string);

int main(int argc, char *argv[]) {
	string palabraA, palabraB;
	bool anagrama;
	cout<<"ingrese la primer palabra: ";
	cin>>palabraA;
	cout<<"ingrese la segunda palabra: ";
	cin>>palabraB;
	anagrama=compruebaAnagrama(palabraA,palabraB);
	if(anagrama) cout<<"Las palabras \""<<palabraA<<"\" y \""<<palabraB<<"\" son anagramas"<<endl;
	else cout<<"Las palabras \""<<palabraA<<"\" y \""<<palabraB<<"\" NO son anagramas"<<endl;
	return 0;
}

bool compruebaAnagrama(string cad1, string cad2){
	//si las cadenas tienen distinta longitud de palabra, descartamos que son anagramas. return FALSE
	if(cad1.length() != cad2.length()) return false; 
	else {
		bool cond1=true, cond2=true;
		//pasamos todas las letras de las cadenas a minusculas.
		for(unsigned int k=0; k<cad1.length(); k++){
			cad1.at(k)=tolower(cad1.at(k));
			cad2.at(k)=tolower(cad2.at(k));
		}
		//comprobar que las letras de la primer cadena se encuentren en la segunda
		for(unsigned int i=0; i<cad1.length(); i++)
			if(cad2.find(cad1.at(i)) == string::npos) cond1=false;
		//comprobar que las letras de la segunda cadena se encuentren en la primera
		for(unsigned int j=0; j<cad2.length(); j++)
			if(cad1.find(cad2.at(j)) == string::npos) cond2=false;
		//SI las letras de la primer cadena estan en la segunda, y viceversa, retorna TRUE
		if(cond1&&cond2) return true;
		//si no se cumple una (o ninguna) de las condiciones, no son anagramas
		else return false;
	}	
}
	
