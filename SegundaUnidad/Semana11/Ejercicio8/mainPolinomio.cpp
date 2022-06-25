#include <iostream>
#include "Polinomio.h"
using std::cout;
using std::endl;

int main()
{

    try
    {
        Polinomio<int> p7(-3);             //Exepciones: ingresar un grado menor a 1
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    Polinomio<int> p8(5);
    std::deque<int> v8 = {3,6,2,6};

    try
    {
        p8.ingresar_coefisientes(v8);       //Exepciones: ingresar una cantidad de coefisientes
    }                                       //menor o mayor que el grado del polinomio
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    Polinomio<int> p1(3), p2(3);
    std::deque<int> v1 = {5,4,3}, v2 = {3,6,2};

    p1.ingresar_coefisientes(v1);
    p2.ingresar_coefisientes(v2);
    p1.mostrar();

    cout << endl << endl;

    p2.mostrar();

    cout << endl << endl;

    p1 + p2;

    p1.mostrar();

    cout << endl <<"**********************"<<endl;

    Polinomio<int> p3(5), p4(6);
    std::deque<int> v3 = {2,5,7,5,3}, v4 = {4,6,2,10,7,3};

    p3.ingresar_coefisientes(v3);
    p4.ingresar_coefisientes(v4);

    p3.mostrar();
    cout << endl << endl;
    p4.mostrar();
    cout << endl <<endl;

    p3+p4;

    p3.mostrar();

    cout << endl <<"**********************"<<endl;

    Polinomio<float> p5(3), p6(2);

    std::deque<float> v5 = {5.2,4.5,12}, v6 = {3.5,2.7};

    p5.ingresar_coefisientes(v5);
    p6.ingresar_coefisientes(v6);

    p5.mostrar();

    cout << endl << endl;

    p6.mostrar();

    cout << endl <<endl;

    p5 - p6;

    p5.mostrar();

    cout << endl << endl;

    return 0;
}