#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

/*El c�digo dado es un programa en C++ que implementa una estructura de datos de cola y pila utilizando listas enlazadas.
Tambi�n incluye algunas funciones adicionales como invertir la cola, verificar si la cola est� en orden ascendente,
fusionar dos colas, verificar si dos colas tienen los mismos datos, ingresar un nuevo dato a la cola en orden ascendente
y obtener los datos mayores a un valor espec�fico en una cola.*/

//estructura de los nodos de la cola
struct nodo{
	int dato;
	struct nodo *siguiente;
};

//estructura de cola
struct cola{
	nodo *delante;
	nodo *atras;
};

typedef nodo *ptrPila; 

void encolar(struct cola &q, int valor){
	struct nodo *aux = new(struct nodo);
	aux->dato = valor;
	aux->siguiente = NULL;
	if(q.delante == NULL){
		q.delante = aux; //encola el primer elemneto 
	}else{
		(q.atras)->siguiente = aux;
		
	}
	q.atras = aux;
}

int desencolar(struct cola &q){
	int num;
	struct nodo *aux;
	
	aux = q.delante;
	num = aux->dato;
	q.delante = (q.delante)->siguiente;
	delete(aux);
	
	return num; 
}

void muestraCola(struct cola q){
	struct nodo *aux;
	aux = q.delante;
	while(aux != NULL){
		cout<<" "<<aux->dato;
		aux = aux->siguiente;
	}
}

void vaciarCola(struct cola &q){
	struct nodo *aux;
	while(q.delante != NULL){
		aux= q.delante;
		q.delante = aux->siguiente;
		delete(aux);
	}
	
	q.delante = NULL;
	q.atras = NULL;
	
}

void push(ptrPila &p, int valor){

    ptrPila aux;
    aux = new(struct nodo);
    aux ->dato = valor;
    aux ->siguiente = p;
    p = aux;
}

void mostrarPila(ptrPila p){
    ptrPila aux;
    aux = p;

    while(aux != NULL){
        cout<<"\t"<<aux->dato<<endl;
        aux = aux->siguiente;
    }
}

int pop ( ptrPila &p){

    int num;
    ptrPila aux;

    aux = p;
    num = aux->dato;
    p = aux ->siguiente;
    delete(aux);
    return num;  
}

void invertirCola(struct cola &q){
	ptrPila aux2;
	aux2 = NULL;
	
	while(q.delante != NULL){
		int num = desencolar(q);
		push(aux2,num);
	}
	
	
	while(aux2 != NULL){
		int num2 = pop(aux2);
		encolar(q,num2);
	}
	
	muestraCola(q);
	
}

void ascendente(struct cola &q){
	bool orden = true;
	
	struct nodo *aux = q.delante->siguiente;
	int prev = q.delante->dato;
	
	while(aux != NULL){
		int num = aux->dato;
		if(prev > num){
			orden = false;
			break;
		}
		prev = num;
		aux = aux->siguiente;
	}
	
	if(orden){
		cout<<"cola en orden ascendente "<<endl;
		muestraCola(q);
	}else{
		cout<<"la cola no esta en orden ascendente"<<endl;
		muestraCola(q);
	}
}

void encolarDosColas(struct cola &q,int valor1,struct cola &q2,int valor2){
	struct nodo *aux = new(struct nodo);
	struct nodo *aux2 = new(struct nodo);
	aux->dato = valor1;
	aux->siguiente = NULL;
	aux2->dato = valor2;
	aux2->siguiente = NULL;
	
	if(q.delante == NULL){
		q.delante = aux; //encola el primer elemneto en la cola 1
	}else{
		(q.atras)->siguiente = aux;
		
	}
	q.atras = aux;
	
	if(q2.delante == NULL){
		q2.delante = aux2; //encola el primer elemneto en la cola 2
	}else{
		(q2.atras)->siguiente = aux2;
		
	}
	q2.atras = aux2;
	
	
}

void muestraDosCola(struct cola q,struct cola q2){
	struct nodo *aux;
	aux = q.delante;
	while(aux != NULL){
		cout<<" "<<aux->dato;
		aux = aux->siguiente;
	}
	
	cout<<endl<<endl;
	
	struct nodo *aux2;
	aux2 = q2.delante;
	while(aux2 != NULL){
		cout<<" "<<aux2->dato;
		aux2 = aux2->siguiente;
	}
}



void datosIguales(struct cola &q, struct cola &q2){
	bool orden = true;
	struct nodo *aux = q.delante;
	struct nodo *aux2 = q2.delante;
	int prev = aux->dato;
	int prev2 = aux2->dato;
	
	while(aux != NULL){
		
		if(prev == prev2){
			
		}else{
			orden= false;
			break;
		}
		aux = aux->siguiente;
		aux2 = aux2->siguiente;
		prev = aux->dato;
		prev2 = aux2->dato;
	}
	
	if(orden){
		cout<<"tiene los mismos datos";
	}else{
		cout<<"tiene distintos datos";
	}
}

void ingresarDato(struct cola &q, struct cola &q2,int valor){
	
	encolar(q2,valor);
	
	while(q.delante != NULL){
		int num = desencolar(q);
		encolar(q2,num);
	}
	q=q2;
}

void datosMayores(struct cola &q, struct cola &q2,struct cola &q3,int valor){
	struct nodo *aux = q.delante;
	
	while(aux != NULL){
		
		int num = aux->dato;
		
		if(num > valor){
			encolar(q2,num);
		}else{
			encolar(q3,num);
		}
		aux = aux->siguiente;
	}
	muestraDosCola(q2,q3);
	
}



