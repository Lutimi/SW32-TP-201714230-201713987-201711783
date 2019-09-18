#pragma once
#include "Motor.h"

namespace Project20 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm2
	/// </summary>
	public ref class MyForm2 : public System::Windows::Forms::Form
	{
	private:

		CPersonaje * pj;
	
		float second;
		int segundos;
		Bitmap^bmpHelados = gcnew Bitmap("Imagenes\\Helado.png");
		Bitmap^bmpJugador = gcnew Bitmap("Imagenes\\Personaje2.png");
		Bitmap^bmpMapa = gcnew Bitmap("Imagenes\\Mapa1.png");
		Bitmap^bmpCliente = gcnew Bitmap("Imagenes\\A2.png");

	public:
		Motor * oMotor = new Motor();
		MyForm2(void)
		{
			pj = new CPersonaje();
			segundos = 0;
			bmpHelados->MakeTransparent(bmpHelados->GetPixel(1, 2));
			bmpJugador->MakeTransparent(bmpJugador->GetPixel(1, 2));
			bmpCliente->MakeTransparent(bmpCliente->GetPixel(1, 1));
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  lblNivel;
	protected:
	private: System::Windows::Forms::ProgressBar^  pbcarga;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Timer^  trCarga;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->lblNivel = (gcnew System::Windows::Forms::Label());
			this->pbcarga = (gcnew System::Windows::Forms::ProgressBar());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->trCarga = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// lblNivel
			// 
			this->lblNivel->AutoSize = true;
			this->lblNivel->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblNivel->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->lblNivel->Location = System::Drawing::Point(266, 254);
			this->lblNivel->Name = L"lblNivel";
			this->lblNivel->Size = System::Drawing::Size(69, 24);
			this->lblNivel->TabIndex = 2;
			this->lblNivel->Text = L"Nivel:";
			// 
			// pbcarga
			// 
			this->pbcarga->Location = System::Drawing::Point(270, 299);
			this->pbcarga->Name = L"pbcarga";
			this->pbcarga->Size = System::Drawing::Size(161, 23);
			this->pbcarga->TabIndex = 3;
			this->pbcarga->Click += gcnew System::EventHandler(this, &MyForm2::pbcarga_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 50;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm2::timer1_Tick);
			// 
			// trCarga
			// 
			this->trCarga->Enabled = true;
			this->trCarga->Interval = 600;
			this->trCarga->Tick += gcnew System::EventHandler(this, &MyForm2::trCarga_Tick);
			// 
			// MyForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(704, 701);
			this->Controls->Add(this->pbcarga);
			this->Controls->Add(this->lblNivel);
			this->Name = L"MyForm2";
			this->Text = L"MyForm2";
			this->Load += gcnew System::EventHandler(this, &MyForm2::MyForm2_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm2::MyForm2_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm2::MyForm2_KeyUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		Graphics ^g = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);
		oMotor->dibujar(buffer->Graphics, bmpJugador, bmpMapa,bmpCliente,bmpHelados, oMotor->getoJugador()->getx(), oMotor->getoJugador()->gety());
		this->Text = " Vidas: " + oMotor->getoJugador()->getvidas() + "   Tiempo:   " + (oMotor->gettiempo() / 16) + "  Monedas:   " + oMotor->getoJugador()->getmonedas() + "  Puntaje: " + oMotor->getoJugador()->getentregados() ;
		segundos++;
		ofstream points;
		points.open("game.txt");
		points << "Puntaje: " << oMotor->getoJugador()->getentregados()
			;
		points.close();

		// cargar progreso
				/*int x;
				ifstream points;
				points.open("game.txt");
				while (points>>x)
				{
					segundos = segundos + x;
				}
				points.close();*/
		buffer->Render(g);
		delete buffer, espacio, g;
		if (segundos % 20 == 0)
		{
			oMotor->AddClientes();
		}
		//oMotor->Getlistaclientes()->DibijarClientes(buffer->Graphics, bmpCliente);
		if (segundos % 39 == 0)
		{
			oMotor->addHelados();
		}
		oMotor->colision_Helados();
		oMotor->EliminarA();
		oMotor->EliminarC();



	}
	private: System::Void MyForm2_Load(System::Object^  sender, System::EventArgs^  e) {

	}
	private: System::Void trCarga_Tick(System::Object^  sender, System::EventArgs^  e) {
		lblNivel->Text = "Nivel: " + oMotor->getNivel();
		pbcarga->Increment(50);
		if (trCarga->Interval == 600) {
			
			trCarga->Enabled = false;
			timer1->Enabled = true;

			lblNivel->Visible = false;
			lblNivel->Enabled = false;
			pbcarga->Visible = false;
			pbcarga->Enabled = false;
		}
	}
private: System::Void MyForm2_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	switch (e->KeyCode)
	{
	case Keys::Up:
		oMotor->getoJugador()->setDireccion(DIRECCIONES::Arriba);
		break;
	case Keys::Down:
		oMotor->getoJugador()->setDireccion(DIRECCIONES::Abajo);
		break;
	case Keys::Left:
		oMotor->getoJugador()->setDireccion(DIRECCIONES::Izquierda);
		break;
	case Keys::Right:
		oMotor->getoJugador()->setDireccion(DIRECCIONES::Derecha);
		break;

	}
}
private: System::Void MyForm2_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	switch (e->KeyCode)
	{
	default:
		oMotor->getoJugador()->setDireccion(DIRECCIONES::Normal);
		break;
	}
}
private: System::Void pbcarga_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
