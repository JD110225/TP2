#include "Controlador.h"

//void Controlador::run(T xD){
	/*std::map<std::string, List<T>*> lista;
	List<T>* list1 = new List<T>(3, nullptr);
	lista["lista1"] = list1;*/
	//std::string comando = "";			
	//while(comando != "salir"){
	//	comando = interfaz.pedirComando("Digite lo que sea: ");//cambiar
	//	if (comando != "") {//check
	//		std::vector<std::string> instrucciones = terminal.separarInstruccion(comando, ' ');			
	//		int accion = terminal.identificarComando(instrucciones[0]);
	//		if (accion != std::string::npos) {
	//			realizarAccion(instrucciones, accion);
	//		}
	//		else{
	//			interfaz.mostrarError("Comando Invalido");//creatividad
	//		}			
	//	}
	//	else {
	//		interfaz.mostrarError("Comando Invalido");//creatividad
	//	}
	//	
	//}
//}


//void Controlador::realizarAccion(std::vector<std::string>& instrucciones, int &accion){
//	switch (accion) {
//	case 0:
//		//crear
//		break; 
//	case 6:
//		//mostrar
//		break;
//	case 14:
//		//buscar
//		break;
//	default:
//		interfaz.mostrarError("Comando Invalido");
//			break;
//	}
//}
//
//void Controlador::crearLista(std::vector<std::string>& instrucciones){
//	switch (instrucciones.size()){//idk
//	case 3:
//		//Jose Delgado
//		crearListaConParentesis(instrucciones);
//		break;
//	case 4:
//		//KABU09
//	default:
//		break;
//	}
//}
//
////void Controlador::crearListaConParentesis(std::vector<std::string>& instrucciones){
////	//Jose Delgado
////	if (listas.find(instrucciones[1]) != listas.end()) {
////		//do 
////	}
////	else {
////		interfaz.mostrarError("Ya existe una lista con ese nombre");
////	}
////}
//
////void Controlador::crearListaConComandos(std::vector<std::string>& instrucciones){
////	if (listas.find(instrucciones[1]) != listas.end()) {
////		std::vector<std::string> cabeza = terminal.separarInstruccion(instrucciones[2], '.');//check if real
////		std::vector<std::string> cola = terminal.separarInstruccion(instrucciones[3], '.');//check if real
////		//List<std::string> lista = algunMetodoQueRecibaMapYelNombreDeLaListayretorneLista();//check data type
////	}
////	else {
////		interfaz.mostrarError("Ya existe una lista con ese nombre");
////	}
////}
