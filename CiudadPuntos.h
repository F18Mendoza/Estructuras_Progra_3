#ifndef CIUDADPUNTOS_H
#define CIUDADPUNTOS_H

#include <iostream>
#include "ConexionPuntos.h"

using namespace std;

class CiudadPuntos {
	
	private:
		
		string nombre;
		int codCiudad;
		ConexionPuntos *conexiones;
		CiudadPuntos *siguiente;
		
	public:
		
		CiudadPuntos(string pNombre, int pCodCiudad) {
			
			nombre = pNombre;
			codCiudad = pCodCiudad;
			conexiones = NULL;
			siguiente = NULL;
		}
		
	friend class GrafoPuntos;
};

#endif
