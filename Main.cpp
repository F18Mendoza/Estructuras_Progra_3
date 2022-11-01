#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "ArbolB.h"
#include "ArbolBB.h"
#include "Compras.h"
#include "ListaDescuento.h"
#include "Reportes.h"
#include <conio.h>

using namespace std;

//--------------------------------------METODOS DE REPORTES-----------------------------------------



//------------------------------------------------------------------------------------------------------------------------

void menuClientesRegistrado(int &descuento, ArbolBB &supermercado, Compras &colaCompras, int &cedulaCliente, ListaDescuento &listaDescuentos, Reportes &listaReportes){
	
	char clientes;
	int codigoPasillo, codigoProducto, codigoMarca, cantidad;
	while (clientes != '5'){
		cout << " _____________________________________________________________" << endl;
		cout << "|                   MENU CLIENTES REGISTRADOS                 |" << endl;
		cout << "|-------------------------------------------------------------|" << endl;
		cout << "| 1. Consultar precio                                         |" << endl;
		cout << "| 2. Consultar descuento                                      |" << endl;
		cout << "| 3. Consultar productos                                      |" << endl;
		cout << "| 4. Comprar                                                  |" << endl;
		cout << "| 5. Salir                                                    |" << endl;                                                     
		cout << "|_____________________________________________________________|" << endl;
		cout << "Seleccione una opcion: ";
		cin >> clientes;
		
		switch (clientes){
			
			case '1':
				cout << "Indique el codigo del pasillo: ";
				cin >> codigoPasillo;
				if (supermercado.existeCodigo(codigoPasillo)) {
					cout << "Indique el codigo del producto: ";
					cin >> codigoProducto;
					if (supermercado.existeProducto(codigoPasillo, codigoProducto)) {
						cout << "Indique el codigo de la marca: ";
						cin >> codigoMarca;
						if (supermercado.existeMarca(codigoPasillo, codigoProducto, codigoMarca)){
							supermercado.mostrarPrecio(codigoPasillo, codigoProducto, codigoMarca);
						} else {
							cout << "El codigo que ingreso es incorrecto. Intente de nuevo." << endl;
						}
					} else {
						cout << "El codigo que ingreso es incorrecto. Intente de nuevo." << endl;
					}
				} else {
					cout << "El codigo que ingreso es incorrecto. Intente de nuevo." << endl;
				}
				break;
				
			case '2':
				if (listaDescuentos.cumpleRequisitos(cedulaCliente)) {
					cout << "Usted aplica para recibir un descuento." << endl;
					cout << "El descuento actual es del " << descuento << "%." << endl;
				} else {
					cout << "Usted aun no aplica para un descuento." << endl;
				}
				break;
				
			case '3':
				cout << "Indique el codigo de pasillo: ";
				cin >> codigoPasillo;
				if (supermercado.existeCodigo(codigoPasillo)) {
					supermercado.mostrarProductos(codigoPasillo);
				} else {
					cout << "El codigo que ingreso es incorrecto. Intente de nuevo." << endl;
				}
				break;
				
			case '4':
				int continuar;
				while (continuar != 2) {
					supermercado.mostrarPasillos();
					cout << endl << "Ingrese el codigo del pasillo que desea visitar: ";
					cin >> codigoPasillo;
					if (codigoPasillo < 0) {
						break;
					}
					if (supermercado.existeCodigo(codigoPasillo)) {
						listaReportes.pasillosVisitar(codigoPasillo);
						supermercado.mostrarProductos(codigoPasillo);
						cout << endl << "Ingrese el codigo del producto que desea visitar: ";
						cin >> codigoProducto;
						if (codigoProducto < 0) {
							break;
						}
						if (supermercado.existeProducto(codigoPasillo, codigoProducto)) {
							supermercado.mostrarMarcas(codigoPasillo, codigoProducto);
							cout << endl << "Ingrese el codigo de la marca que desea agregar a su carrito: ";
							cin >> codigoMarca;
							if (codigoMarca < 0) {
								break;
							}
							if (supermercado.existeMarca(codigoPasillo, codigoProducto, codigoMarca)) {
								cout << endl << "Ingrese la cantidad que desea tomar: ";
								cin >> cantidad;
								if (cantidad > 0) {
									int opcion = 0;
									while (opcion != 3 && cantidad > 0 && !supermercado.verificarCantidad(codigoPasillo, codigoProducto, codigoMarca, cantidad)) {
										cout << endl << "La cantidad que ingreso excede la disponible." << endl;
										cout << "Si desea tomar todos los articulos disponibles digite 1." << endl;
										cout << "Si desea ingresar otra cantidad diferente digite 2." << endl;
										cout << "Si no desea tomar ningun articulo digite 3." << endl;
										cout << "Seleccion: ";
										cin >> opcion;
										if (opcion == 1) {
											cantidad = supermercado.cantidadMaxima(codigoPasillo, codigoProducto, codigoMarca);
											break;
										}
										if (opcion == 2) {
											cout << endl << "Ingrese la cantidad que desea tomar: ";
											cin >> cantidad;
										}
									}
									if (opcion == 3) {
										cout << "No se tomaran articulos." << endl;
									}
									colaCompras.agregarArticulo(cedulaCliente, codigoPasillo, codigoProducto, codigoMarca, cantidad);
									cout << "Los articulos han sido agregados a su carrito de compras.";
									
								} else {
									if (cantidad == 0) {
										cout << "No se tomaran articulos." << endl;
									} else {
										break;
									}
								}
							}else{
								cout << "La marca ingresada no existe" << endl;
								break;
							}
						}else{
							cout << "El producto ingresado no existe" << endl;
							break;
						}
					}else{
						cout << "El pasillo ingresado no existe" << endl;
						break;
					}
					cout << endl << "Si desea continuar comprando digite 1." << endl;
					cout << "Si no desea continuar digite 2." << endl;
					cout << "Seleccion: ";
					cin >> continuar;
					if (continuar == 2) {
						cout << endl << "Para facturar por favor comuniquese con uno de nuestros administradores." << endl;
					}
				}
				break;
				
			case '5': 
				cout << "Volviendo al menu anterior." << endl;
				break;
			default:
				cout << "---------Opcion Invalida-----------" << endl;
		}
	}
}

void menuClientesNoRegistrado(ArbolBB &supermercado, Compras &colaCompras){
	
	char clientes;
	int codigoPasillo, codigoProducto, codigoMarca;

	
	while (clientes != '5') {
		cout << " _____________________________________________________________" << endl;
		cout << "|                MENU CLIENTES NO REGISTRADOS                 |" << endl;
		cout << "|-------------------------------------------------------------|" << endl;
		cout << "| 1. Consultar precio                                         |" << endl;
		cout << "| 2. Consultar descuento (Deshabilitado)                      |" << endl;
		cout << "| 3. Consultar productos                                      |" << endl;
		cout << "| 4. Comprar (Deshabilitado)                                  |" << endl;
		cout << "| 5. Salir                                                    |" << endl;                                                     
		cout << "|_____________________________________________________________|" << endl;
		cout << "Seleccione una opcion: ";
		cin >> clientes;
		
		switch (clientes){
			
			case '1':
				cout << "Indique el codigo del pasillo: ";
				cin >> codigoPasillo;
				if (supermercado.existeCodigo(codigoPasillo)) {
					cout << "Indique el codigo del producto: ";
					cin >> codigoProducto;
					if (supermercado.existeProducto(codigoPasillo, codigoProducto)) {
						cout << "Indique el codigo de la marca: ";
						cin >> codigoMarca;
						if (supermercado.existeMarca(codigoPasillo, codigoProducto, codigoMarca)){
							supermercado.mostrarPrecio(codigoPasillo, codigoProducto, codigoMarca);
						} else {
							cout << "El codigo que ingreso es incorrecto. Intente de nuevo." << endl;
						}
					} else {
						cout << "El codigo que ingreso es incorrecto. Intente de nuevo." << endl;
					}
				} else {
					cout << "El codigo que ingreso es incorrecto. Intente de nuevo." << endl;
				}
				break;
				
			case '2':
				cout << "Usted debe registrarse para poder hacer uso de esta opcion" << endl;
				break;
				
			case '3':
				cout << "Indique el codigo de pasillo: ";
				cin >> codigoPasillo;
				if (supermercado.existeCodigo(codigoPasillo)) {
					supermercado.mostrarProductos(codigoPasillo);
				} else {
					cout << "El codigo que ingreso es incorrecto. Intente de nuevo." << endl;
				}
				break;
				
			case '4':
				cout << "Usted debe registrarse para poder hacer uso de esta opcion" << endl;
				break;
				
			case '5': 
				cout << "Volviendo al menu anterior." << endl;
				break;
				
			default:
			cout << "---------Opcion Invalida-----------" << endl;		}
	}
}

void modificarCosas(ArbolBB &supermercado){
	
	char opcion;
	int codigoPasillo, codigoProducto, codigoMarca;
	string nuevoNombre;
	float nuevoPrecio;
	
	while (opcion != '4'){
		
	
		cout << " _____________________________________________________________" << endl;
		cout << "|                   MENU DE MODIFICACIONES                    |" << endl;
		cout << "|-------------------------------------------------------------|" << endl;
		cout << "| 1. Modificar el precio de una marca                         |" << endl;
		cout << "| 2. Modificar el nombre de una marca                         |" << endl;
		cout << "| 3. Salir                                                    |" << endl;
		cout << "|_____________________________________________________________|" << endl;
		cout << "Seleccione una opcion: ";
		cin >> opcion;
		
		switch (opcion){
				
			case '1':
				cout << "Ingrese el codigo de pasillo: " << endl;
				cin >> codigoPasillo;
				if (supermercado.existeCodigo(codigoPasillo)){
					cout << "Ingrese el codigo del producto: " << endl;
					cin >> codigoProducto;
					if (supermercado.existeProducto(codigoPasillo, codigoProducto)){
						cout << "Ingrese el codigo de la marca a la que le desea modificar el precio: " << endl;
						cin >> codigoMarca;
						if (supermercado.existeMarca(codigoPasillo, codigoProducto, codigoMarca)){
							cout << "Ingrese el nuevo precio para la marca seleccionada: " << endl;
							cin >> nuevoPrecio;
							supermercado.modificarMarcaPrecio(nuevoPrecio, codigoPasillo, codigoProducto, codigoMarca);
							break;
						}else{
							cout << "El codigo de marca no existe" << endl;							
						}						
					}else{
						cout << "El codigo de producto ingresado no existe" << endl;
					}
				}else{
					cout << "El codigo de pasillo ingresado no existe" << endl;
				}
				break;
				
			case '2':
				cout << "Ingrese el codigo de pasillo: " << endl;
				cin >> codigoPasillo;
				if (supermercado.existeCodigo(codigoPasillo)){
					cout << "Ingrese el codigo del producto: " << endl;
					cin >> codigoProducto;
					if (supermercado.existeProducto(codigoPasillo, codigoProducto)){
						cout << "Ingrese el codigo de la marca a la que le desea modificar el nombre: " << endl;
						cin >> codigoMarca;
						if (supermercado.existeMarca(codigoPasillo, codigoProducto, codigoMarca)){
							cout << "Ingrese el nombre por el que desea cambiar el nombre actual: " << endl;
							cin >> nuevoNombre;
							supermercado.modificarMarcaNombre(nuevoNombre, codigoPasillo, codigoProducto, codigoMarca);
							break;
						}else{
							cout << "El codigo de marca no existe" << endl;
						}
					}else{
						cout << "El codigo de producto ingresado no existe" << endl;
					}
				}else{
					cout << "El codigo de pasillo ingresado no existe" << endl;
				}
				break;
			
			case '3':
				cout << "Volviendo al menu anterior" << endl;
				break;
				
			default:
				cout << "---------Opcion Invalida-----------" << endl;
			
		}		
	}	
}

void baseDeDatos(ArbolB &clientes, int &descuento, ArbolBB &supermercado, ListaDescuento &listaDescuentos){
	
	char datos;
	string nomCliente;
	int cedCliente;
	int celCliente;
	string correoCliente;
	int codigoPasillo, codigoProducto, codigoMarca;
	string nombreProducto;
	
	while(datos != '7'){
	
		cout << " _____________________________________________________________" << endl;
		cout << "|                   MENU BASE DE DATOS                        |" << endl;
		cout << "|-------------------------------------------------------------|" << endl;
		cout << "| 1. Insertar producto nuevo                                  |" << endl;
		cout << "| 2. Modificar un producto de una marca, el precio o el nombre|" << endl;
		cout << "| 3. Consultar precio                                         |" << endl;
		cout << "| 4. Consultar descuento                                      |" << endl;
		cout << "| 5. Modificar el descuento                                   |" << endl; 
		cout << "| 6. Registrar clientes                                       |" << endl;   
		cout << "| 7. Salir                                                    |" << endl;                    
		cout << "|_____________________________________________________________|" << endl;
		cout << "Seleccione una opcion: ";
		cin >> datos;
		
		switch (datos){
			
			case '1':
				cout << "Ingrese el codigo del pasillo al cual desea agregar el producto: ";
				cin >> codigoPasillo;
				if (supermercado.existeCodigo(codigoPasillo)) {
					cout << "Ingrese el codigo del producto a registrar: ";
					cin >> codigoProducto;
					if (!supermercado.existeProducto(codigoPasillo, codigoProducto)) {
						cout << "Ingrese el nombre del producto: ";
						cin >> nombreProducto;
						supermercado.insertarProducto(nombreProducto, codigoPasillo, codigoProducto);
					} else {
						cout << "El codigo que ingreso ya esta registrado. Intente de nuevo." << endl;
					}
				} else {
					cout << "El codigo que ingreso no es valido. Intente de nuevo." << endl;
				}
				break;
				
			case '2':
				cout << "Modificar cosas" << endl;
				modificarCosas(supermercado);
				break;
				
			case '3':
				cout << "Indique el codigo del pasillo: ";
				cin >> codigoPasillo;
				if (supermercado.existeCodigo(codigoPasillo)) {
					cout << "Indique el codigo del producto: ";
					cin >> codigoProducto;
					if (supermercado.existeProducto(codigoPasillo, codigoProducto)) {
						cout << "Indique el codigo de la marca: ";
						cin >> codigoMarca;
						if (supermercado.existeMarca(codigoPasillo, codigoProducto, codigoMarca)){
							supermercado.mostrarPrecio(codigoPasillo, codigoProducto, codigoMarca);
						} else {
							cout << "El codigo que ingreso es incorrecto. Intente de nuevo." << endl;
						}
					} else {
						cout << "El codigo que ingreso es incorrecto. Intente de nuevo." << endl;
					}
				} else {
					cout << "El codigo que ingreso es incorrecto. Intente de nuevo." << endl;
				}
				break;
				
			case '4':
				cout << "Para los clientes que han facturado al menos 3 veces... " << endl;
				cout << "El descuento actual es del " << descuento << "%." << endl;
				listaDescuentos.todos();
				break;
				
			case '5':
				cout << "Ingrese el nuevo descuento: ";
				cin >> descuento;
				break;
			
			case '6':
				cout << "Registrar cliente" << endl;
				cout << "El proceso que usted esta por realizar agregara al cliente a la base de datos\n" << endl;
				cout << "Por favor ingrese la cedula del cliente: ";
				cin >> cedCliente;
				if (!clientes.existeCedula(cedCliente)) {
					cout << "Ingrese el nombre del cliente: ";
					cin >> nomCliente;
					cout << "Ingrese el telefono del ciente: ";
					cin >> celCliente;
					cout << "Ingrese el correo del cliente: ";
					cin >> correoCliente;
					clientes.insertar(cedCliente, nomCliente, celCliente, correoCliente);
					listaDescuentos.agregarCliente(cedCliente);
					break;
				}
				cout << "Ya hay un cliente con esa cedula, accion invalida" << endl;
				break;
				
			case '7':
				cout << "Volviendo al menu anterior." << endl;
				break;
				
			default:
				cout << "---------Opcion Invalida-----------" << endl;		
		}
	}	
}

void reportes(ArbolBB &supermercado, ArbolB &clientes, Reportes &listaReportes){
	
	int seleccion;
	int pasilloCliente;
	int productoCliente;
	
	while (seleccion != 15){
		cout << " _____________________________________________________________" << endl;
		cout << "|                      MENU REPORTES                          |" << endl;
		cout << "|-------------------------------------------------------------|" << endl;
		cout << "| 1. Pasillo mas visitado                                     |" << endl;
		cout << "| 2. Pasillo menos visitado                                   |" << endl;
		cout << "| 3. Productos por pasillo mas vendidos                       |" << endl;
		cout << "| 4. Marcas mas vendidas                                      |" << endl;
		cout << "| 5. Cliente que mas compro                                   |" << endl; 
		cout << "| 6. Cliente que menos compro                                 |" << endl; 
		cout << "| 7. Producto que mas se cargo en gondolas                    |" << endl;
		cout << "| 8. Cliente que mas facturo                                  |" << endl;
		cout << "| 9. Marcas de un producto                                    |" << endl;
		cout << "| 10. Factura de mayor monto                                  |" << endl;
		cout << "| 11. Productos de un pasillo                                 |" << endl; 
		cout << "| 12. Clientes del supermercado                               |" << endl; 
		cout << "| 13. Pasillos del supermercado                               |" << endl;
		cout << "| 14. Inventario del supermercado                             |" << endl; 
		cout << "| 15. Salir                                                   |" << endl;                       
		cout << "|_____________________________________________________________|" << endl;
		
		cout << "Seleccione una opcion: " ;
		cin >> seleccion;
		
		switch (seleccion){
			
			case 1:
				listaReportes.pasillosMostrarVisitados(listaReportes.pasillosVisitadosMax(), false);
				break;
			
			case 2:
				listaReportes.pasillosMostrarVisitados(listaReportes.pasillosVisitadosMin(), true);
				break;
				
			case 3:
				cout << "Ingrese el codigo del pasillo: " << endl;
				cin >> pasilloCliente;
				if (supermercado.existeCodigo(pasilloCliente)){
					listaReportes.productosMostrarComprados(pasilloCliente);
					break;
				}
				cout << "Pasillo no valido" << endl;
				break;
				
			case 4:
				cout << "salen marcas mas vendidas" << endl;
				cout << "No se logro realizar" << endl;
				break;
				
			case 5:
				listaReportes.clienteMasCompro();
				break;
				
			case 6:
				listaReportes.clienteMenosCompro();
				break;
		
			case 7: 
				cout << "sale producto mas cargado en gondolas" << endl;
				cout << "No se logro realizar" << endl;
				break;
				
			case 8:
				listaReportes.clienteMasFacturo();
				break;
				
			case 9:
				cout << "Ingrese el codigo del pasillo: " << endl;
				cin >> pasilloCliente;
				if (supermercado.existeCodigo(pasilloCliente)){
					cout << "Ingrese el codigo del producto: ";
					cin >> productoCliente;
					if (supermercado.existeProducto(pasilloCliente, productoCliente)){					
						supermercado.mostrarMarcas(pasilloCliente, productoCliente);
						break;
					}
					cout << "El codigo de producto que ingreso no pertenece a ninguno disponible" << endl;
					break;									
				}
				cout << "El codigo de pasillo que ingreso no corresponde a ninguno disponible" << endl;			
				break;
			
			case 10:
				listaReportes.facturasMayorMonto();
				break;
				
			case 11: 
				cout << "Ingrese el codigo del pasillo: ";
				cin >> pasilloCliente;
				if (supermercado.existeCodigo(pasilloCliente)){
					supermercado.mostrarProductos(pasilloCliente);
					break;
				}
				cout << "El pasillo ingresado no corresponde a ninguno disponible" << endl;
				break;
							
			case 12:
				cout << "Los clientes del supermercado" << endl;
				clientes.mostrar();
				break;
			
			case 13:
				cout << "Los pasillos del supermercado" << endl;
				supermercado.mostrarPasillos();
				break;
				
			case 14:
				cout << "El inventario del supermercado" << endl;
				supermercado.mostrarInventario();
				break;
				
			case 15:
				cout << "Volviendo al menu anterior" << endl;
				break;				
			
			default:
				cout << "---------Opcion Invalida-----------" << endl;
				break;
				
		}
		
	
	}
}

void menuAdministrador(ArbolB &clientes, int &descuento, ArbolBB &supermercado, Compras &colaCompras, ListaDescuento &listaDescuentos, Reportes &listaReportes, int &consecutivoFacturas){
	
	char opcion;
	ofstream file;
	string sCedula;
	
	while (opcion != '6') {
		cout << " _____________________________________________________________" << endl;
		cout << "|                   MENU ADMINISTRADOR                        |" << endl;
		cout << "|-------------------------------------------------------------|" << endl;
		cout << "| 1. Mantenimiento de la Base de Datos                        |" << endl;
		cout << "| 2. Facturar                                                 |" << endl;
		cout << "| 3. Revisar gondolas                                         |" << endl;
		cout << "| 4. Verificar inventario                                     |" << endl;
		cout << "| 5. Reportes                                                 |" << endl; 
		cout << "| 6. Salir                                                    |" << endl;                     
		cout << "|_____________________________________________________________|" << endl;
		cout << "Seleccione una opcion: ";
		cin >> opcion;
		
		switch (opcion){
			
			case '1':
				cout << "Mantenimiento Bases"<< endl;
				baseDeDatos(clientes, descuento, supermercado, listaDescuentos);
				break;
			case '2':
				int cedula;
				cout << "Ingrese la cedula del cliente: ";
				cin >> cedula;
				if (clientes.existeCedula(cedula)) {
					if (colaCompras.confirmacionCedula(cedula)) {
						string nomArchivo(to_string(cedula));
						file.open(nomArchivo);
						file << "----------Factura----------" << endl;
						file << "Consecutivo factura: # " << to_string(consecutivoFacturas) << endl;
						consecutivoFacturas ++;
						file << "Nombre del cliente: " << clientes.nombreCliente(cedula) << endl;
						file << "Telefono del cliente: " << to_string(clientes.telefonoCliente(cedula))<< endl;
						file << "Cantidad	|	Producto	|	Marca	|	Precio unitario	|"<<endl;
						float total = 0;
						while (!colaCompras.carritoVacio()) {
							int codPasillo = colaCompras.obtenerCodigoPasillo();
							int codProducto = colaCompras.obtenerCodigoProducto();
							int codMarca = colaCompras.obtenerCodigoMarca();
							float precio = supermercado.obtenerPrecio(codPasillo, codProducto, codMarca);
							int cantidad = colaCompras.obtenerCantidad();							
							if (supermercado.canasta(codPasillo, codProducto, codMarca)) {
								precio += precio * 0.13;
							} else {
								precio += precio * 0.01;
							}
							cout << "Precio: " << precio * cantidad << endl;
							total += precio * cantidad;
							cout << "Total: " << total << endl;
							file << to_string(cantidad) << "	|	"<< supermercado.nombreProducto(codPasillo, codProducto) << "	|	" << supermercado.nombreMarca(codPasillo, codProducto, codMarca)<< "	|	"  << to_string(precio)<< endl;

							colaCompras.sacarArticulo();
						}
						file << "--------------------------------------------------------------------\n" << endl;
						if (listaDescuentos.cumpleRequisitos(cedula)){
							file << "El descuento que usted posee como cliente es: " << descuento << endl;
							float porcentajeDescuento = descuento/100;
							float totalDescuento = total*porcentajeDescuento;
							total = total-totalDescuento;
							file << "El total de su compra es de: " << to_string(total) << endl;
							file << "Gracias por su compra. Vuelva pronto" << endl;
						}
						else{
						file << "Usted todavía no posee ningún descuento" << endl;
						file << "El total de su compra es de: " << to_string(total) << endl;
						file << "Gracias por su compra. Vuelva pronto" << endl;
						}
						listaReportes.agregarFactura(consecutivoFacturas, total);
						listaDescuentos.nuevaFactura(cedula);
					} else {
						cout << "La cedula ingresada no coincide con la del primer usuario en la cola." << endl;
					}
				} else {
					cout << "La cedula ingresada no existe en el registro de clientes." << endl;
				}
				break;
			case '3':				
				supermercado.revisarGondolas();
				break;	
			case '4':				
				supermercado.verificarInventario();
				cout << "El inventario ha sido reabastecido" << endl;
				break;
			case '5':
				reportes(supermercado, clientes, listaReportes);
				break;
			case '6':
				cout << "Volviendo al menu anterior." << endl;	
				break;
			default:
				cout << "---------Opcion Invalida-----------" << endl;
		}
	}
}


int main() {
	
//-------------------------------------------- Lectura de archivos txt	

	ArbolBB supermercado;
	Reportes listaReportes;
	ofstream file;
	int descuento = 5;
	string linea, codigoPasillo, nombrePasillo, codigoProducto, nombreProducto, codigoMarca, nombreMarca, cantidadMarca, precioMarca, cantidadStock, canastaBasica;
	
	ifstream pasillos("Pasillos.txt");
	while(!pasillos.eof()) {
		
		getline(pasillos, linea);
		stringstream input_stringstream(linea);
		getline(input_stringstream, codigoPasillo, ';');
		getline(input_stringstream, nombrePasillo, ';');
		if (!supermercado.existeCodigo(stoi(codigoPasillo))) {
			supermercado.insertar(nombrePasillo, stoi(codigoPasillo));
			listaReportes.agregarPasillo(stoi(codigoPasillo));
		}
	}
	pasillos.close();
	
	ifstream productos("ProductosPasillos.txt");
	while(!productos.eof()) {
		
		getline(productos, linea);
		stringstream input_stringstream(linea);
		getline(input_stringstream, codigoPasillo, ';');
		getline(input_stringstream, codigoProducto, ';');
		getline(input_stringstream, nombreProducto, ';');
		if (supermercado.existeCodigo(stoi(codigoPasillo)))
			supermercado.insertarProducto(nombreProducto, stoi(codigoPasillo), stoi(codigoProducto));
	}
	productos.close();
	
	ifstream marcas("MarcasProductos.txt");
	while(!marcas.eof()) {
		
		getline(marcas, linea);
		stringstream input_stringstream(linea);
		getline(input_stringstream, codigoPasillo, ';');
		getline(input_stringstream, codigoProducto, ';');
		getline(input_stringstream, codigoMarca, ';');
		getline(input_stringstream, nombreMarca, ';');
		getline(input_stringstream, cantidadMarca, ';');
		getline(input_stringstream, precioMarca, ';');
		if (supermercado.existeProducto(stoi(codigoPasillo), stoi(codigoProducto)))
			supermercado.insertarMarca(nombreMarca, stoi(codigoPasillo), stoi(codigoProducto), stoi(codigoMarca), stoi(cantidadMarca), stof(precioMarca));
	}
	marcas.close();
	
//---------------------------LECTURA DE INVENTARIO-------------------------------------
	
	ifstream inventario("Inventario.txt");
	while (!inventario.eof()) {
		
		getline(inventario, linea);
		stringstream input_stringstream(linea);
		getline(input_stringstream, codigoPasillo, ';');
		getline(input_stringstream, codigoProducto, ';');
		getline(input_stringstream, codigoMarca, ';');
		getline(input_stringstream, nombreMarca, ';');
		getline(input_stringstream, cantidadStock, ';');
		getline(input_stringstream, canastaBasica, ';');
		if (supermercado.existeCodigo(stoi(codigoPasillo))){
			if (supermercado.existeProducto(stoi(codigoPasillo), stoi(codigoProducto))){
				supermercado.insertarInventario(nombreMarca, stoi(codigoPasillo), stoi(codigoProducto), stoi(codigoMarca), stoi(cantidadStock), stoi(canastaBasica));
			}
		}
	}
	inventario.close();

//------------------------LECTURA DE CLIENTES -----------------------------------

	ArbolB clientes;
	ListaDescuento listaDescuentos;
	string cedula, nombre, telefono, correo;
	
	ifstream archivo5("Clientes.txt");
	while (!archivo5.eof()){
		
		getline(archivo5, linea);
		stringstream input_stringstream(linea);
		getline(input_stringstream, cedula, ';');
		getline(input_stringstream, nombre, ';');
		getline(input_stringstream, telefono, ';');
		getline(input_stringstream, correo, ';');
		if (!clientes.existeCedula(stoi(cedula))){
			
			clientes.insertar(stoi(cedula), nombre, stoi(telefono), correo);
			listaDescuentos.agregarCliente(stoi(cedula));
		}
	}

	archivo5.close();


//------------------------LECTURA DE ADMINISTRADORES -----------------------------------

	string codigo;
	ArbolB administradores;

	ifstream archivo6("Administradores.txt");
	while (!archivo6.eof()){
		
		getline(archivo6, linea);
		stringstream input_stringstream(linea);
		getline(input_stringstream, codigo, ';');
		getline(input_stringstream, nombre, ';');
		administradores.insertar(stoi(codigo), nombre);
	}
	
	archivo6.close();

//------------------------LECTURA DE VENDEDORES -----------------------------------
	
	string vendedor;
	ArbolB vendedores;
	
	ifstream archivo7 ("Vendedores.txt");
	while (!archivo7.eof()){
		getline(archivo7, linea);
		stringstream input_stringstream(linea);
		getline(input_stringstream, vendedor, ';');
		getline(input_stringstream, nombre, ';');
		vendedores.insertar(nombre, stoi(vendedor));
	}
	
	archivo7.close();
	
//--------------------LECTURA DE CIUDADES--------------------------

	string ciudad1, ciudad2, peso;
	//GradoCiudades
	
	ifstream archivo8 ("Ciudades.txt");
	while (!archivo8.eof()){
		getline(archivo8, linea);
		stringstream input_stringstream(linea);
		getline(input_stringstream, ciudad1, ';');
		getline(input_stringstream, nombre, ';');
		cout << ciudad1 << "	|	" << nombre << endl;
	}
	
	archivo8.close();

	cout << "-----------------------------------------" << endl;


//--------------------LECTURA DE CONEXIONES--------------------------
	
	
	ifstream archivo9 ("Conexiones.txt");
	while (!archivo9.eof()){
		getline(archivo9, linea);
		stringstream input_stringstream(linea);
		getline(input_stringstream, ciudad1, ';');
		getline(input_stringstream, ciudad2, ';');
		getline(input_stringstream, peso, ';');
		cout << ciudad1 << "	|	" <<ciudad2 << "	|	" << peso << endl;
	}
	
	archivo9.close();	
	
	cout << "-----------------------------------------" << endl;	
	
//--------------------LECTURA DE CIUDADES1--------------------------

	ifstream archivo10 ("Ciudades1.txt");
	while (!archivo10.eof()){
		getline(archivo10, linea);
		stringstream input_stringstream(linea);
		getline(input_stringstream, ciudad1, ';');
		getline(input_stringstream, nombre, ';');
		cout << ciudad1 << "	|	" << nombre << endl;
	}	
	
	archivo10.close();
	cout << "-----------------------------------------" << endl;
	
//--------------------LECTURA DE CONEXIONES1--------------------------	
	
	
	ifstream archivo11 ("Conexiones1.txt");
	while (!archivo11.eof()){
		getline(archivo11, linea);
		stringstream input_stringstream(linea);
		getline(input_stringstream, ciudad1, ';');
		getline(input_stringstream, ciudad2, ';');
		cout << ciudad1 << "	|	" <<ciudad2  << endl;
	}
	
	archivo11.close();


//----------------------MENU PRINCIPAL---------------------------
	
	char ingreso;
	int cedCliente, codigoAdmin;
	Compras colaCompras;
	int consecutivoFacturas = 1;
		
	while(ingreso != '3'){
		
		cout << " _________________________________" << endl;
		cout << "|           MENU INGRESO          |" << endl;
		cout << "|---------------------------------|" << endl;
		cout << "| Desea ingresar como:            |" << endl;
		cout << "| 1. Cliente                      |" << endl;
		cout << "| 2. Administrador                |" <<endl;
		cout << "| 3. Salir                        |" << endl;
		cout << "|_________________________________|" << endl;
		cout << "Seleccione una opcion: ";
		cin >> ingreso;	
		
		switch (ingreso){
			
			case '1':
				cout << "Ingrese su cedula para verificar si esta registrado o no: ";
				cin >> cedCliente;
				if(clientes.existeCedula(cedCliente)){
					menuClientesRegistrado(descuento, supermercado, colaCompras, cedCliente, listaDescuentos, listaReportes);
					break;
				}
				cout << "Usted no es un cliente registrado." << endl;
				menuClientesNoRegistrado(supermercado, colaCompras);
				break;
				
			case '2':
				cout << "Ingrese su codigo de administrador: ";
				cin >> codigoAdmin;
				if (administradores.existeAdmin(codigoAdmin)){
					menuAdministrador(clientes, descuento, supermercado, colaCompras, listaDescuentos, listaReportes, consecutivoFacturas);
					break;
				}
				
				cout << "Codigo invalido" << endl;
					
				break;
			case '3':
				cout << "Adios. Vuelva pronto" << endl;
				break;			
			default:
				cout << "---------Opcion Invalida-----------" << endl;
		}	
	}
	
	supermercado.podar();
	clientes.podar();
	administradores.podar();
	colaCompras.~Compras();
	listaDescuentos.~ListaDescuento();
	
	cout << "Hola" <<endl;
	
	return 0;
}
