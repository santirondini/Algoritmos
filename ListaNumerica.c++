#include <iostream>
#include <math.h>
#include <conio.h>

// compilar: Fn + F6

// compilar en otra terminal : Fn + F8


using namespace std;

struct Nodo{
    int dato;
    Nodo*sgte=NULL; 
};

// Verificación 

bool estaEnLista(int x, Nodo*lista){
    Nodo*aux = lista; 
    while(aux){
        if(aux->dato == x){
            return true;
        } else {
            aux = aux->sgte;
    }
    }
    return false; 
}

// Ordenamiento 

Nodo* ordenarLista(Nodo*lista){
    Nodo*aux=lista;
    Nodo*aux2=lista;
    int temp;
    
    while(aux){
        aux2=aux->sgte;
        while(aux2){
            if(aux->dato > aux2->dato){
                temp=aux->dato;
                aux->dato=aux2->dato;
                aux2->dato=temp;
            }
            aux2=aux2->sgte;
        }
        aux=aux->sgte;
    }
    return lista;
}


// Funciones de Obtención.

Nodo* obtenerUltimo(Nodo*lista){
    Nodo*aux=lista;
    while(aux && aux->sgte){
        aux=aux->sgte;
    }
    return aux;
}

Nodo* obtenerAnteultimo(Nodo*lista){
    Nodo*aux=lista;
    while(aux && aux->sgte && aux->sgte->sgte){
        aux=aux->sgte;
    }
    return aux;
}

// Agregar Numeros:

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

void agregarNumeroAlInicio(Nodo*&lista, int numero){
    Nodo*nuevo = new Nodo();
    nuevo->dato = numero;
    nuevo->sgte = lista;
    lista = nuevo;
}

// Sacar Numeros:

void sacarUltimo(Nodo*&lista){
    Nodo* aux = lista;
    if(aux && aux->sgte){
        aux = obtenerAnteultimo(lista);
        delete aux->sgte;
        aux->sgte = NULL;
    }
    else{
        delete aux;
        lista = NULL;
    }
}

void sacarPrimero(Nodo*&lista){
    Nodo*aux=lista->sgte; 
    lista=aux;
}


void sacar(int numero, Nodo*&lista){
    Nodo*aux=lista;
    Nodo*anterior=lista;
    
    if(!estaEnLista(numero,lista)){
        cout << "El numero no esta en la lista" << endl;
        return;
    }
    else{
    while(aux->dato != numero){
        anterior=aux;
        aux=aux->sgte;
    }
    anterior->sgte=aux->sgte;
    delete aux;
    }
}

// Funciones Para Mostrar

void mostrarLista(Nodo*lista){
    Nodo*aux=lista;
    while(aux){
        cout<<aux->dato<<" | ";
        aux=aux->sgte;
    }
    cout << endl; 
}

void mostrarPosicionDe(Nodo*lista,int numero){
    Nodo*aux=lista;
    int posicion = 0; 
       
    if(!estaEnLista(numero,lista)){
        cout << "El numero no esta en la lista" << endl;
        return;
    }
    
    while(aux->dato != numero){
        aux=aux->sgte;
        posicion++; 
    }

    cout << "La posicion del numero " << numero << " es: " << posicion << endl;
}


// Menú: 

void menu (){
    cout << "a - Agregar al final" << endl;
    cout << "b - Agregar al principio" << endl;
    cout << "c - Sacar ultimo" << endl;
    cout << "d - Sacar primero" << endl;
    cout << "e - Sacar un x" << endl;
    cout << "f - Mostrar Lista" << endl;
    cout << "g - Mostrar Posicion de un numero" << endl;
    cout << "h - Ordenar Lista" << endl;
    cout << "Esc - Salir" << endl;
}

int main()
{
    Nodo*lista=NULL;
    char op;
    int x; 
    do {
        menu(); 
        do {
            op = getch();
        } while (op != 'a' && op != 'b' && op != 'c' && op != 'd' && op != 'e' && op != 'f' && op != 'g' && op != 'h' && op != 27);

        switch (op){

            case 'a': 
            cout << "Ingrese el numero" << endl;
            cin >> x; 
            agregarNumeroFinal(lista,x);
            break; 
            
            case 'b':
            cout << "Ingrese el numero" << endl;
            cin >> x; 
            agregarNumeroAlInicio(lista,x);
            break;

            case 'c':
            sacarUltimo(lista);
            break;

            case 'd':
            sacarPrimero(lista);
            break;

            case 'e':
            cout << "Ingrese el numero" << endl;
            cin >> x;
            sacar(x,lista);
            break;

            case 'f': 
            mostrarLista(lista);
            break; 

            case 'g':
            cout << "Ingrese el numero" << endl;
            cin >> x; 
            mostrarPosicionDe(lista,x);

            case 'h':
            lista = ordenarLista(lista);
            cout << "Lista ordeanda" << endl; 
            break;
        } 
    cout << "Presione cualquier tecla para continuar" << endl;
    getch();
    system("cls");   
    } while (op != 27);
}
