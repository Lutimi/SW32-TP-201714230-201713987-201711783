#pragma once

#include <iostream>

using namespace std;

typedef unsigned int uint;

template<typename T>
ref class Cola {
	ref class Nodo {
	public:
		T elem;
		Nodo^ sig;
		Nodo(T elem) :elem(elem), sig(nullptr) {}
		Nodo(T elem, Nodo^ sig) :elem(elem), sig(sig) {}
	};
	Nodo^ frente;
	Nodo^ fin;

public:
	uint lon;
	Cola() {
		this->frente = nullptr;
		this->fin = nullptr;
		this->lon = 0;
	}
	void insertarCola(T elem);
	void eliminarCola();
	bool Cola_Vacia(Nodo^ frente);
};

template<typename T>
void Cola<T>::insertarCola(T elem)
{
	Nodo^ nuevo_nodo = gcnew Nodo(elem);
	if (Cola_Vacia(this->frente)) {
		this->frente = nuevo_nodo;
	}
	else {
		this->fin->sig = nuevo_nodo;
	}
	this->fin = nuevo_nodo;
	this->lon++;
}

template<typename T>
void Cola<T>::eliminarCola()
{
	Nodo^ aux = this->frente;
	if (this->frente == fin) {
		this->frente = nullptr;
		this->fin = nullptr;
	}
	else
	{
		this->frente = this->frente->sig;
	}
	delete aux;
	this->lon--;
}
template<typename T>
bool Cola<T>::Cola_Vacia(Nodo^ frente)
{
	return(frente == nullptr) ? true : false;
}
