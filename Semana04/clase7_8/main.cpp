/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 13 de abril de 2023, 10:31
 */

    //MEMORIA DINAMICA
    //int *p;
    //p = new int;
    //cin >> *p;
    //delete p;
    
    //LISTAS SIMPLEMENTE ENLAZADAS: 
    /*NODOS: La cantitad es variable, depende de cuantos creamos.
     Cada nodo es un struct, habrá un dato y una dirección algo como: 
     [DATO][DIRECCION].
     elem  sig(puntero: declaración recursiva)
     Los nodos no están juntos en la memoria, están dispersos. Aún así, no me 
     impide saber quien va primero, segundo, etc.
     LISTA: Tiene 2 elementos: 
     [DIRECCION][CANT NODOS]
        cabeza    longitud
     Cabeza: Dirección del primer nodo de la lista. Debe manejarse cuidadosamente.
     Longitud: Número de nodos de la lista.
     Todos los nodos son variables dinámicas.
     La lista van a ser variables estáticas.
     Toda lista empieza vacía: [NULL][0].
     Es simplemente enlazada, porque en cada nodo solo apunta a otro nodo.*/

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

/*
 * JUEVES 13/04/23
 * VIERNES 14/04/23
 */

//definimos el dato del nodo (el dato del nodo puede ser más complejo que un int
//por ejemplo un struct)
typedef int Elemento;

//definimos el nodo
typedef struct nodo{
    Elemento elem;
    struct nodo *sig;
} Nodo; 

//definimos la lista
typedef struct{
    Nodo *cabeza;
    int longitud;
} Lista;

//FUNCIONES CONSTRUCTORAS

void construir(Lista *punteroLista){
    //toda lista empieza vacía
    punteroLista->cabeza = NULL;
    punteroLista->longitud = 0;
}

//FUNCIONES OBSERVADORAS

bool esListaVacia(Lista lista){
    return lista.cabeza == NULL;
    //tambien funciona con return lista.longitud == 0;
}

int obtenerLongitud(Lista lista){
    return lista.longitud;
}

Nodo* crearNodo(Elemento elemento, Nodo *siguiente){
    Nodo *puntero;    
    puntero = new Nodo;
    puntero->elem = elemento;
    puntero->sig = siguiente;
    //devolvemos la dirección de memoria donde se creó el nodo
    return puntero;
}

void insertarComienzo(Lista *punteroLista, Elemento elemento){
    Nodo *puntero;
    puntero = crearNodo(elemento, punteroLista->cabeza);
    punteroLista->cabeza = puntero;
    punteroLista->longitud++;
}

void mostrar(Lista lista){
    Nodo *puntero;
    if(esListaVacia(lista)){
        cout << "Lista vacia" << endl;
    }
    else{
        puntero = lista.cabeza;
        for(int i = 1; i <= lista.longitud; i++){
            cout << puntero->elem << "  ";
            puntero = puntero->sig;
        }
        cout << endl;
    }
}

Nodo* ubicarUltimo(Lista lista){
    Nodo *punteroUltimo;
    if(esListaVacia(lista)){
        //al estar vacía la lista, no hay último
        return NULL;
    }
    else{
        punteroUltimo = lista.cabeza;
        for(int i = 1; i <= lista.longitud-1; i++){
            punteroUltimo = punteroUltimo->sig;
        }
        //devuelve la dirección del último nodo
        return punteroUltimo;
    }
}

void insertarFinal(Lista *punteroLista, Elemento elemento){
    Nodo *puntero, *punteroUltimo;
    puntero = crearNodo(elemento, NULL);
    if(esListaVacia(*punteroLista)){
        punteroLista->cabeza = puntero;
    }
    else{
        punteroUltimo = ubicarUltimo(*punteroLista);
        punteroUltimo->sig = puntero;
    }
    punteroLista->longitud++;
}

Nodo* ubicar(Lista lista, Elemento elemento){
    Nodo *puntero;
    
    if(esListaVacia(lista)){
        return NULL;
    }
    else{
        puntero = lista.cabeza;
        for(int i = 1; i <= lista.longitud; i++){
            if(puntero->elem == elemento){
                //devuelve la dirección del nodo donde encontró el dato elemento
                return puntero;
            }
            puntero = puntero->sig;
        }
        //el dato no fue encontrado en la lista
        return NULL;
    }
}

Nodo* ubicarAnterior(Lista lista, Elemento elemento){
    Nodo *puntero, *punteroAnterior;
    punteroAnterior = NULL;
    puntero = lista.cabeza;
    for(int i = 1; i <= lista.longitud; i++){
        if(puntero->elem == elemento){
            return punteroAnterior;
        }
        punteroAnterior = puntero;
        puntero = puntero->sig;
    }
}

void eliminar(Lista *punteroLista, Elemento elemento){
    Nodo *puntero, *punteroAnterior;
    puntero = ubicar(*punteroLista, elemento);
    //el dato no está en la lista
    if(puntero == NULL){
        cout << "No se puede eliminar un dato inexistente" << endl;
    }
    //el dato si está en la lista
    else{
        punteroAnterior = ubicarAnterior(*punteroLista, elemento);
        //el nodo a eliminar es el primero
        if(punteroAnterior == NULL){
            punteroLista->cabeza = puntero->sig;
        }
        //el nodo a eliminar no es el primero
        else{
            punteroAnterior->sig = puntero->sig;
        }
        punteroLista->longitud--;
        //se elimina el nodo
        delete puntero;
    }
}

void destruir(Lista *punteroLista){
    Nodo *puntero, *punteroAuxiliar;
    if(!esListaVacia(*punteroLista)){
        puntero = punteroLista->cabeza;
        for(int i = 1; i <= punteroLista->longitud; i++){
            punteroAuxiliar = puntero->sig;
            delete puntero;
            puntero = punteroAuxiliar;
        }
        punteroLista->cabeza = NULL;
        punteroLista->longitud = 0;
        cout << "Todos los nodos han sido eliminados" << endl;
    }
}

int main(int argc, char** argv) {
    
    Lista lista1;
    
    construir(&lista1);
    mostrar(lista1);
    
//    insertarComienzo(&lista1, 48);
//    mostrar(lista1);
//    
//    insertarComienzo(&lista1, 51);
//    mostrar(lista1);
//    
//    insertarComienzo(&lista1, 37);
//    mostrar(lista1);
//    
//    insertarComienzo(&lista1, 24);
//    mostrar(lista1);
//    
//    insertarComienzo(&lista1, 80);
//    mostrar(lista1);
    
    insertarFinal(&lista1, 32);
    mostrar(lista1);
    
    insertarFinal(&lista1, 90);
    mostrar(lista1);
    
    insertarFinal(&lista1, 25);
    mostrar(lista1);
    
    insertarFinal(&lista1, 17);
    mostrar(lista1);
    
    insertarFinal(&lista1, 42);
    mostrar(lista1);
    
    eliminar(&lista1, 25);
    mostrar(lista1);
    
    eliminar(&lista1, 42);
    mostrar(lista1);
    
    eliminar(&lista1, 32);
    mostrar(lista1);
    
    eliminar(&lista1, 100);
    mostrar(lista1);
    
    destruir(&lista1);
    mostrar(lista1);
    
    //PC1:
    //P1: IMPLEMENTAR UN TAD COMO EL EJEMPLO DE VECTORES
    //P2: IMPLEMENTAR FUNCIONES ADICIONALES A LAS QUE TENEMOS EN ESTE ARCHIVO
    //    EJ: FUNCION QUE PERMITA IMPRIMIR LA LISTA AL REVÉS
    
    return 0;
}

