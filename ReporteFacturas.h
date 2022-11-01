#ifndef REPORTEFACTURAS_H
#define REPORTEFACTURAS_H

#include <iostream>

using namespace std;

class ReporteFacturas {
	
	private:
		
		int consecutivo;
		float monto;
		ReporteFacturas *siguiente;
		
	public:
		
		ReporteFacturas(int pConsecutivo, float pMonto) {
			
			consecutivo = pConsecutivo;
			monto = pMonto;
			siguiente = NULL;
		}
		
	friend class Reportes;
};

#endif
