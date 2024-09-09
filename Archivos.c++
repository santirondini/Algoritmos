#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;



int main (){

    FILE *archivo;
    int lector; 

    archivo = fopen("archivo.dat","rb");

    if (!archivo){
        archivo = fopen("archivo.txt","wb");
    }

    fwrite("Hola",sizeof(char),1,archivo);

    fread(&lector,sizeof(char),1,archivo);
    cout << lector << endl;
    
}