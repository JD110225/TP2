#pragma once
#include "Decoder.h"
#include <iostream>
#include <sstream>
#include "List.h"
#include "string"
#include <typeinfo>
using namespace std;
class Decoder
{
private:
	int dataTypeID;
public:
	Decoder(int dataTypeID) {  //1.Int 2.char 3.double 4.string   
		this->dataTypeID = dataTypeID;
	}
	template <typename T>
	T dataTypeConverter(string s) { //convierte un string al tipo de dato correspondiente.
		T nuevoValor;
		switch (dataTypeID) {
		case 1: {
			nuevoValor = stoi(s);
			break;
		}
		case 2: {
			nuevoValor = s[0];
			break;
		}
		case 3: {
			nuevoValor = stof(s);
			break;
		}
		/*case 4: {
			nuevoValor = (string)s;
			break;
		}*/
		default: {
			break;
		}


		}
		return nuevoValor;
	}


	int contarOcurrenciasCaracter(string s, char c) {
		int counter = 0;
		for (char caracter : s) {
			if (caracter == c) {
				++counter;
			}
		}
		return counter;
	}
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
	bool esInputValido(string s) {  //revisa que no haya espacios ahi random metidos y que la cantidad de '(' coincida con la cantidad de ')'.
		bool condicion1 = contarOcurrenciasCaracter(s, '(') == contarOcurrenciasCaracter(s, ')');
		bool condicion2 = tieneEspaciosEntreParentesis(s) == false;
		return condicion1 && condicion2;
	}
	void removerInicioYFin(string& s)  //quitar el primero y el ultimo parentesis.
	{
		s.erase(0, 1);
		s.erase(s.length() - 1, 1);
	}
	bool esListaBasica(string s) {
		return contarOcurrenciasCaracter(s, '(') == 1 && contarOcurrenciasCaracter(s, ')') == 1 && contarOcurrenciasCaracter(s, ' ') == 1;
		//return s.length() == 5 && s[0] == '(' && isdigit(s[1]) && s[2] == ' ' && isdigit(s[3]) && s[4] == ')';
	}
	bool esSoloCabeza(string s) {
		return contarOcurrenciasCaracter(s, '(') == 1 && contarOcurrenciasCaracter(s, ')') == 1 && contarOcurrenciasCaracter(s, ' ') == 0;
		// return s.length() == 3 && s[0] == '(' && isdigit(s[1]) && s[2] == ')';
	}
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

};
//
//int main()
//{
//    int type;
//    std::cout << "Type: ";
//    std::cin >> type;
//    std::cin.ignore();
//    std::fflush(stdin);//sin esto se vuelve loco
//
//    //1)Int 2)Char 3)Double 4)String
//    if (type == 1) {
//        //std::fflush(stdin);
//        Decoder d1(1);
//        //string s1 = "((123)(4 5))";
//        std::cout << "Enter a command:";
//        std::string s1;
//        getline(std::cin, s1);
//        //std::fflush(stdin);
//        cout << "Test con enteros: " << s1 << endl;
//        List<int>* l1 = d1.stringToList<int>(s1);
//        cout << "Cabeza: " << l1->getHead()->toString() << endl;
//        //cout << "Type-id del valor atomico: " << typeid(l1->getHead()->getValue()).name() << endl;
//
//    }
//    else if (type == 2) {
//        Decoder d2(2);
//        cout << "\n";
//        std::cout << "Enter a command:";
//        //string s2 = "((a)(b c))";
//        std::string s2;
//        getline(std::cin, s2);
//        cout << "Test con chars: " << s2 << endl;
//        List<char>* l2 = d2.stringToList<char>(s2);
//        cout << "Cabeza: " << l2->getHead()->toString() << endl;
//        //cout << "Type-id del valor atomico: " << typeid(l2->getHead()->getValue()).name() << endl;
//
//    }
//    else if (type == 3) {
//        Decoder d3(3);
//        cout << "\n";
//        std::cout << "Enter a command:";
//        //string s3 = "((12.3)(4 5.1))";
//        std::string s3;
//        getline(std::cin, s3);
//        cout << "Test con doubles: " << s3 << endl;
//        List<double>* l3 = d3.stringToList<double>(s3);
//        cout << "Cabeza: " << l3->getHead()->toString() << endl;
//        //cout << "Type-id del valor atomico: " << typeid(l3->getHead()->getValue()).name() << endl;
//
//    }
//    else if (type == 4) {
//        std::fflush(stdin);
//        Decoder d4(4);
//        cout << "\n";
//        std::cout << "Enter a command:";
//        //string s1 = "((hola)(adios patata))";
//        std::string s4;
//        getline(std::cin, s4);
//        std::fflush(stdin);
//        cout << "Test con string: " << s4 << endl;
//        List<std::string>* l4 = d4.stringToList<std::string>(s4);
//        cout << "Cabeza: " << l4->getHead()->toString() << endl;
//        //cout << "Type-id del valor atomico: " << typeid(l4->getHead()->getValue()).name() << endl;
//    }
//    return 0;
//}
