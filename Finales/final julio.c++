#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;


struct Trabajo
{
    char titulo[50];
    int cat;
    char correo[50];
    int id_evaluadores[3];
    char resultado[3][40];
    Trabajo* sig;
};


char* resultado(int resultados[]){

    int puntos[3]={0};

    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            puntos[i]+=resultados[j+(4*i)];
        }
    }
    if (puntos[0]==0 || puntos[1]==0 || puntos[2]==0){
        return "Rechazado";
    } else if(puntos[0]>22 && puntos[1]>=35 && puntos[2]>=17){
        return "Aprobado Totalmente";
    } else if (puntos[0]>20 && puntos[1]>=30 && puntos[2]>=15){
        return "Aprobado con modificaciones";
    } else if (puntos[0]>17 && puntos[1]>=25 && puntos[2]>=12){
        return "No aprobado reformular";
    } else {
        return "Rechazado";
    }

}


Trabajo* buscarEnLista(Trabajo trabajo,char titulo[]);

void dictamen(Trabajo trabajos[],int resultados[],int id_evaluador,int cat,char titulo[]){
    
    Trabajo* evaluado = buscarEnLista(trabajos[cat-1],titulo);

    for(int i=0;i<3;i++){
        if(evaluado->id_evaluadores[i]=id_evaluador){

            strcpy(evaluado->resultado[i],resultado(resultados));

        }
    }
    
}


void trabajosAprobados(Trabajo* trabajos[]){

    for(int i=0;i<5;i++){
        cout<<"Trabajos aprobados de la categoria "<<i+1<<":"<<endl;
        Trabajo* aux = trabajos[i];
        while(aux!=NULL){
            if(aux->resultado == "Aprobado totalmente"){ //strcmp
                cout<<"Titulo: "<<aux->titulo<<" - ";
                cout<<endl;
            }
            aux=aux->sig;
        }
    }
    
    for(int i=0;i<5;i++){
        cout<<"Trabajos para modificar de la categoria "<<i+1<<":"<<endl;
        Trabajo* aux = trabajos[i];
        while(aux!=NULL){
            if(aux->resultado=="Aprobado copn modificaciones"){ //strcmp
                cout<<"Titulo: "<<aux->titulo<<" - ";
                cout<<endl;
            }
            aux=aux->sig;
        }
    }

}

int main (){
    
}