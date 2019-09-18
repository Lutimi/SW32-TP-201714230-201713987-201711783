#pragma once
#include <string>
#include <ctime>
#include <iostream>
using namespace System::Drawing;
using namespace System;

class Cliente
{
private:
	int x;
	int y;
	int ancho;
	int alto;
	int aumento;
	int indiceX;
	bool ocupado;
	int v;
	int paciencia;
	bool estado;
	bool colision;

public:

	Cliente() {
		colision = false;
		this->estado = true;
		srand(time(NULL));
		this->ocupado = false;
		 v = rand() % 4 + 1 ;
		switch (v)
		{
		case 1:
			if (ocupado==false)
			{
				x = 320;
				y = 180;
			}
				
			break;
		case 2:
			if (ocupado==false)
			{
				x = 110;
				y = 310;
			}
			
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
		paciencia = rand() % 15 + 5;

		indiceX =0;
	
		paciencia = rand() % 1500 + 500;
		ancho = 477;
		alto = 526;
	}

	void dibujarCliente(Graphics^ g, Bitmap^ bmpCliente) {
		if (this->estado) {
		Rectangle PorcionAUsar = Rectangle(indiceX*ancho, 0, ancho, alto);
		Rectangle aumento = Rectangle(x, y, 65, 65);
		g->DrawImage(bmpCliente, aumento, PorcionAUsar, GraphicsUnit::Pixel);
		}
	}
	~Cliente() {}

	Rectangle retornarRectagulo() {
		return Rectangle(x, y, 60, 60);
	}
	int getpaciencia() { this->paciencia = paciencia; }
	int getX() { return x; }
	int  getY() { return y; }
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	bool getColision()
	{
		return colision;
	}
	void setColision(bool b)
	{
		colision = b;
	}
};

