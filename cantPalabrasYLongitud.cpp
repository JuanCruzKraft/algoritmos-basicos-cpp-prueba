/*
//PROBLEMA 5
//DADA LA CADENA DE CARACTERES INDICA EL NUMERO TOTAL DE CARACTERES Y CANTIDAD PALABRAS QUE LA CONFORMAN
*/

#include <iostream>
#include <cstring>
#include <ctype.h>
#define TL 1000
using namespace std;
void cantidadPalabras(char[], int&, int&);

int main(int argc, char *argv[]) {
	char cadena[TL];
	int tam, cont=1;
	cout<<"Ingrese una frase: ";
	cin.getline(cadena, TL);
	cantidadPalabras(cadena, tam, cont);
	cout<<"Numero total de caracteres: "<<tam<<"\nCantidad de palabras: "<<cont<<endl;
	return 0;
}
void cantidadPalabras(char frase[], int& tam, int& cont){
	tam = strlen(frase);
	int i=0;
	while(i<tam){
		if(isblank(frase[i])) cont++;
		i++;
	}
}
