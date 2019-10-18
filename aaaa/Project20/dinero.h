#pragma once
#include <string>
#include <ctime>
#include <iostream>
#include <stdlib.h>


using namespace System::Drawing;
using namespace System;

class Dinero
{
private:
	int x;
	int y;
	int indiceXX;
	int ancho;
	int alto;
	int tipo;
	int v;
	bool estado;
	bool colision;


public:

	Dinero() {
		colision = false;
		srand(time(NULL));
		tipo = rand() % 2 + 1;
		v = rand() % 4 + 1;
		switch (v)
		{
		case 1:
			x = 120;
			y = 210;

			break;
		case 2:

			x = 220;
			y = 120;
		case 3:
			x = 150;
			y = 250;

			break;
		case 4:

			x = 120;
			y = 50;


			break;
		}
	
		ancho = 480;
		alto = 530;
		indiceXX = 0;


		this->estado = true;
	}

	Rectangle retornarRectangulo() {
		return Rectangle(x, y, 65, 65);
	}
	void dibujardinero(BufferedGraphics^buffer, Bitmap^ bmpdinero) {
		/*if (this->estado) {*/
		Rectangle PorcionAUsar = Rectangle(indiceXX*ancho, 0, ancho, alto);
		Rectangle aumento = Rectangle(x, y, 65, 65);
		buffer->Graphics->DrawImage(bmpdinero, aumento, PorcionAUsar, GraphicsUnit::Pixel);

	}



	bool getestado() { return this->estado; }
	void setestado(bool estado) { this->estado = estado; }
	int getx() { return this->x; }
	void setx(int x) { this->x = x; }
	int gety() { return this->y; }
	void sety(int y) { this->y = y; }
	bool getcolision() { return this->colision; }
	void setcolision(bool colision) { this->estado = colision; }

};