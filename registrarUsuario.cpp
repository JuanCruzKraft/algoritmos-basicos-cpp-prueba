/*
//PROBLEMA 2: DISEÑAR UNA FUNCION QUE PERMITA REGISTRAR UN NUEVO USUARIO AL SISTEMA.
//LOS IDENTIFICADORES DEBEN TENER 8 CARACTERES, COMENZAR CON UNA LETRA Y LOS RESTANTES PUEDEN SER LETRAS O NUMEROS
//LA FUNCION DEBE RECIBIR UNA CADENA Y COMPROBAR QUE LA MISMA SEA UN IDENTIFICADOR DE USUARIO VALIDO
*/

#include <iostream>
#include <cstring>
#include <ctype.h>
#define TL 100
using namespace std;

bool registrar(char[]);
int main(int argc, char *argv[]) {
	char username[TL];
	bool crear;
	cout<<"Ingrese un nombre de usuario \nDebe tener 8 caracteres y el primero ser una letra: ";
	cin.getline(username, TL);
	crear=registrar(username);
	if(crear) cout<<"Usuario creado con exito. "<<endl;
	else cout<<"Error al crear el usuario, verifique seguir con las condiciones"<<endl;
	return 0;
}
bool registrar( char user[TL]){

	if(strlen(user)!=8) return false;
	else{
		int i=0;
		while(i<8){
			if(isalnum(user[i])) i++;
			else return false;
		}
	}
	if(!isalpha(user[0])) return false;
	
	else return true;	
}

