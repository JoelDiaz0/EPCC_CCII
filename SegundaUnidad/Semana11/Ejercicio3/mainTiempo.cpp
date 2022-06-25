#include <iostream>
#include "Tiempo.h"
using std::cout;
using std::endl;

int main()
{

	Tiempo t1(5, 20, 30), t2(14, 55, 49), t3(23, 30, 5);

	try
	{
		Tiempo t4(30, 21, 45); //Error, se inicializa el las horas con un valor mayor a 23
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}

	cout << t1 << "    " << t2 << "    " << t3 << endl;
	t1.mostrar_formato_12_horas();
	cout << "-";
	t2.mostrar_formato_12_horas();
	cout << "-";
	t3.mostrar_formato_12_horas();

	Tiempo t4(3, 20, 25);

	cout << "\n\n" << t1 << " + " << t4 << " = ";
	cout << t1 + t4 << endl << endl;

	cout << t4 << " + " << t2 << " = ";
	cout << t4 + t2 << endl << endl;

	cout << t3 << " - " << t1 << " = ";
	cout << t3 - t1 << endl << endl;

	Tiempo t6;

	cout << "Ingrese un tiempo a t6: "; std::cin >> t6;

	Tiempo t7(17, 30, 10);
	cout << "t6 = " << t6 << "  " << "t7 = " << t7 << endl;

	if (t6 < t7)
		cout << "t6 es menor a t7\n";
	else
		cout << "t6 es mayor a t7\n";

	if (t6 != t7)
		cout << "t6 es diferente a t7\n";
	else
		cout << "t6 es igual a t7\n";

	if (t6 >= t7)
		cout << "t6 es mayor o igual a t7\n\n";
	else
		cout << "t6 es menor o igual  a t7\n\n";

	
	cout << t1 << " - " << t4 << " = ";  //Error, se detecta cuando un tiempo es negativo 
 	cout << t1 - t4;                     //o se pasa de 24 en horas o 59 en minutos o segundos

	return 0;
}
	


