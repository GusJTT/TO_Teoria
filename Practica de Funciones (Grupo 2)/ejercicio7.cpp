#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

inline double calcularDescuento(double precio, double porcentaje) {
    return precio - (precio * porcentaje / 100.0);
}

class Producto {
private:
    string nombre;
    double precio;
    int cantidad;

public:
    Producto(string n = "", double p = 0.0, int c = 0)
        : nombre(n), precio(p), cantidad(c) {}

    void mostrar() const {
        cout << "Producto: " << nombre
             << " | Precio: " << precio
             << " | Cantidad: " << cantidad << endl;
    }

    friend ostream& operator<<(ostream& os, const Producto& p);

    double getPrecio() const { return precio; }
    int getCantidad() const { return cantidad; }
    string getNombre() const { return nombre; }

    friend bool compararPrecio(const Producto& a, const Producto& b);

    Producto operator+(const Producto& otro) {
        return Producto(nombre + " & " + otro.nombre,
                        this->precio + otro.precio,
                        this->cantidad + otro.cantidad);
    }
};

ostream& operator<<(ostream& os, const Producto& p) {
    os << "Producto: " << p.nombre
       << " | Precio: " << p.precio
       << " | Cantidad: " << p.cantidad;
    return os;
}

bool compararPrecio(const Producto& a, const Producto& b) {
    return a.precio < b.precio;
}

class SistemaProductos {
private:
    vector<Producto> productos;

public:
    void agregarProducto() {
        string nombre;
        double precio;
        int cantidad;

        cout << "Ingrese nombre del producto: ";
        cin.ignore();
        getline(cin, nombre);

        cout << "Ingrese precio: ";
        cin >> precio;
        cout << "Ingrese cantidad: ";
        cin >> cantidad;

        productos.emplace_back(nombre, precio, cantidad);
        cout << "Producto agregado con exito.\n";
    }

    void mostrarProductos() const {
        if (productos.empty()) {
            cout << "No hay productos registrados.\n";
            return;
        }
        cout << "\n=== Lista de Productos ===\n";
        for (const auto& p : productos) {
            cout << p << endl;
        }
    }

    void filtrarPorPrecio() const {
        if (productos.empty()) {
            cout << "No hay productos para filtrar.\n";
            return;
        }
        double filtro;
        cout << "Ingrese precio minimo: ";
        cin >> filtro;

        cout << "\nProductos con precio mayor a " << filtro << ":\n";
        for_each(productos.begin(), productos.end(), [filtro](const Producto& p) {
            if (p.getPrecio() > filtro)
                cout << p << endl;
        });
    }

    void combinarProductos() {
        if (productos.size() < 2) {
            cout << "Se necesitan al menos dos productos para combinar.\n";
            return;
        }

        int a, b;
        mostrarProductos();
        cout << "Seleccione indice del primer producto (0 a " << productos.size() - 1 << "): ";
        cin >> a;
        cout << "Seleccione indice del segundo producto: ";
        cin >> b;

        if (a >= 0 && a < productos.size() && b >= 0 && b < productos.size()) {
            Producto combinado = productos[a] + productos[b];
            cout << "\nProducto combinado: " << combinado << endl;
        } else {
            cout << "Indices inválidos.\n";
        }
    }

    void aplicarDescuento() {
        if (productos.empty()) {
            cout << "No hay productos registrados.\n";
            return;
        }

        int indice;
        double descuento;
        mostrarProductos();
        cout << "Seleccione el indice del producto para aplicar descuento: ";
        cin >> indice;
        cout << "Ingrese porcentaje de descuento: ";
        cin >> descuento;

        if (indice >= 0 && indice < productos.size()) {
            double precioOriginal = productos[indice].getPrecio();
            double nuevoPrecio = calcularDescuento(precioOriginal, descuento);
            cout << "Precio original: " << precioOriginal
                 << " | Precio con descuento: " << nuevoPrecio << endl;
        } else {
            cout << "Indice invalido.\n";
        }
    }
};

int main() {
    SistemaProductos sistema;
    int opcion;

    do {
        cout << "\n====== SISTEMA DE PRODUCTOS ======\n";
        cout << "1. Agregar producto\n";
        cout << "2. Mostrar productos\n";
        cout << "3. Filtrar productos por precio\n";
        cout << "4. Combinar dos productos\n";
        cout << "5. Aplicar descuento\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: sistema.agregarProducto(); break;
        case 2: sistema.mostrarProductos(); break;
        case 3: sistema.filtrarPorPrecio(); break;
        case 4: sistema.combinarProductos(); break;
        case 5: sistema.aplicarDescuento(); break;
        case 6: cout << "Saliendo del sistema...\n"; break;
        default: cout << "Opcion invalida.\n"; break;
        }

    } while (opcion != 6);

    return 0;
}
