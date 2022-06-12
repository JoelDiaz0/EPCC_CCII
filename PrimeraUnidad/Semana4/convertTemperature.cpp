
//CONVERT TEMPERATURE
//Write a program that converts a temperature from Celsius to Fahrenheit. 

#include <iostream>
using namespace std;

double cels_to_faren(double);

int main()
{
  double num;

  do
  {
    cout<<"Ingrese un valor en escala celsius (-273 a 100): "; cin>>num;
    if (num<-273||num>100)
      cout<<"Ingrese un valor valido!\n";
  } while (num<-273||num>100);

  cout<<"El valor ingresado convertido a fahrenheit es: "<<cels_to_faren(num)<<endl;

  return 0;
}

double cels_to_faren(double cel)
{
  return (cel*9/5)+32;
}