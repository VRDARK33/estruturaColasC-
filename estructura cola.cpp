#include<iostream>
#include<stdlib.h>
#include "colas.h"
using namespace std;

/*El c�digo es un programa en C++ que utiliza estructuras de colas para realizar diversas operaciones. 
La funci�n principal del programa es un men� que permite al usuario elegir entre varias opciones para manipular la cola. 
Estas opciones incluyen encolar y desencolar elementos de la cola, mostrar la cola, vaciar la cola, invertir la cola, 
verificar si dos colas son iguales, encolar elementos en dos colas diferentes, mostrar las dos colas, 
ingresar un dato en una posici�n espec�fica de la cola y encontrar los elementos mayores que un n�mero espec�fico en una cola y 
los dem�s elementos en otra cola.

La implementaci�n de la cola se realiza mediante una estructura que tiene dos punteros: delante y atras. 
Estos punteros apuntan al primer y �ltimo elemento de la cola, respectivamente. 
Adem�s, se utiliza un puntero a una pila para almacenar temporalmente los elementos de la cola en caso de que sea necesario realizar operaciones en la cola.

La funci�n "encolar" permite agregar un elemento al final de la cola, mientras que la funci�n "desencolar" elimina el primer elemento de la cola
y lo devuelve. La funci�n "muestraCola" muestra todos los elementos de la cola en orden de encolado,
y la funci�n "vaciarCola" elimina todos los elementos de la cola.

La funci�n "invertirCola" invierte el orden de los elementos de la cola, 
lo que se logra mediante el uso de una pila temporal. 
La funci�n "ascendente" verifica si los elementos de la cola est�n en orden ascendente y devuelve un mensaje indicando si es as� o no.

La funci�n "encolarDosColas" agrega elementos a dos colas diferentes, 
mientras que la funci�n "muestraDosCola" muestra los elementos de ambas colas en orden de encolado. 
La funci�n "datosIguales" verifica si dos colas tienen los mismos elementos en el mismo orden y devuelve un mensaje indicando si es as� o no.

La funci�n "ingresarDato" permite al usuario agregar un elemento en una posici�n espec�fica de la cola,
 lo que se logra mediante el uso de una pila temporal.

Por �ltimo, la funci�n "datosMayores" encuentra los elementos mayores que un n�mero espec�fico en una cola y los almacena en una cola diferente,
 mientras que los dem�s elementos se almacenan en otra cola.*/

void menu(){
	cout<<"estructuras de colas en C++\n\n";
	cout<<"1. encolar "<<endl;
	cout<<"2. desencolar "<<endl;
	cout<<"3. mostrar cola"<<endl;
	cout<<"4. vaciar cola"<<endl;
	cout<<"5. invertir"<<endl;
	cout<<"6. ascendente "<<endl;
	cout<<"7. encolar en dos pilas"<<endl;
	cout<<"8. mostras las dos colas"<<endl;
	cout<<"9. verificar si C1 y C2 son iguales"<<endl;
	cout<<"10. ingresar dato en pos"<<endl;
	cout<<"11. C1 mayores que X, C2 otros datos "<<endl;
	cout<<"12. salir "<<endl;
	
	cout<<"ingrese la opcion: ";
	
}

int main(){
	struct cola q;
	struct cola q2;
	struct cola q3;
	q2.delante = NULL;
	q2.atras = NULL;
	q3.delante = NULL;
	q3.atras = NULL;
	q.delante = NULL;
	q.atras = NULL;
	ptrPila p = NULL;
	int n; // numero a encolar
	int n2;
	int op;  // opcion del menu
	int x;  // numero que decuelve la funcion pop
	
	
	do{
		menu(); cin>>op;
		switch(op){
			case 1:
				cout<<"\n numero a encolar: "; cin>>n;
				encolar(q,n);
				cout<<"\n\n\t\tnumero "<<n<<" encolado\n\n";
				break;
				
			case 2:
				x = desencolar(q);
				cout<<"\n\n\t\tnumero "<<x<<" desencolado ";
				break;
				
			case 3:
				cout<<"\n\n mostrando cola"<<endl;
				if(q.delante != NULL){
					muestraCola(q);
				}else{
					cout<<"\n\n cola vacia"<<endl;
				}
				break;
				
			case 4:
				vaciarCola(q);
				cout<<"\n\n\t\t hecho \n\n"<<endl;
				break; 
			
			case 5:
				cout<<"\n\n\t\t cola invertida \n\n"<<endl;
				invertirCola(q);
				break;
				
			case 6:
				cout<<"\n\n\t\t verificacion de ascendencia \n\n"<<endl;
				ascendente(q);
				break;
			
			case 7:
				cout<<"\n numero a encolar de la cola 1: "; cin>>n;
				cout<<endl;
				cout<<"\n numero a encolar de la cola 2: "; cin>>n2;
				encolarDosColas(q,n,q2,n2);
				cout<<"\n\n\t\tnumero "<<n<<" y "<<n2<<" encolados\n\n";
				break;
			
			case 8:
				cout<<"\n\n mostrando cola"<<endl;
				if((q.delante != NULL)&&(q2.delante != NULL)){
					muestraDosCola(q,q2);
				}else{
					cout<<"\n\n cola vacia"<<endl;
				}
				break;	
				
			case 9:
				cout<<"\n\n\t\t verificar \n\n"<<endl;
				datosIguales(q,q2);
				break;
				
			case 10:
				cout<<"\n numero a encolar: "; cin>>n;
				ingresarDato(q,q2,n);
				cout<<"\n\n\t\tnumero "<<n<<" encolado en la posicion pos\n\n";
				break;
				
			case 11: 
			cout<<"\n\n\t\t resultados \n\n"<<endl;
			cout<<"\n numero X: "; cin>>n;
			datosMayores(q,q2,q3,n);
			
				
		}
		cout<<endl<<endl;
		system("pause"); system("cls");
	}while(op != 12);
}


