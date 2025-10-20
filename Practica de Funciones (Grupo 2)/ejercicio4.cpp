#include <algorithm>
#include <iostream>
#include <Vector>
#include <numeric>

using namespace std;

int main(){
    vector<int> numeros = {4, 5, 8, 7, 3, 10, 2, 15, 1, 9};
    auto imprimir = [](const vector<int>& v) {
        for (int n : v) {
            cout << n << " ";
        }
    };
    auto contarPares = count_if(numeros.begin(), numeros.end(),
                                     [](int n) { return n % 2 == 0; });
    auto sumaTotal = std::accumulate(numeros.begin(), numeros.end(), 0);
    int valor = 7;

    cout << "Cantidad de elementos pares: " << contarPares << endl;
    cout << "Suma total del vector: " << sumaTotal << endl;
    cout << "Numeros mayores que " << valor << " en el vector: ";

    for_each(numeros.begin(), numeros.end(), [valor](int numero) {
        if (numero > valor)
            cout << numero << " ";
    });
    cout << endl;
    cout << "Elementos del vector: ";
    imprimir(numeros);
    cout << endl;
    sort(numeros.begin(), numeros.end(), [](int a, int b) {
        return a < b;
    });

    cout << "Elementos del vector ordenado: ";
    imprimir(numeros);
    cout << endl;
    return 0;
}
