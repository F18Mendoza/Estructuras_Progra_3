#ifndef ARBOLB_H
#define ARBOLB_H

#include <iostream>
#include "NodoB.h"

using namespace std;

class ArbolB {

    private:
        NodoB *raiz;
    
    public:
        ArbolB() {raiz = NULL;}

		bool vacio() {return raiz == NULL;}
        void insertar(int pCedula, string pNombre, int pTelefono, string pCorreo);
        void insertarRecursivo(NodoB *&r, int pCedula, string pNombre, int pTelefono, string pCorreo);
        void insertar(int pAdmin, string pNombre);
        void insertarRecursivo(NodoB *&r, int pAdmin, string pNombre);
        void insertar(string pNombre, int pVendedor);
        void insertarRecursivo(NodoB *&r, string pNombre, int pVendedor);
        void podar();
        void podarRecursivo(NodoB *&r);
        bool existeCedula(int pCedula);
        bool existeCedulaRecursivo(int pCedula, NodoB *&r);
        bool existeAdmin(int pAdmin);
        bool existeAdminRecursivo(int pAdmin, NodoB *&r);
        bool existeVendedor(int pVendedor);
        bool existeVendedorRecursivo(int pVendedor, NodoB *&r);
        void mostrar();
        void mostrarRecursivo(NodoB *&r);
        void mostrarAdmin();
        void mostrarAdminRecursivo(NodoB *&r);
        void mostrarVendedor();
        void mostrarVendedorRecursivo(NodoB *&r);
        string nombreCliente(int pCedula);
        string nombreClienteRecursivo(NodoB *&r, int pCedula);
        int telefonoCliente(int pCedula);
        int telefonoClienteRecursivo(NodoB *&r, int pCedula);
        void eliminarCiente(int pCedula);
        void eliminarClienteRecursivo(NodoB *&r, int pCedula);
        void suprimirCliente(NodoB *&r);
        NodoB *minimo (NodoB *&r);
};

#endif
