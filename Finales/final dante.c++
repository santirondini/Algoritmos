#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

typedef enum { 
BuenosAires, CABA, Catamarca, Chaco, Chubut, Cordoba, Corrientes, EntreRios, Formosa, Jujuy, 
LaPampa, Rioja, Mendoza, Misiones, Neuquen, RioNegro, Salta, SanJuan, SanLuis, SantaCruz, 
SantaFe, SgoEStero, TdelFuego, Tucuman} Provincia; 


struct archVotos{
    Provincia provincia;
    int partido;
    int localidad; 
    int padron; 
    int blancos;
    int impugnados;
    int listas[5];

};

struct matrizVotos {
    int padron;
    int blancos;
    int impugnados;
    int listas[5];
};

matrizVotos Votos[24][10][20];




int main(){
    FILE* archivoDeVotos;     
    FILE* archivoDeFormulas; 
}


void presidente(){
    
    
}




int main(){

}