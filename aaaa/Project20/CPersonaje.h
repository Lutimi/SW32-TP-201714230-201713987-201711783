using namespace System;
using namespace System::Drawing;
enum DIRECCIONES {Arriba,Abajo, Izquierda, Derecha, Normal };
typedef unsigned short ushort;
class CPersonaje
{
private:
	int x;
	int y;
	int dx;
	int dy;
	int alto;
	int ancho;
	int IX;
	int IY;
	ushort helado;
	DIRECCIONES direccion;
	DIRECCIONES direccion_ultima;

	Rectangle CDI;
	Rectangle CAA;
	int vidas;
	bool invulnerabilidad;
	int monedas;
	int entregados;
	int bolas;
public:
	
	CPersonaje(){
		bolas = 0;
	x=200;
	y= 150;
	this->invulnerabilidad = false;
	dx = 0;
	dy = 0;
	alto = 599;
	ancho = 400;
	entregados = 0;
	IX = 0;
	IY = 0;

	direccion=DIRECCIONES::Normal;
	direccion_ultima = DIRECCIONES::Abajo;
	monedas = 0;
	vidas = 5;
	}
	~CPersonaje(){}
	int getvidas() { return vidas; }
	void Setvidas(int vidas) { this->vidas = vidas; }
	int getmonedas() { return monedas; }
	void Setmonedas(int monedas) { this->monedas = monedas; }
	
	void aumentar_monedas() {
		monedas++;
	}
	void disminuirvidas(){
		
		vidas--;
		x = 90;
		y = 90;
	}
	void bug() {
		x = 73;
		y = 73;
	}

	void aumentar_bolas() {
		bolas++;
}
	void aumentar_entregar() {
		entregados++;
	}

	Rectangle retornarRectangle() {
		return Rectangle(x + 2 / 12 + dx, y + 15 / 14, (ancho - 4) / 14, (alto - 15) / 15);
	}

	void dibujar(BufferedGraphics^ buffer, Bitmap^ bmpPersonaje) {
		
		CDI = Rectangle(x + 2/12 + dx, y + 15 /14, (ancho -4 ) / 14, (alto - 15) / 15);
		CAA = Rectangle(x + 2 /12, y + 15 /14 + dy, (ancho - 4) / 14, (alto - 15) / 15);
		buffer->Graphics->DrawRectangle(Pens::Transparent, CDI);
		buffer->Graphics->DrawRectangle(Pens::Transparent, CAA);

		

		Rectangle PortionToUse = Rectangle(IX*ancho, IY*alto, ancho, alto);
		Rectangle Aumento = Rectangle(x, y, ancho/8, alto/10);
		buffer->Graphics->DrawImage(bmpPersonaje, Aumento, PortionToUse, GraphicsUnit::Pixel);
		x += dx;
		y += dy;

	}
	void mover(BufferedGraphics ^ buffer, Bitmap^ bmpPersonaje) {

		
		switch (direccion)
		{
		case DIRECCIONES::Arriba:
			IY = 1;
			if (IX >= 0 && IX < 3)
				IX++;
			else
				IX = 0;
			if (y < 70|| x + dx + ancho / 14 >= 632||x <70){
				dy = 0;
			dx = 0;
			}
			else
				dy = -10; 
			direccion_ultima = Arriba;
			break;
		case DIRECCIONES::Abajo:
			IY = 0;
			if (IX >= 0 && IX < 3)
				IX++;
			else
				IX = 0;
			if (y + dy + (alto/14) >= buffer->Graphics->VisibleClipBounds.Height - 60 || x+dx+ancho/14 >=632|| x < 70)
			{
				dx = 0;
				dy = 0;
			}
			else
			{
				dy = 10;

			}			
			direccion_ultima = Abajo;
			break;
		case DIRECCIONES::Derecha:
			IY = 3;
			if (IX >= 0 && IX < 3)
				IX++;
			else
				IX = 1;
		
			if (x  + dx+ancho/12 >= 632|| y + dy + (alto / 14) >= buffer->Graphics->VisibleClipBounds.Height - 60|| y < 70)
			{
				dx = 0;
				dy = 0;
			}
			else
				dx = 10;
			direccion_ultima = Derecha;
			break;

		case DIRECCIONES::Izquierda:
			IY = 2;
			if (IX >= 0 && IX < 3)
				IX++;
			else
				IX = 1;
			if (x < 70|| y + dy + (alto / 14) >= buffer->Graphics->VisibleClipBounds.Height - 60|| y < 70)
			{ 
				dx = 0;
			dy = 0;
		}
			else
				dx = -10;

			
			direccion_ultima = Izquierda;
			break;

		case DIRECCIONES::Normal:
			dx = dy = 0;
			if (direccion_ultima==DIRECCIONES::Abajo)
			{
				IX = 2;
				IY = 0;
			}
			if (direccion_ultima == DIRECCIONES::Arriba)
			{
				IX = 2;
				IY = 1;
			}

			if (direccion_ultima == DIRECCIONES::Izquierda)
			{
				IX = 2;
				IY = 2;
			}

			if (direccion_ultima == DIRECCIONES::Derecha)
			{
				IX = 1;
				IY = 3;
			}



		}

		dibujar(buffer,bmpPersonaje);
	}
	bool getinvulnerabilidad() { return this->invulnerabilidad; }
	void setinvulnerabilidad(bool invulnerabilidad) { this->invulnerabilidad = invulnerabilidad; }


	void setDireccion(DIRECCIONES direccion) {
		this->direccion=direccion;
	}
	int getbolas() { return this->bolas; }
	int getx() { return this->x; }
	int gety() { return this->y; }
	void setx(int x) { this->x = x; }
	void sety(int y) { this->y = y; }
	int getentregados() { return this->entregados; }
	
};	  
