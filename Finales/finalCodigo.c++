#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;


char Funcion(int vec[],int len);

int main(){

    int *p, *y; 
    int w; 
    p = new int();
    w = 85;
    *p = w; 
    y = p; 
    w++;
    cout << *y << endl; // muestra 85

}