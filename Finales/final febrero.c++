#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

// Estructuras
struct Otros{
    char* nombre;
    int votos;
    Otros* sgte; 
};
struct posicion{
    int lenguajes[4] = {0};
    Otros* listaDeOtros;     
};

posicion matriz[3][3];

bool lenguajeYaCargado(posicion matriz[][3],char*cual,int actividad){  
    
    for(int i =0; i<3; i++)
    {
    Otros* aux = matriz[actividad-1][i].listaDeOtros;
    while(aux){
        if(strcmp(aux->nombre,cual) == 0 ){
            return true;
        }
        else{
            aux = aux->sgte;
        }
    }
    return false;
    }
}

void cargarMatriz(posicion matriz[][3], int actividad, int institucion, int lenguaje, char*cual){
    matriz[actividad-1][institucion-1].lenguajes[lenguaje-1]++;
    if(lenguaje == 4 && !lenguajeYaCargado(matriz,cual,actividad)){
    Otros* nuevo = new Otros; 
    strcpy(nuevo->nombre,cual);
    nuevo->votos++;
    insertarOrdenado(matriz[actividad-1][institucion-1].listaDeOtros,nuevo);
    } else{    
        Otros*auxiliar = matriz[actividad-1][institucion-1].listaDeOtros; 
        while(auxiliar != NULL && strcmp(auxiliar->nombre,cual) /= 0 ){
        auxiliar = auxiliar->sgte;
        }
        auxiliar->votos++;
    }
}
void mostrarLista(Otros*lista){
    Otros* aux = lista; 
    while(aux && aux->sgte){
        cout << lista->nombre << "  " << lista->votos << endl; 
    }
}
void mostrarResultados(posicion matriz[][3],int actividad){
    
    cout << "Actividad: " ;
    if (actividad == 1){
        cout << "alumno" << endl;
    }
    if (actividad == 2){
        cout << "docente" << endl;
    }
    if (actividad == 3){
        cout << "egresado" << endl;
    }

    cout << "                       " << "   python   " << "  C++  " << "  Java   " << endl;
    cout << "Universidad publica " << matriz[actividad][0].lenguajes[0] << matriz[actividad][0].lenguajes[1] << matriz[actividad][0].lenguajes[2] << endl;
    cout << "Universidad publica " << matriz[actividad][1].lenguajes[0] << matriz[actividad][1].lenguajes[1] << matriz[actividad][1].lenguajes[2] << endl;
    cout << "Universidad publica " << matriz[actividad][2].lenguajes[0] << matriz[actividad][2].lenguajes[1] << matriz[actividad][2].lenguajes[2] << endl;
    
    cout << "Listado de Otros:" << endl;
    cout << "Lenguaje " << "        " << " Cantidad " << endl;
    for(int i=0;i<3;i++){
        mostrarLista(matriz[actividad][i].listaDeOtros);
    }
}
