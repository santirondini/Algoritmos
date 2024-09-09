#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;

struct Alumno {
    string nombre;
    string apellido;
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
    cout << "Apellido: ";
    cin >> info.apellido;
    cout << "Edad: ";
    cin >> info.edad;
}

void cargarMateria (Materia&info){
    cout << "Nombre: ";
    cin >> info.nombreMateria;
}

// VERIFICACIONES:

bool elAlumnoExiste (string nombre, string apellido, NodoAlumno*lista){
    NodoAlumno*aux = lista; 
    while(aux){
        if(aux->info.nombre == nombre && aux->info.apellido == apellido){
            return true;
        }
        aux = aux->sgte;
    }
    return false;
}

bool verificacionMateria (string alumno, string apellido, string materia, NodoAlumno*lista){
    
    NodoAlumno*aux = lista;

    if (!(elAlumnoExiste(alumno, apellido, lista))){    
        cout << "Alumno no encontrado" << endl; // corroboro que el alumno exista
        return false;
    }

    while(aux && aux->info.nombre != alumno && aux->info.apellido != apellido){ // busco el alumno
        aux = aux->sgte;
    }

    Materia*aux2 = aux->NodoMateria; // Nodo a materias que apunte a la lista de materias del alumno

    while(aux2){
        if(aux2->nombreMateria == materia){ 
            return true; // verifico que exista una materia con ese nombre 
        }
        aux2 = aux2->sgte;
    }
    return false;
}

bool tieneNotas(string nombre, string apellido, string materia, NodoAlumno*lista){
    NodoAlumno*aux = lista;

    if (!(elAlumnoExiste(nombre, apellido, lista))){    
        cout << "Alumno no encontrado" << endl; // corroboro que el alumno exista
        return false;
    }

    while(aux && aux->info.nombre != nombre && aux->info.apellido != apellido){ // busco el alumno
        aux = aux->sgte;
    }

    Materia*aux2 = aux->NodoMateria; // Nodo a materias que apunte a la lista de materias del alumno

    while(aux2){
        if(aux2->nombreMateria == materia){ 
            if(aux2->NodoNotas){
                return true; // verifico que exista una materia con ese nombre 
            }
        }
        aux2 = aux2->sgte;
    }
    return false;
}

// SUMAR ELEMENTOS A LAS LISTAS:

void cargarMateriaEnAlumno (string materia, string nombreAlumno, string apellido, NodoAlumno*&listaAlumnos){

    // verifico que exista el alumno y que la materia no este cargada en ese alumno
    
    if (!(elAlumnoExiste(nombreAlumno, apellido, listaAlumnos))){
        cout << "Alumno no encontrado" << endl;
        return;
    }

    if(verificacionMateria(nombreAlumno,apellido,materia,listaAlumnos)){
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

void cargarNotaEnAlumno(string Alumno, string apellido, string materia, int nota, NodoAlumno*lista){
    
    NodoAlumno*aux=lista; 

    if(!elAlumnoExiste(Alumno, apellido, lista)){
        cout << "Alumno no encontrado" << endl;
        return;
    }

    if(!verificacionMateria(Alumno, apellido, materia, lista)){
        cout << "Materia no encontrada" << endl;
        return;
    }

    while(aux && aux->info.nombre != Alumno && aux->info.apellido != apellido){
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

float tamanio (Materia*lista){
    Materia*aux = lista;
    float tamanio = 0;
    while(aux){
        tamanio++;
        aux = aux->sgte;
    }
    return tamanio;
}

float promedioDeNotasDeTodasLasMaterias(Materia*ListaDeMaterias){
    
    Materia*aux = ListaDeMaterias;
    Nota*aux2 = aux->NodoNotas;
    
    float suma = 0;
    float tamanio = 0;

    while(aux){
        while(aux2){
            suma += aux2->nota;
            aux2 = aux2->sgte;
            tamanio++;
        }
        aux = aux->sgte;
    }
    return suma / tamanio;
}

float calcularPromedio(NodoAlumno*lista, string nombre, string apellido){

    NodoAlumno*aux = lista;
    float suma = 0;

    while(aux && aux->info.nombre != nombre && aux->info.apellido != apellido){
        aux = aux->sgte;
    }

    Materia*aux2 = aux->NodoMateria;

    while(aux2){
        suma += promedioDeNotasDeTodasLasMaterias(aux2);
        aux2 = aux2->sgte;
    }

    return suma / tamanio(aux->NodoMateria);
}

void mostrarAlumnos(NodoAlumno*lista){
    NodoAlumno*aux = lista;
    while(aux && aux->sgte){
        cout << "Nombre: " << aux->info.nombre << endl;
        cout << "Apellido: " << aux->info.apellido << endl;
        cout << "Edad: " << aux->info.edad << endl;
        cout << "Promedio: " << calcularPromedio(lista, aux->info.nombre, aux->info.apellido) << endl;
        aux = aux->sgte;
    }
}

int main(){

    NodoAlumno*listaAlumnos = NULL;
    char op;
    Alumno info;
    string materia;
    string nombreAlumno;
    string apellido;
    float nota;

    do {
        menu();
        do{
            op = getch(); 
        } while(op != 'a' && op != 'b' && op != 'c' && op != 'd' && op != 27);

        switch (op){
            
            case 'a': 
            cargarAlumno(info);
            cargarAlumnoEnLista(info, listaAlumnos);
            break; 

            case 'b':
            cout << "Nombre del alumno: " << endl;
            cin >> nombreAlumno;
            cout << "Apellido del alumno: " << endl;
            cin >> apellido;
            cout << "Nombre de la materia: " << endl;
            cin >> materia;
            cargarMateriaEnAlumno(materia, nombreAlumno, apellido, listaAlumnos);
            break;

            case 'c':
            cout << "Nombre del alumno: " << endl;
            cin >> nombreAlumno;
            cout << "Apellido del alumno: " << endl;
            cin >> apellido;
            cout << "Nombre de la materia: " << endl;
            cin >> materia;
            cout << "Nota: " << endl;
            cin >> nota;
            cargarNotaEnAlumno(nombreAlumno, apellido, materia, nota, listaAlumnos);
            break;

            case 'd':
            mostrarAlumnos(listaAlumnos);
            break;

        }
    cout << "Presione cualquier tecla para continuar" << endl;
    getch();
    system("cls");  
    } while(op!= 27);
}

