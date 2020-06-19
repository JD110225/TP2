/**
 * @file Terminal.cpp
 * @author Eduardo Ayales
 * @brief Esta clase se encarga de identificar y separar las instrucciones de la terminal
 * @version 1.0
 * @date 2020-06-19
 *
 * @copyright Free without any restriction
 *
 */
#include "Terminal.h"

 /**
  * @brief Este método separa las partes de una instruccion en strings, recibe la instruccion y un separador para especificar cuando termina una palabra
  *
  * @param instruccion instruccion digitada por el usuario
  * @param separador separador de palabras
  * @return std::vector<std::string> la instruccion digitada por el usuario separada
  */
std::vector<std::string> Terminal::separarInstruccion(std::string const& instruccion, char separador) {
	std::vector<std::string> keyWords;
	std::stringstream ss(instruccion);
	std::string keyWord = "";
	while (getline(ss, keyWord, separador)) {
		keyWords.push_back(keyWord);
	}
	return keyWords;
}

/**
 * @brief Este metodo identifica el comando digitado por el usuario en la terminal
 *
 * @param comando palabra clave digitada por el usuario
 * @return int numero asociado al comando
 */
int Terminal::identificarComando(std::string const& comando) {
	return INSTRUCCIONES.find(comando);
}