#ifndef U02_LISTAS_FRANCCASAVECCHIAUCC_NODO_H
#define U02_LISTAS_FRANCCASAVECCHIAUCC_NODO_H

#ifndef NODO_H
#define NODO_H

template<class T>
class Nodo {
private:
    T dato;
    T prioridad;
    Nodo<T> *next;
public:
    Nodo(T dato, Nodo<T> *next) : dato(dato), next(next) {}

    Nodo(T dato) : dato(dato) {
        this->next = NULL;
    }

    T getDato() const {
        return dato;
    }

    void setDato(T dato) {
        Nodo::dato = dato;
    }

    Nodo<T> *getNext() const {
        return next;
    }

    void setNext(Nodo<T> *next) {
        Nodo::next = next;
    }

    int getPrioridad() const {
        return prioridad;
    }

    void setPrioridad(int nuevaPrioridad) {
        prioridad = nuevaPrioridad;
    }

};
#endif //NODO_H

#endif //U02_LISTAS_FRANCCASAVECCHIAUCC_NODO_H
