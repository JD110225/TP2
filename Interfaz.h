#pragma once
#include <iostream>
class Interfaz{
public:
	std::string pedirComando(std::string mensaje);
	void mostrarError(std::string mensaje);
};

