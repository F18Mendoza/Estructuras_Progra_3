#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>

using namespace std;

class Cliente {
	
	private:
		
		Cliente *siguiente;
		int cedula, contador;
		
	public:
		
		Cliente(int pCedula) {
		
			cedula = pCedula;
			contador = 0;
			siguiente = NULL;
		}
		
	friend class ListaDescuento;
};

#endif
