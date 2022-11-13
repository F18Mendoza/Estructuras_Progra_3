#ifndef CIUDAD_H
#define CIUDAD_H

#include <iostream>
#include "Conexion.h"

using namespace std;

class Ciudad {
	
	private:
		
		string nombre;
		int codCiudad;
		Conexion *conexiones;
		Ciudad *siguiente;
		
	public:
		
		Ciudad(string pNombre, int pCodCiudad) {
			
			nombre = pNombre;
			codCiudad = pCodCiudad;
			conexiones = NULL;
			siguiente = NULL;
		}
		
	friend class Grafo;	
};

#endif
