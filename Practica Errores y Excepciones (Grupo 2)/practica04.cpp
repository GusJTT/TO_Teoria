#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
    double num1, num2, resultado;

    cout << "DIVISION CON MULTIPLES EXCEPCIONES" << endl;

    try {
        cout << "Ingrese el primer numero: ";
        if (!(cin >> num1)) {
            throw invalid_argument("Error: Debe ingresar un numero valido.");
        }

        cout << "Ingrese el segundo numero: ";
        if (!(cin >> num2)) {
            throw invalid_argument("Error: Debe ingresar un numero valido.");
        }

        if (num2 == 0) {
            throw runtime_error("Error: Division por cero.");
        }

        resultado = num1 / num2;
        cout << "El resultado es: " << resultado << endl;
    }
    catch (invalid_argument &e) {
        cout << e.what() << endl;
    }
    catch (runtime_error &e) {
        cout << e.what() << endl;
    }
    finally: {
        cout << "\nOperacion finalizada." << endl;
    }

    return 0;
}
