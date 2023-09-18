cmake_minimum_required(VERSION 3.26)
project(Parcial_1_ProgramacionIII)

set(CMAKE_CXX_STANDARD 14)

include_directories(Cola)
include_directories(Lista)
include_directories(Pila)

add_executable(Parcial_1_ProgramacionIII
        Cola/Cola.h
        Cola/Nodo.h
        Lista/CircList.h
        Lista/Lista.h
        Lista/nodo.h
        Pila/Pila.h
        main.cpp)
