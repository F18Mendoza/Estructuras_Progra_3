#ifndef CONEXION_H
#define CONEXION_H

#include <iostream>

class Conexion {
	
	private:
		
		int peso, codCiudad;
		Conexion *siguiente;
		
	public:
		
		Conexion(int pCodCiudad, int pPeso) {
			
			codCiudad = pCodCiudad;
			peso = pPeso;
			siguiente = NULL;
		}
		
	friend class Grafo;
};

#endif
