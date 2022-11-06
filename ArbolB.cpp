#include "ArbolB.h"
#include <iostream>

using namespace std;

void ArbolB::podar() {

    if (raiz != NULL) {

        podarRecursivo(raiz -> HIzq);
        podarRecursivo(raiz -> HDer);
        delete raiz;
    }
}

void ArbolB::podarRecursivo(NodoB *&r) {

    if (r != NULL) {

        podarRecursivo(r -> HIzq);
        podarRecursivo(r -> HDer);
        delete r;
    }
}

void ArbolB::mostrar(){
	
	if (raiz != NULL){
		
		mostrarRecursivo(raiz->HIzq);
		mostrarRecursivo(raiz->HDer);
		cout << "Nombre del cliente: "<<raiz->nombre << " Cedula: " << raiz -> cedula << endl;
	}
}

void ArbolB::mostrarRecursivo(NodoB *&r){
	
	if (r != NULL){
		
		mostrarRecursivo(r->HIzq);
		mostrarRecursivo(r->HDer);
		cout << "Nombre del cliente: "<< r -> nombre << " Cedula: " << r -> cedula << endl;
	}
}

void ArbolB::mostrarAdmin(){
	
	if (raiz != NULL){
		
		mostrarAdminRecursivo(raiz->HIzq);
		mostrarAdminRecursivo(raiz->HDer);
		cout << raiz->codAdmin << "  |  " <<raiz->nombre<< endl;
	}
}

void ArbolB::mostrarAdminRecursivo(NodoB *&r){
	
	if (r != NULL){
		
		mostrarAdminRecursivo(r->HIzq);
		mostrarAdminRecursivo(r->HDer);
		cout << r->codAdmin << "  |  " <<r->nombre<< endl;
	}
}

void ArbolB::mostrarVendedor(){
	
	if (raiz != NULL){
		
		mostrarVendedorRecursivo(raiz->HIzq);
		mostrarVendedorRecursivo(raiz->HDer);
		cout << raiz->codVendedor << "  |  " <<raiz->nombre<< endl;
	}
}

void ArbolB::mostrarVendedorRecursivo(NodoB *&r){
	
	if (r != NULL){
		
		mostrarVendedorRecursivo(r->HIzq);
		mostrarVendedorRecursivo(r->HDer);
		cout << r->codVendedor << "  |  " <<r->nombre<< endl;
	}
}




bool ArbolB::existeCedula(int pCedula) {

    if (raiz == NULL)
        return false;
    else {

        if (raiz -> cedula == pCedula)
            return true;
        else {
            
            if (pCedula < raiz -> cedula)
                return existeCedulaRecursivo(pCedula, raiz -> HIzq);
            else
                return existeCedulaRecursivo(pCedula, raiz -> HDer);
        }
    }
}

bool ArbolB::existeCedulaRecursivo(int pCedula, NodoB *&r) {

    if (r == NULL)
        return false;
    else {

        if (r -> cedula == pCedula)
            return true;
        else {

            if (pCedula < r -> cedula)
                return existeCedulaRecursivo(pCedula, r -> HIzq);
            else
                return existeCedulaRecursivo(pCedula, r -> HDer);
        }
    }
}


bool ArbolB::existeAdmin(int pAdmin) {

    if (raiz == NULL)
        return false;
    else {

        if (raiz -> codAdmin == pAdmin)
            return true;
        else {
            
            if (pAdmin < raiz -> codAdmin)
                return existeAdminRecursivo(pAdmin, raiz -> HIzq);
            else
                return existeAdminRecursivo(pAdmin, raiz -> HDer);
        }
    }
}

bool ArbolB::existeAdminRecursivo(int pAdmin, NodoB *&r) {

    if (r == NULL)
        return false;
    else {

        if (r -> codAdmin == pAdmin)
            return true;
        else {

            if (pAdmin < r -> codAdmin)
                return existeAdminRecursivo(pAdmin, r -> HIzq);
            else
                return existeAdminRecursivo(pAdmin, r -> HDer);
        }
    }
}

bool ArbolB::existeVendedor(int pVendedor) {

    if (raiz == NULL)
        return false;
    else {

        if (raiz -> codVendedor == pVendedor)
            return true;
        else {
            
            if (pVendedor < raiz -> codVendedor)
                return existeVendedorRecursivo(pVendedor, raiz -> HIzq);
            else
                return existeVendedorRecursivo(pVendedor, raiz -> HDer);
        }
    }
}

bool ArbolB::existeVendedorRecursivo(int pVendedor, NodoB *&r) {

    if (r == NULL)
        return false;
    else {

        if (r -> codVendedor == pVendedor)
            return true;
        else {

            if (pVendedor < r -> codVendedor)
                return existeVendedorRecursivo(pVendedor, r -> HIzq);
            else
                return existeVendedorRecursivo(pVendedor, r -> HDer);
        }
    }
}


void ArbolB::insertar(int pAdmin, string pNombre) {

    if (raiz == NULL)
        raiz = new NodoB(pAdmin, pNombre);
        
    else {

        if (!existeAdmin(pAdmin)){

            if (pAdmin < raiz -> codAdmin)
                insertarRecursivo(raiz -> HIzq, pAdmin, pNombre);
            else
                insertarRecursivo(raiz -> HDer, pAdmin, pNombre);
        }
    }
}

void ArbolB::insertarRecursivo(NodoB *&r, int pAdmin, string pNombre){

    if (r == NULL) {
    	r = new NodoB(pAdmin, pNombre);
    } else {
        if (pAdmin < r -> codAdmin){
            insertarRecursivo(r -> HIzq, pAdmin, pNombre);
        } else {
            insertarRecursivo(r -> HDer, pAdmin, pNombre);
        }
    }
}


void ArbolB::insertar(string pNombre, int pVendedor) {

    if (raiz == NULL)
        raiz = new NodoB(pNombre, pVendedor);
        
    else {

        if (!existeVendedor(pVendedor)){

            if (pVendedor < raiz -> codVendedor)
                insertarRecursivo(raiz -> HIzq, pNombre, pVendedor);
            else
                insertarRecursivo(raiz -> HDer, pNombre, pVendedor);
        }
    }
}

void ArbolB::insertarRecursivo(NodoB *&r,string pNombre, int pVendedor){

    if (r == NULL) {
    	r = new NodoB(pNombre, pVendedor);
    } else {
        if (pVendedor < r -> codVendedor){
            insertarRecursivo(r -> HIzq, pNombre, pVendedor);
        } else {
            insertarRecursivo(r -> HDer, pNombre, pVendedor);
        }
    }
}


void ArbolB::insertar(int pCedula, string pNombre, int pTelefono, string pCorreo) {

    if (raiz == NULL)
        raiz = new NodoB(pCedula, pNombre, pTelefono, pCorreo);
        
    else {

        if (!existeCedula(pCedula)){

            if (pCedula < raiz -> cedula)
                insertarRecursivo(raiz -> HIzq, pCedula, pNombre, pTelefono, pCorreo);
            else
                insertarRecursivo(raiz -> HDer, pCedula, pNombre, pTelefono, pCorreo);
        }
    }
}

void ArbolB::insertarRecursivo(NodoB *&r, int pCedula, string pNombre, int pTelefono, string pCorreo){

    if (r == NULL) {
    	r = new NodoB(pCedula, pNombre, pTelefono, pCorreo);
    } else {
        if (pCedula < r -> cedula){
            insertarRecursivo(r -> HIzq, pCedula, pNombre, pTelefono, pCorreo);
        } else {
            insertarRecursivo(r -> HDer, pCedula, pNombre, pTelefono, pCorreo);
        }
    }
}



int ArbolB::telefonoCliente(int pCedula){
	
	if (raiz == NULL){
		return 0;
	}
	else {
		
		if (raiz->cedula == pCedula){
			return raiz->telefono;
		}
		else{
			if (pCedula < raiz->cedula)
				return telefonoClienteRecursivo(raiz->HIzq, pCedula);
			else
				return telefonoClienteRecursivo(raiz->HDer, pCedula);			
		}
	}
}

int ArbolB::telefonoClienteRecursivo(NodoB *&r, int pCedula){
	
	if (r == NULL){
		return 0;
	}
	else {
		
		if (r->cedula == pCedula){
			return r->telefono;
		}
		else{
			if (pCedula < r->cedula)
				return telefonoClienteRecursivo(r->HIzq, pCedula);
			else
				return telefonoClienteRecursivo(r->HDer, pCedula);		
		}
	}
}


string ArbolB::nombreCliente(int pCedula){
	
	if (raiz == NULL){
		string noNombre = "No hay clientes";
		return noNombre;
	}
	else {
		
		if (raiz->cedula == pCedula){
			return raiz->nombre;
		}
		else{
			if (pCedula < raiz->cedula)
				return nombreClienteRecursivo(raiz->HIzq, pCedula);
			else
				return nombreClienteRecursivo(raiz->HDer, pCedula);			
		}
	}
}

string ArbolB::nombreClienteRecursivo(NodoB *&r, int pCedula){
	
	if (r == NULL){
		string noNombre = "No hay clientes";
		return noNombre;
	}
	else {
		
		if (r->cedula == pCedula){
			return r->nombre;
		}
		else{
			if (pCedula < r->cedula)
				return nombreClienteRecursivo(r->HIzq, pCedula);
			else
				return nombreClienteRecursivo(r->HDer, pCedula);		
		}
	}
}

//--------------------------------ELIMINACION---------------------------

void ArbolB::eliminarCiente(int pCedula){
	
	if (raiz == NULL){
		cout << "No hay elementos en el arbol" << endl;
	}else if (pCedula < raiz->cedula){
		eliminarClienteRecursivo(raiz->HIzq, pCedula);
	}else if (pCedula > raiz-> cedula){
		eliminarClienteRecursivo(raiz->HDer, pCedula);
	}else { //Ya se encontró el elemento 
		suprimirCliente(raiz);
	}	
}
void ArbolB::eliminarClienteRecursivo(NodoB *&r, int pCedula){
	
	if (raiz == NULL){
		cout << "No hay elementos en el arbol" << endl;
	}else if (pCedula < r->cedula){
		eliminarClienteRecursivo(r->HIzq, pCedula);
	}else if (pCedula > r-> cedula){
		eliminarClienteRecursivo(r->HDer, pCedula);
	}else { //Ya se encontró el elemento 
		suprimirCliente(*&r);
	}
}


NodoB * ArbolB::minimo(NodoB *&r){
	
	if (r == NULL){
		return NULL;
	}else{
		if (r->HIzq){
			return minimo(r->HIzq);
		}else{
			return r;
		}
	}
}


void ArbolB::suprimirCliente(NodoB *&r){
	
	if (r->HIzq && r->HDer){
		NodoB *menor = minimo(r->HDer);
		r->cedula = menor->cedula;
		suprimirCliente(menor);
	}
	else if (r->HIzq){
		
	}
}

void ArbolB::modificarCliente (int pCedula, int pTelefono, string pNombre){
	
	if (raiz->cedula == pCedula){
		raiz->nombre = pNombre;
		raiz->telefono = pTelefono;
	}
	else{
		if(pCedula < raiz->cedula){
			modificarClienteRecursivo(raiz->HIzq, pCedula, pTelefono, pNombre);
		}else{
			modificarClienteRecursivo(raiz->HDer, pCedula, pTelefono, pNombre);
		}
	}
	
}
void ArbolB::modificarClienteRecursivo (NodoB *&r, int pCedula, int pTelefono, string pNombre){
	
	if (raiz->cedula == pCedula){
		raiz->nombre = pNombre;
		raiz->telefono = pTelefono;
	}
	else{
		if(pCedula < raiz->cedula){
			modificarClienteRecursivo(raiz->HIzq, pCedula, pTelefono, pNombre);
		}else{
			modificarClienteRecursivo(raiz->HDer, pCedula, pTelefono, pNombre);
		}
	}
}

void ArbolB::modificarAdmin(int pCodAdmin, string pNombre){
	
	if (raiz->codAdmin == pCodAdmin){
		raiz->nombre = pNombre;
	}
	else{
		if(pCodAdmin < raiz->codAdmin){
			modificarAdminRecursivo(raiz->HIzq, pCodAdmin, pNombre);
		}else{
			modificarAdminRecursivo(raiz->HDer, pCodAdmin, pNombre);
		}
	}
}

void ArbolB::modificarAdminRecursivo(NodoB *&r, int pCodAdmin, string pNombre){
	
	if (r->codAdmin == pCodAdmin){
		r->nombre = pNombre;
	}
	else{
		if(pCodAdmin < r->codAdmin){
			modificarAdminRecursivo(r->HIzq, pCodAdmin, pNombre);
		}else{
			modificarAdminRecursivo(r->HDer, pCodAdmin, pNombre);
		}
	}
}

void ArbolB::modificarVendedor(int pCodVendedor, string pNombre){
	
	if (raiz->codVendedor == pCodVendedor){
		raiz->nombre = pNombre;
	}
	else{
		if(pCodVendedor < raiz->codVendedor){
			modificarVendedorRecursivo(raiz->HIzq, pCodVendedor, pNombre);
		}else{
			modificarVendedorRecursivo(raiz->HDer, pCodVendedor, pNombre);
		}
	}
}


void ArbolB::modificarVendedorRecursivo(NodoB *&r, int pCodVendedor, string pNombre){

	if (r->codVendedor == pCodVendedor){
		r->nombre = pNombre;
	}
	else{
		if(pCodVendedor < r->codVendedor){
			modificarVendedorRecursivo(r->HIzq, pCodVendedor, pNombre);
		}else{
			modificarVendedorRecursivo(r->HDer, pCodVendedor, pNombre);
		}
	}	
}
