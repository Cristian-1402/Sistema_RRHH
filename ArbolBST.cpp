#include "ArbolBST.h"
#include <iostream>
#include <algorithm>

using namespace std;

// Constructor del Nodo
ArbolBST::Nodo::Nodo(Empleado emp) : empleado(emp), izquierdo(nullptr), derecho(nullptr) {}

// Constructor y Destructor del Árbol
ArbolBST::ArbolBST() : raiz(nullptr) {}
ArbolBST::~ArbolBST() { vaciar(raiz); }

// Métodos Privados
void ArbolBST::vaciar(Nodo* nodo) {
    if (nodo != nullptr) {
        vaciar(nodo->izquierdo);
        vaciar(nodo->derecho);
        delete nodo;
    }
}

ArbolBST::Nodo* ArbolBST::insertar(Nodo* nodo, Empleado emp) {
    if (nodo == nullptr) return new Nodo(emp);

    if (emp.getCodigo() < nodo->empleado.getCodigo())
        nodo->izquierdo = insertar(nodo->izquierdo, emp);
    else if (emp.getCodigo() > nodo->empleado.getCodigo())
        nodo->derecho = insertar(nodo->derecho, emp);
    else
        cout << "Error: El codigo " << emp.getCodigo() << " ya existe.\n";

    return nodo;
}

ArbolBST::Nodo* ArbolBST::buscar(Nodo* nodo, int codigo) const {
    if (nodo == nullptr || nodo->empleado.getCodigo() == codigo) return nodo;

    if (codigo < nodo->empleado.getCodigo())
        return buscar(nodo->izquierdo, codigo);
    else
        return buscar(nodo->derecho, codigo);
}

ArbolBST::Nodo* ArbolBST::encontrarMinimo(Nodo* nodo) const {
    while (nodo && nodo->izquierdo != nullptr) nodo = nodo->izquierdo;
    return nodo;
}

ArbolBST::Nodo* ArbolBST::eliminar(Nodo* nodo, int codigo) {
    if (nodo == nullptr) return nullptr;

    if (codigo < nodo->empleado.getCodigo())
        nodo->izquierdo = eliminar(nodo->izquierdo, codigo);
    else if (codigo > nodo->empleado.getCodigo())
        nodo->derecho = eliminar(nodo->derecho, codigo);
    else {
        if (nodo->izquierdo == nullptr) {
            Nodo* temp = nodo->derecho;
            delete nodo;
            return temp;
        } else if (nodo->derecho == nullptr) {
            Nodo* temp = nodo->izquierdo;
            delete nodo;
            return temp;
        }
        Nodo* temp = encontrarMinimo(nodo->derecho);
        nodo->empleado = temp->empleado;
        nodo->derecho = eliminar(nodo->derecho, temp->empleado.getCodigo());
    }
    return nodo;
}

void ArbolBST::inorden(Nodo* nodo) const {
    if (nodo != nullptr) {
        inorden(nodo->izquierdo);
        nodo->empleado.mostrarInfo();
        inorden(nodo->derecho);
    }
}

void ArbolBST::preorden(Nodo* nodo) const {
    if (nodo != nullptr) {
        nodo->empleado.mostrarInfo();
        preorden(nodo->izquierdo);
        preorden(nodo->derecho);
    }
}

void ArbolBST::postorden(Nodo* nodo) const {
    if (nodo != nullptr) {
        postorden(nodo->izquierdo);
        postorden(nodo->derecho);
        nodo->empleado.mostrarInfo();
    }
}

int ArbolBST::altura(Nodo* nodo) const {
    if (nodo == nullptr) return 0;
    return 1 + max(altura(nodo->izquierdo), altura(nodo->derecho));
}

void ArbolBST::mostrarHojas(Nodo* nodo) const {
    if (nodo != nullptr) {
        if (nodo->izquierdo == nullptr && nodo->derecho == nullptr)
            nodo->empleado.mostrarInfo();
        mostrarHojas(nodo->izquierdo);
        mostrarHojas(nodo->derecho);
    }
}

// Métodos Públicos
void ArbolBST::insertarEmpleado(Empleado emp) { raiz = insertar(raiz, emp); }

void ArbolBST::buscarEmpleado(int codigo) const {
    Nodo* res = buscar(raiz, codigo);
    if (res) { cout << "\nEncontrado: "; res->empleado.mostrarInfo(); }
    else cout << "\nEmpleado no encontrado.\n";
}

void ArbolBST::eliminarEmpleado(int codigo) {
    if (buscar(raiz, codigo)) {
        raiz = eliminar(raiz, codigo);
        cout << "Empleado " << codigo << " eliminado.\n";
    } else cout << "No se pudo eliminar: Codigo inexistente.\n";
}

void ArbolBST::actualizarEmpleado(int codigo) {
    Nodo* res = buscar(raiz, codigo);
    if (res) {
        string nuevoNombre, nuevoCargo;
        cout << "Nuevo Nombre: "; cin.ignore(); getline(cin, nuevoNombre);
        cout << "Nuevo Cargo: "; getline(cin, nuevoCargo);
        res->empleado.setNombre(nuevoNombre);
        res->empleado.setCargo(nuevoCargo);
        cout << "Datos actualizados correctamente.\n";
    } else cout << "Empleado no encontrado.\n";
}

void ArbolBST::mostrarRaiz() const {
    if (raiz) { cout << "\nRaiz: "; raiz->empleado.mostrarInfo(); }
    else cout << "Arbol vacio.\n";
}

void ArbolBST::mostrarInorden() const { cout << "\n--- INORDEN ---\n"; inorden(raiz); }
void ArbolBST::mostrarPreorden() const { cout << "\n--- PREORDEN ---\n"; preorden(raiz); }
void ArbolBST::mostrarPostorden() const { cout << "\n--- POSTORDEN ---\n"; postorden(raiz); }
void ArbolBST::mostrarAltura() const { cout << "\nAltura: " << altura(raiz) << endl; }
void ArbolBST::mostrarNodosHoja() const { cout << "\n--- HOJAS ---\n"; mostrarHojas(raiz); }