#include "Grafo.h"
#include <iostream>

using namespace std;

void Grafo::insertarCiudad(int pCodCiudad, string pNombre) {
	
	if (primero == NULL) {
		primero = new Ciudad(pNombre, pCodCiudad);
	} else {
		if (!existeCiudad(pCodCiudad)) {
			Ciudad *temp = primero;
			while (temp -> siguiente != NULL){
				temp = temp -> siguiente;
			}
			temp -> siguiente = new Ciudad(pNombre, pCodCiudad);
		}
	}
}

void Grafo::insertarConexion(int pCodCiudad, int pCodLlegada, int pPeso) {
	
	if (existeCiudad(pCodCiudad) && existeCiudad(pCodLlegada)) {
		Ciudad *temp = primero;
		while (temp -> codCiudad != pCodCiudad) {
			temp = temp -> siguiente;
		}
		if (temp -> conexiones == NULL) {
			temp -> conexiones = new Conexion(pCodLlegada, pPeso);
		} else {
			if (!existeConexion(pCodCiudad, pCodLlegada)) {
				Conexion *temp2 = temp -> conexiones;
				while (temp2 -> siguiente != NULL) {
					temp2 = temp2 -> siguiente;
				}
				temp2 -> siguiente = new Conexion(pCodLlegada, pPeso);
			}
		}
		temp = primero;
		while (temp -> codCiudad != pCodLlegada) {
			temp = temp -> siguiente;
		}
		if (temp -> conexiones == NULL) {
			temp -> conexiones = new Conexion(pCodCiudad, pPeso);
		} else {
			if (!existeConexion(pCodLlegada, pCodCiudad)) {
				Conexion *temp2 = temp -> conexiones;
				while (temp2 -> siguiente != NULL) {
					temp2 = temp2 -> siguiente;
				}
				temp2 -> siguiente = new Conexion(pCodCiudad, pPeso);
			}
		}
	}
}

bool Grafo::existeCiudad(int pCodCiudad) {

	if (primero == NULL) {
		return false;
	} else {
		Ciudad *temp = primero;
		while (temp != NULL) {
			if (temp -> codCiudad == pCodCiudad) {
				return true;
			}
			temp = temp -> siguiente;
		}
		return false;
	}
}

bool Grafo::existeConexion(int pCodCiudad, int pCodLlegada) {
	
	Ciudad *temp = primero;
	while (temp -> codCiudad != pCodCiudad) {
		temp = temp -> siguiente;
	}
	if (temp -> conexiones == NULL) {
		return false;
	} else {
		Conexion *temp2 = temp -> conexiones;
		while (temp2 != NULL) {
			if (temp2 -> codCiudad == pCodLlegada) {
				return true;
			}
			temp2 = temp2 -> siguiente;
		}
		return false;
	}
}

void Grafo::mostrar() {
	
	Ciudad *temp = primero;
	while (temp != NULL) {
		cout << "Ciudad: " << temp -> codCiudad << " Nombre: " << temp -> nombre << endl;
		Conexion *temp2 = temp -> conexiones;
		while (temp2 != NULL) {
			cout << "Conexion: " << temp2 -> codCiudad << " Peso: " << temp2 -> peso << endl;
			temp2 = temp2 -> siguiente;
		}
		temp = temp -> siguiente;
	}
}
