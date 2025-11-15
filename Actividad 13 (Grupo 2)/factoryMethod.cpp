#include <iostream>
using namespace std;

class Figura {
public:
    virtual ~Figura() {}
    virtual std::string Dibujar() const = 0;
    virtual std::string Area() const = 0;
};

class Circulo : public Figura {
private:
    int radio;
public:
    Circulo(int r) : radio(r) {}
    std::string Dibujar() const override {
        return "Dibujando circulo con " + std::to_string(radio) + " m de radio";
    }
    std::string Area() const override {
        return "Area del circulo: " + std::to_string(3.14*radio*radio) + " m";
    }
};
class Cuadrado : public Figura {
private:
    int lado;
public:
    Cuadrado(int l) : lado(l) {}
    std::string Dibujar() const override {
        return "Dibujando cuadrado con " + std::to_string(lado) + " m de lado";
    }
    std::string Area() const override {
        return "Area del cuadrado: " + std::to_string(lado*lado) + " m";
    }
};

class Triangulo : public Figura {
private:
    int base;
    int altura;
public:
    Triangulo(int b, int a) : base(b), altura(a) {}
    std::string Dibujar() const override {
        return "Dibujando triangulo con " + std::to_string(base) + " m de base y " + std::to_string(altura) + " m de altura";
    }
    std::string Area() const override {
        return "Area del triangulo: " + std::to_string(base*altura) + " m";
    }
};

class FiguraFactory {
public:
    virtual ~FiguraFactory(){};
    virtual Figura* CrearFigura() const = 0;//Factory Method

    void procesarFigura() const {
        Figura* product = this->CrearFigura();
        cout << product->Dibujar() << endl;
        //product->Area();
    }
};

class CirculoFactory : public FiguraFactory {
private:
    int radio;
public:
    CirculoFactory(int r) : radio(r) {}
    Figura* CrearFigura() const override {
        return new Circulo(radio);
    }
};

class CuadradoFactory : public FiguraFactory {
private:
    int lado;
public:
    CuadradoFactory(int l) : lado(l) {}
    Figura* CrearFigura() const override {
        return new Cuadrado(lado);
    }
};

class TrianguloFactory : public FiguraFactory {
private:
    int base;
    int altura;
public:
    TrianguloFactory(int b, int a) : base(b), altura(a) {}
    Figura* CrearFigura() const override {
        return new Triangulo(base, altura);
    }
};

int main() {
    cout << "=== FACTORY METHOD CON FIGURAS GEOMETRICAS ===" << endl;

    // Crear fábricas
    CirculoFactory factoryCirculo(5.0);
    CuadradoFactory factoryCuadrado(4.0);
    TrianguloFactory factoryTriangulo(6.0, 4.0);

    // Usar las fábricas
    factoryCirculo.procesarFigura();
    factoryCuadrado.procesarFigura();
    factoryTriangulo.procesarFigura();
    cout << endl;

    // También se pueden crear figuras directamente
    cout << "=== CREACION DIRECTA ===" << endl;
    int opcion;
    std::cout << "1. Circulo\n2. Cuadrado\n3. Triangulo\nElija figura: ";
    std::cin >> opcion;
    if (opcion == 1) {
        Figura* circulo = factoryCirculo.CrearFigura();
        cout << circulo->Dibujar() << endl;
        cout << circulo->Area() << endl;
    }
    else if (opcion == 2) {
        Figura* cuadrado = factoryCuadrado.CrearFigura();
        cout << cuadrado->Dibujar() << endl;
        cout << cuadrado->Area() << endl;
    }
    else if (opcion == 3) {
        Figura* triangulo = factoryTriangulo.CrearFigura();
        cout << triangulo->Dibujar() << endl;
        cout << triangulo->Area() << endl;
    } else {
        std::cout << "Opcion no valida.\n";
    }
    return 0;
}
