//Reescriba el ejercicio del conteo de palabras. Imprima las palabras en forma alineada. 
// Escriba una función que encuentre la palabra más grande. 
// Una función para limpiar caracteres que no sean alfabéticos.

#include <iostream>
#include <string>
#include <map>
using namespace std;

void minuscula(string &);
string palabra_mas_grande(map<string,int>);
void limpiar_palabras(map<string,int> &);
bool detecta_numeros(string);
void mostrar_map(const map<string,int>);

int main()
{
  map<string, int> Mymap;
  string palabra;

  do
  {
    cout<<"Ingrese palabras y finalize el proceso con '0': ";cin>>palabra;
    minuscula(palabra);

    if (palabra!="0")
      ++Mymap[palabra];

  } while (palabra!="0");

  cout<<endl;

  mostrar_map(Mymap);

  cout<<"La palabra mas grande es: "<<palabra_mas_grande(Mymap)<<endl;
  cout<<"\n***ELIMINANDO PALABRAS NO ALFAVETICAS***\n";

  limpiar_palabras(Mymap);

  mostrar_map(Mymap);

  return 0;
}

string palabra_mas_grande(map<string,int> Map)
{
    int longitud{0};
    string mayor;
    for (auto element: Map)
    {
        if (longitud<(element.first).length())
        {
          longitud = (element.first).length();
          mayor = element.first;
        }
    }
    return mayor;
}

void limpiar_palabras(map<string, int> &M)
{
  for (auto element: M)
  {
    if (detecta_numeros(element.first))
    {
       M.erase(element.first);
       break;
    }
  }
}

bool detecta_numeros(string pal)
{
  for (int i = 0; i < pal.length(); i++)
  {
    for (char j = 48; j < 58; j++)
    {
      if (pal[i] == j)
        return true;
    }
  }
  return false;
}

void minuscula(string &pal)
{
  for (int i=0; i<pal.length(); i++)
    pal[i]=tolower(pal[i]);
}

void mostrar_map(const map<string,int> m)
{
  for (auto element: m)
    cout<<element.first<<"  "<<element.second<<endl;
  cout<<endl;
}