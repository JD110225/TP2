/**
 * @file Interfaz.h
 * @author Eduardo Ayales
 * @brief Esta clase se encarga de la interacción entrada/salida con el usuario
 * @version 1.0
 * @date 2020-06-19
 *
 * @copyright Free without any restriction
 *
 */
#pragma once
#include <iostream>
#include <string>
class Interfaz {
public:
	std::string pedirComando(std::string mensaje);
	void mostrarError(std::string mensaje);
	void mostrarMensaje(std::string mensaje);
	int  pedirNumero(std::string mensaje);
};

