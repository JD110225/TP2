#pragma once
#include <map>
#include <vector>
#include <iterator>
#include "List.h"
#include "Terminal.h"
#include "Interfaz.h"
#include <sstream>
template<typename T>
class Controlador{
public:
	Controlador(int tipoDato) {
		this->tipoDato = tipoDato;
	}
	int getTipoDato() {
		return tipoDato;
	}
	void run(){
		std::cout << tipoDato << std::endl;
		interfaz.mostrarError("1");		
		std::map<std::string, List<T>*> lista;
		T value;
		std::cin >> value;
		List<T>* list1 = new List<T>(value);
		std::cout << list1->toString() << std::endl;
		interfaz.mostrarError("3");
		lista["lista1"] = list1;
		interfaz.mostrarError("4");

	}
	void realizarAccion(std::vector<std::string>& instrucciones, int &accion);
	void crearLista(std::vector<std::string>& instrucciones);
	void crearListaConParentesis(std::vector<std::string>& instrucciones);
	void crearListaConComandos(std::vector<std::string>& instrucciones);	
private:
	int tipoDato;//1 int  2 char   3 Double   4 String
	Interfaz interfaz;
	Terminal terminal;
};
