#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string>

class Usuario
{
	private:
		std::string nombre;
		int edad;

	public:
		Usuario();
		Usuario(const Usuario&);

		std::string getNombre() const;
		int getEdad() const;

		std::string toString() const;

		void setNombre(const std::string&);
		void setEdad(const int&);

		Usuario& operator = (const Usuario&);
		
};

#endif