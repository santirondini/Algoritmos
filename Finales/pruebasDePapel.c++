#include <iostream>
#include <math.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>


using namespace std;

int salarioMujeres(int salario)


struct Nodo {
    int info;
    Nodo*sgte=NULL;
};

Nodo* unionListas(Nodo*lista1, Nodo*lista2) {
    Nodo*listaUnion = NULL;
    Nodo*aux = lista1;
    while(aux && aux->sgte){
        aux = aux->sgte;
    }
    aux->sgte=lista2;
    listaUnion = lista1;
    return listaUnion;
}

void cargarLista(Nodo*& lista, int cantidad, int semillaExtra) {
    srand(time(0) + semillaExtra);
    for (int i = 0; i < cantidad; ++i) {
        int numero = rand() % 100; // Genera un número aleatorio entre 0 y 99
        Nodo* nuevo = new Nodo();
        nuevo->info = numero;
        nuevo->sgte = lista;
        lista = nuevo;
    }
}

void mostrarLista(Nodo* lista) {
    Nodo* aux = lista;
    while (aux && aux->sgte) {
        cout << aux->info << " | ";
        aux = aux->sgte;
    }
}

int main(){

    Nodo* lista1 = NULL;
    Nodo* lista2 = NULL;

    cargarLista(lista1, 5, 1);
    cargarLista(lista2, 5, 2);

    cout << "Lista 1: " << endl;
    mostrarLista(lista1);
    cout << endl;

    cout << "Lista 2: " << endl;
    mostrarLista(lista2);
    cout << endl;

    Nodo* listaUnion = unionListas(lista1, lista2);
    mostrarLista(listaUnion);



}