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
	~Controlador() {
		delete decoder;
		borrarListas();
	}
	Controlador(int tipoDato) {
		decoder = new Decoder(tipoDato);//recordar hacer delete		
	}
	void run() {
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
		default:
			interfaz.mostrarError("Comando Invalido");
			break;
		}
	}
	void crearLista(std::vector<std::string> instrucciones) {

		switch (instrucciones.size()) {//check size    crear,lista1,lista2.cabeza.cola,lista4.cola.cabeza
		case 3:
			//Jose Delgado
			crearListaConParentesis(instrucciones);
			break;
		case 4:
			//KABU09
			crearListaConComandos(instrucciones);
		default:
			break;
		}
	}
	void crearListaConParentesis(std::vector<std::string> instrucciones) {		
		if (lista.find(instrucciones[1]) == lista.end()) {
			if (decoder->esInputValido(instrucciones[2])) {
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
	void crearListaConComandos(std::vector<std::string> instrucciones) {
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

	void mostrarListas() {
		stringstream ss;
		typename std::map<std::string, List<T>*>::iterator it;
		for (it = lista.begin(); it != lista.end(); ++it) {
			ss << it->first << "		" << it->second->toString() << "\n";
		}
		interfaz.mostrarMensaje(ss.str());
	}

	void buscar(std::vector<std::string> instrucciones) {
		std::vector<std::string> buscar = terminal.separarInstruccion(instrucciones[1], '.');//check if real		
		List<T>* aux = getList(buscar);
		if (aux) {
			interfaz.mostrarMensaje(aux->toString());
		}

	}

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

	void borrarListas() {
		typename std::map<std::string, List<T>*>::iterator it;
		for (it = lista.begin(); it != lista.end(); ++it) {
			delete it->second;

		}
	}



private:
	//1 int  2 char   3 Double   4 String
	std::map<std::string, List<T>*> lista;
	std::string const PARTESLISTA = "cabeza cola";
	Interfaz interfaz;
	Terminal terminal;
	Decoder* decoder;
};