#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;

struct Persona {
    char nombre[20];
    int edad;
    float altura;
};

struct Nodo{
    Persona info;
    Nodo*sgte=NULL; 
};

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void cargarPersona(Persona &p){

    cout << "Nombre: " << endl;
    fgets(p.nombre, 20, stdin);

    cout << "Edad: " << endl;
    cin >> p.edad;

    cout << "Altura: " << endl;
    cin >> p.altura;

    limpiarBuffer();
}

void agregarNodo(Nodo*&lista, Persona p){
    Nodo*nuevo = new Nodo;
    nuevo->info = p;
    nuevo->sgte = lista;
    lista = nuevo;
}

int main(){

    Nodo*lista = NULL; 
    Persona p;

    
    for(int i=0 ;i<3; i++){
        cargarPersona(p);
        agregarNodo(lista, p);
    }
}