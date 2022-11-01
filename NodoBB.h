#ifndef NODOBB_H
#define NODOBB_H

#include <iostream>
#include "ArbolAVL.h"

class NodoBB {

    private:
        std::string nombre;
        int codPasillo;
        NodoBB *HIzq;
        NodoBB *HDer;
        ArbolAVL productos;

    public:
        NodoBB(std::string pNombre, int pCodPasillo) {

            nombre = pNombre;
            codPasillo = pCodPasillo;
            HIzq = NULL;
            HDer = NULL;
        }

    friend class ArbolBB;
};

#endif
