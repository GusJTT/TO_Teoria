#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;

int main() {
    string nombreArchivo;
    string linea;

    cout << "LECTURA DE ARCHIVO SEGURA" << endl;
    cout << "Ingrese el nombre del archivo: ";
    cin >> nombreArchivo;

    try {
        ifstream archivo(nombreArchivo);

        if (!archivo.is_open()) {
            throw runtime_error("Error: No se pudo abrir el archivo.");
        }

        cout << "\nContenido del archivo:\n";
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }

        archivo.close();
    }
    catch (runtime_error &e) {
        cout << e.what() << endl;
    }
    finally: { // Nota: en C++ no existe finally, se simula con un bloque final
        cout << "\nOperacion finalizada." << endl;
    }

    return 0;
}
