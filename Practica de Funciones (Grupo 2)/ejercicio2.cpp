#include <iostream>
using namespace std;

class Caja {
private:
    double peso;

public:
    Caja(double p = 0.0) {
        peso = p;
    }
    
    friend void comparar(Caja c1, Caja c2);
    friend void compararTres(Caja c1, Caja c2, Caja c3);
};

void comparar(Caja c1, Caja c2) {
    cout << "Caja 1: " << c1.peso << " kg" << endl;
    cout << "Caja 2: " << c2.peso << " kg" << endl;
    
    if (c1.peso > c2.peso) {
        cout << "La Caja 1 pesa mas" << endl;
    } else if (c2.peso > c1.peso) {
        cout << "La Caja 2 pesa mas" << endl;
    } else {
        cout << "Pesan lo mismo" << endl;
    }
}

