#ifndef NODORN_H
#define NODORN_H

#include <iostream>

class NodoRN {

    private:
        std::string nombre;
        int codMarca;
        int cantidad;
        float precio;
        NodoRN *HIzq;
        NodoRN *HDer;

    public:
        NodoRN(std::string pNombre, int pCodMarca, int pCantidad, float pPrecio) {

            nombre = pNombre;
            codMarca = pCodMarca;
            cantidad = pCantidad;
            precio = pPrecio;
            HIzq = NULL;
            HDer = NULL;
        }

    friend class ArbolRN;
};

#endif