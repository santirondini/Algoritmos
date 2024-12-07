#include <iostream>
#include <math.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Producto {
    int id;
    char tipo; // P perecedero N no perecedero
    int unidadesEnAlmacen;
};

struct Nodo {
    int idProducto;
    int IdCliente;
    int unidadesRequeridas;      
    Nodo*sgte = NULL; 
};

int recursivo(int n){
    if (n==0) return 1;
    return n + recursivo(n-1);
}

int main() {

    Nodo*ListaProductos = NULL; 
    Producto STOCK[50];
    


    /*int arr[] = {10, 20, 30, 40};
    int *p = arr;
    cout << *(p+2) << endl;
    p++;
    cout << *p << endl;

    int resultado = recursivo(5);
    cout << resultado << endl;
    */



}