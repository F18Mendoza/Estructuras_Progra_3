#ifndef ARBOLRN_H
#define ARBOLRN_H

#include <iostream>
#include "NodoRN.h"

using namespace std;

class ArbolRN {

    private:
        NodoRN *raiz;
    
    public:
        ArbolRN() {raiz = NULL;}

		bool vacio() {return raiz == NULL;}
        void insertar(string pNombre, int pCodMarca, int pCantidad, float pPrecio);
        void insertarRecursivo(NodoRN *&r,string pNombre, int pCodMarca,int pCantidad, float pPrecio);
        void podar();
        void podarRecursivo(NodoRN *&r);
        bool existeCodigo(int pCodMarca);
        bool existeCodigoRecursivo(int pCodMarca, NodoRN *&r);
        void mostrar();
        void mostrarRecursivo(NodoRN *&r);
        void mostrarMarcas();
        void mostrarMarcasRecursivo(NodoRN *&r);
        void mostrarPrecio(int pCodMarca);
        void mostrarPrecioRecursivo(int pCodMarca, NodoRN *&r);       
        bool verificarCantidad(int pCodMarca, int pCantidad);
        bool verificarCantidadRecursivo(NodoRN *&r, int pCodMarca, int pCantidad);
        int cantidadMaxima(int pCodMarca);
        int cantidadMaximaRecursivo(NodoRN *&r, int pCodMarca);
        float obtenerPrecio(int pCodMarca);
        float obtenerPrecioRecursivo(NodoRN *&r, int pCodMarca);
        string nombreMarca(int pCodMarca);
        string nombreMarcaRecursivo(NodoRN *&r, int pCodMarca);
        void sacarDeGondola(int pCodMarca, int pCantidad);
        void sacarDeGondolaRecursivo(NodoRN *&r, int pCodMarca, int pCantidad);
        void revisarGondolas();
        void revisarGondolasRecursivo(NodoRN *&r);
        void modificarMarcaGondola (int pGondola, int pCodMarca);
        void modificarMarcaGondolaRecursivo(NodoRN *&r, int pGondola, int pCodMarca);
        void modificarMarcaNombre (string pNombre, int pCodMarca);
        void modificarMarcaNombreRecursivo(NodoRN *&r, string pNombre, int pCodMarca);
        void modificarMarcaPrecio (float pPrecio, int pCodMarca);
        void modificarMarcaPrecioRecursivo(NodoRN *&r, float pPrecio, int pCodMarca);
        
		
    friend class NodoAVL;
};

#endif
