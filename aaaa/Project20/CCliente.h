#pragma once
#include <string>
#include <ctime>
#include <iostream>
#include <stdlib.h>

enum Estados { normall, desaparecerr };

using namespace System::Drawing;
using namespace System;

class Cliente
{
private:
	int x;
	int y;
	int indiceX;
	int ancho;
	int alto;
	int tipo;
	int v;
	bool estado;
	bool colision;
	Estados estado1;

public:

	Cliente() {
		colision = false;
		srand(time(NULL));
		tipo = rand() % 2 + 1;
		v = rand() % 3 + 1;
		switch (v)
		{
		case 1:
			x = 320;
			y = 180;

			break;
		case 2:

			x = 110;
			y = 310;


			break;
		case 3:
			x = 540;
			y = 310;
			break;
		case 4:

			x = 320;
			y = 480;
			break;

		}
		estado1 = Estados::normall;
		ancho = 477;
		alto = 526;
		indiceX = 0;


		this->estado = true;
	}

	Rectangle retornarRectangulo() {
		return Rectangle(x, y, 65, 65);
	}
	void dibujarCliente(BufferedGraphics^buffer, Bitmap^ bmpCliente) {
		/*if (this->estado) {*/
		Rectangle PorcionAUsar = Rectangle(indiceX*ancho, 0, ancho, alto);
		Rectangle aumento = Rectangle(x, y, 65, 65);
		buffer->Graphics->DrawImage(bmpCliente, aumento, PorcionAUsar, GraphicsUnit::Pixel);

	}
	
	
	Estados getEstado1() { return estado1; }
	bool getestado() { return this->estado; }
	void setestado(bool estado) { this->estado = estado; }
	int getx() { return this->x; }
	void setx(int x) { this->x = x; }
	int gety() { return this->y; }
	void sety(int y) { this->y = y; }
	bool getcolision() { return this->colision; }
	void setcolision(bool colision) { this->estado = colision; }

};


//#pragma once
//#include <ctime>
//#include <stdlib.h>
//#include <iostream>
//enum Estado { normal, desaparecer };
//using namespace std;
//using namespace System;
//using namespace System::Drawing;
//
//class Cliente
//{
//private:
//	int x;
//	int y;
//	int IX;
//	int ancho;
//	int alto;
//	int tipo;
//	int v;
//	bool estado;
//	bool colision;
//	Estado estado1;
//
//public:
//	Cliente() {
//
//		colision = false;
//		srand(time(NULL));
//		tipo = rand() % 2 + 1;
//		v = rand() % 4 + 1;
//		switch (v)
//		{
//		case 1:
//			x = 320;
//		    y = 180;
//
//			break;
//		case 2:
//			x = 110;
//			y = 310;
//
//			break;
//		case 3:
//			x = 540;
//			y = 310;
//			break;
//		case 4:
//			x = 320;
//			y = 480;
//			break;
//	
//		}
//		estado1 = Estado::normal;
//		ancho = 477;
//		alto = 526;
//		IX = 0;
//
//
//		this->estado = true;
//	}
//
//	Rectangle retornarRectagulo() {
//		return Rectangle(x, y, 65, 65);
//	}
//	void DibujarCliente(BufferedGraphics ^ buffer, Bitmap^ bmpcliente) {
//		/*if (this->estado) {*/
//		Rectangle porcionAusar = Rectangle(IX*ancho, 0, ancho, alto);
//		Rectangle aumento = Rectangle(x, y, 45, 50);
//		buffer->Graphics->DrawImage(bmpcliente, aumento, porcionAusar, GraphicsUnit::Pixel);
//
//	}
//	Estado getEstado1() { return estado1; }
//	bool getestado() { return this->estado; }
//	void setestado(bool estado) { this->estado = estado; }
//	int getx() { return this->x; }
//	void setx(int x) { this->x = x; }
//	int gety() { return this->y; }
//	void sety(int y) { this->y = y; }
//	bool getcolision() { return this->colision; }
//	void setcolision(bool colision) { this->estado = colision; }
//
//};
