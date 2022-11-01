#ifndef COMPRAS_H
#define COMPRAS_H

#include <iostream>
#include "Carrito.h"

using namespace std;

class Compras {
	
	private:
		
		Carrito *primero;
		
	public:
		
		Compras() {primero = NULL;}
		~Compras();
		
		bool vacio() {return primero == NULL;}
		bool carritoVacio() {return primero -> vacio();}
		bool confirmacionCedula(int pCedula) {return primero -> cedula == pCedula;}
		void agregarCarrito(int pCedula);
		void agregarArticulo(int pCedula, int pCodPasillo, int pCodProducto, int pCodMarca, int pCantidad);
		int obtenerCodigoPasillo();
		int obtenerCodigoProducto();
		int obtenerCodigoMarca();
		int obtenerCantidad();
		void eliminarCarrito();
		bool existeCarrito(int pCedula);
		void sacarArticulo();
};

#endif
