#ifndef DESCUENTO_H
#define DESCUENTO_H

#include <iostream>

using namespace std;

class Descuento {
	
	private:
		
		Descuento *siguiente;
		int cedula, contadorCompras;
		
	public:
		
		Descuento(int pCedula) {
		
			cedula = pCedula;
			contadorCompras = 0;
			siguiente = NULL;
		}
		
	friend class ListaDescuento;
};

#endif
