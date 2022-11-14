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
        void modificarCliente (int pCedula, int pTelefono, string pNombre);
        void modificarClienteRecursivo (NodoB *&r, int pCedula, int pTelefono, string pNombre);
        void modificarAdmin(int pCodAdmin, string pNombre);
        void modificarAdminRecursivo(NodoB *&r, int pCodAdmin, string pNombre);
        void modificarVendedor (int pCodVendedor, string pNombre);
        void modificarVendedorRecursivo (NodoB *&r, int pCodVendedor, string pNombre);
        void eliminarCliente(int pCedula);
        void eliminarClienteRecursivo(int pCedula, NodoB *&r);
        void eliminarAdmin(int pCodAdmin);
        void eliminarAdminRecursivo(int pCodAdmin, NodoB *&r);
        void eliminarVendedor(int pCodVendedor);
        void eliminarVendedorRecursivo(int pCodVendedor, NodoB *&r);
};

#endif
