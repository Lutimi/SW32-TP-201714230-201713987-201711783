#pragma once
#include "Escenario.h"
#include "CPersonaje.h"
#include "ListaClientes.h"
#include <stdlib.h>
#include "VecHelados.h"
#include <fstream>
#include <string>
using namespace std;
using namespace System;

class Motor
{
private:

	CPersonaje * oJugador;
	ListaClientes* Lista;
	Escenario * oEscenario;
	VecHelados* oHelados;
	Helados* oHelado;

	int nivel;
	float tiempolevel1;
	bool levelcompletado1;

	bool colision;

public:
	Motor() {
		oJugador = new CPersonaje();
		oEscenario = new Escenario(0, 0, 700, 700);
		nivel = 1;
		Lista = new ListaClientes();  
		oHelados = new VecHelados();
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
	void llevarHelado() {
		for (int i = 0; i < oHelados->Getvec().size(); i++)
		{
			if (oJugador->retornarRectangle().IntersectsWith(oHelados->Getvec().at(i)->retornarRectagulo()))
			{
				oHelados->Getvec().at(i)->sety(oJugador->gety());
				oHelados->Getvec().at(i)->setx(oJugador->getx());
					/*oHelados->Getvec().at(i)->setestado(false);*/
					oJugador->aumentar_bolas();
					/*oHelados->borrarMejoras();*/
					
			}
		}
	}

	void EliminarA()
	{

		if (!oHelados->Getvec().empty())
		{
			vector<Helados*> Copiahelados = oHelados->Getvec();
			vector<Helados*>::iterator it = Copiahelados.begin();
			while (it != Copiahelados.end())
			{
				while (it != Copiahelados.end())
				{
					if ((*it)->getcolision())
					{
						it = Copiahelados.erase(it);
					}
					else
						++it;
				}
				oHelados->setVecHelados(Copiahelados);
		}
	}
	}
	bool Colision(Rectangle a, Rectangle b)
	{
		return a.IntersectsWith(b);
	}
	//void colision_Helados()
	//{
	//	for each (Helados * bal in oHelados->Getvec())
	//	{
	//		for each (Cliente * ast in Lista->getlist())
	//		{
	//			if (Colision(bal->retornarRectagulo(), ast->retornarRectagulo()))
	//			{
	//				
	//				bal->setcolision(true);
	//				ast->setColision(true);
	//				oJugador->aumentar_entregar();
	//				oHelados->BorrarMejoras();
	//				/*Lista->eliminar();*/
	//				
	//			}
	//		}
	//	}
	//}
	void AddClientes() {
		Lista->AgregarClientes();
	}
	void addHelados() {
		oHelados->crearmejoras();
	}
	/*void EliminarC() {

		if (Lista->getlist().empty() == 0)
		{
			list<Cliente*> CopiaClientes = Lista->getlist();
			list<Cliente*>::iterator it = CopiaClientes.begin();
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
		
	void dibujar(Graphics^ g, Bitmap^ bmpJugador, Bitmap^ bmpMapa, Bitmap^ bmpClientes,Bitmap^ bmpHelados, int XP, int YP) {

		oEscenario->dibujar(g, bmpMapa);
		Lista->DibijarClientes(g, bmpClientes);
		oJugador->mover(g, bmpJugador);
		
		oHelados->DibijarMejoras(g, bmpHelados);
		tiempo();
		llevarHelado();
	}

	VecHelados* getVechelados() { return oHelados; }
	CPersonaje *getoJugador() { return oJugador; }
	ListaClientes * Getlistaclientes() { return Lista; }
	int gettiempo() { return this->tiempolevel1; }
	
	int getcolision() { return this->colision; }

};

