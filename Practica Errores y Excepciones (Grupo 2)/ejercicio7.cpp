#include <iostream>
#include <Vector>
#include <limits>
#include <fstream>
#include <locale>

using namespace std;

class ArchivoInvalidoException : public std::exception {
private:
    string value;
public:
    // Constructor
    ArchivoInvalidoException(string val) : value(val) {}

    // Override what() method
    const char* what() const noexcept override {
        return "Error: Archivo no encontrado o invalido";
    }

    // Optional: method to get the invalid value
    string getValue() const {
        return value;
    }
};


class Alumno {
private:
    int codigo;
    string nombre;
    int edad;
public:
    Alumno(int c, string n, int e) : codigo(c), nombre(n), edad(e) {}

    int getCodigo() const { return codigo; }
    string getNombre() const { return nombre; }
    int getEdad() const { return edad; }

    void mostrar() const {
        cout << "Codigo: " << codigo << " | Nombre: " << nombre << " | Edad: " << edad << endl;
    }
};

class Registro {
private:
    vector<Alumno> alumnos;
public:
    bool validarEntero(string entrada) {
        if (entrada.empty()) return false;
        for (char c : entrada) {
            if (!isdigit(c)) return false;
        }
        return true;
    }
    bool validarNombre(string entrada) {
        locale loc("");
        if (entrada.empty())
            return false;
        for (char c : entrada) {
            if (!iswalpha(c) && c != ' ') {
                return false;
            }
        }
        return true;
    }

    void registrarAlumno() {
        string nombre, entrada;
        int edad = 0, codigo = 0;

        // Ingreso de código
        while (true) {
            cout << "Ingrese codigo: ";
            cin >> entrada;
            if (validarEntero(entrada)) {
                codigo = stoi(entrada);
                break;
            } else {
                cout << "Error: Ingrese un codigo valido" << std::endl;
            }
        }

        // Ingreso de nombre
        while (true) {
            cout << "Ingrese nombre: ";
            cin >> entrada;
            if (validarNombre(entrada)) {
                nombre = entrada;
                break;
            } else {
                cout << "Error: Ingrese un nombre valido" << endl;
            }
        }

        // Ingreso de edad
        while (true) {
            cout << "Ingrese edad: ";
            cin >> entrada;
            if (validarEntero(entrada)) {
                edad = stoi(entrada);
                break;
            } else {
                cout << "Error: Ingrese una edad valida" << std::endl;
            }
        }

        alumnos.emplace_back(codigo, nombre, edad);
        cout << "Alumno registrado con exito" << endl;
    }

    void buscarAlumno() {
        string entrada;
        int codigo;
        while (true) {
            cout << "Ingrese el codigo del alumno a buscar: ";
            cin >> entrada;
            if (validarEntero(entrada)) {
                codigo = stoi(entrada);
                for (const auto& alumno : alumnos) {
                    if (alumno.getCodigo() == codigo) {
                        cout << "\nAlumno encontrado:\n";
                        alumno.mostrar();
                        break;
                    }
                }
                cout << "Alumno no encontrado" << endl;
                break;
            } else {
                cout << "Error: Ingrese un codigo valido" << std::endl;
            }
        }
    }

    void guardarEnArchivo() {
        ofstream archivo("alumnos.txt");
        if (!archivo.is_open()) {
            throw ArchivoInvalidoException("alumnos.txt");
        }
        for (const auto& alumno : alumnos) {
            archivo << alumno.getCodigo() << "," << alumno.getNombre() << "," << alumno.getEdad() << "\n";
        }
        archivo.close();
        cout << "Datos guardados en alumnos.txt\n";
    }

    void cargarDesdeArchivo() {
        ifstream archivo("alumnos.txt");
        if (!archivo.is_open()) {
            throw ArchivoInvalidoException("alumnos.txt");
        }

        alumnos.clear();
        string codigoStr, nombre, edadStr;
        int edad;
        int codigo;

        while (getline(archivo, codigoStr, ',') && getline(archivo, nombre, ',') && getline(archivo, edadStr)) {
            try {
                codigo = stoi(codigoStr);
                edad = stoi(edadStr);
                alumnos.emplace_back(codigo, nombre, edad);
            } catch (...) {
                cout << "Linea corrupta ignorada.\n";
            }
        }
        archivo.close();
        cout << "Datos cargados exitosamente.\n";
    }

    void mostrarAlumnos() {
        if (alumnos.empty()) {
            cout << "No hay alumnos registrados.\n";
            return;
        }
        for (const auto& alumno : alumnos) alumno.mostrar();
    }
};

int main()
{
    Registro sistema;
    int opcion = 0;

    while (true) {
        cout << "\n====== MENU SISTEMA REGISTRO ALUMNOS ======\n";
        cout << "1. Registrar alumno\n";
        cout << "2. Buscar alumno\n";
        cout << "3. Mostrar alumnos\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        if (cin.fail()) {
            cout << "Entrada invalida, intente nuevamente" << std::endl;
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }

        try {
            switch (opcion) {
            case 1:
                sistema.registrarAlumno();
                break;
            case 2:
                sistema.buscarAlumno();
                break;
            case 3:
                sistema.mostrarAlumnos();
                break;
            case 4:
                sistema.guardarEnArchivo();
                break;
            case 5:
                sistema.cargarDesdeArchivo();
                break;
            case 6:
                cout << "Saliendo del sistema...\n";
                return 0;
            default:
                cout << "Opcion invalida. Intente nuevamente.\n";
                break;
            }
        }
        catch (const exception& e) {
            cout << "Excepcion capturada: " << e.what() << endl;
        }
    }
}
