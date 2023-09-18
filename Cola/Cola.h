#ifndef U04_COLAS_COLA_COLA_H_
#define U04_COLAS_COLA_COLA_H_

#include "Nodo.h"

/**
 * Clase que implementa una Cola generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */
template <class T> class Cola {
private:
    Nodo<T> *fondo;
    Nodo<T> *inicio;
public:
  Cola();

  ~Cola();

  void encolar(T dato);

  T desencolar();

  bool esVacia();

  void vaciar();

  void mostrar();

  int tamano();

  void encolarPrioridad(T dato, int prioridad);
};

/**
 * Constructor de la clase Cola
 * @tparam T
 */
template <class T> Cola<T>::Cola() {
    fondo = inicio = NULL;
}

/**
 * Destructor de la clase Cola, se encarga de liberar la memoria de todos los
 * nodos utilizados en la Cola
 * @tparam T
 */
template <class T> Cola<T>::~Cola() {
    vaciar();
}

/**
 * Inserta un dato en la Cola
 * @tparam T
 * @param dato  dato a insertar
 */
template <class T> void Cola<T>::encolar(T dato) {
    Nodo<T> *aux = new Nodo<T>(dato);

    // Si la cola esta vacia
    if (fondo == NULL && inicio == NULL) {
        inicio = fondo = aux;
    } else {
        fondo->setNext(aux);
        // fondo->setNext(new Nodo<T>(dato));
        fondo = aux;
    }
}

/**
 * Obtener el dato de la Cola
 * @tparam T
 * @return dato almacenado en el nodo
 */
template <class T> T Cola<T>::desencolar() {

    if (esVacia())
        throw 1;

    // si no es vacia.
    T tmp;
    Nodo<T> *aux = inicio;

    inicio = inicio->getNext();
    tmp = aux->getDato();
    delete aux;

    if (inicio == NULL)
        fondo = inicio;

    return tmp;
}

/**
 * Responde si la Cola se encuentra Vacía
 * @tparam T
 * @return
 */
template <class T> bool Cola<T>::esVacia() {
    return (inicio == NULL && fondo == NULL);
}

/**
 * Elimina todos los nodos de la Cola
 * @tparam T
 */
template <class T> void Cola<T>::vaciar() {
    Nodo<T> *aux;

    while (inicio != NULL) {
        aux = inicio;
        inicio = inicio->getNext();
        delete aux;
    }

    fondo = NULL;
}

/**
 * Muestra el contenido de la Cola
 * @tparam T
 */
template <class T> void Cola<T>::mostrar() {
    Nodo<T> *aux = inicio;

    while (aux != NULL) {
        std::cout << aux->getDato();
        aux = aux->getNext();

        if (aux != NULL) {
            std::cout << "->";
        }
    }

    std::cout << std::endl;
}

/**
 * Retorna el tamaño de la Cola
 * @tparam T
 * @return
 */
template <class T> int Cola<T>::tamano() {
    int cont = 0;
    Nodo<T> *aux = inicio;

    while (aux != NULL) {
        cont++;
        aux = aux->getNext();
    }

    return cont;
}

/**
 * Inserta un dato en la Cola según su prioridad
 * @tparam T
 * @param dato  dato a insertar
 */

template<class T>
void Cola<T>::encolarPrioridad(T dato, int prioridad)  {
    Nodo<T> *nuevoNodo = new Nodo<T>(dato);
    nuevoNodo->setPrioridad(prioridad);

    if (esVacia() || prioridad < inicio->getPrioridad()) {
        nuevoNodo->setNext(inicio);
        inicio = nuevoNodo;
    } else {
        Nodo<T> *anterior = nullptr;
        Nodo<T> *actual = inicio;

        while (actual != nullptr && actual->getPrioridad() <= prioridad) {
            anterior = actual;
            actual = actual->getNext();
        }

        anterior->setNext(nuevoNodo);
        nuevoNodo->setNext(actual);
    }
}

#endif // U04_COLAS_COLA_COLA_H_
