#include <iostream>
#include <deque>
using std::cout;
using std::endl;

template<typename type>
class Polinomio
{
public:
    Polinomio(int grado);
    ~Polinomio();
    void ingresar_coefisientes(const std::deque<type>& coeficientes_vec);
    void mostrar();
    int get_grado();
public:   
    Polinomio<type>& operator+(const Polinomio<type>& p1);
    Polinomio<type>& operator-(const Polinomio<type>& p1);

    ////Error: undefined reference to `operator<<(std::ostream&, Polinomio<int>&)'
    //friend std::ostream& operator<<(std::ostream& o, Polinomio<type>& p1);

private:
    std::deque<type> coeficientes_vec;
    int grado{};
};


