#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

struct Alumno{
    int nota;
    char nombre[30];
    Alumno*sgte = NULL;
};

Alumno* insertarOrdenado(Alumno*lista, Alumno valor){
    Nodo*nuevo = new Nodo();
    nuevo->info = valor;
    Nodo*aux = lista;
    Nodo*ant = NULL;

    while(aux && aux->info < valor){
        ant = aux;
        aux = aux->sgte;
    }

    if(ant){
        ant->sgte = nuevo;
    }else{
        lista = nuevo;
    }

    nuevo->sgte = aux;
    return lista;
}

void mostrarLista(Nodo*lista){
    Nodo*aux = lista;
    while(aux){
        cout << aux->info << " ";
        aux = aux->sgte;
    }
    cout << endl;
}

int main(){

    Nodo*lista = NULL;

    lista = insertarOrdenado(lista,5);
    lista = insertarOrdenado(lista,3);
    lista = insertarOrdenado(lista,7);
    lista = insertarOrdenado(lista,1);
    lista = insertarOrdenado(lista,9);

    mostrarLista(lista);
}


