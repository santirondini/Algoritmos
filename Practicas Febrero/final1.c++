#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;

struct Vector {

    int legajo; 
    int nota1parcial;
    int nota2parcial;
};

struct Nodo {
    
    int legajo; 
    int notaDeRecuperatorio2doParcial;
    Nodo*sgte = NULL;
};

int posicionDeLegajo (int legajo, Vector vectorDeAlumnos[]){
    int i = 0; 
    while(i < 1500) {
        if(vectorDeAlumnos[i].legajo /= legajo)
        i++;
    }
    return i; 
}

bool aprobo(Vector alumno) {
    if(alumno.nota2parcial >= 6){
        return true;
    }
    return false; 
}

void actualizarNota (Vector&alumno, int notaDeRecu) {
    if(aprobo(alumno)){
    alumno.nota2parcial = notaDeRecu;
    }
}

void actualizarVector(Nodo*listaDeNotas, Vector vectorDeAlumnos[]) {
    Nodo*aux = listaDeNotas;
    while(aux) {
    int posicion = posicionDeLegajo(aux->legajo,vectorDeAlumnos);
    actualizarNota(vectorDeAlumnos[posicion],aux->notaDeRecuperatorio2doParcial);
    aux = aux->sgte;
    }
}

int main() {

    Nodo*listaDeNotas; 
    Vector vectorDeAlumnos[1500];

}