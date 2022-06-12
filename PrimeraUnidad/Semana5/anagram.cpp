//Dos palabras son anagramas si contienen las mismas
//letras y el mismo número de cada letra.

#include <iostream>
#include <string>
using namespace std;

bool anagram (string,string);
bool igual_tam(string,string);
string minuscula(string);

int main()
{
    string palabra1, palabra2;

    cout<<"Ingrese una palabra: "; getline(cin,palabra1);
    cout<<"Ingrese otra palabra: "; getline(cin,palabra2);

    if (anagram(palabra1,palabra2))
       cout<<"Son Anagram";
    else
       cout<<"No son Anagram";
    
    return 0;
}

bool anagram(string p1,string p2)
{
    if (p1.length() != p2.length())
       return false;
    
    p1 = minuscula(p1);
    p2 = minuscula(p2);
    
    if (igual_tam(p1,p2))
       return true;
    
    return false;
}

bool igual_tam(string p1,string p2)
{
    int cont1, cont2, pos;
    
    for (int i = 0; i < p1.length(); i++)
    {
        cont1 = 0; cont2 = 0; pos = 0;     
        for (int j = 0; j < p1.length(); j++)
        {
            if (p1[i] == p2[j])
            {
              pos = j;
              cont1++;
            }
        }
        for (int j = 0; j < p1.length(); j++)
        {
            if (p2[pos] == p1[j])
              cont2++;
        }

        if (cont1 != cont2)
          return false;
    }
    return true;    
}

string minuscula(string pal)
{
    for (int i = 0; i < pal.length(); i++)
        pal[i] = tolower(pal[i]);
    return pal;
}