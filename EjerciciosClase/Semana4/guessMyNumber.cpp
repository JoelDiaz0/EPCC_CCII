//guessMyNumber
//The goal of this exercise is to program a Guess My Number game. When it's finished, it should work like this:

#include <iostream>
#include <random>
#include <time.h>
using namespace std;

int numrandom();

int main()
{
  srand(time(NULL));

  int num, ran;
  cout<<"Estoy pensando en un numero del 1 al 100 (Inclutendo ambos)...\n";
  cout<<"Puedes adivinar cual es?: \n";
  ran=numrandom();
  
  //cout<<ran<<endl;

  do
  {
    cout<<"Escribe un numero: "; cin>>num;
    if (num<1||num>100)
      cout<<"Debe estar entre 1 y 100!\n";
  } while (num<1||num>100);

  cout<<"Ingresaste "<<num<<endl;

  if (num!=ran)
  {
    cout<<"El numero en que estaba pensado fue "<<ran<<endl;
    if (num>ran)
      cout<<"Te pasaste por "<<num-ran<<endl;
    else
      cout<<"Te falto "<<ran-num<<endl;
  }
  else
    cout<<"Felicidades, "<<ran<<" era el numero en que estaba pensando\n";
  return 0;
}

int numrandom()
{
  return rand()%(102-1);
}
