#ifndef ARBOLBST_H
#define ARBOLBST_H

#include "Empleado.h"

class ArbolBST {
private:
    class Nodo {
    public:
        Empleado empleado;
        Nodo* izquierdo;
        Nodo* derecho;

        Nodo(Empleado emp);
    };

    Nodo* raiz;

    // Métodos privados internos
    void vaciar(Nodo* nodo);
    Nodo* insertar(Nodo* nodo, Empleado emp);
    Nodo* buscar(Nodo* nodo, int codigo) const;
    Nodo* encontrarMinimo(Nodo* nodo) const;
    Nodo* eliminar(Nodo* nodo, int codigo);
    
    void inorden(Nodo* nodo) const;
    void preorden(Nodo* nodo) const;
    void postorden(Nodo* nodo) const;
    int altura(Nodo* nodo) const;
    void mostrarHojas(Nodo* nodo) const;

public:
    ArbolBST();
    ~ArbolBST();

    void insertarEmpleado(Empleado emp);
    void buscarEmpleado(int codigo) const;
    void eliminarEmpleado(int codigo);
    void actualizarEmpleado(int codigo);
    void mostrarRaiz() const;
    void mostrarInorden() const;
    void mostrarPreorden() const;
    void mostrarPostorden() const;
    void mostrarAltura() const;
    void mostrarNodosHoja() const;
};

#endif