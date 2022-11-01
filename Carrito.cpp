#include "Carrito.h"
#include <iostream>

using namespace std;

Carrito::~Carrito() {
	
	Articulo *temp = primero;
	while (primero != NULL) {
		primero = primero -> siguiente;
		delete temp;
		temp = primero;
	}
}

void Carrito::agregarArticulo(int pCodPasillo, int pCodProducto, int pCodMarca, int pCantidad) {
	
	Articulo *temp = primero;
	if (primero == NULL) {
		primero = new Articulo(pCodPasillo, pCodProducto, pCodMarca, pCantidad);
	} else {
		if (!existeArticulo(pCodPasillo, pCodProducto, pCodMarca)) {
			while (temp -> siguiente != NULL) {
				temp = temp -> siguiente;
			}
			temp -> siguiente = new Articulo(pCodPasillo, pCodProducto, pCodMarca, pCantidad);
		} else {
			while (temp != NULL) {
				if (temp -> codPasillo == pCodPasillo) {
					if (temp -> codProducto == pCodProducto) {
						if (temp -> codMarca == pCodMarca) {
							temp -> cantidad += pCantidad;
							break;
						}
					}
				}
			}
		}
	}
}

void Carrito::sacarArticulo() {
	
	Articulo *temp = primero;
	if (primero -> siguiente == NULL) {
		primero = NULL;
		delete temp;
	} else {
		while (temp -> siguiente -> siguiente != NULL) {
			temp = temp -> siguiente;
		}
		Articulo *aux = temp -> siguiente;
		temp -> siguiente = NULL;
		delete aux;
	}
}

int Carrito::obtenerCodigoPasillo() {
	
	Articulo *temp = primero;
	while (temp -> siguiente != NULL) {
		temp = temp -> siguiente;
	}
	return temp -> codPasillo;
}

int Carrito::obtenerCodigoProducto() {
	
	Articulo *temp = primero;
	while (temp -> siguiente != NULL) {
		temp = temp -> siguiente;
	}
	return temp -> codProducto;
}

int Carrito::obtenerCodigoMarca() {
	
	Articulo *temp = primero;
	while (temp -> siguiente != NULL) {
		temp = temp -> siguiente;
	}
	return temp -> codMarca;
}

int Carrito::obtenerCantidad() {
	
	Articulo *temp = primero;
	while (temp -> siguiente != NULL) {
		temp = temp -> siguiente;
	}
	return temp -> cantidad;
}

bool Carrito::existeArticulo(int pCodPasillo, int pCodProducto, int pCodMarca) {
	
	if (primero == NULL) {
		return false;
	} else {
		Articulo *temp = primero;
		while (temp != NULL) {
			if (temp -> codPasillo == pCodPasillo) {
				if (temp -> codProducto == pCodProducto) {
					if (temp -> codMarca == pCodMarca) {
						return true;
					}
				}
			}
			temp = temp -> siguiente;
		}
		return false;
	}
}
