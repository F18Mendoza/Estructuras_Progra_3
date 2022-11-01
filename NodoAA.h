#ifndef NODOAA_H
#define NODOAA_H

#include <iostream>

class NodoAA {

    private:
        std::string nombre;
        int codMarca;
        int stock;
        bool canasta;
        NodoAA *HIzq;
        NodoAA *HDer;

    public:
        NodoAA(std::string pNombre, int pCodMarca, int pStock, bool pCanasta) {

            nombre = pNombre;
            codMarca = pCodMarca;
            stock = pStock;
            canasta = pCanasta;
            HIzq = NULL;
            HDer = NULL;
        }

    friend class ArbolAA;
};

#endif
