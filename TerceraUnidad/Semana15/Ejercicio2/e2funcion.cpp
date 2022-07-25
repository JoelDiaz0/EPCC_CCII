#include <iostream>

using std::cout;
using std::endl;

float sumafi(float a, int b)
{
    return a + b;
}

double restalf(double a, float b)
{
    return a - b;
}

long multiplicaid(long a, int b)
{
    return a * b;
}

template<typename T, typename U>
T operacion(T (*op)(T,U), T a, U b)
{
    return op(a,b);
}

int main()
{
    cout << operacion<float,int>(sumafi,3.3,4) << endl;

    cout << operacion<double,float>(restalf,7.343,2.3) << endl;

    cout << operacion<long,int>(multiplicaid,1232313l,35) << endl;

    return 0;
}