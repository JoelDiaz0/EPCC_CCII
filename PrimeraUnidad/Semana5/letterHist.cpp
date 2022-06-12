//Escriba una función letterHist que tome un string como
//parámetro y devuelva un histograma de las letras del string.

#include <iostream>
#include <string>
using namespace std;

void letterHist(string);
void minuscula(string &);
int repite(char,string);
bool esta(char,string);

int main()
{
    string palabra;
    
    cout<<"Ingrese una palabra cualquiera: "; cin>>palabra;
    cout<<"\n***"<<palabra<<"***\n\nCANTIDAD DE LETRAS REPETIDAS:\n\n";
    letterHist(palabra);

    return 0;
}

void letterHist(string pal)
{
    minuscula(pal);
    string norepetir = "";
    for (int i=0; i<pal.length(); i++)
    {
        if (repite(pal[i],pal)>0 && esta(pal[i],norepetir) == false)
        {
          cout<<pal[i]<<": ";
          norepetir += pal[i];
          for (int j = 0; j < repite(pal[i],pal); j++)
            cout<<"*";
          cout<<endl;
        }      
    }
}

int repite(char letra, string palabra)
{
    int cont = 0;
    for (int i=0; i < palabra.length(); i++)
    {
        if (letra == palabra[i])
           cont++;
    }
    return cont;
}

bool esta(char letra, string palabra)
{
    for (int i=0; i < palabra.length(); i++)
    {
        if (letra == palabra[i])
           return true;
    }
    return false;
}

void minuscula(string &pal)
{
    for (int i = 0; i < pal.length(); i++)
       pal[i] = tolower(pal[i]);
}