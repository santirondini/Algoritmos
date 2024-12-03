#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;

struct Alumno {
    char nombre[20];
    char apellido[20];
    int edad;
};

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main (){

    FILE *archivo;
    Alumno info; 

    archivo = fopen("alumnos.txt", "rb+");

    if (!archivo) {
        archivo = fopen("alumnos.txt", "wb+");
    }
    
    fseek(archivo, 0, SEEK_SET);

    while(fread(&info, sizeof(Alumno), 1, archivo)) {

    cout << "Nombre: " << info.nombre << endl;
    cout << "Apellido: " << info.apellido << endl;
    cout << "Edad: " << info.edad << endl;
    cout << "----------------------------" << endl;
    
    }

    fclose(archivo);
    
}

    


    







    

    
    
