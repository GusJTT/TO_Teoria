#include <iostream>
#include <cmath>

using namespace std;

    inline double areaCuadrado(double lado){
        return (lado*lado);
    }

    inline double areaRectangulo(double altura, double base){
        return (base*altura);
    }

    inline double areaCirculo(double radio){
        return (M_PI*pow(radio,2.0));
    }
int main(){

    cout<<"=========AREAS DE FIGURAS=========="<<endl;
    cout<<"1. Area cuadrado."<<endl;
    cout<<"2. Area Rectangulo."<<endl;
    cout<<"3. Area Circulo."<<endl;
    cout<<"Ingrese una opcion:"<<endl;

    int opcion;
    cin>>opcion;