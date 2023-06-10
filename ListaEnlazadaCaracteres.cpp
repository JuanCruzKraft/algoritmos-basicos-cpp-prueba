/*
LISTA ENLAZADA SIMPLE CUYOS NODOS ALMACENAN CARACTERES,
A MEDIDA QUE SE VAN INSERTANDO SE ORDENAN AUTOMATICAMENTE (ASCII)
PERMITE ELIMINACIONES POR CARACTER.
*/
#include <iostream>
using namespace std;

struct NodoLista{
	char info;
	NodoLista *sig;
};
typedef NodoLista * NodoListaPtr;

void insertar( NodoListaPtr *sPtr, char valor);
char borrar (NodoListaPtr *sPtr, char valor);
int vacia (NodoListaPtr sPtr);
void printLista(NodoListaPtr actual);
void menu();

int main() {
	NodoListaPtr startPtr = NULL;		
	int op;
	char item;
	menu();
	cin>>op;
	while(op!=3){
		switch(op){
		case 1:
			cout<<"Ingrese un caracter: ";
			cin>>item;
			insertar(&startPtr, item);
			printLista(startPtr);
			break;
		case 2:
			if(!vacia(startPtr)){
				cout<<"Ingrese caracter a ser borrado: ";
				cin>>item;
				
				if(borrar(&startPtr, item)){
					cout<<item<<" borrado"<<endl;
					printLista(startPtr);
				}else{
					cout<<item<<" no encontrado"<<endl;
				}
			}
			else
					  cout<<"Lista Vacia"<<endl;
			break;
		default:
			cout<<"Opcion invalida"<<endl;
			break;
		} //end switch
		menu();
		cin>>op;
		system("cls");
	}//end while
	cout<<"Fin del programa"<<endl;
	system("pause>0");
	return 0;
}

void menu(){

	cout<<"\t1 para insertar un elemento en la lista"<<endl;
	cout<<"\t2 para borrar un elemento en la lista"<<endl;
	cout<<"\t3 para terminar"<<endl;
	cout<<"Ingrese su eleccion: ";
}
void insertar( NodoListaPtr *sPtr, char valor){
	NodoListaPtr nuevo, anterior, actual;
	nuevo= new NodoLista;
	if(nuevo!=NULL){
		nuevo->info=valor;
		nuevo->sig=NULL;
		
		anterior=NULL;
		actual= *sPtr;
		//busca la posicion correcta en la lista
		while(actual!=NULL and valor>actual->info){
			anterior=actual;
			actual=actual->sig;
		}
		//inserta nuevo al comienzo de la lista
		if(anterior==NULL){
			nuevo->sig=*sPtr;
			*sPtr=nuevo; //ahora la lista comiena en el nuevo nodo insertado
		}else{ //inserta entre el anterior y el actual
			anterior->sig=nuevo;
			nuevo->sig=actual;
		}
	}else{
		cout<<valor<<" no insertado. No hay memoria disponible"<<endl;
	}
}
	
char borrar (NodoListaPtr *sPtr, char valor){
	NodoListaPtr anterior, actual, tempPtr;
	//borra el primer nodo
	if(valor==(*sPtr)->info){
		tempPtr=*sPtr;
		*sPtr=(*sPtr)->sig;//desengancha el primer nodo
		delete tempPtr;
		return valor;
	}else{
		anterior=*sPtr;
		actual=(*sPtr)->sig;
		//ciclo para encontrar la posicion correcta en la lista
		while(actual!=NULL and actual->info != valor){
			anterior=actual;
			actual=actual->sig;
		}
		//borra el nodo en actual
		if(actual !=NULL){
			tempPtr=actual;
			anterior->sig=actual->sig;
			delete tempPtr;
			return valor;
		}
	}//endl else
	return '\0';
}

int vacia (NodoListaPtr sPtr){
	return sPtr==NULL; //Solo analiza si el puntero a la lista es nulo
}

void printLista(NodoListaPtr actual){
	if(actual==NULL) cout<<"La lista esta vacia."<<endl;
	else{
		cout<<"La lista es: "<<endl;
		while(actual!=NULL){
			cout<<actual->info<<" --> ";
			actual=actual->sig;
		}
		cout<<"NULL"<<endl;
	} // end else
}

