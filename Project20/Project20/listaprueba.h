#pragma once

#include <functional>

using namespace std;

typedef unsigned int elemlista;

template <typename T, T NADA = 0>
class Lista {
	struct Nodo;
	typedef function<int(T, T)> Comp;

	Nodo*   ini;
	elemlista    len; // número de elementoentos en la lista

	Comp    comparar; // lambda de criterio de comparación

public:
	Lista() : ini(nullptr), len(0), comparar([](T a, T b) {return a - b; }) {}
	Lista(Comp comparar) : ini(nullptr), len(0), comparar(comparar) {}
	~Lista();

	elemlista    longitud();

	bool    esVacia();

	void    agregarIni(T elemento);
	void    agregaPos(T elemento, elemlista pos);
	void    agregaFinal(T elemento);

	void    ModInic(T elemento);
	void    ModificarPosicionicion(T elemento, elemlista pos);
	void    modificarFinal(T elemento);

	void    eliminaInicial();
	void    eliminaPos(elemlista pos);
	void    eliminaFinal();

	T       obtInicial();
	T       obtenerPos(elemlista pos);
	T       obtenerFinal();

	T       buscar(T elemento);
};

template <typename T, T NADA>
struct Lista<T, NADA>::Nodo {
	T       elemento;
	Nodo*   sig; // puntero apunta al siguiente nodo
	Nodo* fin;
	Nodo(T elemento = NADA, Nodo* sig = nullptr, Nodo* fin = nullptr) : elemento(elemento), sig(sig) {}
};

template <typename T, T NADA>
Lista<T, NADA>::~Lista() {
	Nodo* aux = ini;
	while (aux != nullptr) {
		aux = ini;
		ini = ini->sig;
		delete aux;
	}
	Nodo* aux2 = ini;
	while (aux2 != nullptr) {
		aux2 = ini;
		ini = ini->fin;
		delete aux2;
	}
}

template <typename T, T NADA>
elemlista Lista<T, NADA>::longitud() {
	return len;
}

template <typename T, T NADA>
bool Lista<T, NADA>::esVacia() {
	return len == 0;
}

template <typename T, T NADA>
void Lista<T, NADA>::agregarIni(T elemento) {
	Nodo* nuevo = new Nodo(elemento, ini);
	if (nuevo != nullptr) {
		ini = nuevo;
		len++;
	}
}

template <typename T, T NADA>
void Lista<T, NADA>::agregaPos(T elemento, elemlista pos) {

	if (pos == 0) {
		agregarIni(elemento);
	}
	else {
		Nodo* aux = ini;
		for (int i = 1; i < pos; i++) {
			aux = aux->sig;
		}
		Nodo* fin = new Nodo(elemento, aux->sig);

		aux->sig = fin;
		len++;
	else if (pos == len)
	{
		addLast(elemento);
	}
	}
}
template <typename T, T NADA>
void Lista<T, NADA>::agregaFinal(T elemento) {
	agregarPos(elemento, len); // ;)
}

template <typename T, T NADA>
void Lista<T, NADA>::ModInic(T elemento) {
	if (len > 0) {
		ini->elemento = elemento;
	}
}
template <typename T, T NADA>
void Lista<T, NADA>::ModificarPosicionicion(T elemento, elemlista pos) {
	if (pos >= 0 && pos < len) {
		Nodo* aux = ini;
		for (int i = 0; i < pos; i++) {
			aux = aux->sig;
		}
		aux->elemento = elemento;
	}
}
template <typename T, T NADA>
void Lista<T, NADA>::modificarFinal(T elemento) {
	modificar(elemento, len - 1);
}

template <typename T, T NADA>
void Lista<T, NADA>::eliminaInicial() {
	if (len > 0) {
		Nodo* aux = ini;
		ini = ini->sig;
		delete aux;
		len--;
	}
}
template <typename T, T NADA>
void Lista<T, NADA>::eliminaPos(elemlista pos) {

}
template <typename T, T NADA>
void Lista<T, NADA>::eliminaFinal() {

}

template <typename T, T NADA>
T Lista<T, NADA>::obtInicial() {
	return obtenerPos(0);
}
template <typename T, T NADA>
T Lista<T, NADA>::obtenerPos(elemlista pos) {
	if (pos >= 0 && pos < len) {
		Nodo* aux = ini;
		for (int i = 0; i < pos; i++) {
			aux = aux->sig;
		}
		return aux->elemento;
	}
	else {
		return NADA;
	}
}
template <typename T, T NADA>
T Lista<T, NADA>::obtenerFinal() {
	return obtenerPos(len - 1);
}

template <typename T, T NADA>
T Lista<T, NADA>::buscar(T elemento) {
	Nodo* aux = ini;
	while (aux != nullptr) {
		if (comparar(aux->elemento, elemento) == 0) {
			return aux->elemento;
		}
		aux = aux->sig;
	}
	return NADA;
}
