#include "Terminal.h"

std::vector<std::string> Terminal::separarInstruccion(std::string const &instruccion, char separador) {	
	std::vector<std::string> keyWords;	
	std::stringstream ss(instruccion);
	std::string keyWord = "";	
	while (getline(ss,keyWord, separador)) {		
		keyWords.push_back(keyWord);
	}	
	return keyWords;
}

int Terminal::identificarComando(std::string const& comando){
	return INSTRUCCIONES.find(comando);
}


//int main(){      //01234567891234567891234567
//	Terminal t;
//	std::string instrucciones = "lista1";
//	std::vector<std::string> keyWords = t.separarInstruccion(instrucciones, '.');
//	std::cout << keyWords.size() << std::endl;
//	for (int i = 0; i < keyWords.size(); ++i) {
//		std::cout << keyWords[i] << std::endl;
//	}
//
//	return 0;
//}