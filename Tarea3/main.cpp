#include <iostream>
#include <stdlib.h>
using namespace std;
struct nodo{
 int numero;
 struct nodo *izquierda, *derecha;
};

typedef struct nodo *ArbolB;

ArbolB crearNodo(int a){
 ArbolB nuevoNodo = new(struct nodo);
 nuevoNodo->numero = a;
 nuevoNodo->izquierda = NULL;
 nuevoNodo->derecha = NULL;
 return nuevoNodo;
}
void insertar(ArbolB &arbol, int a){
 if(arbol==NULL){
        arbol = crearNodo(a);
 }else if(a < arbol->numero)
 insertar(arbol->izquierda, a);
 else if(a > arbol->numero)
 insertar(arbol->derecha, a);
}
void preOrden(ArbolB arbol)
{if(arbol!=NULL){
    cout << arbol->numero <<",";
    preOrden(arbol->izquierda);
    preOrden(arbol->derecha);
 }
}
void inOrden(ArbolB arbol){
 if(arbol!=NULL){
 inOrden(arbol->izquierda);
 cout << arbol->numero << ",";
 inOrden(arbol->derecha);
 }
}
void postOrden(ArbolB arbol){
 if(arbol!=NULL){
 postOrden(arbol->izquierda);
 postOrden(arbol->derecha);
 cout << arbol->numero << ",";
 }
}
int main(){
 ArbolB arbol = NULL; // creado Arbol
    insertar(arbol, 10);
    insertar(arbol, 2);
    insertar(arbol, 3);
    insertar(arbol, 25);
    insertar(arbol, 8);
    insertar(arbol, 36);
    insertar(arbol, 1);
    insertar(arbol, 15);
 cout<<"\nRecorridos del Arbol Binario: ";
 cout<<"\nIn orden: "; inOrden(arbol);
 cout<<"\nPre Orden: "; preOrden(arbol);
 cout<<"\nPost Orden: "; postOrden(arbol);
 cout<< endl << endl;
 system("pause");
 return 0;
}
