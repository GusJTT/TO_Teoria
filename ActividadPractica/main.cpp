#include <iostream>
#include <cmath>

using namespace std;
class Vector2D{
private:
    int x;
    int y;
public:
    Vector2D(int i, int j){
        x=i;
        y=j;
    }
    inline double calcularMagnitud(){
        return sqrt(x * x + y * y);
    }
    void toString() const{
        cout << "(" << x << ", " << y << ")";
    }
    friend int productoPunto(const Vector2D& a, const Vector2D& b);
    Vector2D operator+(const Vector2D& vector) {
        return Vector2D(x + vector.x, y + vector.y);
    }
};

int productoPunto(const Vector2D& a, const Vector2D& b){
    return a.x * b.x + a.y * b.y;
}

int main(){
    Vector2D vector1(-2,4);
    Vector2D vector2(6,8);
    cout << "Vector 1: ";
    vector1.toString();
    cout << endl;
    cout << "Magnitud (vector1): " << vector1.calcularMagnitud() << endl;
    cout << "Vector 2: ";
    vector2.toString();
    cout << endl;
    cout << "Magnitud (vector2): " << vector2.calcularMagnitud() << endl;
    cout << "Producto punto: " << productoPunto(vector1, vector2) << endl;
    Vector2D vector3 = vector1 + vector2;
    cout << "Suma (vector1 + vector2): ";
    vector3.toString();
    cout << endl;
    auto detectarUmbral = [] (Vector2D& vector, double umbral){
        return vector.calcularMagnitud() > umbral;
    };
    double umbral = 5.0;
    cout << "vector1 supera el umbral " << umbral << ": "
         << (detectarUmbral(vector1, umbral) ? "Si" : "No") << endl;
    cout << "vector2 supera el umbral " << umbral << ": "
         << (detectarUmbral(vector2, umbral) ? "Si" : "No") << endl;
    return 0;
}
