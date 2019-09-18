#include "CCliente.h"
#include <list>

using namespace std;
using namespace System;
class ListaClientes
{
private:
	list<Cliente*> Clientes;

public:
	ListaClientes() {
		Clientes = list<Cliente*>();
		
	}
	/*ListaClientes() {




	}*/
	void AgregarClientes() {
		Cliente* nuevo = new Cliente();

		Clientes.push_back(nuevo);

	}
	void eliminar() {
		for (int i = 0; i < Clientes.size(); i++) {
			Clientes.erase(Clientes.begin());
		}
	}
	void DibijarClientes(Graphics^ g, Bitmap^ bmpCliente) {

		for each (Cliente * var in Clientes)

			var->dibujarCliente(g, bmpCliente);


	}
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
	list<Cliente*> getlist() { return Clientes; }

	void setVecclientes(list<Cliente*>vec)
	{
		Clientes = vec;
	}
	~ListaClientes(){}
};