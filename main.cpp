#include <iostream>
#include <string>
#include "Empleado.h"
#include "ArbolBST.h"

using namespace std;

int main() {
    ArbolBST arbol;
    int opcion, cod;

    do {
        cout << "\n===== SISTEMA EMPRESARIAL =====\n";
        cout << "1. Insertar   2. Buscar      3. Eliminar\n";
        cout << "4. Actualizar 5. Ver Raiz    6. Inorden\n";
        cout << "7. Preorden   8. Postorden   9. Altura\n";
        cout << "10. Ver Hojas 0. Salir\n";
        cout << "Opcion: ";
        
        if (!(cin >> opcion)) { 
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (opcion) {
            case 1: {
                int c; string n, car;
                cout << "Codigo: "; cin >> c; cin.ignore();
                cout << "Nombre: "; getline(cin, n);
                cout << "Cargo: ";  getline(cin, car);
                
                Empleado nuevoEmpleado(c, n, car);
                arbol.insertarEmpleado(nuevoEmpleado);
                break;
            }
            case 2: cout << "Codigo: "; cin >> cod; arbol.buscarEmpleado(cod); break;
            case 3: cout << "Codigo a eliminar: "; cin >> cod; arbol.eliminarEmpleado(cod); break;
            case 4: cout << "Codigo a actualizar: "; cin >> cod; arbol.actualizarEmpleado(cod); break;
            case 5: arbol.mostrarRaiz(); break;
            case 6: arbol.mostrarInorden(); break;
            case 7: arbol.mostrarPreorden(); break;
            case 8: arbol.mostrarPostorden(); break;
            case 9: arbol.mostrarAltura(); break;
            case 10: arbol.mostrarNodosHoja(); break;
        }
    } while (opcion != 0);

    return 0;
}