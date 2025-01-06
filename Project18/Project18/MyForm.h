#pragma once
#include "Juego.h"
namespace Project18 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		Juego* juego;
		Bitmap^ bmpObstaculo = gcnew Bitmap("img/Pared1.png");
		Bitmap^ bmpPersonaje = gcnew Bitmap("img/Monachina.png");
		Bitmap^ bmpEnemigo = gcnew Bitmap("img/Enemigo.png");
		Bitmap^ bmpAliado = gcnew Bitmap("img/Ayudante_1.png");
		Bitmap^ bmpBullet = gcnew Bitmap("img/Pokebola.png");
	public:
		MyForm(void)
		{
			InitializeComponent();
			
			juego = new Juego(6, 4, 100, bmpObstaculo, bmpPersonaje, bmpEnemigo, bmpAliado, bmpBullet);
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components){
				delete components;
			} 
			delete juego;
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 33;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(614, 360);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(Object^ sender, EventArgs^ e) {
		// Crear el buffer gráfico
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ bfc = BufferedGraphicsManager::Current;
		BufferedGraphics^ bf = bfc->Allocate(g, this->ClientRectangle);

		bf->Graphics->Clear(Color::White);

		// Mostrar todos los elementos del juego (jugador, enemigos, obstáculos, etc.)
		juego->Mostrar(bf->Graphics, bmpObstaculo, bmpPersonaje, bmpEnemigo, bmpAliado, bmpBullet);

			// Mover balas y otros objetos del juego
			if (juego->Mover(bf->Graphics, Keys::None, bmpBullet) == false) {
				this->Close();  // Cerrar el juego si ha terminado
			}

		// Renderizar el buffer gráfico en la pantalla
		bf->Render(g);

		delete bf;
		delete g;
	}

	private: System::Void MyForm_KeyDown(Object^ sender, KeyEventArgs^ e) {
		juego->MovimientoJugador(true, e->KeyCode, bmpPersonaje,bmpBullet);

		switch (e->KeyCode)
		{
		case Keys::Escape:
			if (MessageBox::Show("¿Está seguro de que desea salir?", "Confirmar salida", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
				this->Close(); // Cerrar el formulario
			}
			break;
		case Keys::P:
			timer1->Enabled = false;
			break;
		case Keys::R:
			timer1->Enabled = true;
			break;
		}
	}
	private: System::Void MyForm_KeyUp(Object^ sender, KeyEventArgs^ e) {
		juego->MovimientoJugador(false, e->KeyCode, bmpPersonaje, bmpBullet);
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
