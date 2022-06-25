#include <iostream>
#include <sstream>
using std::cout;
using std::endl;
using std::string;

template<typename type>
string to_string(const type&);

int main()
{
    int num_entero = 9478482;
    float num_decima1 = 1241.12;

    cout << to_string(num_entero) << endl;
    cout << to_string(num_decima1) << endl;

    char* caracteres = new char[10];
    
    for (int i = 0; i < 10; i++)
        caracteres[i] = 65+i;

    string carac = to_string(caracteres);

    cout << carac << endl;
    
    delete[] caracteres;
    return 0; 
}

template<typename type>
string to_string(const type& st)
{
    std:: stringstream ss{};
    ss << st;
    ss.ignore();

    return ss.str();
}