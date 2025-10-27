#include <iostream>
using namespace std;

class Animal {
public:
    virtual void hacerSonido() {
        cout << "El animal hace un sonido" << endl;
    }
};

class Perro : public Animal {
public:
    void hacerSonido() override {
        cout << "El perro ladra" << endl;
    }
};

class Gato : public Animal {
public:
    void hacerSonido() override {
        cout << "El gato maulla" << endl;
    }
};

// plantilla que acepta punteros a la clase base
template <typename T>
void procesarAnimal(T* animal) {
    animal->hacerSonido();
}

int main() {
    Perro perro;
    Gato gato;

    // podemos pasar punteros a Animal, aunque el objeto sea un Perro o Gato
    procesarAnimal<Animal>(&perro);
    procesarAnimal<Animal>(&gato);

    return 0;
}