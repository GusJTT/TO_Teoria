#include <iostream>
using namespace std;

class Vector2D {
private:
    float x, y; // coordenadas del vector (x, y)

public:
    // --- Constructor: si no paso valores, el vector será (0,0)
    Vector2D(float x_val = 0.0f, float y_val = 0.0f) : x(x_val), y(y_val) {}

    // --- Sobrecarga del operador +:
    // Devuelve un nuevo Vector2D que es la suma componente a componente.
    Vector2D operator+(const Vector2D& v) const {
        // aquí sumo x con x y y con y y retorno el vector resultado
        return Vector2D(x + v.x, y + v.y);
    }

    // --- Sobrecarga del operador ==:
    // Comprueba si ambos componentes son exactamente iguales.
    bool operator==(const Vector2D& v) const {
        return (x == v.x && y == v.y);
    }

    // --- Método para imprimir el vector (lo dejo como método de la clase)
    void mostrar() const {
        cout << "(" << x << ", " << y << ")";
    }
};

int main() {
    // Creo dos vectores de ejemplo
    Vector2D v1(2.0f, 3.0f);
    Vector2D v2(4.0f, 1.0f);

    // Uso del operador + (gracias a la sobrecarga)
    Vector2D suma = v1 + v2;

    // Muestro los resultados (uso mi método mostrar)
    cout << "v1 = "; v1.mostrar(); cout << endl;
    cout << "v2 = "; v2.mostrar(); cout << endl;
    cout << "Suma = "; suma.mostrar(); cout << endl;

    // Comparación con operator==
    if (v1 == v2)
        cout << "v1 y v2 son iguales" << endl;
    else
        cout << "v1 y v2 son distintos" << endl;

    return 0;
}
