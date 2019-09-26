#pragma once
#include "CPersonaje.h"
using namespace std;
typedef unsigned int uint;

class Lista_Cl
{
	class Nodo{
	public:
		Nodo* siguiente;
		Nodo* anterior;
		CPersonaje* cliente;
		Nodo(CPersonaje* cliente, Nodo* anterior, Nodo* siguiente) {
			this->anterior = anterior;
			this->siguiente = siguiente;
			this->cliente = cliente;
		};
	};
	class Iterator {
		uint pos;
		Nodo* aux;
	public:
		Iterator(uint pos, Nodo* aux) {
			this->pos = pos;
			this->aux = aux;
		};
		void operator++() { pos++, aux = aux->siguiente; }
	};


	Nodo* inicial;
	uint longitud;
public:
	Lista_Cl();

	void agregar_inicio();
	void agregar_final();

	void eliminar_inicio();

private:
	Nodo* get_ultimo();
};

