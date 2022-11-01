#ifndef LISTADESCUENTO_H
#define LISTADESCUENTO_H

#include <iostream>
#include "Cliente.h"

using namespace std;

class ListaDescuento {
	
	private:
		Cliente *primero;
		int MIN;
		
	public:
		
		ListaDescuento() {primero = NULL; MIN = 4;}
		~ListaDescuento();
		
		bool cumpleRequisitos(int pCedula);
		void agregarCliente(int pCedula);
		void nuevaFactura(int pCedula);
		void todos();
};

#endif
