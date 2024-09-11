#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;

int main (){

    int matriz[3][3];
    // int matriz [fila][columna]

    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            cout << "Ingrese el valor de la matriz en la posicion [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }

    cout << "La matriz es: " << endl;
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}


