#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;

struct Nodo{
    int dato;
    Nodo*sgte=NULL; 
};

Nodo* obtenerUltimo(Nodo*lista){
    Nodo*aux=lista;
    while(aux && aux->sgte){
        aux=aux->sgte;
    }
    return aux;
}

void agregarNumeroFinal(Nodo*&lista, int numero){
    Nodo*nuevo = new Nodo();
    nuevo->dato = numero;
    nuevo->sgte = NULL;
    if(lista != NULL){
        Nodo*aux = obtenerUltimo(lista);
        aux->sgte = nuevo;
    }
    else{
        lista = nuevo;
    }
}

void mostrarLista(Nodo*lista){
    Nodo*aux=lista;
    while(aux){
        cout<<aux->dato<<" | ";
        aux=aux->sgte;
    }
}


int main()
{
    Nodo*lista=NULL;
    agregarNumeroFinal(lista, 1);   
    agregarNumeroFinal(lista, 2);
    agregarNumeroFinal(lista, 3);
    agregarNumeroFinal(lista, 4);
    agregarNumeroFinal(lista, 5);
    mostrarLista(lista);

}
