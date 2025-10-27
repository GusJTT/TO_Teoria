#include <iostream>
using namespace std;

// Clase base
class Vehiculo {
public:
    virtual Vehiculo* clonar() const { // Método covariante
        cout << "Clonando Vehículo genérico" << endl;
        return new Vehiculo(*this);
    }

    virtual void mostrar() const {
        cout << "Soy un vehículo genérico" << endl;
    }

    virtual ~Vehiculo() {} // Destructor virtual
};

// Clase derivada Auto
class Auto : public Vehiculo {
public:
    Auto* clonar() const override {
        cout << "Clonando un Auto" << endl;
        return new Auto(*this);
    }

    void mostrar() const override {
        cout << "Soy un Auto" << endl;
    }
};

// Clase derivada Moto
class Moto : public Vehiculo {
public:
    Moto* clonar() const override {
        cout << "Clonando una Moto" << endl;
        return new Moto(*this);
    }

    void mostrar() const override {
        cout << "Soy una Moto" << endl;
    }
};

int main() {
    Vehiculo* v1 = new Auto();
    Vehiculo* clon1 = v1->clonar();
    clon1->mostrar();

    Vehiculo* v2 = new Moto();
    Vehiculo* clon2 = v2->clonar();
    clon2->mostrar();

    delete v1;
    delete v2;
    delete clon1;
    delete clon2;

    return 0;
}
