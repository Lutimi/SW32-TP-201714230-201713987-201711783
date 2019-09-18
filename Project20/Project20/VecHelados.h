#pragma once

#include <vector>
#include "helados.h"

using namespace std;
class VecHelados
{
private:
	vector<Helados*> vec;
	
public:
	VecHelados() {
	}
	~VecHelados() {}

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


	void crearmejoras() {

		Helados* nuevo1 = new Helados();
		vec.push_back(nuevo1);

	}
	void DibijarMejoras(Graphics^ g, Bitmap^ bmphelado) {
		for (int i = 0; i < vec.size(); i++) {
			switch (vec.at(i)->getEstado1()) {
			case Estado::normal:
				vec.at(i)->dibujar(g, bmphelado);
				break;
			case Estado::desaparecer:
				vec.erase(vec.begin() + i);
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

	vector<Helados*> Getvec() { return vec; }
	void setVecHelados(vector<Helados*>vec)
	{
		vec = vec;
	}




};
