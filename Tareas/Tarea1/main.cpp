#include <iostream>
#include <conio.h>
#define maxchar 100

using namespace std;

//Se crea un nodo de tipo struct para manejar distintos tipos de datos
struct Nodo{
    int carnet;
    char nombre[maxchar];
    struct Nodo *siguiente;
};
typedef struct Nodo *Lista;
Lista lista=NULL;
//Se crean las funciones vacias
void menu();
void insertar(Lista &);
void buscar(Lista &);
void eliminar(Lista &);

int main()
{
    menu();
    return 0;
}
//Menu de opciones-----------------------------------------
void menu(){
    int op;
    do{
        cout<<"\tRegistro de estudiantes\n";
        cout<<"1. Registrar un nuevo estudiante\n";
        cout<<"2. Buscar registro de estudiante\n";
        cout<<"3. Eliminar registro de estudiante\n";
        cout<<"4. Salir\n";
        cout<<"Ingrese una opcion: ";
        cin>>op;

        switch(op){
        case 1: insertar(lista);
                break;
        case 2: if(lista==NULL){
                        cout<<"\nNo hay registros en el sistema\n";
                }else{
                        buscar(lista);
                }
                system("pause");
                break;
        case 3: if(lista==NULL){
                        cout<<"\nNo hay registros en el sistema\n";
                }else {
                        eliminar(lista);
                }
                system("pause");
                break;
        }
        system("cls");
    }while(op !=4);
    cout<<"\nAbandonando el programa...\n";
}
//Insertar elementos en la lista--------------------------
void insertar(Lista &lista){
    Lista aux2,aux = new(struct Nodo);
    cout<<"\n- Registro de estudiante...\n";
    cout<<"\nDatos del estudiante: ";
    cout<<"\n\nCarnet: ";
    cin>>aux->carnet;
    cin.ignore();cout<<"\nNombre: "; //Se ignora (extrae y descarta) cualquier valor que no queremos segun el puntero
    cin.getline(aux->nombre, maxchar);
    system("cls");
    aux->siguiente = NULL;
    if(lista==NULL){
        lista = aux; //Toma la posicion del aux si es nula la siguiente
    }else {
        aux2 = lista;
        while(aux2->siguiente!=NULL){
                aux2 = aux2->siguiente;
        }
        aux2->siguiente = aux;
    }
    cout<<"\nSe ha registrado correctamente al estudiante...";
    cout<<"\n";
    system("pause");
}
//Buscar registro------------------------------------------
void buscar(Lista &lista){
    bool verif = false;
    int carn;
    Lista aux;
    aux=lista;
    cout<<"\n-Buscar registro...";
    cout<<"\nIngrese el numero de carnet a buscar: ";
    cin>>carn;
    //Se verifica si el registro realmente existe en la lista, segun la posicion del puntero
    while((aux!=NULL) && aux->carnet<=carn){
        if(aux->carnet == carn){
            verif = true;
        }
        aux = aux->siguiente;
    }
    if(verif == true){
        cout<<"\nEl estudiante con el carnet: "<<carn<<" se encuentra registrado en el sistema.\n";
    }
    else{
        cout<<"\nEl carnet: "<<carn<<" NO se encuentra en el registro.\n";
    }
}
//Eliminar registro----------------------------------------------
void eliminar(Lista &lista){
    int carn;
    Lista aux,aux2;
    aux=lista;
    cout<<"\n-Eliminar registro...";
    cout<<"\nIngrese el numero de carnet: ";
    cin>>carn;
    //Se verifica si el registro realmente existe en la lista, segun la posicion del puntero
    while((aux!=NULL) && aux->carnet<=carn){
            if(aux->carnet==carn){
                if(aux==lista)
                    lista=lista->siguiente;
                else
                    aux2->siguiente=aux->siguiente;
                //Borra el registro si es seleccionado por el puntero
                delete(aux);
                cout<<"\nEl registro ha sido eliminado\n";
                return;
            }else {
                aux2=aux;
                aux=aux->siguiente;
        }
    }
    if(aux==NULL)
        cout<<"\nEl registro no existe\n\n";
}
