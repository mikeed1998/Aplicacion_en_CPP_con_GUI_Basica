# Aplicacion_en_CPP_con_GUI_Basica
Ejemplo de una aplicación en C++ implementando interfaces gráficas con GTKMM para insertar y obtener los datos de un objeto.

Para compilar:
g++ *.cpp -o main `pkg-config gtkmm-3.0 --cflags --libs`

Es necesario tener instalado los paquetes: 
libgtkmm-3.0-1v5_3.24.2   (versión actual, puede variar)
 y 
libgtkmm-3.0-dev_3.24.2

así como sus dependencias.
