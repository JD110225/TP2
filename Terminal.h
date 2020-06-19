/**
 * @file Terminal.h
 * @author Eduardo Ayales
 * @brief Esta clase se encarga de identificar y separar las instrucciones de la terminal
 * @version 1.0
 * @date 2020-06-19
 *
 * @copyright Free without any restriction
 *
 */

#pragma once
#include "List.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
 /**
  * @brief Esta clase se encarga de identificar y separar las instrucciones de la terminal
  *
  */
class Terminal {
public:
	std::vector<std::string> separarInstruccion(std::string const& instruccion, char separador);
	int identificarComando(std::string const& comando);
private:
	std::string const INSTRUCCIONES = "crear mostrar buscar";//0 = crear     6 = mostrar   14 = buscar
};

