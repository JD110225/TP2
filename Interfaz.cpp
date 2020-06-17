#include "Interfaz.h"

std::string Interfaz::pedirComando(std::string mensaje){//check for empty string
    std::string comando = "";
    std::cout << mensaje << std::flush;
    std::cin >> comando;
    return comando;
}

void Interfaz::mostrarError(std::string mensaje){
    std::cout << "ERROR, " << mensaje << std::endl;
}
