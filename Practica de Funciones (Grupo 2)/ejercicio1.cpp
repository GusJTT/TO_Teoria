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
    switch (opcion)
    {
    case 1:
        double lado;
        cout<<"Ingrese lado: "<<endl;
        cin>>lado;
        cout<<"Resultado: "<<areaCuadrado(lado)<<endl;
        break;
    case 2:
        double base, altura;
        cout<<"Ingrese base: "<<endl;
        cin>>base;
        cout<<"Ingrese altura: "<<endl;
        cin>>altura;
        cout<<"Resultado: "<<areaRectangulo(base, altura)<<endl;
        break;
    case 3:
        double radio;
        cout<<"Ingrese lado: "<<endl;
        cin>>radio;
        cout<<"Resultado: "<<areaCirculo(radio)<<endl;
        break;
    default:
        cout<<"ingrese la opcion correcta!"<<endl;
        break;
    }
    return 0;
}