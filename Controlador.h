/**
 * @file Controlador.h
 * @author Eduardo Ayales
 * @brief Esta clase controla el flujo del programa
 * @version 1.0
 * @date 2020-06-19
 *
 * @copyright Free without any restriction
 *
 */
#pragma once
#include <map>
#include <vector>
#include <iterator>
#include "List.h"
#include "Terminal.h"
#include "Interfaz.h"
#include "Decoder.h"
#include <sstream>
template<typename T>
class Controlador {
public:
	/**
	 * @brief Destroy the Controlador object
	 *
	 */
	~Controlador() {
		delete decoder;
		//borrarListas();
	}
	/**
	 * @brief Construct a new Controlador object
	 *
	 * @param tipoDato numero correspondiente al tipo de dato seleccionado
	 */
	Controlador(int tipoDato) {
		decoder = new Decoder(tipoDato);
	}
	/**
	 * @brief Este metodo inicia el programa
	 *
	 */
	void run() {
		std::cin.ignore();
		std::fflush(stdin);
		mostrarInstrucciones();		
		std::string comando = "";
		while (comando != "salir") {
			comando = interfaz.pedirComando(">");
			if (comando != "" && comando != "salir") {
				std::vector<std::string> instrucciones = terminal.separarInstruccion(comando, ',');
				int accion = terminal.identificarComando(instrucciones[0]);
				if (accion != std::string::npos) {
					realizarAccion(instrucciones, accion);
				}
				else {
					interfaz.mostrarError("Comando Invalido");
				}
			}
			else if (comando != "salir") {
				interfaz.mostrarError("Comando Invalido");
			}

		}
	}

	/**
	 * @brief Este metodo, segun la accion, procede a realizar lo solicitado por el usuario
	 *
	 * @param instrucciones instruccion del usuario separada por strings
	 * @param accion numero correspondiente al tipo de dato seleccionado
	 */
	void realizarAccion(std::vector<std::string> instrucciones, int& accion) {
		switch (accion) {
		case 0:
			crearLista(instrucciones);
			break;
		case 6:
			mostrarListas();
			break;
		case 14:
			buscar(instrucciones);
			break;
		case 21:
			revisarExiste(instrucciones);
			break;
		default:
			interfaz.mostrarError("Comando Invalido");
			break;
		}
	}

	/**
	 * @brief Este metodo decide cual tipo de lista es la que se va a crear
	 *
	 * @param instrucciones instruccion del usuario separada por strings
	 */
	void crearLista(std::vector<std::string> instrucciones) {
		switch (instrucciones.size()) {
		case 3:
			crearListaConParentesis(instrucciones);
			break;
		case 4:
			crearListaConComandos(instrucciones);
			break;
		default:
			interfaz.mostrarError("Argumentos 11Invalido");
			break;
		}
	}

	/**
	 * @brief Este metodo crear una lista a partir de una hilera de datos digitados por el usuario
	 *
	 * @param instrucciones instruccion del usuario separada por strings
	 */
	void crearListaConParentesis(std::vector<std::string> instrucciones) {
		if (decoder->getDataTypeID() == 4) {
			if (listaString.find(instrucciones[1]) == listaString.end()) {
				if (decoder->esInputValido(instrucciones[2])) {
					List<std::string>* nueva = decoder->stringToList2(instrucciones[2], instrucciones[1]);
					listaString.insert(std::pair<std::string, List<std::string>*>(instrucciones[1], nueva));
				}
				else {
					interfaz.mostrarError("Estructura Invalida de la Lista");
				}
			}
			else {
				interfaz.mostrarError("Ya existe una lista con ese nombre");
			}
		}
		else {
			if (lista.find(instrucciones[1]) == lista.end()) {
				if (decoder->esInputValido(instrucciones[2]) && matchInput(instrucciones[2], decoder->getDataTypeID())) {
					List<T>* nueva = decoder->stringToList<T>(instrucciones[2], instrucciones[1]);
					lista.insert(std::pair<std::string, List<T>*>(instrucciones[1], nueva));
				}
				else {
					interfaz.mostrarError("Estructura Invalida de la Lista");
				}
			}
			else {
				interfaz.mostrarError("Ya existe una lista con ese nombre");
			}
		}
	}

	/**
	 * @brief Este metodo crear una lista a partir de listas ya existentes
	 *
	 * @param instrucciones instruccion del usuario separada por strings
	 */
	void crearListaConComandos(std::vector<std::string> instrucciones) {
		if (decoder->getDataTypeID() == 4) {
			if (listaString.find(instrucciones[1]) == listaString.end()) {
				std::vector<std::string> cabeza = terminal.separarInstruccion(instrucciones[2], '.');//check if real
				std::vector<std::string> cola = terminal.separarInstruccion(instrucciones[3], '.');//check if real
				List<std::string>* listaCabeza = getList2(cabeza);//check data type
				List<std::string>* listaCola = getList2(cola);//check data type
				if (listaCabeza && listaCola) {
					List<std::string>* nueva = new List<std::string>(listaCabeza, listaCola, instrucciones[1], listaCabeza->getValue());//check T valu
					listaString.insert({ instrucciones[1], nueva });
				}

			}
			else {
				interfaz.mostrarError("Ya existe una lista con ese nombre");
			}
		}
		else {
			if (lista.find(instrucciones[1]) == lista.end()) {
				std::vector<std::string> cabeza = terminal.separarInstruccion(instrucciones[2], '.');//check if real
				std::vector<std::string> cola = terminal.separarInstruccion(instrucciones[3], '.');//check if real
				List<T>* listaCabeza = getList(cabeza);//check data type
				List<T>* listaCola = getList(cola);//check data type
				if (listaCabeza && listaCola) {
					List<T>* nueva = new List<T>(listaCabeza, listaCola, instrucciones[1], listaCabeza->getValue());//check T valu
					lista.insert({ instrucciones[1], nueva });
				}

			}
			else {
				interfaz.mostrarError("Ya existe una lista con ese nombre");
			}
		}

	}

	/**
	 * @brief Este metodo verifica si lo digitado por el usuario corresponde al tipo de dato seleccionado
	 *
	 * @param hilera lo digitado por el usuario
	 * @param tipoDato numero correspondiente al tipo de dato
	 * @return true si corresponde al tipo de dato
	 * @return false no corresponde al tipo de dato
	 */
	bool matchInput(std::string const& hilera, int tipoDato) {
		bool valido = true;
		switch (tipoDato) {
		case 1:
			valido = esNumero(hilera);
			break;
		case 3:
			valido = esDouble(hilera);
		default:
			break;
		}
		return valido;
	}

	/**
	 * @brief Este metodo verifica si lo solicitado por el usuario es un entero
	 *
	 * @param hilera lo digitado por el usuario
	 * @return true si es un entero
	 * @return false no es un entero
	 */
	bool esNumero(std::string const& hilera) {
		bool valido = true;
		for (char c : hilera) {
			if (!((isdigit(c)) || (c == '(') || (c == ')') || (c == ' '))) {
				valido = false;
			}
		}
		return valido;
	}

	/**
	 * @brief Este metodo verifica si lo solicitado por el usuario es un double
	 *
	 * @param hilera lo digitado por el usuario
	 * @return true si es un double
	 * @return false no es un double
	 */
	bool esDouble(std::string const& hilera) {
		bool valido = true;
		for (char c : hilera) {
			if (!((isdigit(c)) || (c == '(') || (c == ')') || (c == ' ') || (c == '.'))) {
				valido = false;
			}
		}
		return valido;
	}

	/**
	 * @brief Este metodo muestra todas las listas
	 *
	 */
	void mostrarListas() {
		stringstream ss;
		if (decoder->getDataTypeID() == 4) {
			typename std::map<std::string, List<std::string>*>::iterator it;
			for (it = listaString.begin(); it != listaString.end(); ++it) {
				ss << it->first << "		" << it->second->toString() << "\n";
			}
		}
		else {
			typename std::map<std::string, List<T>*>::iterator it;
			for (it = lista.begin(); it != lista.end(); ++it) {
				ss << it->first << "		" << it->second->toString() << "\n";
			}
		}

		interfaz.mostrarMensaje(ss.str());
	}

	/**
	 * @brief Este metodo busca una lista especifica, si la encuentra, la imprime
	 *
	 * @param instrucciones instruccion del usuario separada por strings
	 */
	void buscar(std::vector<std::string> instrucciones) {
		std::vector<std::string> buscar = terminal.separarInstruccion(instrucciones[1], '.');//check if real		
		if (decoder->getDataTypeID() == 4) {
			List<std::string>* aux1 = getList2(buscar);
			if (aux1) {
				interfaz.mostrarMensaje(aux1->toString());
			}
		}
		else {
			List<T>* aux2 = getList(buscar);
			if (aux2) {
				interfaz.mostrarMensaje(aux2->toString());
			}
		}



	}

	/**
	 * @brief Este metodo le muestra las instrucciones del programa al usuario
	 *
	 */
	void mostrarInstrucciones() {
		std::stringstream ss;
		ss << " Intrucciones de Uso \n 1. Separe cada palabra por coma ',' \n 2. Si quiere agregar una lista siga las siguientes reglas: \n";
		ss << " Separar cada valor por un unico espacio: ((1 2)(3)) \n Cada sublista debe ir entre parentesis ((1 2)(3)) \n \n";
		ss << " Para crear una lista a partir de una hilera, debera usar la instruccion \"crear\" de esta manera: ";
		ss << "\n \t Instruccion, nombreDeLista, hilera \n \t Ejemplo valido: crear,lista1,((123 34)(4 54)) \n \n";
		ss << "Para crear una lista a partir de otras, debera usar la instruccion \"crear\" de esta manera: ";
		ss << "\n \t Instruccion, nombreDeLista, listaCabeza, listaCola \n \t Ejemplo valido: crear,lista3,lista1.cabeza.cola,lista2.cola \n \n";
		ss << "3. Si quiere ver todas las listas digite \"mostrar\" \n \t Ejemplo: mostrar \n";
		ss << "4. Si quiere ver alguna lista en especifico digite \"buscar lista\" \n \t Ejemplos Validos:";
		ss << "\n \t \t buscar,lista1";
		ss << "\n \t \t buscar,lista1.cabeza.cola";
		interfaz.mostrarMensaje(ss.str());
	}

	void revisarExiste(std::vector<std::string> instrucciones) {
		if (decoder->getDataTypeID() == 4) {
			std::vector<std::string> existe = terminal.separarInstruccion(instrucciones[1], '.');//check if real		
			List<std::string>* aux1 = getList2(existe);
			if (aux1) {
				if (aux1->find(instrucciones[2])) {
					interfaz.mostrarMensaje("Elemento Encontrado");
				}
				else {
					interfaz.mostrarError("Elemento No Encontrado");
				}
			}
		}
		else {
			std::vector<std::string> existe = terminal.separarInstruccion(instrucciones[1], '.');//check if real		
			List<T>* aux2 = getList(existe);
			if (aux2) {
				if (aux2->find(decoder->dataTypeConverter<T>(instrucciones[2]))) {
					interfaz.mostrarMensaje("Elemento Encontrado");
				}
				else {
					interfaz.mostrarError("Elemento No Encontrado");
				}
			}
		}
	}

	/**
	 * @brief Este metodo, busca la lista especificada por el usuario, si existe, la devuelve
	 *
	 * @param instrucciones instruccion del usuario separada por strings
	 * @return List<T>* retorna la lista solicitada o nullptr sino fue encontrada
	 */
	List<T>* getList(std::vector<std::string> instrucciones) {
		List <T>* aux = nullptr;
		if (lista.find(instrucciones[0]) != lista.end()) {
			int opcion = 0;
			aux = lista[instrucciones[0]];
			for (int i = 1; i < instrucciones.size() && aux; ++i) {
				opcion = PARTESLISTA.find(instrucciones[i]);//check for npos
				switch (opcion) {
				case 0:
				{
					if (aux->getHead()) {
						aux = aux->getHead();
					}
					else {
						aux = nullptr;
						interfaz.mostrarError("No existe la lista elegida como argumento");
					}
					break;
				}
				case 7:
				{
					if (aux) {//optimizacion
						if (aux->getTail()) {
							aux = aux->getTail();
						}
						else {
							aux = nullptr;
							interfaz.mostrarError("No existe la lista elegida como argumento");
						}
					}

					break;
				}
				default:
					break;
				}
			}
		}
		else {
			interfaz.mostrarError("No existe la lista elegida como argumento");
		}
		return aux;
	}

	/**
	 * @brief Este metodo, busca la lista especificada por el usuario, si existe, la devuelve
	 *
	 * @param instrucciones instruccion del usuario separada por strings
	 * @return List<T>* retorna la lista solicitada o nullptr sino fue encontrada
	 */
	List<std::string>* getList2(std::vector<std::string> instrucciones) {
		List <std::string>* aux = nullptr;
		if (listaString.find(instrucciones[0]) != listaString.end()) {
			int opcion = 0;
			aux = listaString[instrucciones[0]];
			for (int i = 1; i < instrucciones.size() && aux; ++i) {
				opcion = PARTESLISTA.find(instrucciones[i]);//check for npos
				switch (opcion) {
				case 0:
				{
					if (aux->getHead()) {
						aux = aux->getHead();
					}
					else {
						aux = nullptr;
						interfaz.mostrarError("No existe la lista elegida como argumento");
					}
					break;
				}
				case 7:
				{
					if (aux) {//optimizacion
						if (aux->getTail()) {
							aux = aux->getTail();
						}
						else {
							aux = nullptr;
							interfaz.mostrarError("No existe la lista elegida como argumento");
						}
					}

					break;
				}
				default:
					break;
				}
			}
		}
		else {
			interfaz.mostrarError("No existe la lista elegida como argumento");
		}
		return aux;
	}

	/**
	 * @brief Este metodo hace los "deletes" de las listas
	 *
	 */
	void borrarListas() {
		if (decoder->getDataTypeID() == 4) {
			typename std::map<std::string, List<std::string>*>::iterator it;
			for (it = listaString.begin(); it != listaString.end(); ++it) {
				delete it->second;

			}
		}
		else {
			typename std::map<std::string, List<T>*>::iterator it;
			for (it = lista.begin(); it != lista.end(); ++it) {
				delete it->second;

			}
		}

	}



private:
	std::map<std::string, List<T>*> lista;
	std::map<std::string, List<std::string>*> listaString;
	std::string const PARTESLISTA = "cabeza cola";
	Interfaz interfaz;
	Terminal terminal;
	Decoder* decoder;
};