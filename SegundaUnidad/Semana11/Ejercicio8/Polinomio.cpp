#include "Polinomio.h"

template<typename type>
Polinomio<type>::Polinomio(int grado)
{
    if (grado < 1)
    {
        this->grado = 1;
        throw std::invalid_argument("EL GRADO DE UN POLINOMIO DEBE SER POSITIVO!\n");
    }
    else
    {
        this->grado = grado;
        for (int i = 0; i < grado; i++)
            coeficientes_vec.push_back(1);   
    }
}

template<typename type>
Polinomio<type>::~Polinomio()
{

}

template<typename type>
int Polinomio<type>::get_grado()
{
    return grado;
}

template<typename type>
void Polinomio<type>::mostrar()
{
    for (int i = 0; i < grado; i++)
    {
        if (coeficientes_vec.at(i) == 0)
            continue;
        else
        {
            if (coeficientes_vec.at(i) > 0)
            {
                cout << coeficientes_vec.at(i) << "Xʌ"<< grado-i;
                if (i < grado-1)
                   cout << " + ";          
            }            
            else
            {
                cout << coeficientes_vec.at(i) << "Xʌ"<< grado-i; 
                if (i < grado-1)
                   cout << " - ";   
            }                    
        }
    }
}

template<typename type>
void Polinomio<type>::ingresar_coefisientes(const std::deque<type>& coeficientes_vec)
{
    if (coeficientes_vec.size() > grado || coeficientes_vec.size() < grado)
        throw std::invalid_argument("INGRESO UN DEQUE VACIO O NO CONTIENE LA MISMA CANTIDAD DE ELEMENTOS QUE EL VALOR DEL GRADO!\n");   
    else
      this->coeficientes_vec = coeficientes_vec;  
}

template<typename type>
Polinomio<type>& Polinomio<type>::operator+(const Polinomio<type>& p1)
{
    if (this->grado > p1.grado)
    {
        int grado_extra = this->grado - p1.grado;

        for (int i = 0; i < p1.grado; i++)
            this->coeficientes_vec.at(i+grado_extra ) += p1.coeficientes_vec.at(i);
    }
    else if (this->grado < p1.grado)
    {
        int grado_extra = p1.grado - this->grado;

        for (int i = 0; i < grado; i++)
            this->coeficientes_vec.at(i) += p1.coeficientes_vec.at(i+grado_extra);

        for (int i = 0; i < grado_extra; i++)
            this->coeficientes_vec.push_front(p1.coeficientes_vec.at(i));
        this->grado += grado_extra;
    }
    else
    {
        for (int i = 0; i < grado; i++)
           this->coeficientes_vec.at(i) += p1.coeficientes_vec.at(i);
    }
    return *this;
}

template<typename type>
Polinomio<type>& Polinomio<type>::operator-(const Polinomio<type>& p1)
{
    if (this->grado > p1.grado)
    {
        int grado_extra = this->grado - p1.grado;

        for (int i = 0; i < p1.grado; i++)
             this->coeficientes_vec.at(i+grado_extra ) -= p1.coeficientes_vec.at(i);
    }
    else if (this->grado < p1.grado)
    {
        int grado_extra = p1.grado - this->grado;

        for (int i = 0; i < grado; i++)
            this->coeficientes_vec.at(i) -= p1.coeficientes_vec.at(i+grado_extra);

        for (int i = 0; i < grado_extra; i++)
            this->coeficientes_vec.push_front(p1.coeficientes_vec.at(i));
        this->grado += grado_extra;
    }
    else
    {
        for (int i = 0; i < grado; i++)
           this->coeficientes_vec.at(i) -= p1.coeficientes_vec.at(i);
    }

    return *this;
}


//Error: undefined reference to `operator<<(std::ostream&, Polinomio<int>&)'

/*
template<typename type>
std::ostream& operator<<(std::ostream& o, Polinomio<type>& p1) 
{
    for (int i = 0; i < p1.grado; i++)
    {
        if (p1.coeficientes_vec.at(i) == 0)
            continue;
        else
        {
            if (p1.coeficientes_vec.at(i) > 0)
            {
                o << p1.coeficientes_vec.at(i) << "Xʌ"<< p1.grado-i;
                if (i < p1.grado-1)
                   o << " + ";          
            }            
            else
            {
                o << p1.coeficientes_vec.at(i) << "Xʌ"<< p1.grado-i; 
                if (i < p1.grado-1)
                   o << " - ";   
            }                    
        }
    }
	return o;
}
*/