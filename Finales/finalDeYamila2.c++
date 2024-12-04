#include <iostream>
#include <math.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Nodo {
    int info; 
    Nodo*sgte = NULL; 
};

Nodo* obtenerUltimo(Nodo*lista){
    Nodo*aux = lista;
    while(aux && aux->sgte){
        aux = aux->sgte;
    }
    return aux;
}

void mostrarLista(Nodo*lista) {
    Nodo*aux = lista;
    while(aux){
        cout << aux->info << " | ";
        aux = aux->sgte;
    }
}

// Memorizar el ordenar lista

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

Nodo*listaOrdenada(Nodo*pila,Nodo*cola){
    Nodo*aux = cola;
    Nodo*nuevaLista = NULL;
    aux = obtenerUltimo(cola);
    aux->sgte = pila; 
    nuevaLista = cola;
    ordenarLista(nuevaLista);
    return nuevaLista;
}


struct Nota {

    int legajo;
    int nota1parcial;
    int nota2parcial;
};

struct NodoNota {

    int legajo;
    int notaRecu2parcial;
    NodoNota* sgte = NULL;
};

int buscarAlumno(Nota vector[], int legajoAbuscar) {
    int i = 0;
    while(i < 1500 && vector[i].legajo != legajoAbuscar){
        i++;
    }
    return i; 
}

void actualizarAlumno(Nota alumno, NodoNota*lista){

    if(lista->notaRecu2parcial >= 6){
        alumno.nota2parcial = lista->notaRecu2parcial;
        return;
    } else{
        return;   
    }
}

void actualizarVector(Nota vector[], NodoNota*lista){

    NodoNota*aux = lista;
    while(aux && aux->sgte) {
        int posicion = buscarAlumno(vector,aux->legajo);
        actualizarAlumno(vector[posicion],aux);
        aux = aux->sgte;
    }
}

void agregarNumero(Nodo*&lista,int numero){
    Nodo*nuevo = new Nodo();
    nuevo->info = numero; 
    nuevo->sgte = lista;
    lista = nuevo; 

}

void cargarVector(Nota vector[]){
    srand(time(0));
    for (int i = 0; i < 15; ++i) {
        vector[i].legajo = rand() % 100;
        vector[i].nota1parcial = rand() % 10;
        vector[i].nota2parcial = rand() % 10;
    }   
}

void cargarLista(NodoNota*&lista){
    srand(time(0));
    for (int i = 0; i < 15; ++i) {
        NodoNota*nuevo = new NodoNota();
        nuevo->legajo = rand() % 100;
        nuevo->notaRecu2parcial = rand() % 10;
        nuevo->sgte = lista;
        lista = nuevo;
    }
}

void mostraVector(Nota vector[]){
    for (int i = 0; i < 15; ++i) {
        cout << "Legajo: " << vector[i].legajo << " | Nota 1er Parcial: " << vector[i].nota1parcial << " | Nota 2do Parcial: " << vector[i].nota2parcial << endl;
    }
}

void mostrarListaDeNotas(NodoNota*lista){
    NodoNota*aux = lista;
    while(aux){
        cout << "Legajo: " << aux->legajo << " | Nota Recuperatorio 2do Parcial: " << aux->notaRecu2parcial << endl;
        aux = aux->sgte;
    }
}

int main() {

    Nota vector[15]; // debe ser 1500
    NodoNota* lista = NULL;

    cargarVector(vector);
    
    cout << "VECTOR : " << endl;
    mostraVector(vector);

    cout << endl;

    cargarLista(lista);

    cout << "LISTA : " << endl;
    mostrarListaDeNotas(lista);

    cout << endl;

    actualizarVector(vector,lista);

    cout << "VECTOR ACTUALIZADO : " << endl;
    mostraVector(vector);



  /*  Nodo*lista1 = NULL;
    Nodo*lista2 = NULL;

    agregarNumero(lista1,8);
    agregarNumero(lista1,6);
    agregarNumero(lista1,4);
    agregarNumero(lista1,125);
    agregarNumero(lista1,844);

    mostrarLista(lista1);
    cout << endl;


    agregarNumero(lista2,96);
    agregarNumero(lista2,177);
    agregarNumero(lista2,86);
    agregarNumero(lista2,977);
    agregarNumero(lista2,101);
    
    mostrarLista(lista2);
    cout << endl;
    
    mostrarLista(listaOrdenada(lista1,lista2));
*/


}