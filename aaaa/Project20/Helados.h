#pragma once
#include <ctime>
#include <stdlib.h>
#include <iostream>
enum Estado { normal, desaparecer };
using namespace std;
using namespace System;
using namespace System::Drawing;

class Helados
{
private:
	int x;
	int y;
	int IX;
	int ancho;
	int alto;
	int tipo;
	int v;
	bool estado;
	bool colision;
	Estado estado1;

public:
	Helados() {

		colision = false;
		srand(time(NULL));
		tipo = rand() % 2 + 1;
		v = rand() % 6 + 1;
		switch (v)
		{
		case 1:			
				x = 70;
				y = 90;
		
			break;
		case 2:
				x = 110;
				y = 90;

			break;
		case 3:
			x = 160;
			y = 90;
			break;
		case 4:
			x = 210;
			y = 90;
			break;
		case 5:
			x = 260;
			y = 90;
			break;
		case 6:
			x = 310;
			y = 90;
			break;
		}
		estado1 = Estado::normal;
		ancho = 470;
		alto = 500 ;
		IX = 0;
		
	
		this->estado = true;
	}

	Rectangle retornarRectagulo() {
		return Rectangle(x, y, 30, 30);
	}
	void dibujar(BufferedGraphics ^ buffer, Bitmap^ bmphelado) {		
		/*if (this->estado) {*/
			Rectangle porcionAusar = Rectangle(IX*ancho,0, ancho, alto);
			Rectangle aumento = Rectangle(x, y, 45, 50);
			buffer->Graphics->DrawImage(bmphelado, aumento, porcionAusar, GraphicsUnit::Pixel);
	
		}
	Estado getEstado1() { return estado1; }
	bool getestado() { return this->estado; }
	void setestado(bool estado) { this->estado = estado; }
	int getx() { return this->x; }
	void setx(int x) { this->x = x; }
	int gety() { return this->y; }
	void sety(int y) { this->y = y; }
	bool getcolision() { return this->colision; }
	void setcolision(bool colision) { this->estado = colision; }

};
