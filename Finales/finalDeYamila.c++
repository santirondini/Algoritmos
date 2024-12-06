#include <iostream>
#include <math.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

// EJERCICIO 1

struct Nodo {
    int dato;
    Nodo* sgte = NULL;
};

Nodo* obtenerUltimo(Nodo* lista) {
    Nodo* aux = lista;
    while (aux && aux->sgte) {
        aux = aux->sgte;
    }
    return aux;
}

void ordenarLista(Nodo*&lista) {
    Nodo* aux = lista;
    Nodo* aux2 = lista;
    int temp;

    while (aux) {
        aux2 = aux->sgte;
        while (aux2) {
            if (aux->dato > aux2->dato) {
                temp = aux->dato;
                aux->dato = aux2->dato;
                aux2->dato = temp;
            }
            aux2 = aux2->sgte;
        }
        aux = aux->sgte;
    }
}

Nodo* interseccionDeListas(Nodo*&lista1, Nodo*&lista2) {
    Nodo*aux = NULL; 
    aux = obtenerUltimo(lista1);
    aux->sgte = lista2;
    return lista1;
}

Nodo* listaOrdenda(Nodo*&pila, Nodo*&lista) {
    
    Nodo* nuevaLista = interseccionDeListas(pila, lista);
    ordenarLista(nuevaLista);
    return nuevaLista;
}


void cargarValoresEnLista(Nodo*& lista, int semillaExtra ) {
    srand(time(0) + semillaExtra);
    for (int i = 0; i < 10; ++i) {
            int numero = rand() % 100; // Genera un número aleatorio entre 0 y 99
            Nodo* nuevo = new Nodo();
            nuevo->dato = numero;
            nuevo->sgte = lista;
            lista = nuevo;
        }
}

void mostrarLista(Nodo*lista){
    Nodo*aux=lista;
    while(aux){
        cout<<aux->dato<<" | ";
        aux=aux->sgte;
    }
    cout << endl; 
}

// EJERCICIO 2

struct Reserva {
    int codigoHotel;
    int cantReservas; 
    int diasDisponibles;
};


struct NodoReservas {
    int codigoHotel;
    int cantDiasReservados;
    NodoReservas*sgte = NULL; 
};


int posicionDeCodigo(int codigo, Reserva vector[]) {
    int i = 0;
    while(i < 50) {
        if(vector[i].codigoHotel == codigo){
            return i;
        }
        i++;
    }
    return -1;
}

void actualizarHotel(Reserva reservaDeVector, NodoReservas reserva){
    reservaDeVector.diasDisponibles =- reserva.cantDiasReservados;
    reservaDeVector.cantReservas++; 
}

void actualizarVector(Reserva vector[], NodoReservas*lista){
    NodoReservas*aux = lista;
    while(aux && aux->sgte) {
        int posicion = posicionDeCodigo(aux->codigoHotel,vector);
        actualizarHotel(vector[posicion],*aux);
        aux=aux->sgte;
    }
}

// EJERCICIO 3

struct Producto {
    int codigoProducto;
    int peso; 
    char tipo; 
    int cantidadEnStock; 
};

struct NodoProducto{
    Producto info;
    NodoProducto* sgte = NULL; 
};

void insertarOrdenadoEnLista(Producto producto, NodoProducto*&lista) {
    NodoProducto* nuevo = new NodoProducto();
    nuevo->info = producto;

    /*Si la lista esta vacia o el codigo del primer elemento es mayor al cual queremos insertar. Agrega primero*/
    if (lista == NULL || lista->info.codigoProducto >= producto.codigoProducto) {
        nuevo->sgte = lista;
        lista = nuevo;
    } else {
        /*Mientras el siguiente de la lista no sea NULL y ese codigo esa menor al cual queremos insertar, que se mueva el aux*/
        NodoProducto*aux = lista;
        while (aux->sgte != NULL && aux->sgte->info.codigoProducto < producto.codigoProducto) {
            aux = aux->sgte;
        }
        nuevo->sgte = aux->sgte;
        aux->sgte = nuevo;
    }
}


int main() {

    //EJERICIO 3

    FILE*archivo;
    Producto info;
    NodoProducto*lista = NULL; 

    archivo = fopen("STOCK.DAT", "rb+");

    fseek(archivo,0,SEEK_SET);

    while(fread(&info,sizeof(info),1,archivo)){
    insertarOrdenadoEnLista(info,lista);
    }

    fseek(archivo,0,SEEK_SET);

    fclose(archivo);

    archivo = fopen("STOCK.DAT", "wb+");

    while(lista) {
        fwrite(&lista->info,sizeof(Producto),1,archivo);
        lista = lista->sgte;
    }

    fclose(archivo);

    /*
    
    Ejercicio 1
    
    Nodo* pila = NULL;
    Nodo* lista = NULL;
    Nodo* nuevaLista = NULL;

    cargarValoresEnLista(pila, 5);
    cargarValoresEnLista(lista, 8);


    cout << "Pila: " << endl;
    mostrarLista(pila);
    
    cout << endl;

    cout << "Lista: " << endl;
    mostrarLista(lista);
    
    cout << endl;

    nuevaLista = listaOrdenda(pila, lista);
    cout << "Lista Interseccion Ordenada: " << endl;
    cout << endl; 
    mostrarLista(nuevaLista);
    
    */

   //Ejercicio 2

   NodoReservas*lista = NULL;
   Reserva vector[50];

   // EJERICICIO 3

}

