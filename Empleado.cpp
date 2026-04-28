#include "Empleado.h"
#include <iostream>

Empleado::Empleado(int cod, std::string nom, std::string car) 
    : codigo(cod), nombre(nom), cargo(car) {}

int Empleado::getCodigo() const { return codigo; }
std::string Empleado::getNombre() const { return nombre; }
std::string Empleado::getCargo() const { return cargo; }

void Empleado::setNombre(const std::string& nom) { nombre = nom; }
void Empleado::setCargo(const std::string& car) { cargo = car; }

void Empleado::mostrarInfo() const {
    std::cout << "[ID: " << codigo << "] " << nombre << " - " << cargo << std::endl;
}