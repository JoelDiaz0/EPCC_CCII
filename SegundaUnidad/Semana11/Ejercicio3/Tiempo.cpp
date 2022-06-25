#include "Tiempo.h"

Tiempo::Tiempo()
{
	horas = 0;
	minutos = 0;
	segundos = 0;
}

Tiempo::Tiempo(int horas, int minutos, int segundos)
{
	if (horas < 0 || horas > 23 || minutos < 0 || minutos > 59 || segundos < 0 || segundos > 59)
	{
		this->horas = 0;
		this->minutos = 0;
		this->segundos = 0;
		throw std::invalid_argument("HORA INVALIDA!\n");
	}

	else
	{
		this->horas = horas;
		this->minutos = minutos;
		this->segundos = segundos;
	}
}


Tiempo::~Tiempo()
{
}

void Tiempo::mostrar_formato_12_horas()
{
	if (horas > 12)
	{
		if (horas - 12 < 9)
			cout <<"0"<< horas - 12;
		else
			cout << horas - 12;
		if (minutos < 10)
			cout << ":0" << minutos;
		else
			cout << ":" << minutos;
		if (segundos < 10)
			cout << ":0" << segundos;
		else
			cout << ":" << segundos;
		cout << " PM";
	}
	else
	{
		if (horas < 10)
			cout << "0" << horas;
		else
			cout << horas;
		if (minutos < 10)
			cout << ":0" << minutos;
		else
			cout << ":" << minutos;
		if (segundos < 10)
			cout << ":0" << segundos;
		else
			cout << ":" << segundos;
		cout << " AM";
	}
}

Tiempo& Tiempo::operator+(const Tiempo& t1)
{
	if (this->horas + t1.horas > 23)
	{
		std::cerr << "Las horas no pueden ser mayores a 23!\n";
		exit(1);
	}
	else
	{
		if (this->segundos + t1.segundos > 59)
		{
			this->segundos = (this->segundos + t1.segundos) - 60;
			this->minutos++;
		}
		else
			this->segundos = (this->segundos + t1.segundos);
		if (this->minutos + t1.minutos > 59)
		{
			this->minutos = (this->minutos + t1.minutos) - 60;
			this->horas++;
		}
		else
			this->minutos = (this->minutos + t1.minutos);
		if (this->horas + t1.horas > 23)
		{
			this->horas = (this->horas + t1.horas) - 24;
		}
		else
			this->horas = (this->horas + t1.horas);
	}
	return *this;
}

Tiempo& Tiempo::operator-(const Tiempo& t1)
{
	if (this->horas < t1.horas)
	{
		std::cerr << "El tiempo no puede ser negativo!\n";
		exit(1);
	}
	else
	{
		if (this->segundos < t1.segundos)
		{
			this->minutos--;
			this->segundos = (this->segundos + 60 - t1.segundos);
		}
		else
			this->segundos = (this->segundos - t1.segundos);
		if (this->minutos < t1.minutos)
		{
			this->horas--;
			this->minutos = (this->minutos + 60 - t1.minutos);
		}
		else
			this->minutos = (this->minutos - t1.minutos);

		this->horas = this->horas - t1.horas;
	}

	return *this;
}

bool Tiempo::operator==(const Tiempo& t1) const
{
	return this->horas == t1.horas && this->minutos == t1.minutos && this->segundos == t1.segundos;
}

bool Tiempo::operator!=(const Tiempo& t1) const
{
	return this->horas != t1.horas || this->minutos != t1.minutos || this->segundos != t1.segundos;
}

bool Tiempo::operator<(const Tiempo& t1) const
{
	if (this->horas < t1.horas)
		return true;
	else if (this->horas == t1.horas && this->minutos < t1.minutos)
		return true;
	else if (this->horas == t1.horas && this->minutos == t1.minutos && this->segundos < t1.segundos)
		return true;

	return false;
}

bool Tiempo::operator>(const Tiempo& t1) const
{
	if (this->horas > t1.horas)
		return true;
	else if (this->horas == t1.horas && this->minutos > t1.minutos)
		return true;
	else if (this->horas == t1.horas && this->minutos == t1.minutos && this->segundos > t1.segundos)
		return true;
	return false;
}

bool Tiempo::operator<=(const Tiempo& t1) const
{
	if (this->horas <= t1.horas)
		return true;
	else if (this->horas == t1.horas && this->minutos <= t1.minutos)
		return true;
	else if (this->horas == t1.horas && this->minutos == t1.minutos && this->segundos <= t1.segundos)
		return true;
	return false;
}

bool Tiempo::operator>=(const Tiempo& t1) const
{
	if (this->horas >= t1.horas)
		return true;
	else if (this->horas == t1.horas && this->minutos >= t1.minutos)
		return true;
	else if (this->horas == t1.horas && this->minutos == t1.minutos && this->segundos >= t1.segundos)
		return true;
	return false;
}

std::istream& operator>>(std::istream& i, Tiempo& t1)
{
	cout << "Horas: "; i >> t1.horas;

	if (t1.horas > 23 || t1.horas < 0)
	{
		std::cerr << "Las horas no pueden ser negativas o mayores a 23!\n";
		exit(1);
	}

	cout << "Minutos: "; i >> t1.minutos;
	if (t1.minutos > 59 || t1.minutos < 0)
	{
		std::cerr << "Los minutos no pueden ser negativos o mayores a 59!\n";
		exit(1);
	}

	cout << "Segundos: "; i >> t1.segundos;

	if (t1.segundos > 59 || t1.segundos < 0)
	{
		std::cerr << "Los segundos no pueden ser negativos o mayores a 59!\n";
		exit(1);
	}

	i.ignore();
	return i;
}

std::ostream& operator<<(std::ostream& o, Tiempo& t1)
{
	if (t1.horas < 10)
		o << "0" << t1.horas;
	else
		o << t1.horas;
	if (t1.minutos < 10)
		o << ":0" << t1.minutos;
	else
		o << ":" << t1.minutos;
	if (t1.segundos < 10)
		o << ":0" << t1.segundos;
	else
		o << ":" << t1.segundos;

	return o;
}