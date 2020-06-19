/**
 * @file Interfaz.cpp
 * @author Eduardo Ayales
 * @brief Esta clase se encarga de la interacción entrada/salida con el usuario
 * @version 1.0
 * @date 2020-06-19
 *
 * @copyright Free without any restriction
 *
 */
#include "Interfaz.h"

 /**
  * @brief Este metodo le pide la instruccion al usuario
  *
  * @param mensaje el mensaje de lo que se le va a pedir
  * @return std::string la instruccion digitada
  */
std::string Interfaz::pedirComando(std::string mensaje) {//check for empty string
    std::string comando = "";
    std::cout << mensaje << std::flush;
    getline(std::cin, comando);
    return comando;
}

/**
 * @brief Este metodo le muestra un error al usuario
 *
 * @param mensaje el error a desplegar
 */
void Interfaz::mostrarError(std::string mensaje) {
    std::cout << "ERROR, " << mensaje << std::endl;
}

/**
 * @brief Este metodo le muestra un mensaje al usuario
 *
 * @param mensaje el mensaje a desplegar
 */
void Interfaz::mostrarMensaje(std::string mensaje) {
    std::cout << mensaje << std::endl;
}

/**
 * @brief Este metodo le pide un numero al usuario
 *
 * @param mensaje el mensaje de lo que se le va a pedir
 * @return int el numero digitado por el usuario
 */
int Interfaz::pedirNumero(std::string mensaje) {
    std::string stringNumero = "";
    int numero = -1;
    bool valido = true;
    while (numero == -1) {
        std::cout << mensaje << std::flush;
        std::cin >> stringNumero;
        for (char c : stringNumero) {
            if (!isdigit(c)) {
                valido = false;
                numero = -1;
            }
            else {
                numero = stoi(stringNumero);
            }
        }
        if (numero == -1) {
            mostrarError("Input Invalido");
        }
    }
    return numero;
}
