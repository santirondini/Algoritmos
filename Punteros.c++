#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;


int main() {

int *p;
int n; 

// *p = n; -- Esto no deja compilar 

n = 10;
p = &n;

cout << "*p = n;" << endl;
cout << "n = 10" << endl;
cout << endl;

cout << "n = " << n << endl; 
cout << "&n = " << &n << endl;
cout << endl;

cout << "p = " << p << endl;
cout << "*p = " << *p << endl;
cout << "&p = " << &p << endl;
cout << endl;

delete p;
p = NULL; 

//--------------

int *q;
q = new int(5); // lo mismo que hacer *q = 5

cout << "q : " << q << endl;     
cout << "*q : " << *q << endl;
cout << "&q : " << &q << endl;
cout << endl; 

delete q;
q = NULL;


//--------------

int *r;
r = new int[5]; 

cout << "r = new int[5];" << endl; 

cout << "r :" << r << endl;
cout << "*r :" << *r << endl;
cout << "&r :" << &r << endl;
cout << endl;

/*

Haciendo el cout antes de asignar los valores:

r : 0x1067f70
*r : 17201888
&r : 0x62fef8

Haciendo el cout después de asignar los valores:

r :0xf57f70
*r :0
&r :0x62fef8

La dirección del HEAP cambia, pero la dirección de la variable r no cambia.
*/

for (int i = 0; i < 5; i++) {
    r[i] = i;
}

for (int i = 0; i < 5; i++) {
    cout << "r[" << i << "] = " << *(r+i) << endl;
}

cout << "r :" << r << endl;
cout << "*r :" << *r << endl;
cout << "&r :" << &r << endl;
cout << endl;

//----------------------------------------

int z;
int *s;
int **t;

z = 25;
s = &z;
t = &s;

cout << "z = 25;" << endl;
cout << "s = &z;" << endl;
cout << "t = &s;" << endl;
cout << endl;

cout << "z = " << z << endl;
cout << "&z = " << &z << endl;
cout << endl;

cout << "s = " << s << endl;
cout << "*s = " << *s << endl;
cout << "&s = " << &s << endl;
cout << endl;

cout << "t = " << t << endl;
cout << "*t = " << *t << endl;
cout << "**t = " << **t << endl;
cout << "&t = " << &t << endl;
cout << endl;



/* 
Errores: 

1) 
int* ptr; // Puntero no inicializado
*ptr = 10; // Error: acceso a memoria no válida

2) 
int* ptr = nullptr;
*ptr = 5; // Error: acceso a puntero nulo

3) 
int *p;
*p = 10

Solución: 

int var = 10;  -- Una variable normal
int p = &var; -- El puntero ahora apunta a la dirección de 'var'
*p = 20;       -- Cambias el valor de 'var' a través del puntero

*/

getch();
}