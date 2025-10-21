#include <iostream>
#include <stdexcept> // Para usar excepciones estándar
using namespace std;

// Creamos nuestra excepción personalizada
class EdadInvalidaException : public exception {
public:
    const char* what() const noexcept override {
        return "Edad fuera de rango"; // Mensaje que mostrará si se lanza la excepción
    }
};

int main() {
    int edad;

    // Iniciamos el bloque try para probar código que podría causar un error
    try {
        cout << "Ingrese su edad: ";
        cin >> edad;

        // Si la edad no es válida, lanzamos la excepción
        if (edad < 0 || edad > 120) {
            throw EdadInvalidaException();
        }

        // Si no hay error, mostramos la edad
        cout << "Edad valida: " << edad << " anios." << endl;
    }
    catch (EdadInvalidaException& e) {
        // Capturamos y mostramos el mensaje de error
        cout << "Error: " << e.what() << endl;
    }
    catch (...) {
        // Captura de cualquier otro error no previsto
        cout << "Error desconocido." << endl;
    }

    cout << "Programa finalizado." << endl;
    return 0;
}
