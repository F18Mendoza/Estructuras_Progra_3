#include <iostream>
#include "ListaDescuento.h"

using namespace std;

ListaDescuento::~ListaDescuento() {
	
	Cliente *temp = primero;
	while (primero != NULL) {
		primero = primero -> siguiente;
		delete temp;
		temp = primero;
	}
}

bool ListaDescuento::cumpleRequisitos(int pCedula) {
	
	Cliente *temp = primero;
	while (temp -> cedula != pCedula) {
		temp = temp -> siguiente;
	}
	if (temp -> contador >= MIN) {
		return true;
	}
	return false;
}

void ListaDescuento::agregarCliente(int pCedula) {
	
	if (primero == NULL) {
		primero = new Cliente(pCedula);
	} else {
		Cliente *temp = primero;
		while (temp -> siguiente != NULL) {
			temp = temp -> siguiente;
		}
		temp -> siguiente = new Cliente(pCedula);
	}
}

void ListaDescuento::nuevaFactura(int pCedula) {
	
	Cliente *temp = primero;
	while (temp -> cedula != pCedula) {
		temp = temp -> siguiente;
	}
	temp -> contador++;
}

void ListaDescuento::todos() {
	
	Cliente *temp = primero;
	while (temp != NULL) {
		if (temp -> contador >= MIN) {
			cout << "El cliente de cedula " << temp -> cedula << " aplica para un descuento, ha facturado " << temp -> contador << " veces." << endl;
		} else {
			cout << "El cliente de cedula " << temp -> cedula << " no aplica para un descuento, ha facturado " << temp -> contador << " veces." << endl;
		}
		temp = temp -> siguiente;
	}
}
