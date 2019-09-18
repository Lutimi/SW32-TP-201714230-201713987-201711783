#include "CGraphics.h"
using namespace System::Drawing;

class Escenario : public CGraphics
{
private:




public:
	Escenario(int x, int y, int w, int h) : CGraphics(x, y, w, h) {}

	~Escenario() {}

	void dibujar(Graphics^ g, Bitmap^ bm) {
		bm = gcnew Bitmap("Imagenes/Mapa1.png");
		g->DrawImage(bm, this->x, this->y, this->w, this->h);
		delete bm;
	}





};