#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;

struct Nodo {
    int info;
    Nodo*sgte = NULL;
};

bool estaEnLista(Nodo*lista , int valor) {
    Nodo*aux = lista; 
    while(aux && aux->sgte){
        if(aux->info == valor){
            return true;
        }
        aux = aux->sgte;
    }
    return false; 
}

void agregar(Nodo*&lista,int valor){
    Nodo*nuevo = new Nodo();
    nuevo->info = valor;
    nuevo->sgte = lista;
    lista = nuevo;
}

void agregarSinRepetir(Nodo*&lista, int valor) {
    if(!estaEnLista(lista,valor)){
        agregar(lista,valor);
    }
}

Nodo* interseccion(Nodo*lista1, Nodo*lista2){
    Nodo*aux = lista1;
    Nodo*aux2 = lista2;
    Nodo*listaInterseccion = NULL; 

    while(aux){
        aux2 = lista2;
        while(aux2){
            if(aux->info == aux2->info){
                agregarSinRepetir(listaInterseccion,aux->info);
                break;
            }
            aux2 = aux2->sgte;
        }
        aux = aux->sgte;
    }
    return listaInterseccion;
}

void ordenarLista(Nodo*lista){
    int temp; 
    Nodo*aux1 = lista;
    Nodo*aux2 = lista;

    while(aux1){
        aux2 = aux1->sgte;
        while(aux2){
            if(aux1->info > aux2->info){
                temp = aux1->info;
                aux1->info = aux2->info;
                aux2->info = temp; 
            }
            aux2 = aux2->sgte;
        }
        aux1 = aux1->sgte;
    }
}



int main(){
    
}