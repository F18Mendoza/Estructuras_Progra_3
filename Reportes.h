#ifndef REPORTES_H
#define REPORTES_H

#include <iostream>
#include "ReportePasillos.h"
#include "ReporteProductos.h"
#include "ReporteClientes.h"
#include "ReporteFacturas.h"

using namespace std;

class Reportes {
	
	private:
		
		ReportePasillos *pasillos;
		ReporteProductos *productos;
		ReporteClientes *clientes;
		ReporteFacturas *facturas;
		
	public:
		
		Reportes () {pasillos = NULL; productos = NULL; clientes = NULL; facturas = NULL;}
		~Reportes();
		
		int pasillosVisitadosMax();
		int pasillosVisitadosMin();
		int pasillosContarVisitados(int pVisitas);
		void agregarPasillo(int pCodigo);
		void pasillosMostrarVisitados(int pVisitas, bool menos);
		void pasillosVisitar(int pCodigo);
		int productosCompradosMax(int pCodPasillo);
		bool productosVacio() {return productos == NULL;}
		void productosMostrarComprados(int pCodPasillo);
		int productosContarComprados(int pCodPasillo);
		void agregarProducto(int pCodPasillo, int pCodProducto, int pCantidad);
		bool existeProducto(int pCodPasillo, int pCodProducto);
		bool clientesVacio() {return clientes == NULL;}
		void agregarCliente(int pCedula, float pMonto);
		bool existeCliente(int pCedula);
		void clienteMasCompro();
		void clienteMenosCompro();
		void clienteMasFacturo();
		bool facturasVacio() {return facturas == NULL;}
		void agregarFactura(int pConsecutivo, float pMonto);
		void facturasMayorMonto();
};

#endif
