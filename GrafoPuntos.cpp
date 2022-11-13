#include "GrafoPuntos.h"
#include <iostream>

using namespace std;

void GrafoPuntos::insertarCiudad(int pCodCiudad, string pNombre) {
	
	if (primero == NULL) {
		primero = new CiudadPuntos(pNombre, pCodCiudad);
	} else {
		if (!existeCiudad(pCodCiudad)) {
			CiudadPuntos *temp = primero;
			while (temp -> siguiente != NULL) {
				temp = temp -> siguiente;
			}
			temp -> siguiente = new CiudadPuntos(pNombre, pCodCiudad);
		}
	}
}

void GrafoPuntos::insertarConexion(int pCodCiudad, int pCodLlegada) {
	
	if (existeCiudad(pCodCiudad) && existeCiudad(pCodLlegada)) {
		CiudadPuntos *temp = primero;
		while (temp -> codCiudad != pCodCiudad) {
			temp = temp -> siguiente;
		}
		if (temp -> conexiones == NULL) {
			temp -> conexiones = new ConexionPuntos(pCodLlegada);
		} else {
			if (!existeConexion(pCodCiudad, pCodLlegada)) {
				ConexionPuntos *temp2 = temp -> conexiones;
				while (temp2 -> siguiente != NULL) {
					temp2 = temp2 -> siguiente;
				}
				temp2 -> siguiente = new ConexionPuntos(pCodLlegada);
			}
		}
		temp = primero;
		while (temp -> codCiudad != pCodLlegada) {
			temp = temp -> siguiente;
		}
		if (temp -> conexiones == NULL) {
			temp -> conexiones = new ConexionPuntos(pCodCiudad);
		} else {
			if (!existeConexion(pCodLlegada, pCodCiudad)) {
				ConexionPuntos *temp2 = temp -> conexiones;
				while (temp2 -> siguiente != NULL) {
					temp2 = temp2 -> siguiente;
				}
				temp2 -> siguiente = new ConexionPuntos(pCodCiudad);
			}
		}
	}
}

bool GrafoPuntos::existeCiudad(int pCodCiudad) {
	
	if (primero == NULL) {
		return false;
	} else {
		CiudadPuntos *temp = primero;
		while (temp != NULL) {
			if (temp -> codCiudad == pCodCiudad) {
				return true;
			}
			temp = temp -> siguiente;
		}
		return false;
	}
}

bool GrafoPuntos::existeConexion(int pCodCiudad, int pCodLlegada) {
	
	CiudadPuntos *temp = primero;
	while (temp -> codCiudad != pCodCiudad) {
		temp = temp -> siguiente;
	}
	if (temp -> conexiones == NULL) {
		return false;
	} else {
		ConexionPuntos *temp2 = temp -> conexiones;
		while (temp2 != NULL) {
			if (temp2 -> codCiudad == pCodLlegada) {
				return true;
			}
			temp2 = temp2 -> siguiente;
		}
		return false;
	}
}

void GrafoPuntos::mostrar() {
	
	CiudadPuntos *temp = primero;
	while (temp != NULL) {
		cout << "Ciudad: " << temp -> codCiudad << " Nombre: " << temp -> nombre << endl;
		ConexionPuntos *temp2 = temp -> conexiones;
		while (temp2 != NULL) {
			cout << "Conexion: " << temp2 -> codCiudad << endl;
			temp2 = temp2 -> siguiente;
		}
		temp = temp -> siguiente;
	}
}
