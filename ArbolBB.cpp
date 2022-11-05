#include "ArbolBB.h"
#include <iostream>

using namespace std;

void ArbolBB::podar() {

    if (raiz != NULL) {

        podarRecursivo(raiz -> HIzq);
        podarRecursivo(raiz -> HDer);
        raiz -> productos.podar();
        delete raiz;
    }
}

void ArbolBB::podarRecursivo(NodoBB *&r) {

    if (r != NULL) {

        podarRecursivo(r -> HIzq);
        podarRecursivo(r -> HDer);
        r -> productos.podar();
        delete r;
    }
}

void ArbolBB::insertar(string pNombre, int pCodPasillo) {

    if (raiz == NULL)
        raiz = new NodoBB(pNombre, pCodPasillo);
    else {

        if (!existeCodigo(pCodPasillo)){

            if (pCodPasillo < raiz -> codPasillo)
                insertarRecursivo(raiz -> HIzq, pNombre, pCodPasillo);
            else
                insertarRecursivo(raiz -> HDer, pNombre, pCodPasillo);
        }
    }
}

void ArbolBB::insertarRecursivo(NodoBB *&r, string pNombre, int pCodPasillo){

    if (r == NULL) {
    	r = new NodoBB(pNombre, pCodPasillo);
    } else {
        if (pCodPasillo < r -> codPasillo){
            insertarRecursivo(r -> HIzq, pNombre, pCodPasillo);
        } else {
            insertarRecursivo(r -> HDer, pNombre, pCodPasillo);
        }
    }
}

bool ArbolBB::existeCodigo(int pCodPasillo) {

    if (raiz == NULL)
        return false;
    else {

        if (raiz -> codPasillo == pCodPasillo)
            return true;
        else {
            
            if (pCodPasillo < raiz -> codPasillo)
                return existeCodigoRecursivo(pCodPasillo, raiz -> HIzq);
            else
                return existeCodigoRecursivo(pCodPasillo, raiz -> HDer);
        }
    }
}

bool ArbolBB::existeCodigoRecursivo(int pCodPasillo, NodoBB *&r) {

    if (r == NULL)
        return false;
    else {

        if (r -> codPasillo == pCodPasillo)
            return true;
        else {

            if (pCodPasillo < r -> codPasillo)
                return existeCodigoRecursivo(pCodPasillo, r -> HIzq);
            else
                return existeCodigoRecursivo(pCodPasillo, r -> HDer);
        }
    }
}

bool ArbolBB::existeProducto(int pCodPasillo, int pCodProducto) {
	
	if (raiz -> codPasillo == pCodPasillo) {
		return raiz -> productos.existeCodigo(pCodProducto);
	} else {
		if (pCodPasillo < raiz -> codPasillo) {
			return existeProductoRecursivo(pCodPasillo, pCodProducto, raiz -> HIzq);
		} else {
			return existeProductoRecursivo(pCodPasillo, pCodProducto, raiz -> HDer);
		}
	}
}

bool ArbolBB::existeProductoRecursivo(int pCodPasillo, int pCodProducto, NodoBB *&r) {
	
	if (r -> codPasillo == pCodPasillo) {
		return r -> productos.existeCodigo(pCodProducto);
	} else {
		if (pCodPasillo < r -> codPasillo) {
			return existeProductoRecursivo(pCodPasillo, pCodProducto, r -> HIzq);
		} else {
			return existeProductoRecursivo(pCodPasillo, pCodProducto, r -> HDer);
		}
	}
}

bool ArbolBB::existeMarca(int pCodPasillo, int pCodProducto, int pCodMarca) {
	
	if (raiz -> codPasillo == pCodPasillo) {
		return raiz -> productos.existeMarca(pCodProducto, pCodMarca);
	} else {
		if (pCodPasillo < raiz -> codPasillo) {
			return existeMarcaRecursivo(pCodPasillo, pCodProducto, pCodMarca, raiz -> HIzq);
		} else {
			return existeMarcaRecursivo(pCodPasillo, pCodProducto, pCodMarca, raiz -> HDer);
		}
	}
}

bool ArbolBB::existeMarcaRecursivo(int pCodPasillo, int pCodProducto, int pCodMarca, NodoBB *&r) {
	
	if (r -> codPasillo == pCodPasillo) {
		return r -> productos.existeMarca(pCodProducto, pCodMarca);
	} else {
		if (pCodPasillo < r -> codPasillo) {
			return existeMarcaRecursivo(pCodPasillo, pCodProducto, pCodMarca, r -> HIzq);
		} else {
			return existeMarcaRecursivo(pCodPasillo, pCodProducto, pCodMarca, r -> HDer);
		}
	}
}

void ArbolBB::insertarProducto(string pNombre, int pCodPasillo, int pCodProducto) {

     if (raiz -> codPasillo == pCodPasillo) {
        raiz -> productos.insertar(pNombre, pCodProducto);
     } else {
        if (pCodPasillo < raiz -> codPasillo)
            insertarProductoRecursivo(raiz -> HIzq, pNombre, pCodPasillo, pCodProducto);
        else
            insertarProductoRecursivo(raiz -> HDer, pNombre, pCodPasillo, pCodProducto);
     }
}

void ArbolBB::insertarProductoRecursivo(NodoBB *&r, string pNombre, int pCodPasillo, int pCodProducto) {

    if (r -> codPasillo == pCodPasillo) {
        r -> productos.insertar(pNombre, pCodProducto);
    } else {
        if (pCodPasillo < r -> codPasillo)
            insertarProductoRecursivo(r -> HIzq, pNombre, pCodPasillo, pCodProducto);
        else
            insertarProductoRecursivo(r -> HDer, pNombre, pCodPasillo, pCodProducto);
    }
}

void ArbolBB::insertarMarca(string pNombre, int pCodPasillo, int pCodProducto, int pCodMarca, int pCantidad, float pPrecio) {
	
	if (raiz -> codPasillo == pCodPasillo) {
		raiz -> productos.insertarMarca(pNombre, pCodProducto, pCodMarca, pCantidad, pPrecio);
	} else {
		if (pCodPasillo < raiz -> codPasillo) {
			insertarMarcaRecursivo(raiz -> HIzq, pNombre, pCodPasillo, pCodProducto, pCodMarca, pCantidad, pPrecio);
		} else {
			insertarMarcaRecursivo(raiz -> HDer, pNombre, pCodPasillo, pCodProducto, pCodMarca, pCantidad, pPrecio);
		}
	}
}

void ArbolBB::insertarMarcaRecursivo(NodoBB *&r, string pNombre, int pCodPasillo, int pCodProducto, int pCodMarca, int pCantidad, float pPrecio) {
	
	if (r -> codPasillo == pCodPasillo) {
		r -> productos.insertarMarca(pNombre, pCodProducto, pCodMarca, pCantidad, pPrecio);
	} else {
		if (pCodPasillo < r -> codPasillo) {
			insertarMarcaRecursivo(r -> HIzq, pNombre, pCodPasillo, pCodProducto, pCodMarca, pCantidad, pPrecio);
		} else {
			insertarMarcaRecursivo(r -> HDer, pNombre, pCodPasillo, pCodProducto, pCodMarca, pCantidad, pPrecio);
		}
	}
}



void ArbolBB::insertarInventario(string pNombre, int pCodPasillo, int pCodProducto, int pCodMarca, int pStock, int pCanasta) {
	
	if (raiz -> codPasillo == pCodPasillo) {
		raiz -> productos.insertarInventario(pNombre, pCodProducto, pCodMarca, pStock, pCanasta);
	} else {
		if (pCodPasillo < raiz -> codPasillo) {
			insertarInventarioRecursivo(raiz -> HIzq, pNombre, pCodPasillo, pCodProducto, pCodMarca, pStock, pCanasta);
		} else {
			insertarInventarioRecursivo(raiz -> HDer, pNombre, pCodPasillo, pCodProducto, pCodMarca, pStock, pCanasta);
		}
	}
}

void ArbolBB::insertarInventarioRecursivo(NodoBB *&r, string pNombre, int pCodPasillo, int pCodProducto, int pCodMarca, int pStock, int pCanasta) {
	
	if (r -> codPasillo == pCodPasillo) {
		r -> productos.insertarInventario(pNombre, pCodProducto, pCodMarca, pStock, pCanasta);
	} else {
		if (pCodPasillo < r -> codPasillo) {
			insertarInventarioRecursivo(r -> HIzq, pNombre, pCodPasillo, pCodProducto, pCodMarca, pStock, pCanasta);
		} else {
			insertarInventarioRecursivo(r -> HDer, pNombre, pCodPasillo, pCodProducto, pCodMarca, pStock, pCanasta);
		}
	}
}

void ArbolBB::mostrarPasillos() {
	
	if (raiz != NULL) {
		
		mostrarPasillosRecursivo(raiz -> HIzq);
		cout << raiz -> codPasillo << " " << raiz -> nombre << endl;
		mostrarPasillosRecursivo(raiz -> HDer);
	}
}

void ArbolBB::mostrarPasillosRecursivo(NodoBB *&r) {
	
	if (r != NULL) {
		
		mostrarPasillosRecursivo(r -> HIzq);
		cout << r -> codPasillo << " " << r -> nombre << endl;
		mostrarPasillosRecursivo(r -> HDer);
	}
}

void ArbolBB::mostrarProductos(int pCodPasillo) {
	
	if (raiz -> codPasillo == pCodPasillo) {
		raiz -> productos.mostrarProductos();
	} else {
		if (pCodPasillo < raiz -> codPasillo) {
			mostrarProductosRecursivo(raiz -> HIzq, pCodPasillo);
		} else {
			mostrarProductosRecursivo(raiz -> HDer, pCodPasillo);
		}
	}
}

void ArbolBB::mostrarProductosRecursivo(NodoBB *&r, int pCodPasillo) {
	
	if (r -> codPasillo == pCodPasillo) {
		r -> productos.mostrarProductos();
	} else {
		if (pCodPasillo < r -> codPasillo) {
			mostrarProductosRecursivo(r -> HIzq, pCodPasillo);
		} else {
			mostrarProductosRecursivo(r -> HDer, pCodPasillo);
		}
	}
}

void ArbolBB::mostrarMarcas(int pCodPasillo, int pCodProducto) {
	
	if (raiz -> codPasillo == pCodPasillo) {
		raiz -> productos.mostrarMarcas(pCodProducto);
	} else {
		if (pCodPasillo < raiz -> codPasillo) {
			mostrarMarcasRecursivo(raiz -> HIzq, pCodPasillo, pCodProducto);
		} else {
			mostrarMarcasRecursivo(raiz -> HDer, pCodPasillo, pCodProducto);
		}
	}
}

void ArbolBB::mostrarMarcasRecursivo(NodoBB *&r, int pCodPasillo, int pCodProducto) {
	
	if (r -> codPasillo == pCodPasillo) {
		r -> productos.mostrarMarcas(pCodProducto);
	} else {
		if (pCodPasillo < r -> codPasillo) {
			mostrarMarcasRecursivo(r -> HIzq, pCodPasillo, pCodProducto);
		} else {
			mostrarMarcasRecursivo(r -> HDer, pCodPasillo, pCodProducto);
		}
	}
}

void ArbolBB::mostrar() {
	
	if (raiz != NULL && !raiz -> productos.vacio()) {
		cout << raiz -> codPasillo << " " << raiz -> nombre << endl;
		raiz -> productos.mostrar();
		mostrarRecursivo(raiz -> HIzq);
		mostrarRecursivo(raiz -> HDer);
	}
}

void ArbolBB::mostrarRecursivo(NodoBB *&r) {
	
	if (r != NULL && !r -> productos.vacio()) {
		
		cout << r -> codPasillo << " " << r -> nombre << endl;
		r -> productos.mostrar();
		mostrarRecursivo(r -> HIzq);
		mostrarRecursivo(r -> HDer);
	}
}

void ArbolBB::mostrarInventario() {
	
	if (raiz != NULL && !raiz -> productos.vacio()) {
		
		cout << "Pasillo: " << raiz -> codPasillo << endl;
		raiz -> productos.mostrarInventario();
		mostrarInventarioRecursivo(raiz -> HIzq);
		mostrarInventarioRecursivo(raiz -> HDer);
	}
}

void ArbolBB::mostrarInventarioRecursivo(NodoBB *&r) {
	
	if (r != NULL && !r -> productos.vacio()) {
		
		cout << "Pasillo: " << r -> codPasillo << endl;
		r -> productos.mostrarInventario();
		mostrarInventarioRecursivo(r -> HIzq);
		mostrarInventarioRecursivo(r -> HDer);
	}
}

void ArbolBB::mostrarPrecio(int pCodPasillo, int pCodProducto, int pCodMarca) {
	
	if (raiz -> codPasillo == pCodPasillo) {
		raiz -> productos.mostrarPrecio(pCodProducto, pCodMarca);
	} else {
		if (pCodPasillo < raiz -> codPasillo) {
			mostrarPrecioRecursivo(pCodPasillo, pCodProducto, pCodMarca, raiz -> HIzq);
		} else {
			mostrarPrecioRecursivo(pCodPasillo, pCodProducto, pCodMarca, raiz -> HDer);
		}
	}
}

void ArbolBB::mostrarPrecioRecursivo(int pCodPasillo, int pCodProducto, int pCodMarca, NodoBB *&r) {
	
	if (r -> codPasillo == pCodPasillo) {
		r -> productos.mostrarPrecio(pCodProducto, pCodMarca);
	} else {
		if (pCodPasillo < r -> codPasillo) {
			mostrarPrecioRecursivo(pCodPasillo, pCodProducto, pCodMarca, r -> HIzq);
		} else {
			mostrarPrecioRecursivo(pCodPasillo, pCodProducto, pCodMarca, r -> HDer);
		}
	}
}


void ArbolBB::modificarMarcaNombre (string pNombre, int pCodPasillo, int pCodProducto, int pCodMarca){
	
	if (raiz -> codPasillo == pCodPasillo) {
		raiz -> productos.modificarMarcaNombre(pNombre, pCodProducto, pCodMarca);
	} else {
		if (pCodPasillo < raiz -> codPasillo) {
			modificarMarcaNombreRecursivo(raiz -> HIzq, pNombre, pCodPasillo, pCodProducto, pCodMarca);
		} else {
			modificarMarcaNombreRecursivo(raiz -> HDer, pNombre, pCodPasillo, pCodProducto, pCodMarca);
		}
	}
}


void ArbolBB::modificarMarcaNombreRecursivo(NodoBB *&r, string pNombre, int pCodPasillo, int pCodProducto, int pCodMarca){
	
	if (r -> codPasillo == pCodPasillo) {
		r -> productos.modificarMarcaNombre(pNombre, pCodProducto, pCodMarca);
	} else {
		if (pCodPasillo < r -> codPasillo) {
			modificarMarcaNombreRecursivo(r -> HIzq, pNombre, pCodPasillo, pCodProducto, pCodMarca);
		} else {
			modificarMarcaNombreRecursivo(r -> HDer, pNombre, pCodPasillo, pCodProducto, pCodMarca);
		}
	}
}


void ArbolBB::modificarMarcaPrecio(float pPrecio, int pCodPasillo, int pCodProducto, int pCodMarca){
	
	if (raiz -> codPasillo == pCodPasillo) {
		raiz -> productos.modificarMarcaPrecio(pPrecio, pCodProducto, pCodMarca);
	} else {
		if (pCodPasillo < raiz -> codPasillo) {
			modificarMarcaPrecioRecursivo(raiz -> HIzq, pPrecio, pCodPasillo, pCodProducto, pCodMarca);
		} else {
			modificarMarcaPrecioRecursivo(raiz -> HDer, pPrecio, pCodPasillo, pCodProducto, pCodMarca);
		}
	}
}


void ArbolBB::modificarMarcaPrecioRecursivo(NodoBB *&r, float pPrecio, int pCodPasillo, int pCodProducto, int pCodMarca){
	
	if (r -> codPasillo == pCodPasillo) {
		r -> productos.modificarMarcaPrecio(pPrecio, pCodProducto, pCodMarca);
	} else {
		if (pCodPasillo < r -> codPasillo) {
			modificarMarcaPrecioRecursivo(r -> HIzq, pPrecio, pCodPasillo, pCodProducto, pCodMarca);
		} else {
			modificarMarcaPrecioRecursivo(r -> HDer, pPrecio, pCodPasillo, pCodProducto, pCodMarca);
		}
	}
}


void ArbolBB::modificarMarcaGondola (int pGondola, int pCodPasillo, int pCodProducto, int pCodMarca){
	
	if (raiz -> codPasillo == pCodPasillo) {
		raiz -> productos.modificarMarcaGondola(pGondola, pCodProducto, pCodMarca);
	} else {
		if (pCodPasillo < raiz -> codPasillo) {
			modificarMarcaGondolaRecursivo(raiz -> HIzq, pGondola, pCodPasillo, pCodProducto, pCodMarca);
		} else {
			modificarMarcaGondolaRecursivo(raiz -> HDer, pGondola, pCodPasillo, pCodProducto, pCodMarca);
		}
	}
	
}



void ArbolBB::modificarMarcaGondolaRecursivo(NodoBB *&r, int pGondola, int pCodPasillo, int pCodProducto, int pCodMarca){

		if (r -> codPasillo == pCodPasillo) {
		r -> productos.modificarMarcaGondola(pGondola, pCodProducto, pCodMarca);
	} else {
		if (pCodPasillo < r -> codPasillo) {
			modificarMarcaGondolaRecursivo(r -> HIzq, pGondola, pCodPasillo, pCodProducto, pCodMarca);
		} else {
			modificarMarcaGondolaRecursivo(r -> HDer, pGondola, pCodPasillo, pCodProducto, pCodMarca);
		}
	}	
}


bool ArbolBB::verificarCantidad(int pCodPasillo, int pCodProducto, int pCodMarca, int pCantidad) {
	
	if (raiz -> codPasillo == pCodPasillo) {
		return raiz -> productos.verificarCantidad(pCodProducto, pCodMarca, pCantidad);
	} else {
		if (pCodPasillo < raiz -> codPasillo) {
			return verificarCantidadRecursivo(raiz -> HIzq, pCodPasillo, pCodProducto, pCodMarca, pCantidad);
		} else {
			return verificarCantidadRecursivo(raiz -> HDer, pCodPasillo, pCodProducto, pCodMarca, pCantidad);
		}
	}
}

bool ArbolBB::verificarCantidadRecursivo(NodoBB *&r, int pCodPasillo, int pCodProducto, int pCodMarca, int pCantidad) {
	
	if (r -> codPasillo == pCodPasillo) {
		return r -> productos.verificarCantidad(pCodProducto, pCodMarca, pCantidad);
	} else {
		if (pCodPasillo < r -> codPasillo) {
			return verificarCantidadRecursivo(r -> HIzq, pCodPasillo, pCodProducto, pCodMarca, pCantidad);
		} else {
			return verificarCantidadRecursivo(r -> HDer, pCodPasillo, pCodProducto, pCodMarca, pCantidad);
		}
	}
}

int ArbolBB::cantidadMaxima(int pCodPasillo, int pCodProducto, int pCodMarca) {
	
	if (raiz -> codPasillo == pCodPasillo) {
		return raiz -> productos.cantidadMaxima(pCodProducto, pCodMarca);
	} else {
		if (pCodPasillo < raiz -> codPasillo) {
			return cantidadMaximaRecursivo(raiz -> HIzq, pCodPasillo, pCodProducto, pCodMarca);
		} else {
			return cantidadMaximaRecursivo(raiz -> HDer, pCodPasillo, pCodProducto, pCodMarca);
		}
	}
}

int ArbolBB::cantidadMaximaRecursivo(NodoBB *&r, int pCodPasillo, int pCodProducto, int pCodMarca) {
	
	if (r -> codPasillo == pCodPasillo) {
		return r -> productos.cantidadMaxima(pCodProducto, pCodMarca);
	} else {
		if (pCodPasillo < r -> codPasillo) {
			return cantidadMaximaRecursivo(r -> HIzq, pCodPasillo, pCodProducto, pCodMarca);
		} else {
			return cantidadMaximaRecursivo(r -> HDer, pCodPasillo, pCodProducto, pCodMarca);
		}
	}
}

bool ArbolBB::canasta(int pCodPasillo, int pCodProducto, int pCodMarca) {
	
	if (raiz -> codPasillo == pCodPasillo) {
		return raiz -> productos.canasta(pCodProducto, pCodMarca);
	} else {
		if (pCodPasillo < raiz -> codPasillo) {
			return canastaRecursivo(raiz -> HIzq, pCodPasillo, pCodProducto, pCodMarca);
		} else {
			return canastaRecursivo(raiz -> HDer, pCodPasillo, pCodProducto, pCodMarca);
		}
	}
}

bool ArbolBB::canastaRecursivo(NodoBB *&r, int pCodPasillo, int pCodProducto, int pCodMarca) {
	
	if (r -> codPasillo == pCodPasillo) {
		return r -> productos.canasta(pCodProducto, pCodMarca);
	} else {
		if (pCodPasillo < r -> codPasillo) {
			return canastaRecursivo(r -> HIzq, pCodPasillo, pCodProducto, pCodMarca);
		} else {
			return canastaRecursivo(r -> HDer, pCodPasillo, pCodProducto, pCodMarca);
		}
	}
}

float ArbolBB::obtenerPrecio(int pCodPasillo, int pCodProducto, int pCodMarca) {
	
	if (raiz -> codPasillo == pCodPasillo) {
		return raiz -> productos.obtenerPrecio(pCodProducto, pCodMarca);
	} else {
		if (pCodPasillo < raiz -> codPasillo) {
			return obtenerPrecioRecursivo(raiz -> HIzq, pCodPasillo, pCodProducto, pCodMarca);
		} else {
			return obtenerPrecioRecursivo(raiz -> HDer, pCodPasillo, pCodProducto, pCodMarca);
		}
	}
}

float ArbolBB::obtenerPrecioRecursivo(NodoBB *&r, int pCodPasillo, int pCodProducto, int pCodMarca) {
	
	if (r -> codPasillo == pCodPasillo) {
		return r -> productos.obtenerPrecio(pCodProducto, pCodMarca);
	} else {
		if (pCodPasillo < r -> codPasillo) {
			return obtenerPrecioRecursivo(r -> HIzq, pCodPasillo, pCodProducto, pCodMarca);
		} else {
			return obtenerPrecioRecursivo(r -> HDer, pCodPasillo, pCodProducto, pCodMarca);
		}
	}
}

string ArbolBB::nombreProducto(int pCodPasillo, int pCodProducto) {
	
	if (raiz -> codPasillo == pCodPasillo) {
		return raiz -> productos.nombreProducto(pCodProducto);
	} else {
		if (pCodPasillo < raiz -> codPasillo) {
			return nombreProductoRecursivo(raiz -> HIzq, pCodPasillo, pCodProducto);
		} else {
			return nombreProductoRecursivo(raiz -> HDer, pCodPasillo, pCodProducto);
		}
	}
}

string ArbolBB::nombreProductoRecursivo(NodoBB *&r, int pCodPasillo, int pCodProducto) {
	
	if (r -> codPasillo == pCodPasillo) {
		return r -> productos.nombreProducto(pCodProducto);
	} else {
		if (pCodPasillo < r -> codPasillo) {
			return nombreProductoRecursivo(r -> HIzq, pCodPasillo, pCodProducto);
		} else {
			return nombreProductoRecursivo(r -> HDer, pCodPasillo, pCodProducto);
		}
	}
}

string ArbolBB::nombreMarca(int pCodPasillo, int pCodProducto, int pCodMarca) {
	
	if (raiz -> codPasillo == pCodPasillo) {
		return raiz -> productos.nombreMarca(pCodProducto, pCodMarca);
	} else {
		if (pCodPasillo < raiz -> codPasillo) {
			return nombreMarcaRecursivo(raiz -> HIzq, pCodPasillo, pCodProducto, pCodMarca);
		} else {
			return nombreMarcaRecursivo(raiz -> HDer, pCodPasillo, pCodProducto, pCodMarca);
		}
	}
}

string ArbolBB::nombreMarcaRecursivo(NodoBB *&r, int pCodPasillo, int pCodProducto, int pCodMarca) {
	
	if (r -> codPasillo == pCodPasillo) {
		return r -> productos.nombreMarca(pCodProducto, pCodMarca);
	} else {
		if (pCodPasillo < r -> codPasillo) {
			return nombreMarcaRecursivo(r -> HIzq, pCodPasillo, pCodProducto, pCodMarca);
		} else {
			return nombreMarcaRecursivo(r -> HDer, pCodPasillo, pCodProducto, pCodMarca);
		}
	}
}

void ArbolBB::sacarDeGondola(int pCodPasillo, int pCodProducto, int pCodMarca, int pCantidad) {
	
	if (raiz -> codPasillo == pCodPasillo) {
		raiz -> productos.sacarDeGondola(pCodProducto, pCodMarca, pCantidad);
	} else {
		if (pCodPasillo < raiz -> codPasillo) {
			sacarDeGondolaRecursivo(raiz -> HIzq, pCodPasillo, pCodProducto, pCodMarca, pCantidad);
		} else {
			sacarDeGondolaRecursivo(raiz -> HDer, pCodPasillo, pCodProducto, pCodMarca, pCantidad);
		}
	}
}

void ArbolBB::sacarDeGondolaRecursivo(NodoBB *&r, int pCodPasillo, int pCodProducto, int pCodMarca, int pCantidad) {
	
	if (r -> codPasillo == pCodPasillo) {
		r -> productos.sacarDeGondola(pCodProducto, pCodMarca, pCantidad);
	} else {
		if (pCodPasillo < r -> codPasillo) {
			sacarDeGondolaRecursivo(r -> HIzq, pCodPasillo, pCodProducto, pCodMarca, pCantidad);
		} else {
			sacarDeGondolaRecursivo(r -> HDer, pCodPasillo, pCodProducto, pCodMarca, pCantidad);
		}
	}
}

void ArbolBB::verificarInventario() {
	
	if (raiz != NULL) {
		
		raiz -> productos.verificarInventario();
		verificarInventarioRecursivo(raiz -> HIzq);
		verificarInventarioRecursivo(raiz -> HDer);
	}
}

void ArbolBB::verificarInventarioRecursivo(NodoBB *&r) {
	
	if (r != NULL) {
		
		r -> productos.verificarInventario();
		verificarInventarioRecursivo(r -> HIzq);
		verificarInventarioRecursivo(r -> HDer);
	}
}

void ArbolBB::revisarGondolas(){
	

	if (raiz != NULL){
		
		revisarGondolasRecursivo(raiz->HIzq);
		revisarGondolasRecursivo(raiz->HDer);
		
		raiz->productos.revisarGondolas();

}
}
void ArbolBB::revisarGondolasRecursivo(NodoBB *&r){
	
	
	if (r != NULL){
		
		revisarGondolasRecursivo(r->HIzq);
		revisarGondolasRecursivo(r->HDer);
		
		r->productos.revisarGondolas();

}

}

void ArbolBB::modificarPasillo(string pNombre, int pCodPasillo){
	
	if (raiz->codPasillo == pCodPasillo){
		raiz->nombre = pNombre;
	}else{
		if (pCodPasillo < raiz -> codPasillo){
			modificarPasilloRecursivo(raiz->HIzq, pNombre, pCodPasillo);
		}
		else{
			modificarPasilloRecursivo(raiz->HDer, pNombre, pCodPasillo);
		}
	}
}

void ArbolBB::modificarPasilloRecursivo(NodoBB *&r, string pNombre, int pCodPasillo){
	
	if (r->codPasillo == pCodPasillo){
		r->nombre = pNombre;
	}else{
		if (pCodPasillo < r -> codPasillo){
			modificarPasilloRecursivo(r->HIzq, pNombre, pCodPasillo);
		}
		else{
			modificarPasilloRecursivo(r->HDer, pNombre, pCodPasillo);
		}
	}
}

void ArbolBB::modificarProducto(string pNombre, int pCodPasillo, int pCodProducto){
	
	if (raiz->codPasillo == pCodPasillo){
		raiz-> productos.modificarProducto(pNombre, pCodProducto);
	}else{
		if (pCodPasillo < raiz -> codPasillo){
			modificarProductoRecursivo(raiz->HIzq, pNombre, pCodPasillo, pCodProducto);
		}
		else{
			modificarProductoRecursivo(raiz->HDer, pNombre, pCodPasillo, pCodProducto);
		}
	}
}

void ArbolBB::modificarProductoRecursivo(NodoBB *&r, string pNombre, int pCodPasillo, int pCodProducto){
	
	if (r->codPasillo == pCodPasillo){
		r->productos.modificarProducto(pNombre, pCodProducto);
	}else{
		if (pCodPasillo < r -> codPasillo){
			modificarProductoRecursivo(r->HIzq, pNombre, pCodPasillo, pCodProducto);
		}
		else{
			modificarProductoRecursivo(r->HDer, pNombre, pCodPasillo, pCodProducto);
		}
	}
}
