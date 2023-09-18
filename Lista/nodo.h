//
// Created by franc on 7/9/2023.
//

#ifndef U02_LISTAS_FRANCCASAVECCHIAUCC_NODO_H
#define U02_LISTAS_FRANCCASAVECCHIAUCC_NODO_H

#ifndef NODO_H
#define NODO_H

template<class T>
class Nodo{
private:
    T dato;
    Nodo<T> *siguiente;

public:
    T getDato(){
        return dato;
    }

    void setDato(T d){
        dato = d;
    }

    Nodo<T> *getSiguiente(){
        return siguiente;
    }

    void setSiguiente(Nodo<T> *siguiente){
        this->siguiente = siguiente;
    }


};

#endif //NODO_H

#endif //U02_LISTAS_FRANCCASAVECCHIAUCC_NODO_H
