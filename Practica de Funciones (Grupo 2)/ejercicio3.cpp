#include <iostream>

using namespace std;

class Empleado {
private:
    string nombre;
    int edad;
    double salario;
public:
    Empleado(string n, int e, double s) {
        nombre = n;
        edad = e;
        salario = s;
    }
    void mostrarDatos() const{
        cout << nombre << ":"<< endl;
        cout << "Edad: " << edad << " años" << endl;
        cout << "Salario: S/" << salario << endl;
    }
};

int main(){
    Empleado empleado1("Juan Perez", 30, 1500.00);
    Empleado empleado2("Maria Morales", 25, 1200.00);
    Empleado empleado3("Jose Lopez", 22, 1100.00);
    empleado1.mostrarDatos();
    empleado2.mostrarDatos();
    empleado3.mostrarDatos();
    return 0;
}
