//simularRobots.cpp


#include <iostream>
#include "Robot.h"

int main()
{
	Robot r1("norte",7,3);

	r1.mostrar();
	r1.instrucciones("DAAIAI");
	r1.mostrar();

    return 0;
}

