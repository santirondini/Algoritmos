#include <iostream>
#include <math.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;


struct Nodo{
    int info;
    Nodo*sgte=NULL;
};

void agregar(Nodo*&lista,int valor){
    Nodo*nuevo = new Nodo();
    nuevo->info = valor; 
    nuevo->sgte = lista;
    lista = nuevo;
}

Nodo* interseccion(Nodo* lista1, Nodo* lista2) {
    Nodo* listaInterseccion = NULL;
    Nodo* aux1 = lista1;
    Nodo* aux2 = lista2;

    while (aux1) {
        aux2 = lista2;
        while (aux2) {
            if (aux1->info == aux2->info) {
                agregar(listaInterseccion, aux1->info);
                break;
            }
            aux2 = aux2->sgte;
        }
        aux1 = aux1->sgte;
    }
    return listaInterseccion;
}

/*
Nodo* interseccionEntreDosListas(Nodo*lista1,Nodo*lista2) {

    Nodo*listaInterseccion = NULL;
    Nodo*aux1 = lista1;
    Nodo*aux2 = lista2;

    while(aux1) {
        aux2 = lista2;
        while(aux2) {
            if(aux1->info == aux2->info) {
                agregar(listaInterseccion, aux1->info);
                aux1 = aux1->sgte;
            }
            else{
                aux2 = aux2->sgte; 
            }
        
        }
        aux1 = aux1 ->sgte;
    }
    return listaInterseccion;
}
*/
void ordenarLista(Nodo*&lista){

    Nodo*aux1 = lista;
    Nodo*aux2 = lista;
    int temp; 

    while(aux1){
        aux2 = aux1->sgte;
        while(aux2){
            if (aux1->info > aux2->info) {
                temp = aux1->info;
                aux1->info = aux2->info;
                aux2->info = temp;
            }
            aux2 = aux2->sgte;
        }
        aux1 = aux1->sgte;
    }
}



Nodo* pasarDeVaL(int v[], int tam) {
    int t = 0;
    Nodo*lista = NULL;
    while(t<tam){
        agregar(lista,v[t]);
        t++;
    }
    return lista;
}

Nodo* unirListas(Nodo*L1, Nodo*L2) {
    Nodo*listaNuevo = NULL;
    Nodo*aux = NULL;
    aux = L1; 
    while(aux && aux->sgte){
        aux = aux->sgte;
    }
    aux->sgte = L2; 
    listaNuevo = L1;
    return listaNuevo;
}

Nodo* listaDeColaYVector(int vec[], int tam, Nodo*cola) {
    Nodo*listaNueva; 
    Nodo*listaDeVector = pasarDeVaL(vec,tam);
    listaNueva = unirListas(listaDeVector,cola);
    ordenarLista(listaNueva);
    return listaNueva;
}

// Funciones No-Parcial

void mostraLista(Nodo*lista){
    Nodo*aux = lista;
    while(aux){
        cout << aux->info << " |  ";
        aux = aux->sgte; 
    }
}

void cargarListaAleatoria(Nodo*& lista, int tam) {
    srand(time(0));
    for (int i = 0; i < tam; ++i) {
        int valor = rand() % 25; // Genera valores aleatorios entre 0 y 99
        agregar(lista, valor);
    }
}

void mostrarvector(int vec[], int tam) {
    for (int i = 0; i < tam; ++i) {
        cout << vec[i] << " | ";
    }
    cout << endl;
}

int main() {

    int vec[10] = {1,5,7,9,2,1,6,7,5,3};
    Nodo*lista1 = NULL;
    Nodo*lista2 = NULL;
    
    cargarListaAleatoria(lista1,10);

    cout << "LISTA 1 :" << endl;
    mostraLista(lista1);
    cout << endl;

    cargarListaAleatoria(lista2,5);

    cout << "LISTA 2 : " << endl;
    mostraLista(lista2);
    cout << endl;

    Nodo*lista3 = interseccion(lista1,lista2);

    mostraLista(lista3);


}