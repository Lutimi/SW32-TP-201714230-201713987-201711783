#pragma once
#include "Nodo.h"

template<typename T>
class ArbolAVL {
private:
	Nodo<T>* raiz;
	void(*procesar)(T);
	//---
	int max(int a, int b) {
		return (a > b ? a : b);
	}
	//---
	int _altura(Nodo<T>* nodo) {
		if (nodo == nullptr) return -1;
		return nodo->altura;
	}
	//---
	bool _insertar(Nodo<T>*& nodo, T e) {
		if (nodo == nullptr) {
			nodo = new Nodo<T>();
			nodo->llave = e;
		}
		else if (e < nodo->llave) {
			_insertar(nodo->izquierda, e);
		}
		else if (e >= nodo->llave) {
			_insertar(nodo->derecha, e);
		}
		//===============================================================
		//INI_DE_BALANCEO
		int hi = _altura(nodo->izquierda);
		int hd = _altura(nodo->derecha);
		int d = hd - hi;
		if (d > 1) {//pesado a la derecha
			int hni = _altura(nodo->derecha->izquierda);
			int hnd = _altura(nodo->derecha->derecha);
			if (hni > hnd) { //zig zag derecha izquierda
				_rotarDer(nodo->derecha->izquierda, nodo->derecha, nodo->derecha);
			}
			_rotarIzq(nodo, nodo->derecha, nodo);
		}
		else if (d < -1) { //pesado a la izquierda
			int hni = _altura(nodo->izquierda->izquierda);
			int hnd = _altura(nodo->izquierda->derecha);
			if (hnd > hni) {//zig zag derecha izquierda
				_rotarIzq(nodo->izquierda, nodo->izquierda->derecha, nodo->izquierda);
			}
			_rotarDer(nodo->izquierda, nodo, nodo);
		}
		//FIN_DE_BALANCEO
		//===============================================================
		hi = _altura(nodo->izquierda);
		hd = _altura(nodo->derecha);
		nodo->altura = 1 + ((hi > hd) ? hi : hd);
		return true;
	}
	//---
	//p is paren of x
	void _rotarDer(Nodo<T>*& x, Nodo<T>* y, Nodo<T>*& p) {
		p = x;
		y->izquierda = x->derecha;
		p->derecha = y;
	}
	//---
	//p is paren of x
	void _rotarIzq(Nodo<T>* x, Nodo<T>*& y, Nodo<T>*& p) {
		p = y;
		x->derecha = y->izquierda;
		p->izquierda = x;
	}
	//---
	void _inOrder(Nodo<T>* nodo) {
		if (nodo == nullptr) return;
		_inOrder(nodo->izquierda);
		procesar(nodo->llave);
		_inOrder(nodo->derecha);
	}
public:
	ArbolAVL(void(*pf)(T)) {
		this->procesar = pf;
		raiz = nullptr;
	}
	//----
	void insertar(T e) {
		_insertar(raiz, e);
	}
	//---
	void inOrder() {
		_inOrder(raiz);
	}
};
