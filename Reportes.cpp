#include <iostream>
#include "Reportes.h"

using namespace std;

Reportes::~Reportes() {
	
	ReporteFacturas *tempFacturas = facturas;
	ReportePasillos *tempPasillos = pasillos;
	ReporteProductos *tempProductos = productos;
	ReporteClientes *tempClientes = clientes;
	while (facturas != NULL) {
		facturas = facturas -> siguiente;
		delete tempFacturas;
		tempFacturas = facturas;
	}
	while (pasillos != NULL) {
		pasillos = pasillos -> siguiente;
		delete tempPasillos;
		tempPasillos = pasillos;
	}
	while (productos != NULL) {
		productos = productos -> siguiente;
		delete tempProductos;
		tempProductos = productos;
	}
	while (clientes != NULL) {
		clientes = clientes -> siguiente;
		delete tempClientes;
		tempClientes = clientes;
	}
}

int Reportes::pasillosContarVisitados(int pVisitas) {
	
	int cont = 0;
	ReportePasillos *temp = pasillos;
	while (temp != NULL) {
		if (temp -> contador == pVisitas) {
			cont++;
		}
		temp = temp -> siguiente;
	}
	return cont;
}

int Reportes::pasillosVisitadosMax() {
	
	ReportePasillos *temp = pasillos;
	int max = temp -> contador;
	while (temp != NULL) {
		if (max < temp -> contador) {
			max = temp -> contador;
		}
		temp = temp -> siguiente;
	}
	return max;
}

int Reportes::pasillosVisitadosMin() {
	
	ReportePasillos *temp = pasillos;
	int min = temp -> contador;
	while (temp != NULL) {
		if (min > temp -> contador) {
			min = temp -> contador;
		}
		temp = temp -> siguiente;
	}
	return min;
}

void Reportes::agregarPasillo(int pCodigo) {
	
	if (pasillos == NULL) {
		pasillos = new ReportePasillos(pCodigo);
	} else {
		ReportePasillos *temp = pasillos;
		while (temp -> siguiente != NULL) {
			temp = temp -> siguiente;
		}
		temp -> siguiente = new ReportePasillos(pCodigo);
	}
}

void Reportes::pasillosMostrarVisitados(int pVisitas, bool menos) {
	
	if (pasillosContarVisitados(pVisitas) > 1) {
		if (menos) {
			cout << "Los pasillos menos visitados son:" << endl;
			ReportePasillos *temp = pasillos;
			while (temp != NULL) {
				if (temp -> contador == pVisitas) {
					cout << "Codigo de pasillo: " << temp -> codigo << endl;
				}
				temp = temp -> siguiente;
			}
			cout << "Han sido visitados " << pVisitas << " veces." << endl;
		} else {
			cout << "Los pasillos mas visitados son:" << endl;
			ReportePasillos *temp = pasillos;
			while (temp != NULL) {
				if (temp -> contador == pVisitas) {
					cout << "Codigo de pasillo: " << temp -> codigo << endl;
				}
				temp = temp -> siguiente;
			}
			cout << "Han sido visitados " << pVisitas << " veces." << endl;
		}
	} else {
		if (menos) {
			cout << "El pasillo menos visitado es:" << endl;
			ReportePasillos *temp = pasillos;
			while (temp != NULL) {
				if (temp -> contador == pVisitas) {
					cout << "Codigo de pasillo: " << temp -> codigo << endl;
				}
				temp = temp -> siguiente;
			}
			cout << "Ha sido visitado " << pVisitas << " veces." << endl;
		} else {
			cout << "El pasillo mas visitado es:" << endl;
			ReportePasillos *temp = pasillos;
			while (temp != NULL) {
				if (temp -> contador == pVisitas) {
					cout << "Codigo de pasillo: " << temp -> codigo << endl;
				}
				temp = temp -> siguiente;
			}
			cout << "Ha sido visitado " << pVisitas << " veces." << endl;
		}
	}
}

void Reportes::pasillosVisitar(int pCodigo) {
	
	if (pasillos -> codigo == pCodigo) {
		pasillos -> contador++;
	} else {
		ReportePasillos *temp = pasillos;
		while (temp -> codigo != pCodigo) {
			temp = temp -> siguiente;
		}
		temp -> contador++;
	}
}

int Reportes::productosCompradosMax(int pCodPasillo) {
	
	int max = productos -> vendidos;
	ReporteProductos *temp = productos;
	while (temp != NULL) {
		if (temp -> codPasillo == pCodPasillo) {
			if (max < temp -> vendidos) {
				max = temp -> vendidos;
			}
		}
		temp = temp -> siguiente;
	}
	return max;
}

void Reportes::productosMostrarComprados(int pCodPasillo) {
	
	int cantidad = productosCompradosMax(pCodPasillo);
	int comprados = productosContarComprados(pCodPasillo);
	if (comprados > 1) {
		cout << "Los productos mas comprados del pasillo con codigo " << pCodPasillo << " son:" << endl;
		ReporteProductos *temp = productos;
		while (temp != NULL) {
			if (temp -> codPasillo == pCodPasillo) {
				if (temp -> vendidos == cantidad) {
					cout << "Codigo de producto: " << temp -> codigo << endl;
				}
			}
			temp = temp -> siguiente;
		}
	} else {
		cout << "El producto mas comprado del pasillo con codigo " << pCodPasillo << " es:" << endl;
		ReporteProductos *temp = productos;
		while (temp != NULL) {
			if (temp -> codPasillo == pCodPasillo) {
				if (temp -> vendidos == cantidad) {
					cout << "Codigo de producto: " << temp -> codigo << endl;
				}
			}
			temp = temp -> siguiente;
		}
	}
}

int Reportes::productosContarComprados(int pCodPasillo) {
	
	ReporteProductos *temp = productos;
	int cantidad = productosCompradosMax(pCodPasillo);
	int contador;
	while (temp != NULL) {
		if (temp -> codPasillo == pCodPasillo) {
			if (temp -> vendidos == cantidad) {
				contador++;
			}
		}
		temp = temp -> siguiente;
	}
	return contador;
}

void Reportes::agregarProducto(int pCodPasillo, int pCodProducto, int pCantidad) {
	
	ReporteProductos *temp = productos;
	if (productos == NULL) {
		productos = new ReporteProductos(pCodProducto, pCodPasillo);
	} else {
		if (!existeProducto(pCodPasillo, pCodProducto)) {
			while (temp -> siguiente != NULL) {
				temp = temp -> siguiente;
			}
			temp -> siguiente = new ReporteProductos(pCodProducto, pCodPasillo);
		}
	}
	temp = productos;
	while (temp != NULL) {
		if (temp -> codPasillo == pCodPasillo) {
			if (temp -> codigo == pCodProducto) {
				temp -> vendidos += pCantidad;
				break;
			}
		}
		temp = temp -> siguiente;
	}
}

bool Reportes::existeProducto(int pCodPasillo, int pCodProducto) {
	
	if (productos == NULL) {
		return false;
	} else {
		ReporteProductos *temp = productos;
		while (temp != NULL) {
			if (temp -> codPasillo == pCodPasillo) {
				if (temp -> codigo == pCodProducto) {
					return true;
				}
			}
			temp = temp -> siguiente;
		}
		return false;
	}
}

void Reportes::agregarCliente(int pCedula, float pMonto) {
	
	ReporteClientes *temp = clientes;
	if (clientes == NULL) {
		clientes = new ReporteClientes(pCedula);
	} else {
		if (!existeCliente(pCedula)) {
			while (temp -> siguiente != NULL) {
				temp = temp -> siguiente;
			}
			temp -> siguiente = new ReporteClientes(pCedula);
		}
	}
	temp = clientes;
	while (temp != NULL) {
		if (temp -> cedula == pCedula) {
			if (temp -> monto < pMonto) {
				temp -> monto = pMonto;
				temp -> facturas++;
				break;
			}
			break;
		}
		temp = temp -> siguiente;
	}
}

bool Reportes::existeCliente(int pCedula) {
	
	if (clientes -> cedula == pCedula) {
		return true;
	} else {
		ReporteClientes *temp = clientes;
		while (temp != NULL) {
			if (temp -> cedula == pCedula) {
				return true;
			}
			temp = temp -> siguiente;
		}
		return false;
	}
}

void Reportes::clienteMasCompro() {
	
	float max = clientes -> monto;
	if (clientes -> siguiente == NULL) {
		cout << "El cliente que mas compro es el cliente con la cedula: " << clientes -> cedula << endl;
	} else {
		ReporteClientes *temp = clientes;
		while (temp != NULL) {
			if (max < temp -> monto) {
				max = temp -> monto;
			}
			temp = temp -> siguiente;
		}
		temp = clientes;
		while (temp -> monto != max) {
			temp = temp -> siguiente;
		}
		cout << "El cliente que mas compro es el cliente con la cedula: " << temp -> cedula << endl;
	}
}

void Reportes::clienteMenosCompro() {
	
	float min = clientes -> monto;
	if (clientes -> siguiente == NULL) {
		cout << "El cliente que menos compro es el cliente con la cedula: " << clientes -> cedula << endl;	
	} else {
		ReporteClientes *temp = clientes;
		while (temp != NULL) {
			if (min > temp -> monto) {
				min = temp -> monto;
			}
			temp = temp -> siguiente;
		}
		temp = clientes;
		while (temp -> monto != min) {
			temp = temp -> siguiente;
		}
		cout << "El cliente que menos compro es el cliente con la cedula: " << temp -> cedula << endl;
	}
}

void Reportes::clienteMasFacturo() {
	
	int max = clientes -> facturas;
	if (clientes -> siguiente == NULL) {
		cout << "El cliente con mas facturas es el cliente con la cedula: " << clientes -> cedula << endl;
	} else {
		ReporteClientes *temp = clientes;
		while (temp != NULL) {
			if (max < temp -> facturas) {
				max = temp -> facturas;
			}
			temp = temp -> siguiente;
		}
		temp = clientes;
		while (temp -> facturas != max) {
			temp = temp -> siguiente;
		}
		cout << "El cliente con mas facturas es el cliente con la cedula: " << temp -> cedula << endl;
	}
}

void Reportes::agregarFactura(int pConsecutivo, float pMonto) {
	
	if (facturas == NULL) {
		facturas = new ReporteFacturas(pConsecutivo, pMonto);
	} else {
		ReporteFacturas *temp = facturas;
		while (temp -> siguiente != NULL) {
			temp = temp -> siguiente;
		}
		temp -> siguiente = new ReporteFacturas(pConsecutivo, pMonto);
	}
}

void Reportes::facturasMayorMonto() {
	
	if (facturas -> siguiente == NULL) {
		cout << "La factura con el consecutivo " << facturas -> consecutivo << " es la de mayor monto, por un total de " << facturas -> monto << "." << endl;
	} else {
		ReporteFacturas *temp = facturas;
		float max = temp -> monto;
		while (temp != NULL) {
			if (max < temp -> monto) {
				max = temp -> monto;
			}
			temp = temp -> siguiente;
		}
		temp = facturas;
		while (temp -> monto != max) {
			temp = temp -> siguiente;
		}
		cout << "La factura con el consecutivo " << temp -> consecutivo << " es la de mayor monto, por un total de " << temp -> monto << "." << endl;
	}
}
