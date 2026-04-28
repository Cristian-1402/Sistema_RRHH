#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>

class Empleado {
private:
    int codigo;
    std::string nombre;
    std::string cargo;

public:
    // Constructor
    Empleado(int cod = 0, std::string nom = "", std::string car = "");

    // Getters
    int getCodigo() const;
    std::string getNombre() const;
    std::string getCargo() const;

    // Setters
    void setNombre(const std::string& nom);
    void setCargo(const std::string& car);

    // Métodos
    void mostrarInfo() const;
};

#endif