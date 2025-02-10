#include <iostream>
#include <math.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

void cargarMatriz(int matriz[][5]){
    srand(time(0));
    for(int i = 0; i < 5; i++){
        for (int j = 0;j<5;j++){
            matriz[i][j] = rand() % 20; 
        }
    }
}

void mostrarMatriz(int matriz[][5]){
    for(int i = 0; i<5;i++){
        for(int j=0;j<5;j++){
            cout << matriz[i][j] << "  "; 
        }
        cout << endl; 
    }
}

int diagonalPrincipal(int matriz[][5]) {
    int suma = 0;  
    for(int i = 0;i<5;i++){
        suma += matriz[i][i];
    }
    return suma; 
}

int diagonalConWhile(int matriz[][5]){
    int suma = 0;
    int i = 0;
    while(i < 5){
        suma += matriz[i][i];
        i++;
    }
    return suma;
}

int sumarTotalDeMatriz(int matriz[][5]){
    int suma = 0; 
    for(int i = 0;i<5;i++){
        for(int j = 0; j<5;j++){
            suma += matriz[i][j];
        }
    }
    return suma; 
}

int numeroMasGrande(int matriz[][5]){
    int masgrande = matriz[0][0];
    for(int i = 0; i < 5; i++){
        for (int j = 0; j<5;j++){
            if(masgrande < matriz[i][j])
            masgrande = matriz[i][j];
        }
    }
    return masgrande;
}

int main(){

    int matriz[5][5];

    cargarMatriz(matriz);
    mostrarMatriz(matriz);


    cout << "La suma de la diagonal principal (usando for) es: " << diagonalPrincipal(matriz) << endl;     
    cout << "La suma de la diagonal principal (usando while) es: " << diagonalConWhile(matriz) << endl; 
    cout << "El numero mas grande de la matriz es: " << numeroMasGrande(matriz) << endl; 
}