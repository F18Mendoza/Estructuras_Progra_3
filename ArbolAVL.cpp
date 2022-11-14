#include "ArbolAVL.h"
#include <iostream>

using namespace std;

void ArbolAVL::podar() {

    if (raiz != NULL) {

        podarRecursivo(raiz -> HIzq);
        podarRecursivo(raiz -> HDer);
        raiz -> marcas.podar();
        raiz -> inventario.podar();
        delete raiz;
    }
}

void ArbolAVL::podarRecursivo(NodoAVL *&r) {

    if (r != NULL) {

        podarRecursivo(r -> HIzq);
        podarRecursivo(r -> HDer);
        r -> marcas.podar();
        r -> inventario.podar();
        delete r;
    }
}

void ArbolAVL::insertar(string pNombre, int pCodProducto) {

    if (raiz == NULL){
        raiz = new NodoAVL(pNombre, pCodProducto);
    }
    else {

        if (!existeCodigo(pCodProducto)){

            if (pCodProducto < raiz -> codProducto)
                insertarRecursivo(raiz -> HIzq, pNombre, pCodProducto);
            else
                insertarRecursivo(raiz -> HDer, pNombre, pCodProducto);
        }
    }
}

void ArbolAVL::insertarRecursivo(NodoAVL *&r, string pNombre, int pCodProducto){

    if (r == NULL) {
    	r = new NodoAVL(pNombre, pCodProducto);
    } else {
        if (pCodProducto < r -> codProducto){
            insertarRecursivo(r -> HIzq, pNombre, pCodProducto);
        } else {
            insertarRecursivo(r -> HDer, pNombre, pCodProducto);
        }
    }
}

void ArbolAVL::insertarMarca(string pNombre, int pCodProducto, int pCodMarca, int pCantidad, float pPrecio) {
	
	if (raiz -> codProducto == pCodProducto) {
		raiz -> marcas.insertar(pNombre, pCodMarca, pCantidad, pPrecio);
	} else {
		
		if (pCodProducto < raiz -> codProducto) {
			insertarMarcaRecursivo(raiz -> HIzq, pNombre, pCodProducto, pCodMarca, pCantidad, pPrecio);
		} else {
			insertarMarcaRecursivo(raiz -> HDer, pNombre, pCodProducto, pCodMarca, pCantidad, pPrecio);
		}
	}
}

void ArbolAVL::insertarMarcaRecursivo(NodoAVL *&r, string pNombre, int pCodProducto, int pCodMarca, int pCantidad, float pPrecio) {
	
	if (r -> codProducto == pCodProducto) {
		r -> marcas.insertar(pNombre, pCodMarca, pCantidad, pPrecio);
	} else {
		
		if (pCodProducto < r -> codProducto) {
			insertarMarcaRecursivo(r -> HIzq, pNombre, pCodProducto, pCodMarca, pCantidad, pPrecio);
		} else {
			insertarMarcaRecursivo(r -> HDer, pNombre, pCodProducto, pCodMarca, pCantidad, pPrecio);
		}
	}
}

void ArbolAVL::insertarInventario(string pNombre, int pCodProducto, int pCodMarca, int pStock, int pCanasta) {
	
	if (raiz -> codProducto == pCodProducto) {
		raiz -> inventario.insertar(pNombre, pCodMarca, pStock, pCanasta);
	} else {
		if (pCodProducto < raiz -> codProducto) {
			insertarInventarioRecursivo(raiz -> HIzq, pNombre, pCodProducto, pCodMarca, pStock, pCanasta);
		} else {
			insertarInventarioRecursivo(raiz -> HDer, pNombre, pCodProducto, pCodMarca, pStock, pCanasta);
		}
	}
}

void ArbolAVL::insertarInventarioRecursivo(NodoAVL *&r, string pNombre, int pCodProducto, int pCodMarca, int pStock, int pCanasta) {
	
	if (r -> codProducto == pCodProducto) {
		r -> inventario.insertar(pNombre, pCodMarca, pStock, pCanasta);
	} else {
		
		if (pCodProducto < r -> codProducto) {
			insertarInventarioRecursivo(r -> HIzq, pNombre, pCodProducto, pCodMarca, pStock, pCanasta);
		} else {
			insertarInventarioRecursivo(r -> HDer, pNombre, pCodProducto, pCodMarca, pStock, pCanasta);
		}
	}
}

bool ArbolAVL::existeCodigo(int pCodProducto) {

    if (raiz == NULL)
        return false;
    else {

        if (raiz -> codProducto == pCodProducto)
            return true;
        else {
            
            if (pCodProducto < raiz -> codProducto)
                return existeCodigoRecursivo(pCodProducto, raiz -> HIzq);
            else
                return existeCodigoRecursivo(pCodProducto, raiz -> HDer);
        }
    }
}

bool ArbolAVL::existeCodigoRecursivo(int pCodProducto, NodoAVL *&r) {

    if (r == NULL)
        return false;
    else {

        if (r -> codProducto == pCodProducto)
            return true;
        else {

            if (pCodProducto < r -> codProducto)
                return existeCodigoRecursivo(pCodProducto, r -> HIzq);
            else
                return existeCodigoRecursivo(pCodProducto, r -> HDer);
        }
    }
}

bool ArbolAVL::existeMarca(int pCodProducto, int pCodMarca) {
	
	if (raiz -> codProducto == pCodProducto) {
		return raiz -> marcas.existeCodigo(pCodMarca);
	} else {
		if (pCodProducto < raiz -> codProducto) {
			return existeMarcaRecursivo(pCodProducto, pCodMarca, raiz -> HIzq);
		} else {
			return existeMarcaRecursivo(pCodProducto, pCodMarca, raiz -> HDer);
		}
	}
}

bool ArbolAVL::existeMarcaRecursivo(int pCodProducto, int pCodMarca, NodoAVL *&r) {
	
	if (r -> codProducto == pCodProducto) {
		return r -> marcas.existeCodigo(pCodMarca);
	} else {
		if (pCodProducto < r -> codProducto) {
			return existeMarcaRecursivo(pCodProducto, pCodMarca, r -> HIzq);
		} else {
			return existeMarcaRecursivo(pCodProducto, pCodMarca, r -> HDer);
		}
	}
}

bool ArbolAVL::existeInventario(int pCodProducto, int pCodMarca) {
	
	if (raiz -> codProducto == pCodProducto) {
		return raiz -> inventario.existeMarca(pCodMarca);
	} else {
		if (pCodProducto < raiz -> codProducto) {
			return existeInventarioRecursivo(pCodProducto, pCodMarca, raiz -> HIzq);
		} else {
			return existeInventarioRecursivo(pCodProducto, pCodMarca, raiz -> HDer);
		}
	}
}

bool ArbolAVL::existeInventarioRecursivo(int pCodProducto, int pCodMarca, NodoAVL *&r) {
	
	if (r -> codProducto == pCodProducto) {
		return r -> inventario.existeMarca(pCodMarca);
	} else {
		if (pCodProducto < r -> codProducto) {
			return existeInventarioRecursivo(pCodProducto, pCodMarca, r -> HIzq);
		} else {
			return existeInventarioRecursivo(pCodProducto, pCodMarca, r -> HDer);
		}
	}
}

void ArbolAVL::mostrarProductos() {
	
	if (raiz != NULL) {
		cout << raiz -> codProducto << " " << raiz -> nombre << endl;
		mostrarProductosRecursivo(raiz -> HIzq);
		mostrarProductosRecursivo(raiz -> HDer);
	}
}

void ArbolAVL::mostrarProductosRecursivo(NodoAVL *&r) {
	
	if (r != NULL) {
		cout << r -> codProducto << " " << r -> nombre << endl;
		mostrarProductosRecursivo(r -> HIzq);
		mostrarProductosRecursivo(r -> HDer);
	}
}

void ArbolAVL::mostrarMarcas(int pCodProducto) {
	
	if (raiz -> codProducto == pCodProducto) {
		raiz -> marcas.mostrar();
	} else {
		if (pCodProducto < raiz -> codProducto) {
			mostrarMarcasRecursivo(raiz -> HIzq, pCodProducto);
		} else {
			mostrarMarcasRecursivo(raiz -> HDer, pCodProducto);
		}
	}
}

void ArbolAVL::mostrarMarcasRecursivo(NodoAVL *&r, int pCodProducto) {
	
	if (r -> codProducto == pCodProducto) {
		r -> marcas.mostrar();
	} else {
		if (pCodProducto < r -> codProducto) {
			mostrarMarcasRecursivo(r -> HIzq, pCodProducto);
		} else {
			mostrarMarcasRecursivo(r -> HDer, pCodProducto);
		}
	}
}

void ArbolAVL::mostrar() {
	
	if (raiz != NULL && !raiz -> marcas.vacio()) {
		cout << raiz -> codProducto << " " << raiz -> nombre << endl;
		raiz -> marcas.mostrar();
		mostrarRecursivo(raiz -> HIzq);
		mostrarRecursivo(raiz -> HDer);
	}
}

void ArbolAVL::mostrarRecursivo(NodoAVL *&r) {
	
	if (r != NULL && !r -> marcas.vacio()) {
		cout << r -> codProducto << " " << r -> nombre << endl;
		r -> marcas.mostrar();
		mostrarRecursivo(r -> HIzq);
		mostrarRecursivo(r -> HDer);
	}
}

void ArbolAVL::mostrarInventario() {
	
	if (raiz != NULL && !raiz -> inventario.vacio()) {
		cout << "Producto: " << raiz -> codProducto << " ";
		raiz -> inventario.mostrar();
		mostrarInventarioRecursivo(raiz -> HIzq);
		mostrarInventarioRecursivo(raiz -> HDer);
	}
}

void ArbolAVL::mostrarInventarioRecursivo(NodoAVL *&r) {
	
	if (r != NULL && !r -> inventario.vacio()) {
		cout << "Producto: " << r -> codProducto << " ";
		r -> inventario.mostrar();
		mostrarInventarioRecursivo(r -> HIzq);
		mostrarInventarioRecursivo(r -> HDer);
	}
}

void ArbolAVL::mostrarPrecio(int pCodProducto, int pCodMarca) {
	
	if (raiz -> codProducto == pCodProducto) {
		raiz -> marcas.mostrarPrecio(pCodMarca);
	} else {
		if (pCodProducto < raiz -> codProducto) {
			mostrarPrecioRecursivo(pCodProducto, pCodMarca, raiz -> HIzq);
		} else {
			mostrarPrecioRecursivo(pCodProducto, pCodMarca, raiz -> HDer);
		}
	}
}

void ArbolAVL::mostrarPrecioRecursivo(int pCodProducto, int pCodMarca, NodoAVL *&r) {
	
	if (r -> codProducto == pCodProducto) {
		r -> marcas.mostrarPrecio(pCodMarca);
	} else {
		if (pCodProducto < r -> codProducto) {
			mostrarPrecioRecursivo(pCodProducto, pCodMarca, r -> HIzq);
		} else {
			mostrarPrecioRecursivo(pCodProducto, pCodMarca, r -> HDer);
		}
	}
}


void ArbolAVL::modificarMarcaNombre(string pNombre, int pCodProducto, int pCodMarca){
	
	if (raiz -> codProducto == pCodProducto) {
		raiz -> marcas.modificarMarcaNombre(pNombre, pCodMarca);
		raiz -> inventario.modificarMarcaNombre (pNombre, pCodMarca);
	} else {
		if (pCodProducto < raiz -> codProducto) {
			modificarMarcaNombreRecursivo(raiz -> HIzq, pNombre, pCodProducto, pCodMarca);
		} else {
			modificarMarcaNombreRecursivo(raiz -> HDer, pNombre, pCodProducto, pCodMarca);
		}
	}
}


void ArbolAVL::modificarMarcaNombreRecursivo(NodoAVL *&r, string pNombre, int pCodProducto, int pCodMarca){
	
	if (r -> codProducto == pCodProducto) {
		r -> marcas.modificarMarcaNombre(pNombre, pCodMarca);
		r -> inventario.modificarMarcaNombre (pNombre, pCodMarca);
	} else {
		if (pCodProducto < r -> codProducto) {
			modificarMarcaNombreRecursivo(r -> HIzq, pNombre, pCodProducto, pCodMarca);
		} else {
			modificarMarcaNombreRecursivo(r -> HDer, pNombre, pCodProducto, pCodMarca);
		}
	}
}

void ArbolAVL::modificarMarcaPrecio(float pPrecio, int pCodProducto, int pCodMarca){
	
	if (raiz -> codProducto == pCodProducto) {
		raiz -> marcas.modificarMarcaPrecio(pPrecio, pCodMarca);

	} else {
		if (pCodProducto < raiz -> codProducto) {
			modificarMarcaPrecioRecursivo(raiz -> HIzq, pPrecio, pCodProducto, pCodMarca);
		} else {
			modificarMarcaPrecioRecursivo(raiz -> HDer, pPrecio, pCodProducto, pCodMarca);
		}
	}
}


void ArbolAVL::modificarMarcaPrecioRecursivo(NodoAVL *&r, float pPrecio, int pCodProducto, int pCodMarca){
	
	if (r -> codProducto == pCodProducto) {
		r -> marcas.modificarMarcaPrecio(pPrecio, pCodMarca);

	} else {
		if (pCodProducto < r -> codProducto) {
			modificarMarcaPrecioRecursivo(r -> HIzq, pPrecio, pCodProducto, pCodMarca);
		} else {
			modificarMarcaPrecioRecursivo(r -> HDer, pPrecio, pCodProducto, pCodMarca);
		}
	}
}


void ArbolAVL::modificarMarcaGondola (int pGondola, int pCodProducto, int pCodMarca){
	
	if (raiz -> codProducto == pCodProducto) {
		raiz -> marcas.modificarMarcaGondola(pGondola, pCodMarca);

	} else {
		if (pCodProducto < raiz -> codProducto) {
			modificarMarcaGondolaRecursivo(raiz -> HIzq, pGondola, pCodProducto, pCodMarca);
		} else {
			modificarMarcaGondolaRecursivo(raiz -> HDer, pGondola, pCodProducto, pCodMarca);
		}
	}
}



void ArbolAVL::modificarMarcaGondolaRecursivo(NodoAVL *&r, int pGondola, int pCodProducto, int pCodMarca){
	
	if (r -> codProducto == pCodProducto) {
		r -> marcas.modificarMarcaGondola(pGondola, pCodMarca);

	} else {
		if (pCodProducto < r -> codProducto) {
			modificarMarcaGondolaRecursivo(r -> HIzq, pGondola, pCodProducto, pCodMarca);
		} else {
			modificarMarcaGondolaRecursivo(r -> HDer, pGondola, pCodProducto, pCodMarca);
		}
	}
}



bool ArbolAVL::verificarCantidad(int pCodProducto, int pCodMarca, int pCantidad) {
	
	if (raiz -> codProducto == pCodProducto) {
		return raiz -> marcas.verificarCantidad(pCodMarca, pCantidad);
	} else {
		if (pCodProducto < raiz -> codProducto) {
			return verificarCantidadRecursivo(raiz -> HIzq, pCodProducto, pCodMarca, pCantidad);
		} else {
			return verificarCantidadRecursivo(raiz -> HDer, pCodProducto, pCodMarca, pCantidad);
		}
	}
}

bool ArbolAVL::verificarCantidadRecursivo(NodoAVL *&r, int pCodProducto, int pCodMarca, int pCantidad) {
	
	if (r -> codProducto == pCodProducto) {
		return r -> marcas.verificarCantidad(pCodMarca, pCantidad);
	} else {
		if (pCodProducto < r -> codProducto) {
			return verificarCantidadRecursivo(r -> HIzq, pCodProducto, pCodMarca, pCantidad);
		} else {
			return verificarCantidadRecursivo(r -> HDer, pCodProducto, pCodMarca, pCantidad);
		}
	}
}

int ArbolAVL::cantidadMaxima(int pCodProducto, int pCodMarca) {
	
	if (raiz -> codProducto == pCodProducto) {
		return raiz -> marcas.cantidadMaxima(pCodMarca);
	} else {
		if (pCodProducto < raiz -> codProducto) {
			return cantidadMaximaRecursivo(raiz -> HIzq, pCodProducto, pCodMarca);
		} else {
			return cantidadMaximaRecursivo(raiz -> HDer, pCodProducto, pCodMarca);
		}
	}
}

int ArbolAVL::cantidadMaximaRecursivo(NodoAVL *&r, int pCodProducto, int pCodMarca) {
	
	if (r -> codProducto == pCodProducto) {
		return r -> marcas.cantidadMaxima(pCodMarca);
	} else {
		if (pCodProducto < r -> codProducto) {
			return cantidadMaximaRecursivo(r -> HIzq, pCodProducto, pCodMarca);
		} else {
			return cantidadMaximaRecursivo(r -> HDer, pCodProducto, pCodMarca);
		}
	}
}

bool ArbolAVL::canasta(int pCodProducto, int pCodMarca) {
	
	if (raiz -> codProducto == pCodProducto) {
		return raiz -> inventario.canasta(pCodMarca);
	} else {
		if (pCodProducto < raiz -> codProducto) {
			return canastaRecursivo(raiz -> HIzq, pCodProducto, pCodMarca);
		} else {
			return canastaRecursivo(raiz -> HDer, pCodProducto, pCodMarca);
		}
	}
}

bool ArbolAVL::canastaRecursivo(NodoAVL *&r, int pCodProducto, int pCodMarca) {
	
	if (r -> codProducto == pCodProducto) {
		return r -> inventario.canasta(pCodMarca);
	} else {
		if (pCodProducto < r -> codProducto) {
			return canastaRecursivo(r -> HIzq, pCodProducto, pCodMarca);
		} else {
			return canastaRecursivo(r -> HDer, pCodProducto, pCodMarca);
		}
	}
}

float ArbolAVL::obtenerPrecio(int pCodProducto, int pCodMarca) {
	
	if (raiz -> codProducto == pCodProducto) {
		return raiz -> marcas.obtenerPrecio(pCodMarca);
	} else {
		if (pCodProducto < raiz -> codProducto) {
			return obtenerPrecioRecursivo(raiz -> HIzq, pCodProducto, pCodMarca);
		} else {
			return obtenerPrecioRecursivo(raiz -> HDer, pCodProducto, pCodMarca);
		}
	}
}

float ArbolAVL::obtenerPrecioRecursivo(NodoAVL *&r, int pCodProducto, int pCodMarca) {
	
	if (r -> codProducto == pCodProducto) {
		return r -> marcas.obtenerPrecio(pCodMarca);
	} else {
		if (pCodProducto < r -> codProducto) {
			return obtenerPrecioRecursivo(r -> HIzq, pCodProducto, pCodMarca);
		} else {
			return obtenerPrecioRecursivo(r -> HDer, pCodProducto, pCodMarca);
		}
	}
}

string ArbolAVL::nombreProducto(int pCodProducto) {
	
	if (raiz -> codProducto == pCodProducto) {
		return raiz -> nombre;
	} else {
		if (pCodProducto < raiz -> codProducto) {
			return nombreProductoRecursivo(raiz -> HIzq, pCodProducto);
		} else {
			return nombreProductoRecursivo(raiz -> HDer, pCodProducto);
		}
	}
}

string ArbolAVL::nombreProductoRecursivo(NodoAVL *&r, int pCodProducto) {
	
	if (r -> codProducto == pCodProducto) {
		return r -> nombre;
	} else {
		if (pCodProducto < r -> codProducto) {
			return nombreProductoRecursivo(r -> HIzq, pCodProducto);
		} else {
			return nombreProductoRecursivo(r -> HDer, pCodProducto);
		}
	}
}

string ArbolAVL::nombreMarca(int pCodProducto, int pCodMarca) {
	
	if (raiz -> codProducto == pCodProducto) {
		return raiz -> marcas.nombreMarca(pCodMarca);
	} else {
		if (pCodProducto < raiz -> codProducto) {
			return nombreMarcaRecursivo(raiz -> HIzq, pCodProducto, pCodMarca);
		} else {
			return nombreMarcaRecursivo(raiz -> HDer, pCodProducto, pCodMarca);
		}
	}
}

string ArbolAVL::nombreMarcaRecursivo(NodoAVL *&r, int pCodProducto, int pCodMarca) {
	
	if (r -> codProducto == pCodProducto) {
		return r -> marcas.nombreMarca(pCodMarca);
	} else {
		if (pCodProducto < r -> codProducto) {
			return nombreMarcaRecursivo(r -> HIzq, pCodProducto, pCodMarca);
		} else {
			return nombreMarcaRecursivo(r -> HDer, pCodProducto, pCodMarca);
		}
	}
}

void ArbolAVL::sacarDeGondola(int pCodProducto, int pCodMarca, int pCantidad) {
	
	if (raiz -> codProducto == pCodProducto) {
		raiz -> marcas.sacarDeGondola(pCodMarca, pCantidad);
	} else {
		if (pCodProducto < raiz -> codProducto) {
			sacarDeGondolaRecursivo(raiz -> HIzq, pCodProducto, pCodMarca, pCantidad);
		} else {
			sacarDeGondolaRecursivo(raiz -> HDer, pCodProducto, pCodMarca, pCantidad);
		}
	}
}

void ArbolAVL::sacarDeGondolaRecursivo(NodoAVL *&r, int pCodProducto, int pCodMarca, int pCantidad) {
	
	if (r -> codProducto == pCodProducto) {
		r -> marcas.sacarDeGondola(pCodMarca, pCantidad);
	} else {
		if (pCodProducto < r -> codProducto) {
			sacarDeGondolaRecursivo(r -> HIzq, pCodProducto, pCodMarca, pCantidad);
		} else {
			sacarDeGondolaRecursivo(r -> HDer, pCodProducto, pCodMarca, pCantidad);
		}
	}
}

void ArbolAVL::verificarInventario() {
	
	if (raiz != NULL) {
		
		raiz -> inventario.verificarInventario();
		verificarInventarioRecursivo(raiz -> HIzq);
		verificarInventarioRecursivo(raiz -> HDer);
	}
}

void ArbolAVL::verificarInventarioRecursivo(NodoAVL *&r) {
	
	if (r != NULL) {
		
		r -> inventario.verificarInventario();
		verificarInventarioRecursivo(r -> HIzq);
		verificarInventarioRecursivo(r -> HDer);
	}
}

void ArbolAVL::revisarGondolas(){
	
	
	if (raiz != NULL){
		
		revisarGondolasRecursivo(raiz->HIzq);
		revisarGondolasRecursivo(raiz->HDer);
		
		raiz->marcas.revisarGondolas();

}
}

void ArbolAVL::revisarGondolasRecursivo(NodoAVL *&r){
	
	
	if (r != NULL){
		
		revisarGondolasRecursivo(r->HIzq);
		revisarGondolasRecursivo(r->HDer);
		
		r->marcas.revisarGondolas();

}

}

void ArbolAVL::modificarProducto(string pNombre, int pCodProducto){
	
	if (raiz->codProducto == pCodProducto){
		raiz->codProducto = pCodProducto;
	}else{
		if (pCodProducto < raiz -> codProducto){
			modificarProductoRecursivo(raiz->HIzq, pNombre, pCodProducto);
		}
		else{
			modificarProductoRecursivo(raiz->HDer, pNombre, pCodProducto);
		}
	}
}

void ArbolAVL::modificarProductoRecursivo(NodoAVL *&r, string pNombre, int pCodProducto){
	
	if (r->codProducto == pCodProducto){
		r->codProducto = pCodProducto;
	}else{
		if (pCodProducto < r -> codProducto){
			modificarProductoRecursivo(r->HIzq, pNombre, pCodProducto);
		}
		else{
			modificarProductoRecursivo(r->HDer, pNombre, pCodProducto);
		}
	}
}

void ArbolAVL::modificarInventario (string pNombre, int pCantStock, int pCanasta, int pCodProducto, int pCodMarca){
	
	if (raiz->codProducto == pCodProducto){
		raiz->inventario.modificarInventario(pNombre, pCantStock, pCanasta, pCodMarca);
	}
	else{
		if (pCodProducto < raiz->codProducto){
			modificarInventarioRecursivo(raiz->HIzq, pNombre, pCantStock, pCanasta, pCodProducto, pCodMarca);
		}else{
			modificarInventarioRecursivo(raiz->HDer, pNombre, pCantStock, pCanasta, pCodProducto, pCodMarca);
		}
	}
}
void ArbolAVL::modificarInventarioRecursivo (NodoAVL *&r, string pNombre, int pCantStock, int pCanasta, int pCodProducto, int pCodMarca){
	
	if (r->codProducto == pCodProducto){
		r->inventario.modificarInventario(pNombre, pCantStock, pCanasta, pCodMarca);
	}
	else{
		if (pCodProducto < r->codProducto){
			modificarInventarioRecursivo(r->HIzq, pNombre, pCantStock, pCanasta, pCodProducto, pCodMarca);
		}else{
			modificarInventarioRecursivo(r->HDer, pNombre, pCantStock, pCanasta, pCodProducto, pCodMarca);
		}
	}
}

void ArbolAVL::eliminarProducto(int pCodProducto) {
	
	if (raiz -> codProducto == pCodProducto) {
		raiz -> marcas.podar();
		if (raiz -> HIzq != NULL) {
			NodoAVL *temp = raiz -> HIzq;
			while (temp -> HDer != NULL) {
				temp = temp -> HDer;
			}
			NodoAVL *temp2 = raiz;
			if (temp2 -> HIzq != temp) {
				temp2 = temp2 -> HIzq;
				while (temp2 -> HDer != temp) {
					temp2 = temp2 -> HDer;
				}
				temp2 -> HDer = temp -> HIzq;
			} else {
				temp2 -> HIzq = temp -> HIzq;
			}
			temp -> HDer = raiz -> HDer;
			temp -> HIzq = raiz -> HIzq;
			raiz = temp;
		} else {
			if (raiz -> HDer != NULL) {
				NodoAVL *temp = raiz -> HDer;
				while (temp -> HIzq != NULL) {
					temp = temp -> HIzq;
				}
				NodoAVL *temp2 = raiz;
				if (temp2 -> HDer != temp) {
					temp2 = temp2 -> HDer;
					while (temp2 -> HIzq != temp) {
						temp2 = temp2 -> HIzq;
					}
					temp2 -> HIzq = temp -> HDer;
				} else {
					temp2 -> HDer = temp -> HDer;
				}
				temp -> HDer = raiz -> HDer;
				temp -> HIzq = raiz -> HIzq;
				raiz = temp;
			} else {
				raiz = NULL;
			}
		}
	} else {
		if (pCodProducto < raiz -> codProducto) {
			eliminarProductoRecursivo(pCodProducto, raiz -> HIzq);
		} else {
			eliminarProductoRecursivo(pCodProducto, raiz -> HDer);
		}
	}
}

void ArbolAVL::eliminarProductoRecursivo(int pCodProducto, NodoAVL *&r) {
	
	if (r -> codProducto == pCodProducto) {
		r -> marcas.podar();
		if (r -> HIzq != NULL) {
			NodoAVL *temp = r -> HIzq;
			while (temp -> HDer != NULL) {
				temp = temp -> HDer;
			}
			NodoAVL *temp2 = r;
			if (temp2 -> HIzq != temp) {
				temp2 = temp2 -> HIzq;
				while (temp2 -> HDer != temp) {
					temp2 = temp2 -> HDer;
				}
				temp2 -> HDer = temp -> HIzq;
			} else {
				temp2 -> HIzq = temp -> HIzq;
			}
			temp -> HDer = r -> HDer;
			temp -> HIzq = r -> HIzq;
			r = temp;
		} else {
			if (r -> HDer != NULL) {
				NodoAVL *temp = r -> HDer;
				while (temp -> HIzq != NULL) {
					temp = temp -> HIzq;
				}
				NodoAVL *temp2 = r;
				if (temp2 -> HDer != temp) {
					temp2 = temp2 -> HDer;
					while (temp2 -> HIzq != temp) {
						temp2 = temp2 -> HIzq;
					}
					temp2 -> HIzq = temp -> HDer;
				} else {
					temp2 -> HDer = temp -> HDer;
				}
				temp -> HDer = r -> HDer;
				temp -> HIzq = r -> HIzq;
				r = temp;
			} else {
				r = NULL;
			}
		}
	} else {
		if (pCodProducto < raiz -> codProducto) {
			eliminarProductoRecursivo(pCodProducto, raiz -> HIzq);
		} else {
			eliminarProductoRecursivo(pCodProducto, raiz -> HDer);
		}
	}
}

void ArbolAVL::eliminarMarca(int pCodProducto, int pCodMarca) {
	
	if (raiz -> codProducto == pCodProducto) {
		raiz -> marcas.eliminarMarca(pCodMarca);
	} else {
		if (pCodProducto < raiz -> codProducto) {
			eliminarMarcaRecursivo(pCodProducto, pCodMarca, raiz -> HIzq);
		} else {
			eliminarMarcaRecursivo(pCodProducto, pCodMarca, raiz -> HDer);
		}
	}
}

void ArbolAVL::eliminarMarcaRecursivo(int pCodProducto, int pCodMarca, NodoAVL *&r) {
	
	if (r -> codProducto == pCodProducto) {
		r -> marcas.eliminarMarca(pCodMarca);
	} else {
		if (pCodProducto < r -> codProducto) {
			eliminarMarcaRecursivo(pCodProducto, pCodMarca, r -> HIzq);
		} else {
			eliminarMarcaRecursivo(pCodProducto, pCodMarca, r -> HDer);
		}
	}
}

void ArbolAVL::eliminarInventario(int pCodProducto, int pCodMarca) {
	
	if (raiz -> codProducto == pCodProducto) {
		raiz -> inventario.eliminarInventario(pCodMarca);
	} else {
		if (pCodProducto < raiz -> codProducto) {
			eliminarInventarioRecursivo(pCodProducto, pCodMarca, raiz -> HIzq);
		} else {
			eliminarInventarioRecursivo(pCodProducto, pCodMarca, raiz -> HDer);
		}
	}
}

void ArbolAVL::eliminarInventarioRecursivo(int pCodProducto, int pCodMarca, NodoAVL *&r) {
	
	if (r -> codProducto == pCodProducto) {
		r -> inventario.eliminarInventario(pCodMarca);
	} else {
		if (pCodProducto < r -> codProducto) {
			eliminarInventarioRecursivo(pCodProducto, pCodMarca, r -> HIzq);
		} else {
			eliminarInventarioRecursivo(pCodProducto, pCodMarca, r -> HDer);
		}
	}
}
