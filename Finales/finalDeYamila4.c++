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

bool existeEnLista(Nodo* lista, int valor) {
    Nodo* aux = lista;
    while (aux) {
        if (aux->info == valor) {
            return true;
        }
        aux = aux->sgte;
    }
    return false;
}

void agregarSinRepetir(Nodo*& lista, int valor) {
    
    if (!existeEnLista(lista, valor)) {
        agregar(lista, valor);
    }
}

Nodo* interseccion2(Nodo* lista1, Nodo* lista2) {
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


Nodo* interseccion1(Nodo* lista1, Nodo* lista2) {
    Nodo* listaInterseccion = NULL;
    Nodo* aux1 = lista1;
    Nodo* aux2 = lista2;

    while (aux1) {
        aux2 = lista2;
        while (aux2) {
            if (aux1->info == aux2->info) {
                agregarSinRepetir(listaInterseccion, aux1->info);
                break;
            }
            aux2 = aux2->sgte;
        }
        aux1 = aux1->sgte;
    }
    return listaInterseccion;
}

struct Alumno {
    int nota;
    char nombre[30];
    int legajo;
};

struct NodoAlumno {
    Alumno info;
    NodoAlumno* sgte = NULL;
};


void ordenarListaAlumnosPorLegajo(NodoAlumno*&lista){

    NodoAlumno*aux1 = lista;
    NodoAlumno*aux2 = lista;
    Alumno temp; 

    while(aux1){
        aux2 = aux1->sgte;
        while(aux2){
            if (aux1->info.legajo > aux2->info.legajo) {
                temp = aux1->info;
                aux1->info = aux2->info;
                aux2->info = temp;
            }
            aux2 = aux2->sgte;
        }
        aux1 = aux1->sgte;
    }
}



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

Nodo* pasarDeVectorALista(int vec[], int tam) {
    Nodo*lista = NULL;
    for (int i = 0; i < tam; ++i) {
        agregar(lista, vec[i]);
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
        int valor = rand() % 12; // Genera valores aleatorios entre 0 y 99
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
    
    cout << "LISTA 1 :" << endl;
    cargarListaAleatoria(lista1,9);
    mostraLista(lista1);
    cout << endl;

    cout << "LISTA 2 : " << endl;
    cargarListaAleatoria(lista2,7);
    mostraLista(lista2);
    cout << endl;

    cout << "INTERSECCION ENTRE 1 Y 2 SIN REPETIR" << endl;
    Nodo*lista3 = interseccion1(lista1,lista2);
    mostraLista(lista3);
    cout << endl;

    
    cout << "INTERSECCION ENTRE 1 Y 2 REPETIENDO" << endl;
    Nodo*lista4 = interseccion2(lista1,lista2);
    mostraLista(lista4);
    cout << endl;

    cout << "VECTOR :" << endl;
    pasarDeVectorALista(vec,10);
    mostraLista();
}
