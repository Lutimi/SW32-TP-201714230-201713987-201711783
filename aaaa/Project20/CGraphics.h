
#pragma once

using namespace System::Drawing;

#pragma once

using namespace System::Drawing;

class CGrafico {
protected:
	Rectangle areaDibujo;
public:
	CGrafico(Rectangle _areaDibujo) {
		this->areaDibujo = _areaDibujo;
	}
	Rectangle getArea() { return this->areaDibujo; }
	Point getPosicion() { return this->areaDibujo.Location; }
	void  setPosicion(Point _origen) { this->areaDibujo.Location = _origen; }
	void dibujar(BufferedGraphics^ _buffer) {
		Pen^ lapicero = gcnew Pen(Color::Red, 5);
		_buffer->Graphics->DrawArc(lapicero, this->areaDibujo, 270, 180);
	}
};
class CImagen : public CGrafico {
public:
	CImagen(Rectangle _areaDibujo) : CGrafico(_areaDibujo) { }
	void hacerTransparente(Bitmap^ _imagen) {
		Color color = _imagen->GetPixel(0, 0);
		_imagen->MakeTransparent(color);
	}
	virtual void dibujar(BufferedGraphics^ _buffer, Bitmap^ _imagen) {
		_buffer->Graphics->DrawImage(_imagen, this->areaDibujo);
	}
};