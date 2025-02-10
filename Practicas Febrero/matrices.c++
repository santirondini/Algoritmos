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

void cargarMatriz(int matriz[][5]){
    srand(time(0));
    for(int i = 0; i < 5; i++){
        for (int j = 0;j<5;j++){
            matriz[i][j] = rand() % 20; 
        }
    }
}

void mostrarMatriz(int matriz[][5]){
    for(int i = 0; i<5;i++){
        for(int j=0;j<5;j++){
            cout << matriz[i][j] << "  "; 
        }
        cout << endl; 
    }
}

int diagonalPrincipal(int matriz[][5]) {
    int suma = 0;  
    for(int i = 0;i<5;i++){
        suma += matriz[i][i];
    }
    return suma; 
}

int diagonalConWhile(int matriz[][5]){
    int suma = 0;
    int i = 0;
    while(i < 5){
        suma += matriz[i][i];
        i++;
    }
    return suma;
}

int sumarTotalDeMatriz(int matriz[][5]){
    int suma = 0; 
    for(int i = 0;i<5;i++){
        for(int j = 0; j<5;j++){
            suma += matriz[i][j];
        }
    }
    return suma; 
}

int numeroMasGrande(int matriz[][5]){
    int masgrande = matriz[0][0];
    for(int i = 0; i < 5; i++){
        for (int j = 0; j<5;j++){
            if(masgrande < matriz[i][j])
            masgrande = matriz[i][j];
        }
    }
    return masgrande;
}

void ordenarLista(Nodo*&lista) {
    Nodo*aux1 = lista;
    Nodo*aux2 = lista;
    int temp; 

    while(aux1) {
        aux2 = aux1->sgte;
        while(aux2) {
            if(aux1->info > aux2->info){
                temp = aux1-> info;
                aux1->info = aux2->info;
                aux2->info = temp;
            }
            aux2 = aux2->sgte;
        }
        aux1 = aux1->sgte;
    }
    return; 
}

void agregar(int info, Nodo*&lista) {
    Nodo*nuevo = new Nodo();
    nuevo->info = info; 
    nuevo->sgte = lista;
    lista = nuevo;
}

Nodo*interseccion(Nodo*lista1, Nodo*lista2) {
    Nodo*listaInterseccion = NULL;
    Nodo*aux1 = lista1;
    Nodo*aux2 = lista2;

    while(aux1) {
        aux2 = lista2;
        while(aux2) {
            if(aux2->info == aux1->info){
                agregar(aux1->info,listaInterseccion);
                break;
            } 
            aux2 = aux2->sgte;
        }
        aux1 = aux1->sgte;
    }
    return listaInterseccion;
}

void llenarListaConRandom(Nodo*& lista) {
    int tamano = rand() % 6 + 5; // tamaño entre 5 y 10
    for (int i = 0; i < tamano; i++) {
        int numero = rand() % 15 + 1; // números entre 1 y 15
        agregar(numero, lista);
    }
}

int main(){

    int matriz[5][5];
    Nodo*lista1 = NULL;
    Nodo*lista2 = NULL;
    Nodo*listaInterseccion = NULL;

    /*
    srand(time(0));
    cargarMatriz(matriz);
    mostrarMatriz(matriz);

    cout << "La suma de la diagonal principal (usando for) es: " << diagonalPrincipal(matriz) << endl;     
    cout << "La suma de la diagonal principal (usando while) es: " << diagonalConWhile(matriz) << endl; 
    cout << "El numero mas grande de la matriz es: " << numeroMasGrande(matriz) << endl; 
    
    cout << endl;
    cout << endl;
    cout << endl;

    */

    cout << "Tema de listas" << endl;
    srand(time(0)); // Ensure different seed for each list
    llenarListaConRandom(lista1);
    srand(time(0) + 1); // Change seed for the second list
    llenarListaConRandom(lista2);

    cout << "Lista 1: " << endl;
    Nodo*aux = lista1;
    while(aux){
        cout << aux->info << " ";
        aux = aux->sgte;
    }

    cout << endl;

    cout << "Lista 2: " << endl;
    aux = lista2;
    while(aux){
        cout << aux->info << " ";
        aux = aux->sgte;
    }

    cout << endl;

    listaInterseccion = interseccion(lista1, lista2);

    cout << "Lista interseccion: " << endl;
    aux = listaInterseccion;
    while(aux){
        cout << aux->info << " ";
        aux = aux->sgte;
    }

    cout << endl; 

    cout << "Lista 1 ordenada: " << endl;
    ordenarLista(lista1);

    aux = lista1;
    while(aux){
        cout << aux->info << " ";
        aux = aux->sgte;
    }

    cout << endl;

    cout << "Lista 2 ordenada: " << endl;
    ordenarLista(lista2);

    aux = lista2;
    while(aux){
        cout << aux->info << " ";
        aux = aux->sgte;
    }

    cout << endl;

    return 0;
}