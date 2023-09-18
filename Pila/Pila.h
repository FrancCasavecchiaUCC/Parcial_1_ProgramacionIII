#ifndef LISTA_H
#define LISTA_H

#include <iostream>

template <class T>

class nodo {
private:
    T dato;
    nodo* siguiente;
public:
    nodo(){
        siguiente = NULL;
    }
    nodo(T d, nodo* s){
        dato = d;
        siguiente = s;
    }
    T getDato(){
        return dato;
    }
    void setDato(T d) {
        dato = d;
    }
    nodo *getSiguiente(){
        return siguiente;
    }
    void setSiguiente(nodo *n) {
        siguiente = n;
    }
};

/**
 * Clase que implementa una Pila generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */
template<class T>
class Pila {
private:
    nodo<T> *inicio;
public:
    Pila();

    ~Pila();

    void push(T dato);

    T pop();

    bool esVacia();

    T peek();

    void show();

    void mostrarTope();

};


/**
 * Constructor de la clase Pila
 * @tparam T
 */
template<class T>
Pila<T>::Pila() {
    inicio = NULL;
}


/**
 * Destructor de la clase Lista, se encarga de liberar la memoria de todos los nodos
 * utilizados en la lista
 * @tparam T
 */
template<class T>
Pila<T>::~Pila() {
    while(!esVacia()) {
        pop();
    }
}


/**
 * Inserta un dato en la pila
 * @tparam T
 * @param dato  dato a insertar
 */
template<class T>
void Pila<T>::push(T dato) {
    nodo<T> *aux = new nodo<T>(dato,inicio);
    inicio = aux;
}


/**
 * Obtener el dato de la pila
 * @tparam T
 * @return dato almacenado en el nodo
 */
template<class T>
T Pila<T>::pop() {
    if (inicio == NULL) {
        throw 1;
    }
    T dato = inicio->getDato();
    nodo<T> *aux = inicio;
    inicio = inicio->getSiguiente();
    delete aux;
    return dato;
}

/**
 * Responde si la pila se encuentra Vacía
 * @tparam T
 * @return
 */
template<class T>
bool Pila<T>::esVacia() {
    return  inicio == NULL;
}

/**
 * Obtener el dato de la pila
 * @tparam T
 * @return dato almacenado en el nodo
 */
template<class T>
T Pila<T>::peek() {
    if (inicio == NULL) {
        throw 1;
    }
    return inicio->getDato();
}

/**
 * Muestra los datos de la pila
 * @tparam T
 */

template<class T>
void Pila<T>::show() {
    nodo<T> *aux = inicio;
    while (aux != NULL) {
        std::cout << aux->getDato() << std::endl;
        aux = aux->getSiguiente();
    }
}

template<class T>
void Pila<T>::mostrarTope() {
    if (inicio == NULL) {
        throw 1;
    }
    std::cout << inicio->getDato() << std::endl;
}


#endif //LISTA_H