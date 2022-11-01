#ifndef REPORTECLIENTES_H
#define REPORTECLIENTES_H

#include <iostream>

using namespace std;

class ReporteClientes {
	
	private:
		
		int cedula, facturas;
		float monto;
		ReporteClientes *siguiente;
		
	public:
		
		ReporteClientes(int pCedula) {
		
			cedula = pCedula;
			monto = 0;
			facturas = 0;
			siguiente = NULL;
		}
		
	friend class Reportes;
};

#endif
