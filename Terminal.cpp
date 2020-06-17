#include "Terminal.h"

std::vector<std::string>& Terminal::separarInstruccion(std::string const &instruccion, char separador) {
	std::vector<std::string> keyWords;	
	std::stringstream ss(instruccion);
	std::string keyWord = "";	
	while (getline(ss,keyWord, ' ')) {
		keyWords.push_back(keyWord);
	}
	return keyWords;
}

int Terminal::identificarComando(std::string const& comando){
	return INSTRUCCIONES.find(comando);
}

//
//int main(){                    //01234567891234567891234567
//	std::string instrucciones = "crear mostrar buscar";
//	//std::string instrucciones = "cabeza cola";
//	int x = instrucciones.find("buscar");
//	//int x = instrucciones.find("cola");
//	std::cout << x << std::endl;
//	std::cout << instrucciones[x] << std::endl;
//	return 0;
//}