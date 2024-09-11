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

void agregarNodo(Nodo*&lista, Persona p, FILE*archivo){
    
    Nodo*nuevo = new Nodo;
    nuevo->info = p;
    nuevo->sgte = lista;
    lista = nuevo;

    fwrite(&p, sizeof(Nodo), 1, archivo);
}

void mostrarLista(FILE*archivo){
    Persona p;
    fseek(archivo, 0, SEEK_SET);

    while(fread(&p, sizeof(Persona), 1, archivo)) {
        cout << "Nombre: " << p.nombre << endl;
        cout << "Edad: " << p.edad << endl;
        cout << "Altura: " << p.altura << endl;
        cout << "----------------------------" << endl;
    }
}


int main(){

    Nodo*lista = NULL;
    FILE*archivo; 
    Persona p;
    
    archivo = fopen("personas.txt", "wb+");

    if (!archivo) {
        archivo = fopen("personas.txt", "wb+");
    }

    fseek(archivo, 0, SEEK_SET);

    cargarPersona(p);
    agregarNodo(lista, p, archivo);

    cout << "----------------------------" << endl;

    cargarPersona(p);
    agregarNodo(lista, p, archivo);

    cout << "----------------------------" << endl;

    cargarPersona(p);
    agregarNodo(lista, p, archivo);

    cout << "----------------------------" << endl;

    mostrarLista(archivo);



     

}