////////////////////////////////////////
/*
	FileName: main.c
	FileType: C source file
	Author: Sandoval Pérez, Michael Eduardo
	Created on: 31/05/2021
	Description: Creación de un arreglo que almacena matrices de cadenas de caracteres definidas con un struct
*/
////////////////////////////////////////

#include <gtkmm.h>
#include <iostream>

#include "usuario.h"

using namespace Gtk;
using namespace std;

// Definimos punteros para cada uno de los Widgets de la ventana.
Window* pVentana = nullptr;		// Ventana principal
Label* p_lbl_titulo = nullptr;		
Label* p_lbl_descripcion = nullptr;
Label* p_lbl_nombre = nullptr;
Entry* p_txt_nombre = nullptr;		// Almacena un nombre tipo STRING
Label* p_lbl_edad = nullptr;
Entry* p_txt_edad = nullptr;		// Almacena la edad tipo INT
Label* p_lbl_resultado = nullptr;
Button* p_btn_salir = nullptr;
Button* p_btn_resultado = nullptr;	// Almacena un resultado tipo STRING

// Creamos un objeto de tipo user
Usuario user;

static void on_btn_resultado_clicked()	// Definimos la función que se ejecutará cuando hagamos clic en btn_resultado
{
	if((p_txt_nombre->get_text() != "") and (p_txt_edad->get_text() != ""))	// Ninguna de las entradas debe estar vacia.
	{
		user.setNombre(p_txt_nombre->get_text());	// Insertamos el nombre 
		user.setEdad(stoi(p_txt_edad->get_text())); // setEdad coge un entero, por lo que tenemos que convertir el texto de la entrada en un int con stoi.

		// Llamamos a el metodo toString() de user y lo insertamos en la etiqueta resultado, con esto nos evitamos convertir en string a cada valor.
		p_lbl_resultado->set_text(user.toString());

		p_txt_nombre->set_text("");	// Limpiamos la entrada nombre.
		p_txt_edad->set_text("");	// Limpiamos la entrada edad.
	}
}

static void on_btn_salir_clicked()
{
	if(pVentana)
		pVentana->hide();	// Se encarga de cerrar la aplicación.
}

int main(int argc, char *argv[])
{
	auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");	// inicializamos gtkmm
	auto ptrWidget = Gtk::Builder::create();	// Definimos y creamos una instancia de un puntero a widget
	
	// Tratamos de ejecutar el archivo .glade que contiene nuestra GUI (que técnicamente se puede considerar como un archivo XML)
	try
	{
		ptrWidget->add_from_file("ventana.glade");
	}
	catch(const Glib::FileError& ex) //Analizamos los errores si no encuentra el fichero
 	{
 		cerr << "FileError: " << ex.what() << endl; //errores asociados al fichero
 		return 1;
 	}
 	catch(const Glib::MarkupError& ex)
 	{
 		cerr << "MarkupError: " << ex.what() << endl; //errores asociados a la sintaxis del fichero
 		return 1;
 	}
 	catch(const BuilderError& ex)
 	{
 		cerr << "BuilderError: " << ex.what() << endl; //errores asociados a la API Builder
 		return 1;
 	}

	ptrWidget->get_widget("main_window", pVentana);		// Apuntamos nuestro puntero a la ventana del programa
	if(pVentana)	//Si la función get_widget ha devuelto un puntero es porque ha encontrado la ventana dentro del archivo .glade (xml)
	{
		ptrWidget->get_widget("btn_resultado", p_btn_resultado);
		if(p_btn_resultado)
		{
			// apuntamos los punteros hacia los elementos de la pantalla y enlazamos con sus manejadores, en este caso solo aplica con los botones
			// ya que estamos utilizando sus manejadores o eventos "clicked", estamos haciendo que al presionar se llame a la función de arriba.
			p_btn_resultado->signal_clicked().connect(sigc::ptr_fun(on_btn_resultado_clicked));
		}

		ptrWidget->get_widget("btn_salir", p_btn_salir);
		if(p_btn_salir)
		{
			p_btn_salir->signal_clicked().connect(sigc::ptr_fun(on_btn_salir_clicked));
		}

		//Apuntamos los punteros de las entradas y las etiquetas hacia los elementos definidos en la GUI de glade, como no utilizamos ninguno de sus
		// manejadores (eventos) no es necesario utilizar los if para apuntar a una función.
		ptrWidget->get_widget("lbl_titulo", p_lbl_titulo);
		ptrWidget->get_widget("lbl_descripcion", p_lbl_descripcion);
		ptrWidget->get_widget("lbl_nombre", p_lbl_nombre);
		ptrWidget->get_widget("txt_nombre", p_txt_nombre);
		ptrWidget->get_widget("lbl_edad", p_lbl_edad);
		ptrWidget->get_widget("txt_edad", p_txt_edad);
		ptrWidget->get_widget("lbl_resultado", p_lbl_resultado);

		app->run(*pVentana);	// Lanzamos la aplicación.
	}

	delete pVentana;

	return 0;
}
