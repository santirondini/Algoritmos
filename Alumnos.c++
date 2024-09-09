#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;

struct Alumno {
    string nombre;
    int edad;
    float promedio;
};

struct Nota{
    float nota;
    Nota*sgte=NULL;
};

struct Materia {
    string nombreMateria;
    Nota*NodoNotas = NULL;
    Materia*sgte=NULL;
};
struct NodoAlumno {
    Alumno info;
    Materia* NodoMateria = NULL;
    NodoAlumno*sgte=NULL;
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

void cargarNotaEnAlumno(string Alumno, string materia, int nota, NodoAlumno*lista){
    
    NodoAlumno*aux=lista; 

    if(!elAlumnoExiste(Alumno, lista)){
        cout << "Alumno no encontrado" << endl;
        return;
    }

    if(!verificacionMateria(Alumno, materia, lista)){
        cout << "Materia no encontrada" << endl;
        return;
    }

    while(aux && aux->info.nombre != Alumno){
        aux = aux->sgte;
    }

    Materia*auxm = aux->NodoMateria;

    while(auxm && auxm->nombreMateria != materia){
        auxm = auxm->sgte;
    }

    Nota*nuevo = new Nota;
    nuevo->nota = nota; 
    nuevo->sgte = auxm->NodoNotas;
}

char menu (){
    cout << " a - cargar alumno" << endl; 
    cout << " b - cargar materia en alumno" << endl;
    cout << " c - cargar nota en materia" << endl;
    cout << " d - mostrar alumnos" << endl;
    cout << " Esc - salir" << endl;

}

int main(){

    NodoAlumno*listaAlumnos = NULL;
    char op;
    Alumno info;
    string materia;
    string nombreAlumno;
    int nota;

    do {
        menu();
        do{
            op = getch();
            tolower(op);
        } while(op != 'a' && op != 'b' && op != 'c' && op != 'd' && op != 27);

        switch (op){
            
            case 'a': 
            cargarAlumno(info);
            cargarAlumnoEnLista(info, listaAlumnos);
            break; 

            case 'b':
            cout << "Nombre del alumno: " << endl;
            cin >> nombreAlumno;
            cout << "Nombre de la materia: " << endl;
            cin >> materia;
            cargarMateriaEnAlumno(materia, nombreAlumno, listaAlumnos);
            break;

            case 'c':
            cout << "Nombre del alumno: " << endl;
            cin >> nombreAlumno;
            cout << "Nombre de la materia: " << endl;
            cin >> materia;
            cout << "Nota: " << endl;
            cin >> nota;
            cargarNotaEnAlumno(nombreAlumno, materia, nota, listaAlumnos);
            break;
        }

    cout << "Presione cualquier tecla para continuar" << endl;
    getch();
    system("cls");  
    } while(op!= 27);
}