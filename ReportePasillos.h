#ifndef REPORTEPASILLOS_H
#define REPORTEPASILLOS_H

#include <iostream>

using namespace std;

class ReportePasillos {
	
	private:
		
		int codigo, contador;
		ReportePasillos *siguiente;
		
	public:
		
		ReportePasillos(int pCodigo) {
			
			codigo = pCodigo;
			contador = 0;
			siguiente = NULL;
		}
		
	friend class Reportes;
};

#endif
