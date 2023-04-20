/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 31 de marzo de 2023, 16:11
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

const int VERDADERO = 1;
const int FALSO = 0;

typedef struct {
    int valor;
} Booleano;

/*
 * IMPLEMENTAR UN TAD LLAMADO BOOLEANO (logica)
 * Crearemos una estructura con unico campo valor, para almacenar un 0 o 1
 * para Falso o Verdadero
 * Luego ordenar los archivos
 */

//OPERACIONES CONSTRUCTORAS: (inicializar datos del TAD)
//punteroBooleano = puntero a booleano
void construirV(Booleano *punteroBooleano){
    (*punteroBooleano).valor = VERDADERO;
    //punteroBooleano->valor = VERDADERO;
}

void construirF(Booleano *punteroBooleano){
    punteroBooleano->valor = FALSO;
}

//OPERACIONES OBSERVADORAS: (devuelve un no TAD, o no devuelve valor)
void mostrar(Booleano booleano){
    if(booleano.valor == VERDADERO){
        cout << "VERDADERO" << endl;
    }
    else{
        cout << "FALSO" << endl;
    }
}

void asignarValor(Booleano *punteroBooleano, int valor){
    //debemos proteger la consistencia del valor del TAD que creamos
    if(valor == VERDADERO or valor == FALSO){
        punteroBooleano->valor = valor;
    }
    else{
        cout << "ERROR: el valor ingresado no es valido" << endl;
    }
}

int obtenerValor(Booleano booleano){
    if(booleano.valor == VERDADERO){
        return VERDADERO;
    }
    else{
        return FALSO;
    }
    //return booleano.valor;
}

//OPERACIONES MODIFICADORAS: (devuelve mismo tipo del TAD) 
Booleano negacion(Booleano booleano){
    Booleano negacion;
    if(booleano.valor == FALSO){
        construirV(&negacion);
    }
    else{
        construirF(&negacion);
    }
    return negacion;
}

Booleano conjuncion(Booleano booleano1, Booleano booleano2){
    Booleano conjuncion;
    if(booleano1.valor == VERDADERO and booleano2.valor == VERDADERO){
        construirV(&conjuncion);
    }
    else{
        construirF(&conjuncion);
    }
    return conjuncion;
}

Booleano disyuncion(Booleano booleano1, Booleano booleano2){
    Booleano disyuncion;
    if(booleano1.valor == VERDADERO or booleano2.valor == VERDADERO){
        construirV(&disyuncion);
    }
    else{
        construirF(&disyuncion);
    }
    return disyuncion;
}

Booleano disyuncionExclusiva(Booleano booleano1, Booleano booleano2){
    Booleano x;
    if(booleano1.valor != booleano2.valor){
        construirV(&x);
    }
    else{
        construirF(&x);
    }
    return x;
}

int main(int argc, char** argv) {

    Booleano booleano1, booleano2, booleano3, booleano4, booleano5, booleano6;
    
    //enviamos la dirección de la variable para recibirlo por punteroBooleano
    construirV(&booleano1);
    cout << "Booleano 1:";
    mostrar(booleano1);
    
    construirF(&booleano2);
    cout << "Booleano 2:";
    mostrar(booleano2);
    
    asignarValor(&booleano1, FALSO);
    cout << "Booleano 1: ";
    mostrar(booleano1);
    
    asignarValor(&booleano2, 43);
    cout << "Booleano 2: ";
    mostrar(booleano2);
    
    cout << "El valor del booleano 1 es " << obtenerValor(booleano1) << endl;
    cout << "El valor del booleano 2 es " << obtenerValor(booleano2) << endl;
    
    booleano3 = negacion(booleano1);
    cout << "Booleano 3 (negacion de booleano 1): ";
    mostrar(booleano3);
    
    booleano4 = conjuncion(booleano2, booleano3);
    cout << "Booleano 4 (conjuncion de booleano 2 y booleano 3: ";
    mostrar(booleano4);
    
    booleano5 = disyuncion(booleano2, booleano3);
    cout << "Booleano 5 (disyuncion de booleano 2 y booleano3): ";
    mostrar(booleano5);
    
    booleano6 = disyuncionExclusiva(booleano2, booleano3);
    cout << "Booleano 6 (disyuncion exclusivs de booleano 2 y booleano3): ";
    mostrar(booleano6);
    
    return 0;
}