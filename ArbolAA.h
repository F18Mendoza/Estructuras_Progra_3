#ifndef ARBOLAA_H
#define ARBOLAA_H

#include <iostream>
#include "NodoAA.h"

using namespace std;

class ArbolAA {

    private:
    	NodoAA *raiz;
    
    public:
        ArbolAA() {raiz = NULL;}

		bool vacio() {return raiz == NULL;}
		void insertar(string pNombre, int pCodMarca, int pStock, int pCanasta);
        void insertarRecursivo(NodoAA *&r, string pNombre, int pCodMarca, int pStock, int pCanasta);
        void podar();
        void podarRecursivo(NodoAA *raiz);
		bool existeMarca(int pCodMarca);
		bool existeMarcaRecursivo(NodoAA *&r, int pCodMarca);
		void mostrar();
		void mostrarRecursivo(NodoAA *&r);
		void modificarMarcaNombre (string pNombre, int pCodMarca);
        void modificarMarcaNombreRecursivo(NodoAA *&r, string pNombre, int pCodMarca);
        bool canasta(int pCodMarca);
        bool canastaRecursivo(NodoAA *&r, int pCodMarca);
        void verificarInventario();
        void verificarInventarioRecursivo(NodoAA *&r);
        void modificarInventario (string pNombre, int pCantStock, int pCanasta, int pCodMarca);
        void modificarInventarioRecursivo (NodoAA *&r, string pNombre, int pCantStock, int pCanasta, int pCodMarca);
        void eliminarInventario(int pCodMarca);
        void eliminarInventarioRecursivo(int pCodMarca, NodoAA *&r);

};

#endif
