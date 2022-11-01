#ifndef CARRITO_H
#define CARRITO_H

#include <iostream>
#include "Articulo.h"

using namespace std;

class Carrito {
	
	private:
		
		int cedula;
		Articulo *primero;
		Carrito *siguiente;
		
	public:
		
		Carrito(int pCedula) {primero = NULL; cedula = pCedula; siguiente = NULL;}
		~Carrito();
		
		bool vacio() {return primero == NULL;}
		void agregarArticulo(int pCodPasillo, int pCodProducto, int pCodMarca, int pCantidad);
		int obtenerCodigoPasillo();
		int obtenerCodigoProducto();
		int obtenerCodigoMarca();
		int obtenerCantidad();
		void sacarArticulo();
		bool existeArticulo(int pCodPasillo, int pCodProducto, int pCodMarca);
	
	friend class Compras;
};

#endif
