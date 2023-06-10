/*
SE IMPLEMENTA UNA LISTA ENLAZADA SIMPLE, DONDE CADA NODO ALMACENA UN NUMERO ENTERO
EN LA LISTA PODEMOS AGREGAR ELEMENTOS POR SU INICIO, FINAL O POSICION ESPECIFICA
SE PERMITE ELIMINAR NODOS A TRAVES DEL VALOR ENTERO ALMACENADO
*/


#include <iostream>
using namespace std;

struct Nodo{
	int valor;
	Nodo* sig;
};

void menu();
void menuIns();
void insertarInicio(Nodo** inicio, int val);
void insertarFinal( Nodo** inicio, int val);
void insertarEn(Nodo* previo, int val);
bool borrarNodo(Nodo ** inicio, int val);
void printLista(Nodo* actual);


int main(int argc, char *argv[]) {
	Nodo* inicio = NULL;
	int op, op2,num;
	menu();
	cin>>op;
	while(op!=3){
		switch(op){
		case 1:
			cout<<"Ingrese un numero a agregar: ";
			cin>>num;
			menuIns();
			cin>>op2;
			switch(op2){
			case 1: //insertar al comienzo de la lista
				insertarInicio(&inicio, num);
				printLista(inicio);
				break;
			case 2: //insertar al final de la lista
				insertarFinal(&inicio, num); 
				printLista(inicio);
				break;
			case 3:{ //insertar en lugar especifico
				Nodo* temp=new Nodo;
				temp=inicio;
				int lugar;
				cout<<"En que posicion desea insertar. Comenzando a contar como 1 la primera posicion\n Insertar despues del elemento numero: ";
				cin>>lugar;
				lugar--;
				while(lugar!=0){
					temp=temp->sig;
					lugar--;
				}
				insertarEn(temp,num);
				printLista(inicio);
				delete temp;}
				break;
			default:
				cout<<"Opcion invalida"<<endl;
				break;
			}// fin switch anidado
			break;
		case 2: // borrar elementos de la lista
			if( inicio!=NULL){
				bool borra;
				cout<<"Ingrese un numero a borrar: ";
				cin>>num;
				borra = borrarNodo(&inicio, num);
				if(!borra) cout<<"Error. El numero no se encuentra en la lista"<<endl;
				else cout<<"Numero "<<num<<" borrado exitosamente."<<endl;
				printLista(inicio);
			}else
			   cout<<"La lista esta vacia. No hay elementos para borrar"<<endl;
			   
			
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
void insertarInicio(Nodo** inicio, int val){
	Nodo* nuevo= new Nodo;
	nuevo->valor= val;
	nuevo->sig=*inicio;
	*inicio=nuevo;
}
void insertarFinal( Nodo** inicio, int val){
	Nodo* nuevo= new Nodo;
	nuevo->valor=val;
	nuevo->sig=NULL;
	if((*inicio)==NULL){
		*inicio=nuevo;
		return;
	}
	Nodo * temporal=*inicio;
	while(temporal->sig!=NULL) 
		temporal=temporal->sig;
	temporal->sig=nuevo;
}
void insertarEn(Nodo* previo, int val){
	if(previo==NULL){
		cout << "Prevo no puede ser NULL" << endl;
		return;
	}
	Nodo* nuevo= new Nodo;
	nuevo->valor=val;
	nuevo->sig=previo->sig;
	previo->sig=nuevo;
}
bool borrarNodo(Nodo ** inicio, int val){
	Nodo *temporal= new Nodo;
	Nodo *actual= new Nodo;
	Nodo *anterior= new Nodo;
	if(val==(*inicio)->valor){
		*temporal=**inicio;
		*inicio=(*inicio)->sig;
		delete temporal;
		return true;
	}else{
		anterior=*inicio;
		actual=(*inicio)->sig;
		while((actual)!=NULL and (actual)->valor!=val){
			anterior=actual;
			actual=(actual)->sig;
		}
		if(actual!=NULL){
			temporal=actual;
			anterior->sig=actual->sig;
			delete temporal;
			return true;
		}
		return false;
	}
	delete actual;
	delete anterior;  
	return false;
}
void printLista(Nodo* actual){
	if(actual==NULL) cout<<"La lista esta vacia."<<endl;
	else{
		cout<<"La lista es: "<<endl;
		while(actual!=NULL){
			cout<<actual->valor<<" --> ";
			actual=actual->sig;
		}
		cout<<"NULL"<<endl;
	} // end else
}
void menu(){
	cout<<"\t1 para insertar un elemento en la lista"<<endl;
	cout<<"\t2 para borrar un elemento en la lista"<<endl;
	cout<<"\t3 para terminar"<<endl;
	cout<<"Ingrese su eleccion: ";
}
void menuIns(){
	cout<<"\t1 para insertar el elemento al comienzo de la lista"<<endl;
	cout<<"\t2 para insertar el elemento al final de la lista"<<endl;
	cout<<"\t3 para insertar el elemento en una posicion especifica"<<endl;
	cout<<"Ingrese su eleccion: ";
}
	
