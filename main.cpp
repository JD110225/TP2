/**
 * @file main.cpp
 * @author Eduardo Ayales
 * @brief Esta clase tiene el main del programa
 * @version 1.0
 * @date 2020-06-19
 *
 * @copyright Free without any restriction
 *
 */
#include "main.h"
#include "Controlador.h"

void run();

int main() {
	run();
	return 0;
}











































































































/**
 * @brief Este metodo se encarga de elegir la instancia adecuada del Controlador según el tipo de dato digitado por el usuario
 *
 */
void run() {
	Interfaz interfaz;
	std::stringstream ss;
	ss << " 1. Int \n 2. Char \n 3. Double \n 4. String \n";
	interfaz.mostrarMensaje(ss.str());
	int dataType = -1;

	while (!(dataType >= 1 && dataType <= 4)) {

		dataType = interfaz.pedirNumero("Digite la opcion correspondiente al dato: ");
		switch (dataType) {
		case 1:
		{
			Controlador <int> c(dataType);
			c.run();
			break;
		}
		case 2:
		{
			Controlador <char> c(dataType);
			c.run();
			break;
		}
		case 3:
		{
			Controlador <double> c(dataType);
			c.run();
			break;
		}
		case 4:
		{
			Controlador <std::string> c(dataType);
			c.run();
			break;
		}
		default:
			interfaz.mostrarError("Input Invalido");
			break;
		}
	}
}