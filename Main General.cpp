#include "main.h"
#include "Controlador.h"

void run();
int main() {
	run();
	return 0;
}

void run(){
	Interfaz interfaz;	
	int dataType = 4;
	if (dataType == 1) {
		Controlador <std::string> c(dataType);
		c.run();		
	}else if (dataType == 2) {
		Controlador <int> c(dataType);
		c.run();
	}else if (dataType == 3) {
		Controlador <double> c(dataType);
		c.run();
	}else if (dataType == 4) {
		Controlador <char> c(dataType);
		c.run();
	}
	/*switch (dataType) {
	case 1:
	{
		Controlador <int> c = Controlador <int> (dataType);
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
		break;
	}*/
}