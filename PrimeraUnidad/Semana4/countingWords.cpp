//countingWords

//Your task is to write a program that reads words and counts the frequency of each unique word. 
//A word is a string of nonspace characters separated by white space.

#include <iostream>
#include <string>
#include <map>

using namespace std;

string minuscula(string &);

int main()
{
  map<string, int> Mymap;
  map<string, int>::iterator iter;

  string palabra;

  do
  {
    cout<<"Ingrese palabras y finalize el proceso con '0': ";cin>>palabra;
    minuscula(palabra);

    if (palabra!="0")
      ++Mymap[palabra];

  } while (palabra!="0");
  
  for (iter=Mymap.begin(); iter!=Mymap.end(); iter++)
  {
    cout<<"Frecuencia: "<<iter->first<<"   Palabra: "<<iter->second<<endl;
  }
  return 0;
}

string minuscula(string &pal)
{
  for (int i=0; i<pal.length(); i++)
  {
    pal[i]=tolower(pal[i]);
  }
  return pal;
}