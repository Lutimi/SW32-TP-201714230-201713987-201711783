#include "CCliente.h"
#include "listaprueba.h"
#include <list>

using namespace std;
using namespace System;
class ListaClientes
{
private:
	Lista<Cliente> Clientes;

public:
	ListaClientes() {
		Clientes = Lista<Cliente>();
		
	}
	/*ListaClientes() {




	}*/
	void AgregarClientes() {
		Cliente *nuevo = new Cliente();

		Clientes.agregarIni(*nuevo);

	}
	void eliminar() {
		for (int i = 0; i < Clientes.longitud(); i++) {
			Clientes.eliminaInicial();
		}
	}
	/*void DibijarClientes(Graphics^ g, Bitmap^ bmpCliente) {

		for each (Cliente * var in Clientes)

			var->dibujarCliente(g, bmpCliente);


	}*/
	//void dibujar(Graphics^ g, Bitmap^ bmpClientes) {
	//	for (int i = 0; i < Clientes.size(); i++) {
	//		switch (Clientes.at(i)->getEstado()) {
	//		case Estado::normal:
	//			Clientes.at(i)->dibujar(g, bmpBala);

	//			break;
	//		case Estado::desaparecer:
	//			arrBala.erase(arrBala.begin() + i);
	//			break;
	//		}
	//	}
	//}
	/*void borrarClientes() {

		for (int i = 0; i < Clientes.size(); i++)
		{

				Clientes.erase(Clientes.begin().operator->+i);

		}
	}*/
	Lista<Cliente*> getlist() { return Clientes.obtInicial; }

	void setVecclientes(int n)
	{
		Clientes.obtenerPos(n);
	}
	~ListaClientes(){}
};