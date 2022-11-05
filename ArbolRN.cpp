#include "ArbolRN.h"
#include <iostream>
#include <sstream>

using namespace std;

void ArbolRN::podar() {

    if (raiz != NULL) {

        podarRecursivo(raiz -> HIzq);
        podarRecursivo(raiz -> HDer);
        delete raiz;
    }
}

void ArbolRN::podarRecursivo(NodoRN *&r) {

    if (r != NULL) {

        podarRecursivo(r -> HIzq);
        podarRecursivo(r -> HDer);
        delete r;
    }
}

void ArbolRN::insertar(string pNombre, int pCodMarca, int pCantidad, float pPrecio) {

    if (raiz == NULL)
        raiz = new NodoRN(pNombre, pCodMarca, pCantidad, pPrecio);
    else {

        if (!existeCodigo(pCodMarca)){

            if (pCodMarca < raiz -> codMarca)
                insertarRecursivo(raiz -> HIzq, pNombre, pCodMarca, pCantidad, pPrecio);
            else
                insertarRecursivo(raiz -> HDer, pNombre, pCodMarca, pCantidad, pPrecio);
        }
    }
}

void ArbolRN::insertarRecursivo(NodoRN *&r, string pNombre, int pCodMarca, int pCantidad, float pPrecio){

    if (r == NULL) {
    	r = new NodoRN(pNombre, pCodMarca, pCantidad, pPrecio);
    } else {
        if (pCodMarca < r -> codMarca){
            insertarRecursivo(r -> HIzq, pNombre, pCodMarca, pCantidad, pPrecio);
        } else {
            insertarRecursivo(r -> HDer, pNombre, pCodMarca, pCantidad, pPrecio);
        }
    }
}

bool ArbolRN::existeCodigo(int pCodMarca) {

    if (raiz == NULL)
        return false;
    else {

        if (raiz -> codMarca == pCodMarca)
            return true;
        else {
            
            if (pCodMarca < raiz -> codMarca)
                return existeCodigoRecursivo(pCodMarca, raiz -> HIzq);
            else
                return existeCodigoRecursivo(pCodMarca, raiz -> HDer);
        }
    }
}

bool ArbolRN::existeCodigoRecursivo(int pCodMarca, NodoRN *&r) {

    if (r == NULL)
        return false;
    else {

        if (r -> codMarca == pCodMarca)
            return true;
        else {

            if (pCodMarca < r -> codMarca)
                return existeCodigoRecursivo(pCodMarca, r -> HIzq);
            else
                return existeCodigoRecursivo(pCodMarca, r -> HDer);
        }
    }
}

void ArbolRN::mostrarMarcas() {
	
	if (raiz != NULL) {
		cout << raiz -> codMarca << " " << raiz -> nombre << " " << raiz -> cantidad << " " << raiz -> precio << endl;
		mostrarRecursivo(raiz -> HIzq);
		mostrarRecursivo(raiz -> HDer);
	}
}

void ArbolRN::mostrarMarcasRecursivo(NodoRN *&r) {
	
	if (r != NULL) {
		cout << r -> codMarca << " " << r -> nombre << " " << r -> cantidad << " " << r -> precio << endl;
		mostrarRecursivo(r -> HIzq);
		mostrarRecursivo(r -> HDer);
	}
}

void ArbolRN::mostrar() {
	
	if (raiz != NULL) {
		cout << raiz -> codMarca << " " << raiz -> nombre << " " << raiz -> cantidad << " " << raiz -> precio << endl;
		mostrarRecursivo(raiz -> HIzq);
		mostrarRecursivo(raiz -> HDer);
	}
}

void ArbolRN::mostrarRecursivo(NodoRN *&r) {
	
	if (r != NULL) {
		cout << r -> codMarca << " " << r -> nombre << " " << r -> cantidad << " " << r -> precio << endl;
		mostrarRecursivo(r -> HIzq);
		mostrarRecursivo(r -> HDer);
	}
}

void ArbolRN::mostrarPrecio(int pCodMarca) {
	
	if (raiz -> codMarca == pCodMarca) {
		cout << "Nombre: " << raiz -> nombre << " Precio: " << raiz -> precio << endl;
	} else {
		if (pCodMarca < raiz -> codMarca) {
			mostrarPrecioRecursivo(pCodMarca, raiz -> HIzq);
		} else {
			mostrarPrecioRecursivo(pCodMarca, raiz -> HDer);
		}
	}
}

void ArbolRN::mostrarPrecioRecursivo(int pCodMarca, NodoRN *&r) {
	
	if (r -> codMarca == pCodMarca) {
		cout << "Nombre: " << raiz -> nombre << " Precio: " << raiz -> precio << endl;
	} else {
		if (pCodMarca < r -> codMarca) {
			mostrarPrecioRecursivo(pCodMarca, r -> HIzq);
		} else {
			mostrarPrecioRecursivo(pCodMarca, r -> HDer);
		}
	}
}



void ArbolRN::modificarMarcaNombre (string pNombre, int pCodMarca){
	
	if (raiz -> codMarca == pCodMarca) {
		raiz -> nombre = pNombre;
	} else {
		if (pCodMarca < raiz -> codMarca) {
			modificarMarcaNombreRecursivo(raiz -> HIzq, pNombre, pCodMarca);
		} else {
			modificarMarcaNombreRecursivo(raiz -> HDer, pNombre, pCodMarca);
		}
	}
}


void ArbolRN::modificarMarcaNombreRecursivo(NodoRN *&r, string pNombre, int pCodMarca){
	
	if (r -> codMarca == pCodMarca) {
		r-> nombre = pNombre;
	} else {
		if (pCodMarca < r -> codMarca) {
			modificarMarcaNombreRecursivo(r -> HIzq, pNombre, pCodMarca);
		} else {
			modificarMarcaNombreRecursivo(r -> HDer, pNombre, pCodMarca);
		}
	}
}

void ArbolRN::modificarMarcaPrecio (float pPrecio, int pCodMarca){
	
	if (raiz -> codMarca == pCodMarca) {
		raiz -> precio = pPrecio;
	} else {
		if (pCodMarca < raiz -> codMarca) {
			modificarMarcaPrecioRecursivo(raiz -> HIzq, pPrecio, pCodMarca);
		} else {
			modificarMarcaPrecioRecursivo(raiz -> HDer, pPrecio, pCodMarca);
		}
	}
}


void ArbolRN::modificarMarcaPrecioRecursivo(NodoRN *&r, float pPrecio, int pCodMarca){
	
	if (r -> codMarca == pCodMarca) {
		r-> precio = pPrecio;
	} else {
		if (pCodMarca < r -> codMarca) {
			modificarMarcaPrecioRecursivo(r -> HIzq, pPrecio, pCodMarca);
		} else {
			modificarMarcaPrecioRecursivo(r -> HDer, pPrecio, pCodMarca);
		}
	}
}

void ArbolRN::modificarMarcaGondola (int pGondola, int pCodMarca){
	
	if (raiz-> codMarca == pCodMarca){
		raiz->cantidad = pGondola;
	}
	else{
		if (pCodMarca < raiz->cantidad){
			modificarMarcaGondolaRecursivo(raiz->HIzq, pGondola, pCodMarca);
		}
		else{
			modificarMarcaGondolaRecursivo(raiz->HDer, pGondola, pCodMarca);
		}
	}
}


void ArbolRN::modificarMarcaGondolaRecursivo(NodoRN *&r, int pGondola, int pCodMarca){
	
	if (r-> codMarca == pCodMarca){
		r->cantidad = pGondola;
	}
	else{
		if (pCodMarca < r->cantidad){
			modificarMarcaGondolaRecursivo(r->HIzq, pGondola, pCodMarca);
		}
		else{
			modificarMarcaGondolaRecursivo(r->HDer, pGondola, pCodMarca);
		}
	}
}



bool ArbolRN::verificarCantidad(int pCodMarca, int pCantidad) {
	
	if (raiz -> codMarca == pCodMarca) {
		return pCantidad <= raiz -> cantidad;
	} else {
		if (pCodMarca < raiz -> codMarca) {
			return verificarCantidadRecursivo(raiz -> HIzq, pCodMarca, pCantidad);
		} else {
			return verificarCantidadRecursivo(raiz -> HDer, pCodMarca, pCantidad);
		}
	}
}

bool ArbolRN::verificarCantidadRecursivo(NodoRN *&r, int pCodMarca, int pCantidad) {
	
	if (r -> codMarca == pCodMarca) {
		return pCantidad <= r -> cantidad;
	} else {
		if (pCodMarca < r -> codMarca) {
			return verificarCantidadRecursivo(r -> HIzq, pCodMarca, pCantidad);
		} else {
			return verificarCantidadRecursivo(r -> HDer, pCodMarca, pCantidad);
		}
	}
}

int ArbolRN::cantidadMaxima(int pCodMarca) {
	
	if (raiz -> codMarca == pCodMarca) {
		return raiz -> cantidad;
	} else {
		if (pCodMarca < raiz -> codMarca) {
			return cantidadMaximaRecursivo(raiz -> HIzq, pCodMarca);
		} else {
			return cantidadMaximaRecursivo(raiz -> HDer, pCodMarca);
		}
	}
}

int ArbolRN::cantidadMaximaRecursivo(NodoRN *&r, int pCodMarca) {
	
	if (r -> codMarca == pCodMarca) {
		return r -> cantidad;
	} else {
		if (pCodMarca < r -> codMarca) {
			return cantidadMaximaRecursivo(r -> HIzq, pCodMarca);
		} else {
			return cantidadMaximaRecursivo(r -> HDer, pCodMarca);
		}
	}
}

float ArbolRN::obtenerPrecio(int pCodMarca) {
	
	if (raiz -> codMarca == pCodMarca) {
		return raiz -> precio;
	} else {
		if (pCodMarca < raiz -> codMarca) {
			return obtenerPrecioRecursivo(raiz -> HIzq, pCodMarca);
		} else {
			return obtenerPrecioRecursivo(raiz -> HDer, pCodMarca);
		}
	}
}

float ArbolRN::obtenerPrecioRecursivo(NodoRN *&r, int pCodMarca) {
	
	if (r -> codMarca == pCodMarca) {
		return r -> precio;
	} else {
		if (pCodMarca < r -> codMarca) {
			return obtenerPrecioRecursivo(r -> HIzq, pCodMarca);
		} else {
			return obtenerPrecioRecursivo(r -> HDer, pCodMarca);
		}
	}
}

string ArbolRN::nombreMarca(int pCodMarca) {
	
	if (raiz -> codMarca == pCodMarca) {
		return raiz -> nombre;
	} else {
		if (pCodMarca < raiz -> codMarca) {
			return nombreMarcaRecursivo(raiz -> HIzq, pCodMarca);
		} else {
			return nombreMarcaRecursivo(raiz -> HDer, pCodMarca);
		}
	}
}

string ArbolRN::nombreMarcaRecursivo(NodoRN *&r, int pCodMarca) {
	
	if (r -> codMarca == pCodMarca) {
		return r -> nombre;
	} else {
		if (pCodMarca < r -> codMarca) {
			return nombreMarcaRecursivo(r -> HIzq, pCodMarca);
		} else {
			return nombreMarcaRecursivo(r -> HDer, pCodMarca);
		}
	}
}

void ArbolRN::sacarDeGondola(int pCodMarca, int pCantidad) {
	
	if (raiz -> codMarca == pCodMarca) {
		raiz -> cantidad -= pCantidad;
	} else {
		if (pCodMarca < raiz -> codMarca) {
			sacarDeGondolaRecursivo(raiz -> HIzq, pCodMarca, pCantidad);
		} else {
			sacarDeGondolaRecursivo(raiz -> HDer, pCodMarca, pCantidad);
		}
	}
}

void ArbolRN::sacarDeGondolaRecursivo(NodoRN *&r, int pCodMarca, int pCantidad) {
	
	if (r -> codMarca == pCodMarca) {
		r -> cantidad -= pCantidad;
	} else {
		if (pCodMarca < r -> codMarca) {
			sacarDeGondolaRecursivo(r -> HIzq, pCodMarca, pCantidad);
		} else {
			sacarDeGondolaRecursivo(r -> HDer, pCodMarca, pCantidad);
		}
	}
}


void ArbolRN::revisarGondolas(){
	
	int abastecer = 7;
	
	if (raiz != NULL){
		
		
		revisarGondolasRecursivo(raiz->HIzq);
		revisarGondolasRecursivo(raiz->HDer);
		
		if (raiz->cantidad < 2){
			
			int cantGondola = raiz->cantidad;
			cout << "La cantidad existente en la gondola era de: " << cantGondola << endl;
			raiz->cantidad = (abastecer + cantGondola);
			string newCantidad = to_string(raiz->cantidad);
			cout << "La nueva cantidad en gondola es: " << newCantidad << endl;
		}
	}
	
}


void ArbolRN::revisarGondolasRecursivo(NodoRN *&r){
	
	int abastecer = 7;
	
	if (r != NULL){
		
		
		revisarGondolasRecursivo(r->HIzq);
		revisarGondolasRecursivo(r->HDer);
		
		if (r->cantidad < 2){
			
			int cantGondola = r->cantidad;
			cout << "La cantidad existente en la gondola era de: " << cantGondola << endl;
			r->cantidad = (abastecer + cantGondola);
			string newCantidad = to_string(r->cantidad);
			cout << "La nueva cantidad en gondola es: " << newCantidad << endl;
		}
	}
	
}
