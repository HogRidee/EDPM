/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 31 de marzo de 2023, 17:42
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

/*
 * BUSCAMOS IMPLEMENTAR UN TAD DE VECTORES EN R3
 */

typedef struct{
    double x;
    double y;
    double z;
} VectorR3;

//OPERACIONES CONSTRUCTORAS:
//inicializa el vector en 0
void construir(VectorR3 *punteroVector);
//mismo nombre, sobrecarga de funciones (funciones con el mismo nombre pero
//con diferente cantidad de parámetro o un parámetro ser de diferente tipo)
void construir(VectorR3 *punteroVector, double xx, double yy, double zz);

//OPERACIONES OBSERVADORAS:
//la funcion mostrar siempre debe estar
void mostrar();
void asignarX(VectorR3 *pv, double xx);
void asignarY(VectorR3 *pv, double yy);
void asignarZ(VectorR3 *pv, double zz);
double obtenerX(VectorR3 v);
double obtenerY(VectorR3 v);
double obtenerZ(VectorR3 v);
//ingresar el valor de cada componente
void ingresar(VectorR3 *pv);
double modulo(VectorR3 v);
double productoEscalar(VectorR3 v1, VectorR3 v2);
double angulo(VectorR3 v1, VectorR3 v2);
bool sonIguales(VectorR3 v1, VectorR3 v2);z

//OPERACIONES MODIFICADORAS:
VectorR3 sumar(VectorR3 v1, VectorR3 v2);
VectorR3 productoVectorial(VectorR3 v1, VectorR3 v2);

int main(int argc, char** argv) {

    
    
    return 0;
}

