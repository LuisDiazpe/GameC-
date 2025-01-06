#pragma once
#include"MyForm.h"
namespace Project18 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de pantalla
	/// </summary>
	public ref class pantalla : public System::Windows::Forms::Form
	{
	public:
		pantalla(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~pantalla()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ Jugar;
	protected:

	private: System::Windows::Forms::Button^ Creditos;
	protected:

	private: System::Windows::Forms::Button^ Salir;


	private: System::Windows::Forms::Button^ Instrucciones;


	private: System::Windows::Forms::PictureBox^ pcb_credits;
	private: System::Windows::Forms::PictureBox^ pcb_instructions;
	private: System::Windows::Forms::Button^ btn_return;
	private: System::Windows::Forms::Button^ btn_false_ins;





	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(pantalla::typeid));
			this->Jugar = (gcnew System::Windows::Forms::Button());
			this->Creditos = (gcnew System::Windows::Forms::Button());
			this->Salir = (gcnew System::Windows::Forms::Button());
			this->Instrucciones = (gcnew System::Windows::Forms::Button());
			this->pcb_credits = (gcnew System::Windows::Forms::PictureBox());
			this->pcb_instructions = (gcnew System::Windows::Forms::PictureBox());
			this->btn_return = (gcnew System::Windows::Forms::Button());
			this->btn_false_ins = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pcb_credits))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pcb_instructions))->BeginInit();
			this->SuspendLayout();
			// 
			// Jugar
			// 
			this->Jugar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Jugar->Location = System::Drawing::Point(507, 139);
			this->Jugar->Name = L"Jugar";
			this->Jugar->Size = System::Drawing::Size(192, 56);
			this->Jugar->TabIndex = 0;
			this->Jugar->Text = L"Jugar";
			this->Jugar->UseVisualStyleBackColor = true;
			this->Jugar->Click += gcnew System::EventHandler(this, &pantalla::Jugar_Click);
			// 
			// Creditos
			// 
			this->Creditos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Creditos->Location = System::Drawing::Point(507, 241);
			this->Creditos->Name = L"Creditos";
			this->Creditos->Size = System::Drawing::Size(187, 57);
			this->Creditos->TabIndex = 1;
			this->Creditos->Text = L"Créditos";
			this->Creditos->UseVisualStyleBackColor = true;
			this->Creditos->Click += gcnew System::EventHandler(this, &pantalla::Creditos_Click);
			// 
			// Salir
			// 
			this->Salir->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Salir->Location = System::Drawing::Point(507, 440);
			this->Salir->Name = L"Salir";
			this->Salir->Size = System::Drawing::Size(187, 61);
			this->Salir->TabIndex = 2;
			this->Salir->Text = L"Salir";
			this->Salir->UseVisualStyleBackColor = true;
			this->Salir->Click += gcnew System::EventHandler(this, &pantalla::Salir_Click);
			// 
			// Instrucciones
			// 
			this->Instrucciones->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Instrucciones->Location = System::Drawing::Point(507, 336);
			this->Instrucciones->Name = L"Instrucciones";
			this->Instrucciones->Size = System::Drawing::Size(187, 61);
			this->Instrucciones->TabIndex = 0;
			this->Instrucciones->Text = L"Instrucciones";
			this->Instrucciones->UseVisualStyleBackColor = true;
			this->Instrucciones->Click += gcnew System::EventHandler(this, &pantalla::Instrucciones_Click);
			// 
			// pcb_credits
			// 
			this->pcb_credits->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pcb_credits.Image")));
			this->pcb_credits->Location = System::Drawing::Point(0, 0);
			this->pcb_credits->Name = L"pcb_credits";
			this->pcb_credits->Size = System::Drawing::Size(757, 560);
			this->pcb_credits->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pcb_credits->TabIndex = 8;
			this->pcb_credits->TabStop = false;
			// 
			// pcb_instructions
			// 
			this->pcb_instructions->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pcb_instructions.Image")));
			this->pcb_instructions->Location = System::Drawing::Point(0, 0);
			this->pcb_instructions->Name = L"pcb_instructions";
			this->pcb_instructions->Size = System::Drawing::Size(757, 560);
			this->pcb_instructions->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pcb_instructions->TabIndex = 9;
			this->pcb_instructions->TabStop = false;
			// 
			// btn_return
			// 
			this->btn_return->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btn_return->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_return->ForeColor = System::Drawing::Color::White;
			this->btn_return->Location = System::Drawing::Point(12, 473);
			this->btn_return->Name = L"btn_return";
			this->btn_return->Size = System::Drawing::Size(143, 31);
			this->btn_return->TabIndex = 10;
			this->btn_return->Text = L"VOLVER";
			this->btn_return->UseVisualStyleBackColor = false;
			this->btn_return->Click += gcnew System::EventHandler(this, &pantalla::btn_return_Click_1);
			// 
			// btn_false_ins
			// 
			this->btn_false_ins->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btn_false_ins->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_false_ins->ForeColor = System::Drawing::Color::White;
			this->btn_false_ins->Location = System::Drawing::Point(584, 473);
			this->btn_false_ins->Name = L"btn_false_ins";
			this->btn_false_ins->Size = System::Drawing::Size(143, 31);
			this->btn_false_ins->TabIndex = 11;
			this->btn_false_ins->Text = L"VOLVER";
			this->btn_false_ins->UseVisualStyleBackColor = false;
			this->btn_false_ins->Click += gcnew System::EventHandler(this, &pantalla::btn_false_ins_Click_1);
			// 
			// pantalla
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(739, 513);
			this->Controls->Add(this->btn_false_ins);
			this->Controls->Add(this->btn_return);
			this->Controls->Add(this->pcb_instructions);
			this->Controls->Add(this->pcb_credits);
			this->Controls->Add(this->Instrucciones);
			this->Controls->Add(this->Salir);
			this->Controls->Add(this->Creditos);
			this->Controls->Add(this->Jugar);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"pantalla";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"pantalla";
			this->Load += gcnew System::EventHandler(this, &pantalla::pantalla_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pcb_credits))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pcb_instructions))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void pantalla_Load(System::Object^ sender, System::EventArgs^ e) {
		pcb_credits->Visible = false;
		pcb_instructions->Visible = false;
		btn_return->Visible = false;
		btn_return->Enabled = false;
		btn_false_ins->Visible = false;
		btn_false_ins->Enabled = true;
	}
	private: System::Void Salir_Click(System::Object^ sender, System::EventArgs^ e) {
		if (MessageBox::Show("¿Está seguro de que desea salir?", "Confirmar salida", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
			this->Close(); // Cerrar el formulario
		}
	}
	private: System::Void Jugar_Click(System::Object^ sender, System::EventArgs^ e) {
		MyForm^ myform = gcnew MyForm(); // Crear el formulario
		this->Visible = false; // Ocultar el formulario actual
		myform->ShowDialog(); // Mostrar el formulario
		this->Visible = true; // Mostrar el formulario actual
	}
	private: System::Void Creditos_Click(System::Object^ sender, System::EventArgs^ e) {
		pcb_credits->Visible = true;
		btn_return->Enabled = true;
		btn_return->Visible = true;
	}
	private: System::Void btn_return_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
	private: System::Void Instrucciones_Click(System::Object^ sender, System::EventArgs^ e) {
		btn_false_ins->Visible = true;
		btn_false_ins->Enabled = true;
		pcb_instructions->Visible = true;
	}
	private: System::Void btn_false_ins_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
	private: System::Void btn_return_Click_1(System::Object^ sender, System::EventArgs^ e) {
		pcb_credits->Visible = false;
		btn_return->Visible = false;
		btn_return->Enabled = false;
	}
	private: System::Void btn_false_ins_Click_1(System::Object^ sender, System::EventArgs^ e) {
		pcb_instructions->Visible = false;
		btn_false_ins->Visible = false;
	}
};
}
