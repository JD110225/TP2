#pragma once
#include "List.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
class Terminal{
public:
	std::vector<std::string> separarInstruccion(std::string const &instruccion, char separador);
	int identificarComando(std::string const& comando);
private:
	std::string const INSTRUCCIONES = "crear mostrar buscar";//0 = crear     6 = mostrar   14 = buscar
};

