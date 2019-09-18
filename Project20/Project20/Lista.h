#include <conio.h>
#include "CPersonaje.h"
#include <iostream>
#include "CCliente.h"

using namespace std;
using namespace System;

template<typename T>
class Lista
{
private:
	struct nodo {
		nodo* next;
		nodo* prev;
		CPersonaje
		nodo(nodo* next,T elemento,nodo* prev) {
			this->next = next;
			this->elemento = elemento;
			this->prev = prev;
		}		
	};


	class Iterator {
		unsigned int pos;
		nodo* aux;
	public:
		Iterator(unsigned int pos, nodo* AUX) {
			this->aux = AUX;
			this->pos = pos;
		}
		void operator ++() { pos++; aux = aux->next; }
		bool operator !=(Iterator x) { return pos != x.pos; }
		T operator *() { return aux->elem; }

	};
	nodo* firts;
	int size;


public:
	Lista() {
		firts = nullptr;
		size = 0;
		last = nullptr;
	
	}
	~Lista(){}

	void añadir(T obj) {
		nodo* n;
		if (size ==0) {
			n = new nodo(nullptr, obj)
				last = n;
		}
		else {
			n = new nodo(firts, obj)
				last->next = n;
			n->next->prev = n;
		}
		size++;
		firts = n;
	}
	void eliminarElmento(int valor) {
		nodo* aux = this->buscarElemento(valor);
		if (aux) {
			nodo* ant = aux->ant;
			nodo* sig = aux->sig;
			delete aux;
			if (prev) prev->next = next;
			if (next) next->prev = prev;
			if (aux == this->ini) this->ini = sig;
		}
	}


};

void xd() {
	//Lista<Cliente*> lista;
	//lista.añadir(new Cliente(300,300));

}