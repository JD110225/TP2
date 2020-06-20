#pragma once
#include "Decoder.h"
#include <iostream>
#include <sstream>
#include "List.h"
#include <string>
#include <typeinfo>
using namespace std;
class Decoder
{
private:
	int dataTypeID;
public:
	/**
	 * @brief Construct a new Decoder object
	 * 
	 * @param dataTypeID 
	 */
	Decoder(int dataTypeID) {  //1.Int 2.char 3.double 4.string   xd
		this->dataTypeID = dataTypeID;
	}

	/**
	 * @brief Get the Data Type I D object
	 * 
	 * @return int 
	 */
	int getDataTypeID() {
		return dataTypeID;
	}
	/**
	 * @brief Convierte un string a su repectivo tipo de dato dependiendo del dataTypeID
	 * @param T
	 * @param s hilera a ser casteada
	 * @return T dato casteado
	 */
	template <typename T>
	T dataTypeConverter(string s) { //convierte un string al tipo de dato correspondiente.
		T nuevoValor;
		switch (dataTypeID) {
		case 1: {//int
			nuevoValor = stoi(s);
			break;
		}
		case 2: {//char
			nuevoValor = s[0];
			break;
		}
		case 3: {//double
			nuevoValor = stof(s);
			break;
		}
		default: {
			break;
		}


		}
		return nuevoValor;
	}

	/**
	 * @brief cuenta las ocurrencias de un caracter
	 * 
	 * @param s hilera a ser recorrida
	 * @param c caracter a ser contado
	 * @return int 
	 */
	int contarOcurrenciasCaracter(string s, char c) {
		int counter = 0;
		for (char caracter : s) {
			if (caracter == c) {
				++counter;
			}
		}
		return counter;
	}

	/**
	 * @brief encuentra la posicion de un caracter en una hilera
	 * 
	 * @param s  hilera
	 * @param c caracter a buscar
	 * @return int 
	 */
	int findIndex(string s, char c) {
		int index = -1;
		bool found = false;
		for (unsigned int i = 0; i < s.length() && !found; ++i) {
			if (s[i] == c) {
				index = i;
				found = true;
			}
		}
		return index;
	}
	/**
	 * @brief verifica si una hilera tiene espacios entre parentesis
	 * 
	 * @param s hilera
	 * @return true 
	 * @return false 
	 */
	bool tieneEspaciosEntreParentesis(string s) {
		bool tiene = false;
		int indice = findIndex(s, ' ');
		while (indice != -1 && tiene == false) {
			if (s[indice - 1] == '(' || s[indice - 1] == ')' || s[indice + 1] == '(' || s[indice + 1] == ')') {
				tiene = true;
			}
			s = s.substr(indice + 1);
			indice = findIndex(s, ' ');
		}
		return tiene;
	}
	/**
	 * @brief verifica si la hilera es un input valido
	 * 
	 * @param s hilera
	 * @return true 
	 * @return false 
	 */
	bool esInputValido(string s) {  //revisa que no haya espacios ahi random metidos y que la cantidad de '(' coincida con la cantidad de ')'.
		bool condicion1 = contarOcurrenciasCaracter(s, '(') == contarOcurrenciasCaracter(s, ')') && contarOcurrenciasCaracter(s, '(') != 0;
		bool condicion2 = tieneEspaciosEntreParentesis(s) == false;
		return condicion1 && condicion2;
	}
	/**
	 * @brief equivalente a trim() en algunos lenguajes. Quita espacios en los extremos
	 * 
	 * @param s hilera
	 */
	void removerInicioYFin(string& s)  //quitar el primero y el ultimo parentesis.
	{
		s.erase(0, 1);
		s.erase(s.length() - 1, 1);
	}
	/**
	 * @brief verifica si la hilera es una entrada valida
	 * 
	 * @param s hilera
	 * @return true 
	 * @return false 
	 */
	bool esListaBasica(string s) {
		return contarOcurrenciasCaracter(s, '(') == 1 && contarOcurrenciasCaracter(s, ')') == 1 && contarOcurrenciasCaracter(s, ' ') == 1;
		//return s.length() == 5 && s[0] == '(' && isdigit(s[1]) && s[2] == ' ' && isdigit(s[3]) && s[4] == ')';
	}
	/**
	 * @brief verifica si una lista en forma de hilera es solo cabeza
	 * 
	 * @param s hilera
	 * @return true 
	 * @return false 
	 */
	bool esSoloCabeza(string s) {
		return contarOcurrenciasCaracter(s, '(') == 1 && contarOcurrenciasCaracter(s, ')') == 1 && contarOcurrenciasCaracter(s, ' ') == 0;
		// return s.length() == 3 && s[0] == '(' && isdigit(s[1]) && s[2] == ')';
	}
	/**
	 * @brief convierte una lista en forma de hilera en tipo List. Construye una lista
	 * a partir de sublistas
	 * 
	 * @tparam T 
	 * @param s 
	 * @param nombre 
	 * @return List<T>* 
	 */
	template <typename T>
	List<T>* stringToList(string s, string nombre) {
		List<T>* l = nullptr;
		List<T>* head = nullptr;
		List<T>* tail = nullptr;
		T valorAtomico{};
		if (esInputValido(s)) {
			if (esSoloCabeza(s)) {
				stringstream stream(s.substr(1));
				string token;
				getline(stream, token, ')');
				valorAtomico = dataTypeConverter<T>(token);
			}
			else {
				if (esListaBasica(s)) {
					stringstream stream(s.substr(1));
					string token;
					getline(stream, token, ' ');
					T atomicVal1 = dataTypeConverter<T>(token);
					head = new List<T>((atomicVal1));
					getline(stream, token, ')');
					T atomicVal2 = dataTypeConverter<T>(token);
					tail = new List<T>((atomicVal2));
				}
				else {
					removerInicioYFin(s);
					string cabeza;
					int indiceFinal = 0; //indice donde termina la cabeza
					int counter = 0;
					bool cabezaEncontrada = false;
					for (unsigned int i = 0; i < s.length() && !cabezaEncontrada; ++i)
					{
						char c = s[i];
						cabeza += c;
						if (c == '(')
						{
							++counter;
						}
						else
						{
							if (c == ')')
							{
								if (counter == 1)
								{
									head = stringToList<T>(cabeza, nombre);
									cabezaEncontrada = true;
									indiceFinal = i;
								}
								else
								{
									--counter;
								}
							}

						}
					}
					std::string cola = s.substr(indiceFinal + 1); //La cola va desde donde termina la cabeza, hasta el final de la lista
					tail = stringToList<T>(cola, nombre);
				}
			}
		}
		l = new List<T>(head, tail, nombre, valorAtomico);
		return l;
	}
	
	/**
	 * @brief se usa en algunos casos especiales. Crea un objeto List<T> a partir de una hilera
	 * 
	 * @param s 
	 * @param nombre 
	 * @return List<string>* 
	 */
	List<string>* stringToList2(string s, string nombre)
	{
		List<string>* l = nullptr;
		List<string>* head = nullptr;
		List<string>* tail = nullptr;
		string valorAtomico;
		if (esInputValido(s)) {
			if (esSoloCabeza(s)) {
				stringstream stream(s.substr(1));
				string token;
				getline(stream, token, ')');
				valorAtomico = token;
			}
			else {
				if (esListaBasica(s)) {
					stringstream stream(s.substr(1));
					string token;
					getline(stream, token, ' ');
					string atomicVal1 = token;
					head = new List<string>((atomicVal1));
					getline(stream, token, ')');
					string atomicVal2 = token;
					tail = new List<string>((atomicVal2));
				}
				else {
					removerInicioYFin(s);
					string cabeza;
					int indiceFinal = 0; //indice donde termina la cabeza
					int counter = 0;
					bool cabezaEncontrada = false;
					for (unsigned int i = 0; i < s.length() && !cabezaEncontrada; ++i)
					{
						char c = s[i];
						cabeza += c;
						if (c == '(')
						{
							++counter;
						}
						else
						{
							if (c == ')')
							{
								if (counter == 1)
								{
									head = stringToList2(cabeza, nombre);
									cabezaEncontrada = true;
									indiceFinal = i;
								}
								else
								{
									--counter;
								}
							}

						}
					}
					std::string cola = s.substr(indiceFinal + 1); //La cola va desde donde termina la cabeza, hasta el final de la lista
					tail = stringToList2(cola, nombre);
				}
			}
		}
		l = new List<string>(head, tail, nombre, valorAtomico);
		return l;
	}

};