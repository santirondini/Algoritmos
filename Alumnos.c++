#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;

struct Alumno {
    string nombre;
    int edad;
    float promedio;
};

struct NodoAlumno {
    Alumno info;
    Materia*NodoMateria = NULL;
    NodoAlumno*sgte=NULL;
};

struct Materia {
    string nombreMateria;
    Nota*NodoNotas = NULL;
    Materia*sgte=NULL;
};

struct Nota{
    float nota;
    Nota*sgte=NULL;
};


// CARGAR ELEMENTOS: 

void cargarAlumno (Alumno&info){
    cout << "Nombre: ";
    cin >> info.nombre;
    cout << "Edad: ";
    cin >> info.edad;
}

void cargarMateria (Materia&info){
    cout << "Nombre: ";
    cin >> info.nombreMateria;
}

// VERIFICACIONES:

bool elAlumnoExiste (string nombre, NodoAlumno*lista){
    NodoAlumno*aux = lista; 
    while(aux){
        if(aux->info.nombre == nombre){
            cout << "Alumno ya cargado" << endl;
            return true;
        }
        aux = aux->sgte;
    }
    return false;
}

bool verificacionMateria (string alumno, string materia, NodoAlumno*lista){
    
    NodoAlumno*aux = lista;

    if (!elAlumnoExiste(alumno, lista)){    
        cout << "Alumno no encontrado" << endl; // corroboro que el alumno exista
        return false;
    }

    while(aux && aux->info.nombre != alumno){ // busco el alumno
        aux = aux->sgte;
    }

    Materia*aux2 = aux->NodoMateria; // Nodo a materias que apunte a la lista de materias del alumno

    while(aux2){
        if(aux2->nombreMateria == materia){
            cout << "La materia existe" << endl; // verifico que exista una materia con ese nombre 
            return true;
        }
        aux2 = aux2->sgte;
    }
    return false;
}

// SUMAR ELEMENTOS A LAS LISTAS:

void cargarMateriaEnAlumno (string materia, string nombreAlumno, NodoAlumno*&listaAlumnos){

    // verifico que exista el alumno y que la materia no este cargada en ese alumno
    
    if (!elAlumnoExiste(nombreAlumno, listaAlumnos)){
        cout << "Alumno no encontrado" << endl;
        return;
    }

    if(!verificacionMateria(nombreAlumno, materia, listaAlumnos)){
        cout << "Materia ya cargada" << endl;
        return;
    }

    NodoAlumno*aux = listaAlumnos;
    while(aux && aux->info.nombre != nombreAlumno){
        aux = aux->sgte;
    }

    Materia*nuevo = new Materia;
    nuevo->nombreMateria = materia;
    nuevo->sgte = aux->NodoMateria;
    aux->NodoMateria = nuevo;
}   

void cargarAlumnoEnLista (Alumno info, NodoAlumno*&lista){
    NodoAlumno*nuevo = new NodoAlumno;
    nuevo->info = info; 
    nuevo->sgte = lista;
    lista = nuevo;
}

void cargarNotaEnAlumno(string Alumno, string Materia, int nota, NodoAlumno*lista){
    
    NodoAlumno*aux=lista; 

    if(!elAlumnoExiste(Alumno, lista)){
        cout << "Alumno no encontrado" << endl;
        return;
    }

    if(!verificacionMateria(Alumno, Materia, lista)){
        cout << "Materia no encontrada" << endl;
        return;
    }

    while(aux && aux->info.nombre != Alumno){
        aux = aux->sgte;
    }

    Materia* auxm = aux->NodoMateria;

    while(auxm && auxm->nombreMateria != Materia){
        auxm = auxm->sgte;
    }



}

int main(){

}