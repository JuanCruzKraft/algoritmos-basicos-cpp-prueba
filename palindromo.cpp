/*
COMPRUEBA SI UNA PALABRA ES PALINDROMO O CAPICUA (case sensitive)
*/

#include <iostream>
#include <cctype>
using namespace std;
bool esPalindromo(string palabra){
	bool hayDistintas=false;
	int izq=0, der;
	der=palabra.size()-1;// sin el -1 me da out of range
	while(izq<der and not hayDistintas){
		if(palabra.at(izq)!=palabra.at(der)) hayDistintas=true;
		else{
			izq++;
			der--;
		}}
	return !hayDistintas;
}

int main(int argc, char *argv[]) {
	string s;
	getline(cin,s);
	cout<<"Palindromo? "<<boolalpha<<esPalindromo(s);
	return 0;
}

