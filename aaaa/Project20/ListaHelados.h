#pragma once

#include <vector>
#include "helados.h"
#include "Lista.h"

using namespace std;
class ListaHelados
{
private:
	vector<Helados*> vec;
	Lista<Helados*>* lluviadehelados;
public:
	ListaHelados() {
		lluviadehelados = new Lista<Helados*>();
	}
	~ListaHelados() {}

	void BorrarMejoras() {

		for (int i = 0; i < vec.size(); i++)
		{
			vec.erase(vec.begin() + i);
		}
	}

	void borrarMejoras() {

		for (int i = 0; i < vec.size(); i++)
		{
			if (vec.at(i)->getestado() == false) {
				vec.erase(vec.begin() + i);
			}
		}
	}

	void crearhelados() {
		
		lluviadehelados->agregaFinal(new Helados());

	}
	/*void crearmejoras() {

		Helados* nuevo1 = new Helados();
		vec.push_back(nuevo1);

	}*/
	void DibijarMejoras(BufferedGraphics ^buffer, Bitmap^ bmphelado) {
		for (int i = 0; i < lluviadehelados->longitud(); i++) {
			switch (lluviadehelados->obtenerPos(i)->getEstado1()) {
			case Estado::normal:
				lluviadehelados->obtenerPos(i)->dibujar(buffer, bmphelado);
				break;
			case Estado::desaparecer:
				lluviadehelados->eliminaPos(i);
				break;
			}
		}
	}
	/*void DibijarMejoras(Graphics^ g, Bitmap^ bmppwrup) {
		for (int i = 0; i < vec.size(); i++)
		{
			vec.at(i)->dibujar(g, bmppwrup);
			
		}
	}*/
	int tamaño() {
		return lluviadehelados->longitud();
	}
	Lista<Helados*> Getvec() { return *lluviadehelados; }

	Helados obtenerpos(int i) {
		*lluviadehelados->obtenerPos(i);
	}
	bool vacia() {
		if (lluviadehelados->esVacia())
			true;
		else false;
	}

};
