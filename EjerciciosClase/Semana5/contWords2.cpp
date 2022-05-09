//Reescriba el ejercicio del conteo de palabras. Imprima las palabras en forma alineada. 
// Escriba una función que encuentre la palabra más grande. 
// Una función para limpiar caracteres que no sean alfabéticos.

#include <iostream>
#include <string>
#include <map>
using namespace std;

string minuscula(string &);
string palabra_mas_grande(map<string,int>);
void limpiar_palabras(map<string,int> &);

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
  
  for (auto element: Mymap)
    cout<<element.first<<"\t"<<element.second<<endl;

  cout<<"La palabra mas grande es: "<<palabra_mas_grande(Mymap)<<endl;
  cout<<"\n***ELIMINANDO PALABRAS NO ALFAVETICAS***\n";

  limpiar_palabras(Mymap);

  for (auto element: Mymap)
    cout<<element.first<<"\t"<<element.second<<endl;
  
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

void limpiar_palabras(map<string,int> &Map)
{
    map<string,int> :: iterator iter;
    string aux;

    for (iter=Map.begin(); iter!=Map.end(); iter++)
    {
        aux = iter->first;
        for (int i=0; i<aux.length(); i++)
        {
            for (char c=48; c<=57; c++)
            {
              if (aux[i] == c)
                Map.erase(aux);
            }
        }
    }
}

string minuscula(string &pal)
{
  for (int i=0; i<pal.length(); i++)
  {
    pal[i]=tolower(pal[i]);
  }
  return pal;
}
