//convertSeconds
//Write a program that converts a total number of seconds to hours, minutes, and seconds.

#include <iostream>
using namespace std;

void convertsegun(int);

int main()
{
  int segundos;

  do
  {
    cout<<"Ingrese la cantidad de sengundos a convertir: "; cin>>segundos;
    if (segundos<0)
      cout<<"Ingrese un valor positivo!\n";
  } while (segundos<0);
  
  convertsegun(segundos);

  return 0;
}

void convertsegun(int segun)
{
  int horas, min, seg;

  min=segun/60;
  seg=segun%60;
  horas=min/60;
  min=min%60;

  cout<<segun<<" segundos son equivalentes a "<<horas<<" horas "<<min<<" minutos y "<<seg<<" segundos\n";
}
