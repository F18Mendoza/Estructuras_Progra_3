#ifndef ARBOLBB_H
#define ARBOLBB_H

#include <iostream>
#include "NodoBB.h"

using namespace std;

class ArbolBB {

    private:
        NodoBB *raiz;
    
    public:
        ArbolBB() {raiz = NULL;}

        void insertar(string pNombre, int pCodPasillo);
        void insertarRecursivo(NodoBB *&r, string pNombre, int pCodPasillo);
        void podar();
        void podarRecursivo(NodoBB *&r);
        bool existeCodigo(int pCodPasillo);
        bool existeCodigoRecursivo(int pCodPasillo, NodoBB *&r);
        bool existeProducto(int pCodPasillo, int pCodProducto);
        bool existeProductoRecursivo(int pCodPasillo, int pCodProducto, NodoBB *&r);
        bool existeMarca(int pCodPasillo, int pCodProducto, int pCodMarca);
        bool existeMarcaRecursivo(int pCodPasillo, int pCodProducto, int pCodMarca, NodoBB *&r);
        void insertarProducto(string pNombre, int pCodPasillo, int pCodProducto);
        void insertarProductoRecursivo(NodoBB *&r, string pNombre, int pCodPasillo, int pCodProducto);
        void insertarMarca(string pNombre, int pCodPasillo, int pCodProducto, int pCodMarca, int pCantidad, float pPrecio);
        void insertarMarcaRecursivo(NodoBB *&r, string pNombre, int pCodPasillo, int pCodProducto, int pCodMarca, int pCantidad, float pPrecio);
        void insertarInventario(string pNombre, int pCodPasillo, int pCodProducto, int pCodMarca, int pStock, int pCanasta);
        void insertarInventarioRecursivo(NodoBB *&r, string pNombre, int pCodPasillo, int pCodProducto, int pCodMarca, int pStock, int pCanasta);
        void mostrarPasillos();
        void mostrarPasillosRecursivo(NodoBB *&r);
        void mostrarProductos(int pCodPasillo);
        void mostrarProductosRecursivo(NodoBB *&r, int pCodPasillo);
        void mostrarMarcas(int pCodPasillo, int pCodProducto);
        void mostrarMarcasRecursivo(NodoBB *&r, int pCodPasillo, int pCodProducto);
        void mostrarInventario();
        void mostrarInventarioRecursivo(NodoBB *&r);
        void mostrar();
        void mostrarRecursivo(NodoBB *&r);
        void mostrarPrecio(int pCodPasillo, int pCodProducto, int pCodMarca);
        void mostrarPrecioRecursivo(int pCodPasillo, int pCodProducto, int pCodMarca, NodoBB *&r);
        bool verificarCantidad(int pCodPasillo, int pCodProducto, int pCodMarca, int pCantidad);
        bool verificarCantidadRecursivo(NodoBB *&r, int pCodPasillo, int pCodProducto, int pCodMarca, int pCantidad);
        int cantidadMaxima(int pCodPasillo, int pCodProducto, int pCodMarca);
        int cantidadMaximaRecursivo(NodoBB *&r, int pCodPasillo, int pCodProducto, int pCodMarca);
        bool canasta(int pCodPasillo, int pCodProducto, int pCodMarca);
        bool canastaRecursivo(NodoBB *&r, int pCodPasillo, int pCodProducto, int pCodMarca);
        float obtenerPrecio(int pCodPasillo, int pCodProducto, int pCodMarca);
        float obtenerPrecioRecursivo(NodoBB *&r, int pCodPasillo, int pCodProducto, int pCodMarca);
        string nombreProducto(int pCodPasillo, int pCodProducto);
        string nombreProductoRecursivo(NodoBB *&r, int pCodPasillo, int pCodProducto);
        string nombreMarca(int pCodPasillo, int pCodProducto, int pCodMarca);
        string nombreMarcaRecursivo(NodoBB *&r, int pCodPasillo, int pCodProducto, int pCodMarca);
        void sacarDeGondola(int pCodPasillo, int pCodProducto, int pCodMarca, int pCantidad);
        void sacarDeGondolaRecursivo(NodoBB *&r, int pCodPasillo, int pCodProducto, int pCodMarca, int pCantidad);
        void verificarInventario();
        void verificarInventarioRecursivo(NodoBB *&r);
        void revisarGondolas();
        void revisarGondolasRecursivo(NodoBB *&r);
        void modificarPasillo(string pNombre, int pCodPasillo);
        void modificarPasilloRecursivo(NodoBB *&r, string pNombre, int pCodPasillo);
        void modificarProducto(string pNombre, int pCodPasillo, int pCodProducto);
        void modificarProductoRecursivo(NodoBB *&r, string pNombre, int pCodPasillo, int pCodProducto);
        void modificarMarcaGondola (int pGondola, int pCodPasillo, int pCodProducto, int pCodMarca);
        void modificarMarcaGondolaRecursivo(NodoBB *&r, int pGondola, int pCodPasillo, int pCodProducto, int pCodMarca);
        void modificarMarcaNombre (string pNombre, int pCodPasillo, int pCodProducto, int pCodMarca);
        void modificarMarcaNombreRecursivo(NodoBB *&r, string pNombre, int pCodPasillo, int pCodProducto, int pCodMarca);
        void modificarMarcaPrecio (float pPrecio, int pCodPasillo, int pCodProducto, int pCodMarca);
        void modificarMarcaPrecioRecursivo(NodoBB *&r, float pPrecio, int pCodPasillo, int pCodProducto, int pCodMarca);
        void modificarInventario (string pNombre, int pCantStock, int pCanasta, int pCodPasillo, int pCodProducto, int pCodMarca);
        void modificarInventarioRecursivo (NodoBB *&r, string pNombre, int pCantStock, int pCanasta, int pCodPasillo, int pCodProducto, int pCodMarca);
        void eliminarPasillo(int pCodPasillo);
        void eliminarPasilloRecursivo(int pCodPasillo, NodoBB *&r);
        void eliminarProducto(int pCodPasillo, int pCodProducto);
        void eliminarProductoRecursivo(int pCodPasillo, int pCodProducto, NodoBB *&r);
        void eliminarMarca(int pCodPasillo, int pCodProducto, int pCodMarca);
        void eliminarMarcaRecursivo(int pCodPasillo, int pCodProducto, int pCodMarca, NodoBB *&r);
};

#endif
