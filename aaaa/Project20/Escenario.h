#include "CGraphics.h"
using namespace System::Drawing;

class Escenario : public CImagen
{
private:
	Rectangle areadibujo;
	CImagen * escenario;



public:
	Escenario(Rectangle _areadibujo) : CImagen(areaDibujo){
		this->areaDibujo = _areadibujo;
	}
	~Escenario() {}

	void dibujarE(BufferedGraphics ^buffer, Bitmap^ bm) {
		escenario->dibujar(buffer, bm);
		
	}





};