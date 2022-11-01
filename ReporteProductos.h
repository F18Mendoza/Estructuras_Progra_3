#ifndef REPORTEPRODUCTOS_H
#define REPORTEPRODUCTOS_H

#include <iostream>

using namespace std;

class ReporteProductos {
	
	private:
		
		int codigo, vendidos, codPasillo;
		ReporteProductos *siguiente;
		
	public:
		
		ReporteProductos(int pCodigo, int pCodigoPasillo) {
		
		codigo = pCodigo;
		codPasillo = pCodigoPasillo;
		vendidos = 0;
		siguiente = NULL;
		}
		
	friend class Reportes;
};

#endif
