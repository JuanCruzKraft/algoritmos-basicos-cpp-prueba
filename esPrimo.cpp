#include <iostream>
#include <cmath>
using namespace std;

bool esPrimo(long num){
	bool hayDivisor=false;
	for(int i=2; i<=sqrt(num); i++)
		if(num%i==0) hayDivisor=true;
	if(!hayDivisor)
		return true;
	else
		return false;
}
int main(){
	long n;
	cout<<"Ingrese numeros positivos mayores a 1, o cualquier otro para finalizar: ";
	while(cin>>n && n>1){
	cout<<"Es Primo?: ";
	esPrimo(n)? cout<<"Si"<<endl : cout<<"No"<<endl;
	}
	return 0;
}
