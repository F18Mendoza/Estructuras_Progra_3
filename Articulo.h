#ifndef ARTICULO_H
#define ARTICULO_H

#include <iostream>

using namespace std;

class Articulo {
	
	private:
		
		int codPasillo, codProducto, codMarca, cantidad;
		Articulo *siguiente;
		
	public:
		
		Articulo(int pCodPasillo, int pCodProducto, int pCodMarca, int pCantidad) {
			
			codPasillo = pCodPasillo;
			codProducto = pCodProducto;
			codMarca = pCodMarca;
			cantidad = pCantidad;
			siguiente = NULL;
		}
	
	friend class Carrito;
};

#endif
