#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include "Ciudad.h"

using namespace std;

class Grafo {
	
	private:
		
		Ciudad *primero;
		
	public:
		
		Grafo() {primero = NULL;}
		
		void insertarCiudad(int pCodCiudad, string pNombre);
		void insertarConexion(int pCodCiudad, int pCodLlegada, int pPeso);
		bool existeCiudad(int pCodCiudad);
		bool existeConexion(int pCodCiudad, int pCodLlegada);
		void mostrar();
};

#endif
