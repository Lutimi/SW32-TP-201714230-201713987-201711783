#pragma once
template <typename T>
struct Nodo
{
	T llave;
	struct Nodo* izquierda;
	struct Nodo* derecha;
	int altura; 
	Nodo()
	{
		izquierda = nullptr;
		derecha = nullptr;
		altura = 0;
	}
};

