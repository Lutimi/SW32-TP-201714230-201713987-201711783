#pragma once
#include "Motor.h"
#include <cmath> 
namespace Project20 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Xml;

	/// <summary>
	/// Summary for MyForm2
	/// </summary>
	public ref class MyForm2 : public System::Windows::Forms::Form
	{
	private:
		BufferedGraphicsContext^ espacioBuffer;
		Graphics^ graficador;
		BufferedGraphics^ buffer;
		CPersonaje * pj;
	
		float second;
		int segundos;
		Bitmap^bmpHelados = gcnew Bitmap("Imagenes\\Helado.png");
		Bitmap^bmpJugador = gcnew Bitmap("Imagenes\\Personaje2.png");
		Bitmap^bmpMapa = gcnew Bitmap("Imagenes\\Mapa1.png");
		Bitmap^bmpCliente = gcnew Bitmap("Imagenes\\A2.png");
		Bitmap^bmpDinero = gcnew Bitmap("Imagenes\\dinero.png");
	private: System::Windows::Forms::Button^  btn_nuevo;
	private: System::Windows::Forms::Button^  btn_reanudar;
	private: System::Windows::Forms::Button^  btn_guardar;
	private: System::Windows::Forms::Button^  btn_cargar;
			 Motor * oMotor;
	public:
		
		MyForm2(void)
		{
			InitializeComponent();
			this->espacioBuffer = BufferedGraphicsManager::Current;
			this->graficador = this->CreateGraphics();
			this->buffer = espacioBuffer->Allocate(this->graficador, this->ClientRectangle);
			oMotor = new Motor(this->ClientRectangle);
			pj = new CPersonaje();
			segundos = 0;
			bmpHelados->MakeTransparent(bmpHelados->GetPixel(1, 2));
			bmpJugador->MakeTransparent(bmpJugador->GetPixel(1, 2));
			bmpCliente->MakeTransparent(bmpCliente->GetPixel(1, 1));
			bmpDinero->MakeTransparent(bmpCliente->GetPixel(1, 1));
		
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
			this->lblNivel = (gcnew System::Windows::Forms::Label());//holaa
			this->pbcarga = (gcnew System::Windows::Forms::ProgressBar());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->trCarga = (gcnew System::Windows::Forms::Timer(this->components));
			this->btn_nuevo = (gcnew System::Windows::Forms::Button());
			this->btn_reanudar = (gcnew System::Windows::Forms::Button());
			this->btn_guardar = (gcnew System::Windows::Forms::Button());
			this->btn_cargar = (gcnew System::Windows::Forms::Button());
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
			// btn_nuevo
			// 
			this->btn_nuevo->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btn_nuevo->Location = System::Drawing::Point(90, 156);
			this->btn_nuevo->Name = L"btn_nuevo";
			this->btn_nuevo->Size = System::Drawing::Size(95, 23);
			this->btn_nuevo->TabIndex = 4;
			this->btn_nuevo->Text = L"Nueva Partida";
			this->btn_nuevo->UseVisualStyleBackColor = true;
			this->btn_nuevo->Click += gcnew System::EventHandler(this, &MyForm2::btn_nuevo_Click);
			// 
			// btn_reanudar
			// 
			this->btn_reanudar->Enabled = false;
			this->btn_reanudar->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btn_reanudar->Location = System::Drawing::Point(217, 156);
			this->btn_reanudar->Name = L"btn_reanudar";
			this->btn_reanudar->Size = System::Drawing::Size(75, 23);
			this->btn_reanudar->TabIndex = 5;
			this->btn_reanudar->Text = L"Reanudar";
			this->btn_reanudar->UseVisualStyleBackColor = true;
			this->btn_reanudar->Visible = false;
			this->btn_reanudar->Click += gcnew System::EventHandler(this, &MyForm2::btn_reanudar_Click);
			// 
			// btn_guardar
			// 
			this->btn_guardar->Enabled = false;
			this->btn_guardar->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btn_guardar->Location = System::Drawing::Point(318, 156);
			this->btn_guardar->Name = L"btn_guardar";
			this->btn_guardar->Size = System::Drawing::Size(75, 23);
			this->btn_guardar->TabIndex = 6;
			this->btn_guardar->Text = L"Guardar";
			this->btn_guardar->UseVisualStyleBackColor = true;
			this->btn_guardar->Visible = false;
			this->btn_guardar->Click += gcnew System::EventHandler(this, &MyForm2::btn_guardar_Click);
			// 
			// btn_cargar
			// 
			this->btn_cargar->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btn_cargar->Location = System::Drawing::Point(432, 156);
			this->btn_cargar->Name = L"btn_cargar";
			this->btn_cargar->Size = System::Drawing::Size(95, 23);
			this->btn_cargar->TabIndex = 7;
			this->btn_cargar->Text = L"Cargar Partida";
			this->btn_cargar->UseVisualStyleBackColor = true;
			// 
			// MyForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(704, 701);
			this->Controls->Add(this->btn_cargar);
			this->Controls->Add(this->btn_guardar);
			this->Controls->Add(this->btn_reanudar);
			this->Controls->Add(this->btn_nuevo);
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

		oMotor->dibujar(buffer, bmpDinero, bmpJugador, bmpMapa, bmpCliente, bmpHelados, oMotor->getoJugador()->getx(), oMotor->getoJugador()->gety());
		this->Text = " Vidas: " + oMotor->getoJugador()->getvidas() + "   Tiempo:   " + (oMotor->gettiempo() / 16) + "  Monedas:   " + oMotor->getoJugador()->getmonedas() + "  Puntaje: " + oMotor->getoJugador()->getentregados()+ "  Cola:   " + oMotor->getcontadorC();
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
		
		if (segundos % 50 == 0)
		{
			oMotor->AddClientes();
			oMotor->addHelados();
			oMotor->adddinero();
		
		}
		
		/*if (segundos % 50 == 0)
		{
			
		}*/
		
		
		buffer->Render();



	}
				private: void cargar_archivo_puntaje() {
					XmlWriter^ archivo = XmlWriter::Create("Datos.xml");
					//archivo->WriteStartElement("GuardadoX");
					//archivo->WriteString(this->jugador->getX().ToString());
					archivo->WriteStartElement("Puntaje");
					archivo->WriteString(this->oMotor->getoJugador()->getentregados().ToString());
					archivo->WriteEndElement();
					archivo->WriteEndDocument();
					archivo->Close();
					delete archivo;
				}
	private: void cargar_archivo_vidas() {
		XmlWriter^ archivo1 = XmlWriter::Create("Life.xml");
		archivo1->WriteStartElement("Vidas");
		archivo1->WriteString(this->oMotor->getoJugador()->getvidas().ToString());
		archivo1->WriteEndElement();
		archivo1->WriteEndDocument();
		archivo1->Close();
		delete archivo1;
	}

	private: System::Void MyForm2_Load(System::Object^  sender, System::EventArgs^  e) {

	}
	private: System::Void trCarga_Tick(System::Object^  sender, System::EventArgs^  e) {
		lblNivel->Text = "Nivel: " + oMotor->getNivel();
		/*pbcarga->Increment(50);
		if (trCarga->Interval == 600) {
			
			trCarga->Enabled = false;
			timer1->Enabled = true;

			lblNivel->Visible = false;
			lblNivel->Enabled = false;
			pbcarga->Visible = false;
			pbcarga->Enabled = false;
		}*/
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
	case Keys::P: this->timer1->Enabled = false;
		this->btn_reanudar->Visible = true;
		this->btn_guardar->Visible = true;
		this->btn_guardar->Enabled = true;
		this->btn_reanudar->Enabled = true;
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
private: System::Void btn_nuevo_Click(System::Object^  sender, System::EventArgs^  e) {
		this->btn_nuevo->Enabled = false;
	this->btn_cargar->Enabled = false;
	this->btn_nuevo->Visible = false;
	this->btn_cargar->Visible = false;
	this->timer1->Enabled = true;
	//this->timer2->Enabled = true;
	lblNivel->Visible = false;
	lblNivel->Enabled = false;
	pbcarga->Visible = false;
	pbcarga->Enabled = false;
}
private: System::Void btn_reanudar_Click(System::Object^  sender, System::EventArgs^  e) {
	this->btn_guardar->Enabled = false;
	this->btn_reanudar->Enabled = false;
	this->btn_guardar->Visible = false;
	this->btn_reanudar->Visible = false;
	this->timer1->Enabled = true;
}
private: System::Void btn_guardar_Click(System::Object^  sender, System::EventArgs^  e) {
	this->btn_guardar->Enabled = false;
	this->btn_reanudar->Enabled = false;
	this->btn_guardar->Visible = false;
	this->btn_reanudar->Visible = false;
	this->cargar_archivo_puntaje();
	this->cargar_archivo_vidas();
	this->Close();
}
};
}
