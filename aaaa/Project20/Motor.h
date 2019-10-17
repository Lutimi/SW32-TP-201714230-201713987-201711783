#pragma once
#include "Escenario.h"
#include "CPersonaje.h"
#include <stdlib.h>
#include <fstream>
#include <string>
#include "Lista.h"
#include "Helados.h"
#include "CCliente.h"
#include "Cola.h"
using namespace std;
using namespace System;

class Motor
{
private:

	CPersonaje * oJugador;
	Escenario * oEscenario;
	Lista<Cliente*>* lluviadeclientes;
	Lista<Helados*>* lluviadehelados;
	Cola<Helados*>* guardarhelados;



	int nivel;
	float tiempolevel1;
	bool levelcompletado1;

	bool colision;

public:
	Motor(Rectangle areadibujo) {
		oEscenario = new Escenario(areadibujo);
		oJugador = new CPersonaje();
		lluviadehelados = new Lista<Helados*>();
		lluviadeclientes = new Lista<Cliente*>();
		guardarhelados = new Cola<Helados*>();


		
		nivel = 1;
	 
		tiempolevel1 = 0;
		this->colision = true;


	}
	~Motor() {}
	int getNivel() { return nivel; }
	void setNivel(int nivel) { this->nivel = nivel; }
	void tiempo() {

		tiempolevel1++;
	}

	void arreglobug() {
		if (oJugador->getx() == 70 && oJugador->gety() == 70 || oJugador->getx() == 69 && oJugador->gety() == 69)
		{
			oJugador->bug();
		}

	}
	void llevarHelado(Lista<Helados*>* _lluviadehelados) {
		for (int i = 0; i < _lluviadehelados->longitud(); i++)
		{
			if (oJugador->retornarRectangle().IntersectsWith(_lluviadehelados->obtenerPos(i)->retornarRectagulo()))
			{
				_lluviadehelados->obtenerPos(i)->sety(oJugador->gety());
				_lluviadehelados->obtenerPos(i)->setx(oJugador->getx());
				
				

			}
		}
	}

	void colisionC(Lista<Cliente*>* _lluviadeclientes, Lista<Helados*>* _lluviadehelados) {
		for (int i = 0; i < _lluviadeclientes->longitud(); i++){
			if (oJugador->retornarRectangle().IntersectsWith(_lluviadeclientes->obtenerPos(i)->retornarRectangulo()))
			{
				_lluviadeclientes->eliminaPos(i);
				_lluviadehelados->eliminaFinal();

			}
				
			}
		}
	
	
	bool Colision(Rectangle a, Rectangle b)
	{
		return a.IntersectsWith(b);
	}
	/*void colision_Helados()
	{
		for each (Helados * bal in oHelados->Getvec())
		{
			for each (Cliente * ast in Lista->getlist())
			{
				if (Colision(bal->retornarRectagulo(), ast->retornarRectagulo()))
				{

					bal->setcolision(true);
					ast->setColision(true);
					oJugador->aumentar_entregar();
					oHelados->BorrarMejoras();*/
					/*Lista->eliminar();*/

	//			}
	//		}
	//	}
	//}
	void AddClientes() {

		lluviadeclientes->agregaInicial(new Cliente());
		
		
	}

	
	void addHelados() {
		lluviadehelados->agregaInicial(new Helados);
			
	}
	/*void EliminarC() {

		if (Lista->vacia() == 0)
		{
			Lista<Cliente*> CopiaClientes = Lista->getlist();
			Lista<Cliente*>::iterator it = CopiaClientes.begin();
			while (it != CopiaClientes.end())
			{
				if ((*it)->getColision())
				{
					it = CopiaClientes.erase(it);
				}
				else
					++it;
			}
			Lista->setVecclientes(CopiaClientes);
		}
	}*/
	/*void entregarhelado() {




	}*/
		
	void dibujar(BufferedGraphics^buffer, Bitmap^ bmpJugador, Bitmap^ bmpMapa, Bitmap^ bmpClientes,Bitmap^ bmpHelados, int XP, int YP) {

		oEscenario->dibujar(buffer, bmpMapa);
		oJugador->mover(buffer, bmpJugador);
		DibujarH(buffer, bmpHelados);
		DibujarC(buffer, bmpClientes);
		llevarHelado(lluviadehelados);
		colisionC(lluviadeclientes, lluviadehelados);
		tiempo();
		
	}

	void DibujarH(BufferedGraphics ^buffer, Bitmap^ bmphelado) {
		for (int i = 0; i < lluviadehelados->longitud(); i++) {

			switch (lluviadehelados->obtenerPos(i)->getEstado1()) {
			case Estado::normal:
				lluviadehelados->obtenerPos(i)->dibujar(buffer, bmphelado);
				break;
			case Estado::desaparecer:
				/*lluviadehelados->eliminaPos(i);*/
				break;
			}
		}
	}
	void DibujarC(BufferedGraphics ^buffer, Bitmap^ bmpcliente) {
		for (int i = 0; i < lluviadeclientes->longitud(); i++) {

			switch (lluviadeclientes->obtenerPos(i)->getEstado1()) {
			case Estado::normal:
				lluviadeclientes->obtenerPos(i)->dibujarCliente(buffer, bmpcliente);
				break;
			case Estado::desaparecer:
				lluviadeclientes->eliminaPos(i);
				break;
			}
		}
	}
	void DibujarClientes(BufferedGraphics ^ buffer, Bitmap^ bmpCliente) {

		for (Cliente *a : *lluviadeclientes) {

			a->dibujarCliente(buffer, bmpCliente);
		}

	}
	/*ListaHelados* getVechelados() { return oHelados; }*/
	CPersonaje *getoJugador() { return oJugador; }
	/*Lista * Getlistaclientes() { return lluviadeclientes; }*/
	int gettiempo() { return this->tiempolevel1; }
	
	int getcolision() { return this->colision; }

};

