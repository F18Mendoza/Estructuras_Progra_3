#include "Compras.h"
#include <iostream>

using namespace std;

Compras::~Compras() {
	
	Carrito *temp = primero;
	while (primero != NULL) {
		primero = primero -> siguiente;
		temp -> ~Carrito();
		delete temp;
		temp = primero;
	}
}

void Compras::agregarCarrito(int pCedula) {
	
	if (primero == NULL) {
		primero = new Carrito(pCedula);
	} else {
		Carrito *temp = primero;
		while (temp -> siguiente != NULL) {
			temp = temp -> siguiente;
		}
		temp -> siguiente = new Carrito(pCedula);
	}
}

void Compras::eliminarCarrito() {
	
	Carrito *temp = primero;
	primero = primero -> siguiente;
	delete temp;
}

int Compras::obtenerCodigoPasillo() {
	
	return primero -> obtenerCodigoPasillo();
} 

int Compras::obtenerCodigoProducto() {
	
	return primero -> obtenerCodigoProducto();
} 

int Compras::obtenerCodigoMarca() {
	
	return primero -> obtenerCodigoMarca();
} 

int Compras::obtenerCantidad() {
	
	return primero -> obtenerCantidad();
} 

void Compras::agregarArticulo(int pCedula, int pCodPasillo, int pCodProducto, int pCodMarca, int pCantidad) {
	
	if (!existeCarrito(pCedula)) {
		agregarCarrito(pCedula);
	}
	Carrito *temp = primero;
	while (temp -> cedula != pCedula) {
		temp = temp -> siguiente;
	}
	temp -> agregarArticulo(pCodPasillo, pCodProducto, pCodMarca, pCantidad);
}

bool Compras::existeCarrito(int pCedula) {
	
	if (primero == NULL) {
		return false;
	}
	Carrito *temp = primero;
	while (temp -> cedula != pCedula) {
		temp = temp -> siguiente;
	}
	if (temp -> cedula == pCedula) {
		return true;
	}
	return false;
}

void Compras::sacarArticulo() {
	
	primero -> sacarArticulo();
}
