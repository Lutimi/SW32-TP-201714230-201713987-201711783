#include "Lista_Cl.h"

Lista_Cl::Lista_Cl() {

}
void Lista_Cl::agregar_inicio() {
	Nodo* generado = new Nodo(new CPersonaje(), nullptr, nullptr);
	this->inicial = generado;
	this->longitud++;
}
void Lista_Cl::agregar_final() {
	Nodo* generado = new Nodo(new CPersonaje(), nullptr, nullptr);
	if (this->inicial == nullptr) this->inicial = generado;
	else {
		Nodo* ultimo = get_ultimo();
		ultimo->siguiente = generado;
		generado->anterior = ultimo;
	}
	this->longitud++;
}
void Lista_Cl::eliminar_inicio() {

}

Lista_Cl::Nodo* Lista_Cl::get_ultimo() {
	Nodo* last = this->inicial;
	while (last->siguiente != nullptr)
	{
		last = last->siguiente;
	}
	return last;
}