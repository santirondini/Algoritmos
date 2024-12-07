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

// Funciones Generadoras

void cargarVectorConLegajosDistintos(Nota vector[], int tam) {
    srand(time(0));
    bool legajoRepetido;
    for (int i = 0; i < tam; ++i) {
        do {
            legajoRepetido = false;
            vector[i].legajo = rand() % 10 + 1; // Genera legajos entre 1 y 10
            for (int j = 0; j < i; ++j) {
                if (vector[i].legajo == vector[j].legajo) {
                    legajoRepetido = true;
                    break;
                }
            }
        } while (legajoRepetido);
        vector[i].nota1parcial = rand() % 10;
        vector[i].nota2parcial = rand() % 10;
    }
}

void mostraVector(Nota vector[]){
    for (int i = 0; i < 7; ++i) {
        cout << "Legajo: " << vector[i].legajo << " | Nota 1er Parcial: " << vector[i].nota1parcial << " | Nota 2do Parcial: " << vector[i].nota2parcial << endl;
    }
}

void mostrarListaNota(NodoNota* lista) {
    NodoNota* aux = lista;
    while (aux) {
        cout << "Legajo: " << aux->legajo << " | Nota Recuperatorio 2do Parcial: " << aux->notaRecu2parcial << endl;
        aux = aux->sgte;
    }
}

void crearListaNota(NodoNota*& lista) {
    srand(time(0));
    bool legajoRepetido;
    for (int i = 0; i < 7; ++i) {
        NodoNota* nuevo = new NodoNota();
        do {
            legajoRepetido = false;
            nuevo->legajo = rand() % 10 + 1; // Genera legajos entre 1 y 10
            NodoNota* aux = lista;
            while (aux) {
                if (aux->legajo == nuevo->legajo) {
                    legajoRepetido = true;
                    break;
                }
                aux = aux->sgte;
            }
        } while (legajoRepetido);
        nuevo->notaRecu2parcial = rand() % 10;
        nuevo->sgte = lista;
        lista = nuevo;
    }
}

//FUNCIONES DEL EJERCICIO -------------------------

int buscarAlumno(Nota vector[], int legajoAbuscar) {
    int i = 0;
    while(i < 7 && vector[i].legajo != legajoAbuscar){
        i++;
    }
    return i; // retorna la posición del vector donde se encuentra el alumno con ese legajo  
}

// clave poner el &

void actualizarAlumno(Nota &alumno, NodoNota*lista){

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


//------------------------


void agregarNumero(Nodo*&lista,int numero){
    Nodo*nuevo = new Nodo();
    nuevo->info = numero; 
    nuevo->sgte = lista;
    lista = nuevo; 

}

int main() {

    Nota vector[7]; // debe ser 1500
    NodoNota* lista = NULL;

    cargarVectorConLegajosDistintos(vector,7);
    
    cout << "VECTOR : " << endl;
    mostraVector(vector);
    cout << endl;

    cout << "LISTA : " << endl;
    crearListaNota(lista);
    mostrarListaNota(lista);
    cout << endl;

    cout << "VECTOR ACTUALIZADO :" << endl;
    actualizarVector(vector,lista);
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