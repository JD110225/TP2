#include "main.h"
#include "Controlador.h"

void run();
int main() {
	run();
	return 0;
}

void run() {
	Interfaz interfaz;
	std::stringstream ss;
	ss << " 1. Int \n 2. Char \n 3. Double \n 4. String \n";
	interfaz.mostrarMensaje(ss.str());
	int dataType = interfaz.pedirNumero("Digite la opcion correspondiente al dato: ");
	std::cin.ignore();
	std::fflush(stdin);
	if (dataType == 1) {
		Controlador <int> c(dataType);
		c.run();
	}else if (dataType == 2) {
		Controlador <char> c(dataType);
		c.run();
	}else if (dataType == 3) {
		Controlador <double> c(dataType);
		c.run();
	}else if (dataType == 4) {
		Controlador <std::string> c(dataType);
		c.run();
	}
}