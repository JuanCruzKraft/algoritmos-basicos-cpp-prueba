#include <iostream>
#include<iomanip>
using namespace std;
//muestra el porcentaje de vacunas aplicadas con respecto a las distribuidas
//y porcentaje personas vacunadas con esquema completo
//aplicaciones total= esq iniciado + esq completo + refuerzo+ cuarta
int main(int argc, char *argv[]) {
	 long vacAplicadas, dosisTotal, esqCompleto, esqIniciado;
	 double porcVacunadosEC, porcDosisApl;
	cout<<"Cantidad de vacunas aplicadas: ";
	cin>>vacAplicadas;
	cout<<"Cantidad de dosis distribuidas: ";
	cin>>dosisTotal;
	cout<<"Cantidad de vacunados con esquema iniciado: ";
	cin>>esqIniciado;
	cout<<"Cantidad de vacunados con esquema completo: ";
	cin>>esqCompleto;
	if(dosisTotal<esqCompleto || dosisTotal<vacAplicadas || dosisTotal<esqIniciado){
		cout<<"ERROR,el numero de vacunados no puede ser mayor que las dosis distribuidas"<<endl;
	} else{
		porcDosisApl=((double) vacAplicadas/(double)dosisTotal)*100.00;
		porcVacunadosEC=((double)esqCompleto/(double)esqIniciado)*100.00;
		cout<<fixed<<setprecision(2);
		cout<<" \n \nPorcentaje de dosis aplicadas respecto a distribuidas: "<<porcDosisApl<<"%"<<endl;
		cout<<"Porcentaje de vacunados con esquema completo: "<<porcVacunadosEC<<"%"<<endl;
	}
	return 0;
}

