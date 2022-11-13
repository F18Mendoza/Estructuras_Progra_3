#ifndef GRAFOPUNTOS_H
#define GRAFOPUNTOS_H

#include <iostream>
#include "CiudadPuntos.h"

using namespace std;

class GrafoPuntos {
	
	private:
		
		CiudadPuntos *primero;
	
	public:
		
		GrafoPuntos() {primero = NULL;}
		
		void insertarCiudad(int pCodCiudad, string pNombre);
		void insertarConexion(int pCodCiudad, int pCodLlegada);
		bool existeCiudad(int pCodCiudad);
		bool existeConexion(int pCodCiudad, int pCodLlegada);
		void mostrar();
};

#endif
