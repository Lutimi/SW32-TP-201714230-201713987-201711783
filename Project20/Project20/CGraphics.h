
#pragma once

using namespace System::Drawing;

class CGraphics
{
public:
	CGraphics(int x, int y, int w, int h);
	~CGraphics();
	virtual void dibujar(Graphics^ g, Bitmap^ bm) = 0;
	int getx();
	int gety();
	int getw();
	int geth();
	void setx(int value);
	void sety(int value);
	void setw(int value);
	void seth(int value);

protected:
	int x, y, w, h;
};

CGraphics::CGraphics(int x, int y, int w, int h) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}
CGraphics::~CGraphics() {}

int CGraphics::getx() { return this->x; }
int CGraphics::gety() { return this->y; }
int CGraphics::getw() { return this->w; }
int CGraphics::geth() { return this->h; }

void CGraphics::setx(int value) { this->x = value; }
void CGraphics::sety(int value) { this->y = value; }
void CGraphics::setw(int value) { this->w = value; }
void CGraphics::seth(int value) { this->h = value; }