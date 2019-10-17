#include "CCliente.h"
#include "Lista.h"

using namespace std;
using namespace System;
class ListaClientes
{
private:
	Lista<Cliente*>*clientes;

public:
	ListaClientes() {
		clientes = new Lista<Cliente*>();
		
	}
	
	void setAgregarC(BufferedGraphics ^ buffer, Bitmap^ bmpCliente) {
		
			clientes->agregaInicial(new Cliente());
			DibujarClientes(buffer, bmpCliente);
		

	}
	void eliminarI() {
		clientes->eliminaInicial();
	}

	void DibujarClientes(BufferedGraphics ^ buffer, Bitmap^ bmpCliente) {

		for (Cliente *a : *clientes) {

			a->dibujarCliente(buffer, bmpCliente);
		}

	}

	Rectangle obtenerposR(int i) {
		
		return clientes->obtenerPos(i)->retornarRectagulo();
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

	Lista<Cliente*> getlist() { return *clientes; }

	bool vacia() {
		if (clientes->esVacia())
			true;
		else false;
	}

	/*void setVecclientes(list<Cliente*>vec)
	{
		Clientes = vec;
	}
	~ListaClientes(){}*/
};