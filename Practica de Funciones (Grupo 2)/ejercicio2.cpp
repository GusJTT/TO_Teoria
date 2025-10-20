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

void compararTres(Caja c1, Caja c2, Caja c3) {
    cout << "Caja 1: " << c1.peso << " kg" << endl;
    cout << "Caja 2: " << c2.peso << " kg" << endl;
    cout << "Caja 3: " << c3.peso << " kg" << endl;
    
    if (c1.peso >= c2.peso && c1.peso >= c3.peso) {
        cout << "La Caja 1 pesa mas" << endl;
    } else if (c2.peso >= c1.peso && c2.peso >= c3.peso) {
        cout << "La Caja 2 pesa mas" << endl;
    } else {
        cout << "La Caja 3 pesa mas" << endl;
    }
}

int main() {
    double p1, p2, p3;
    int opcion;
    
    cout << "1. Comparar 2 cajas" << endl;
    cout << "2. Comparar 3 cajas" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    
    if (opcion == 1) {
        cout << "Peso Caja 1: ";
        cin >> p1;
        cout << "Peso Caja 2: ";
        cin >> p2;
        
        Caja caja1(p1);
        Caja caja2(p2);
        
        comparar(caja1, caja2);
    } else if (opcion == 2) {
        cout << "Peso Caja 1: ";
        cin >> p1;
        cout << "Peso Caja 2: ";
        cin >> p2;
        cout << "Peso Caja 3: ";
        cin >> p3;
        
        Caja caja1(p1);
        Caja caja2(p2);
        Caja caja3(p3);
        
        compararTres(caja1, caja2, caja3);
    }
    
    return 0;
}