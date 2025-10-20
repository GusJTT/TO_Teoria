#include <iostream>
#include <iomanip> // para setw y setfill
using namespace std;

class Fecha {
private:
    int dia, mes, anio;
    // Método privado para validar día (no considero distintos meses con 30/31/febrero con 28/29 por simplicidad)
    int validarDia(int d) {
        if (d < 1 || d > 31) return 1; // si está fuera, lo corrijo a 1
        return d;
    }
    // Método privado para validar mes
    int validarMes(int m) {
        if (m < 1 || m > 12) return 1;
        return m;
    }
public:
    // Constructor: aplico validación simple al crear la fecha
    Fecha(int d, int m, int a) : dia(validarDia(d)), mes(validarMes(m)), anio(a) {}

    // Sobrecargo operator<< como friend para poder acceder a atributos privados
    friend ostream& operator<<(ostream& salida, const Fecha& f) {
        // Uso setw(2) y setfill('0') para asegurar 2 dígitos en día y mes
        salida << setw(2) << setfill('0') << f.dia << "/"
               << setw(2) << setfill('0') << f.mes << "/"
               << f.anio;
        // Importante: restablecer fill no es estrictamente necesario aquí
        return salida;
    }
};

int main() {
    // Pruebo varias fechas, incluyendo una inválida para demostrar la corrección
    Fecha f1(7, 3, 2024);
    Fecha f2(15, 11, 2025);
    Fecha f3(32, 13, 2023); // valores fuera de rango -> se normalizan a 01/01/2023

    cout << "Fecha 1: " << f1 << endl;
    cout << "Fecha 2: " << f2 << endl;
    cout << "Fecha 3 (corregida): " << f3 << endl;

    return 0;
}
