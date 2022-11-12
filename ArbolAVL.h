#ifndef ARBOLAVL_H
#define ARBOLAVL_H

#include <iostream>
#include "NodoAVL.h"

using namespace std;

class ArbolAVL {

    private:
        NodoAVL *raiz;
    
    public:
        ArbolAVL() {raiz = NULL;}

		bool vacio() {return raiz == NULL;}
        void insertar(string pNombre, int pCodProducto);
        void insertarRecursivo(NodoAVL *&r,string pNombre, int pCodProducto);
        void insertarMarca(string pNombre, int pCodProducto, int pCodMarca, int pCantidad, float pPrecio);
        void insertarMarcaRecursivo(NodoAVL *&r, string pNombre, int pCodProducto, int pCodMarca, int pCantidad, float pPrecio);
        void insertarInventario(string pNombre, int pCodProducto, int pCodMarca, int pStock, int pCanasta);
        void insertarInventarioRecursivo(NodoAVL *&r, string pNombre, int pCodProducto, int pCodMarca, int pStock, int pCanasta);
        void podar();
        void podarRecursivo(NodoAVL *&r);
        bool existeCodigo(int pCodProducto);
        bool existeCodigoRecursivo(int pCodProducto, NodoAVL *&r);
        bool existeMarca(int pCodProducto, int pCodMarca);
        bool existeMarcaRecursivo(int pCodProducto, int pCodMarca, NodoAVL *&r);
        void mostrarProductos();
        void mostrarProductosRecursivo(NodoAVL *&r);
        void mostrarMarcas(int pCodProducto);
        void mostrarMarcasRecursivo(NodoAVL *&r, int pCodProducto);
        void mostrarInventario();
        void mostrarInventarioRecursivo(NodoAVL *&r);
        void mostrar();
        void mostrarRecursivo(NodoAVL *&r);
        void mostrarPrecio(int pCodProducto, int pCodMarca);
        void mostrarPrecioRecursivo(int pCodProducto, int pCodMarca, NodoAVL *&r);
        bool verificarCantidad(int pCodProducto, int pCodMarca, int pCantidad);
        bool verificarCantidadRecursivo(NodoAVL *&r, int pCodProducto, int pCodMarca, int pCantidad);
        int cantidadMaxima(int pCodProducto, int pCodMarca);
        int cantidadMaximaRecursivo(NodoAVL *&r, int pCodProducto, int pCodMarca);
        bool canasta(int pCodProducto, int pCodMarca);
        bool canastaRecursivo(NodoAVL *&r, int pCodProducto, int pCodMarca);
        float obtenerPrecio(int pCodProducto, int pCodMarca);
        float obtenerPrecioRecursivo(NodoAVL *&r, int pCodProducto, int pCodMarca);
        string nombreProducto(int pCodProducto);
        string nombreProductoRecursivo(NodoAVL *&r, int pCodProducto);
        string nombreMarca(int pCodProducto, int pCodMarca);
        string nombreMarcaRecursivo(NodoAVL *&r, int pCodProducto, int pCodMarca);
        void sacarDeGondola(int pCodProducto, int pCodMarca, int pCantidad);
        void sacarDeGondolaRecursivo(NodoAVL *&r, int pCodProducto, int pCodMarca, int pCantidad);
        void verificarInventario();
        void verificarInventarioRecursivo(NodoAVL *&r);
        void revisarGondolas();
        void revisarGondolasRecursivo(NodoAVL *&r);
        void modificarProducto(string pNombre, int pCodProducto);
        void modificarProductoRecursivo(NodoAVL *&r, string pNombre, int pCodProducto);
        void modificarMarcaGondola (int pGondola, int pCodProducto, int pCodMarca);
        void modificarMarcaGondolaRecursivo(NodoAVL *&r, int pGondola, int pCodProducto, int pCodMarca);
        void modificarMarcaNombre(string pNombre, int pCodProducto, int pCodMarca);
        void modificarMarcaNombreRecursivo(NodoAVL *&r, string pNombre, int pCodProducto, int pCodMarca);
        void modificarMarcaPrecio(float pPrecio, int pCodProducto, int pCodMarca);
        void modificarMarcaPrecioRecursivo(NodoAVL *&r, float pPrecio, int pCodProducto, int pCodMarca);
        void modificarInventario (string pNombre, int pCantStock, int pCanasta, int pCodProducto, int pCodMarca);
        void modificarInventarioRecursivo (NodoAVL *&r, string pNombre, int pCantStock, int pCanasta, int pCodProducto, int pCodMarca);
        void eliminarProducto(int pCodProducto);
        void eliminarProductoRecursivo(int pCodProducto, NodoAVL *&r);
        void eliminarMarca(int pCodProducto, int pCodMarca);
        void eliminarMarcaRecursivo(int pCodProducto, int pCodMarca, NodoAVL *&r);

    friend class NodoBB;
};

#endif
