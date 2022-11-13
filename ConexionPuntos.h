#ifndef CONEXIONPUNTOS_H
#define CONEXIONPUNTOS_H

#include <iostream>

using namespace std;

class ConexionPuntos {
	
	private:
		
		int codCiudad;
		ConexionPuntos *siguiente;
		
	public:
		
		ConexionPuntos(int pCodCiudad) {
			
			codCiudad = pCodCiudad;
			siguiente = NULL;
		}
		
	friend class GrafoPuntos;
};

#endif
