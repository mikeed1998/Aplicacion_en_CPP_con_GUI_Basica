#include "usuario.h"

using namespace std;

Usuario::Usuario() { }

Usuario::Usuario(const Usuario& u) : nombre(u.nombre), edad(u.edad) { }

Usuario& Usuario::operator = (const Usuario& u)
{
	nombre = u.nombre;
	edad = u.edad;

	return *this;
}

string Usuario::getNombre() const
{
	return nombre;
}

int Usuario::getEdad() const
{
	return edad;
}

string Usuario::toString() const
{
	return nombre + " y " + to_string(edad);
}

void Usuario::setNombre(const string& n)
{
	nombre = n;
}

void Usuario::setEdad(const int& e)
{
	edad = e;
}

