#include "main.h"
#include "Controlador.h"
<<<<<<< Updated upstream

void run();
int main() {
	run();
	return 0;
}

=======

void run();
int main() {
	run();
	return 0;
}
































>>>>>>> Stashed changes
void run() {
	Interfaz interfaz;
	std::stringstream ss;
	ss << " 1. Int \n 2. Char \n 3. Double \n 4. String \n";
<<<<<<< Updated upstream
	interfaz.mostrarMensaje(ss.str());
	int dataType = interfaz.pedirNumero("Digite la opcion correspondiente al dato: ");
	std::cin.ignore();
	std::fflush(stdin);
	if (dataType == 1) {
=======
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
	

	/*if (dataType == 1) {
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
	}
=======
	}*/
>>>>>>> Stashed changes
}