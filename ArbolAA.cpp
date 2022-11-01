#include "ArbolAA.h"
#include <iostream>

using namespace std;

void ArbolAA::podarRecursivo(NodoAA *raiz) {

    if (raiz != NULL) {

        podarRecursivo(raiz -> HIzq);
        podarRecursivo(raiz -> HDer);
        delete raiz;
    }
}

void ArbolAA::podar() {

    if (raiz != NULL) {

        podarRecursivo(raiz -> HIzq);
        podarRecursivo(raiz -> HDer);
        delete raiz;
    }
}

void ArbolAA::insertar(string pNombre, int pCodMarca, int pStock, int pCanasta) {
	
	if (raiz == NULL) {
		//cout << "shit" << endl;
		raiz = new NodoAA(pNombre, pCodMarca, pStock, (pCanasta == 1));
	} else {
		if (!existeMarca(pCodMarca)){
			//cout << "shit" << endl;
			if (pCodMarca < raiz -> codMarca){
				insertarRecursivo(raiz -> HIzq, pNombre, pCodMarca, pStock, pCanasta);
			} else {
				insertarRecursivo(raiz -> HDer, pNombre, pCodMarca, pStock, pCanasta);
			}
		}
	}
}

void ArbolAA::insertarRecursivo(NodoAA *&r, string pNombre, int pCodMarca, int pStock, int pCanasta) {
	
	if (r == NULL) {
		r = new NodoAA(pNombre, pCodMarca, pStock, (pCanasta == 1));
	} else {
		if (pCodMarca < r -> codMarca){
			insertarRecursivo(r -> HIzq, pNombre, pCodMarca, pStock, pCanasta);
		} else {
			insertarRecursivo(r -> HDer, pNombre, pCodMarca, pStock, pCanasta);
		}
	}
}

bool ArbolAA::existeMarca(int pCodMarca) {
	
	if (raiz == NULL) {
		return false;
	} else {
		if (raiz -> codMarca == pCodMarca) {
			return true;
		} else {
			if (pCodMarca < raiz -> codMarca) {
				return existeMarcaRecursivo(raiz -> HIzq, pCodMarca);
			} else {
				return existeMarcaRecursivo(raiz -> HDer, pCodMarca);
			}
		}
	}
}

bool ArbolAA::existeMarcaRecursivo(NodoAA *&r, int pCodMarca) {
	
	if (r == NULL) {
		return false;
	} else {
		if (r -> codMarca == pCodMarca) {
			return true;
		} else {
			if (pCodMarca < r -> codMarca) {
				return existeMarcaRecursivo(raiz -> HIzq, pCodMarca);
			} else {
				return existeMarcaRecursivo(raiz -> HDer, pCodMarca);
			}
		}
	}
}

void ArbolAA::mostrar() {
	
	if (raiz != NULL) {
		
		cout << "Codigo: " << raiz -> codMarca << " Nombre: " << raiz -> nombre << " Stock: " << raiz -> stock << " CanastaBasica: " << raiz -> canasta << endl;
		mostrarRecursivo(raiz -> HIzq);
		mostrarRecursivo(raiz -> HDer);
	}
}

void ArbolAA::mostrarRecursivo(NodoAA *&r) {
	
	if (r != NULL) {
		
		cout << "Codigo: " << r -> codMarca << " Nombre: " << r -> nombre << " Stock: " << r -> stock << " CanastaBasica: " << r -> canasta << endl;
		mostrarRecursivo(r -> HIzq);
		mostrarRecursivo(r -> HDer);
	}
}

void ArbolAA::modificarMarcaNombre (string pNombre, int pCodMarca){
	
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


void ArbolAA::modificarMarcaNombreRecursivo(NodoAA *&r, string pNombre, int pCodMarca){
	
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

bool ArbolAA::canasta(int pCodMarca) {
	
	if (raiz -> codMarca == pCodMarca) {
		return raiz -> canasta;
	} else {
		if (pCodMarca < raiz -> codMarca) {
			return canastaRecursivo(raiz -> HIzq, pCodMarca);
		} else {
			return canastaRecursivo(raiz -> HDer, pCodMarca);
		}
	}
}

bool ArbolAA::canastaRecursivo(NodoAA *&r, int pCodMarca) {
	
	if (r -> codMarca == pCodMarca) {
		return r -> canasta;
	} else {
		if (pCodMarca < r -> codMarca) {
			return canastaRecursivo(r -> HIzq, pCodMarca);
		} else {
			return canastaRecursivo(r -> HDer, pCodMarca);
		}
	}
}

void ArbolAA::verificarInventario() {
	
	if (raiz != NULL) {
		if (raiz -> stock < 20) {
			raiz -> stock += 20;
		}
		verificarInventarioRecursivo(raiz -> HIzq);
		verificarInventarioRecursivo(raiz -> HDer);
	}
}

void ArbolAA::verificarInventarioRecursivo(NodoAA *&r) {
	
	if (r != NULL) {
		if (r -> stock < 20) {
			r -> stock += 20;
		}
		verificarInventarioRecursivo(r -> HIzq);
		verificarInventarioRecursivo(r -> HDer);
	}
}
