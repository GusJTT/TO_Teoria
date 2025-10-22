#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

int main() {
    // Creamos una lista (vector) con 5 números
    vector<int> numeros = {10, 20, 30, 40, 50};
    int indice;

    // Iniciamos el bloque try para intentar acceder al elemento del vector
    try {
        cout << "La lista tiene 5 elementos (indices del 0 al 4)." << endl;
        cout << "Ingrese el indice del elemento que desea ver: ";
        cin >> indice;

        // Usamos .at() en lugar de [] porque lanza excepción si el índice no existe
        cout << "El elemento en la posicion " << indice << " es: " << numeros.at(indice) << endl;
    }
    catch (out_of_range& e) {
        // Capturamos el error si el índice no es válido
        cout << "Error: el indice esta fuera del rango permitido." << endl;
    }
    catch (...) {
        // Cualquier otro error
        cout << "Ocurrio un error desconocido." << endl;
    }

    cout << "Programa finalizado." << endl;
    return 0;
}


