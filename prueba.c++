#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;

struct Alumno 
{
    std::string nombre;
    int edad;
    float promedio;
    std::string carrera;
    int notas[5];
};

char menu (){
    cout << "¿Que desea hacer con el numero?" << endl;
    cout << "a. Sumar" << endl;
    cout << "b. Restar" << endl;
    cout << "c. Multiplicar" << endl;
    cout << "d. Dividir" << endl;
}

int main()
{
    int x, y ,z;
    char c;
    cout << "Ingrese el valor de x: " << std::endl;
    cin >> x;
    cout << "Ingrese el valor de y: " << std::endl;
    cin >> y;
    cout << "Ingrese el valor de z: " << std::endl;
    cin >> z;
    do {
        menu ();
        getch(c);
        do {
            switch (c){
                case 'a':{
                    cout << "La suma de los numeros es: " << x + y + z << endl;
                    break;
                }
                cas
            }
                break;
            }



        } while ();
    } while()

}


