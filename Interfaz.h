#pragma once
#include <iostream>
#include <string>
class Interfaz{
public:
	std::string pedirComando(std::string mensaje);
	void mostrarError(std::string mensaje);
	void mostrarMensaje(std::string mensaje);
	int  pedirNumero(std::string mensaje);
};

