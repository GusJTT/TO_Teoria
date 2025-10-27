#include <iostream>     
#include <stdexcept>    
#include <string>       
using namespace std;    

//excepción personalizada
//declaramos de una clase que hereda de exception
class ErrorConexion : public exception {   private:
    string mensaje; //almacenar el texto del error
public:
// Constructor que inicializa 'mensaje'

    ErrorConexion(const string& msg) : mensaje(msg) {} 
    const char* what() const noexcept override {               
        return mensaje.c_str();                       
    }
};

// Función que simula una conexión a servidor
void conectarServidor(const string& servidor, bool disponible) {
    cout << "Intentando conectar con: " << servidor << endl; 
    
    if (!disponible) {                                       
        throw ErrorConexion("No se pudo establecer la conexión con el servidor: " + servidor);
        // Lanza (throw) una excepción del tipo ErrorConexion con un mensaje personalizado
    }

    cout << "Conexión exitosa con " << servidor << " " << endl;
    }

int main() {
    try { 
        conectarServidor("ServidorCentral", false); 
        conectarServidor("ServidorBackup", true);       
    }
    catch (const ErrorConexion& e) {         
        cerr << "Error de conexión : " << e.what() << endl; 	
    }
    catch (const exception& e) { 
        cerr << "Otro error detectado: " << e.what() << endl;
    }

    cout << "Programa finalizado " << endl; 
    return 0; 
}