#include <gtkmm.h>
#include <iostream>

#include "usuario.h"

using namespace Gtk;
using namespace std;

Window* pVentana = nullptr;
Label* p_lbl_titulo = nullptr;
Label* p_lbl_descripcion = nullptr;
Label* p_lbl_nombre = nullptr;
Entry* p_txt_nombre = nullptr;
Label* p_lbl_edad = nullptr;
Entry* p_txt_edad = nullptr;
Label* p_lbl_resultado = nullptr;
Button* p_btn_salir = nullptr;
Button* p_btn_resultado = nullptr;

Usuario user;

static void on_btn_resultado_clicked()
{
	if((p_txt_nombre->get_text() != "") and (p_txt_edad->get_text() != ""))
	{
		user.setNombre(p_txt_nombre->get_text());
		user.setEdad(stoi(p_txt_edad->get_text()));

		p_lbl_resultado->set_text(user.toString());

		p_txt_nombre->set_text("");
		p_txt_edad->set_text("");
	}
}

static void on_btn_salir_clicked()
{
	if(pVentana)
		pVentana->hide();
}

int main(int argc, char *argv[])
{
	auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");
	auto ptrWidget = Gtk::Builder::create();

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

	ptrWidget->get_widget("main_window", pVentana);
	if(pVentana)
	{
		ptrWidget->get_widget("btn_resultado", p_btn_resultado);
		if(p_btn_resultado)
		{
			p_btn_resultado->signal_clicked().connect(sigc::ptr_fun(on_btn_resultado_clicked));
		}

		ptrWidget->get_widget("btn_salir", p_btn_salir);
		if(p_btn_salir)
		{
			p_btn_salir->signal_clicked().connect(sigc::ptr_fun(on_btn_salir_clicked));
		}

		ptrWidget->get_widget("lbl_titulo", p_lbl_titulo);
		ptrWidget->get_widget("lbl_descripcion", p_lbl_descripcion);
		ptrWidget->get_widget("lbl_nombre", p_lbl_nombre);
		ptrWidget->get_widget("txt_nombre", p_txt_nombre);
		ptrWidget->get_widget("lbl_edad", p_lbl_edad);
		ptrWidget->get_widget("txt_edad", p_txt_edad);
		ptrWidget->get_widget("lbl_resultado", p_lbl_resultado);

		app->run(*pVentana);
	}

	delete pVentana;

	return 0;
}