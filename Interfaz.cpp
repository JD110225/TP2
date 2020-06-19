#include "Interfaz.h"

std::string Interfaz::pedirComando(std::string mensaje){//check for empty string
    std::string comando = "";
    std::cout << mensaje << std::flush;
    getline(std::cin, comando);
    return comando;
}

void Interfaz::mostrarError(std::string mensaje){
    std::cout << "ERROR, " << mensaje << std::endl;
}

void Interfaz::mostrarMensaje(std::string mensaje){
    std::cout << mensaje << std::endl;
}

int Interfaz::pedirNumero(std::string mensaje){
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
