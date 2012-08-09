#pragma once
#include "Form3.h"
#include "Form1.h"
#include "Form2.h"
#include <windows.h>

namespace Action {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Form4
	/// </summary>
	public ref class Form4 : public System::Windows::Forms::Form
	{
	public:
		Form4(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form4()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  name_label;





	public: System::Windows::Forms::Label^  user_label;
	private: System::Windows::Forms::Button^  previous_button;
	public: 
	private: 
	protected: 

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form4::typeid));
			this->name_label = (gcnew System::Windows::Forms::Label());
			this->user_label = (gcnew System::Windows::Forms::Label());
			this->previous_button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// name_label
			// 
			this->name_label->AutoSize = true;
			this->name_label->BackColor = System::Drawing::Color::Transparent;
			this->name_label->Font = (gcnew System::Drawing::Font(L"Mistral", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->name_label->ForeColor = System::Drawing::Color::DodgerBlue;
			this->name_label->Location = System::Drawing::Point(44, 328);
			this->name_label->Name = L"name_label";
			this->name_label->Size = System::Drawing::Size(97, 38);
			this->name_label->TabIndex = 1;
			this->name_label->Text = L"ACTION";
			// 
			// user_label
			// 
			this->user_label->AutoEllipsis = true;
			this->user_label->AutoSize = true;
			this->user_label->BackColor = System::Drawing::Color::Transparent;
			this->user_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->user_label->ForeColor = System::Drawing::Color::DodgerBlue;
			this->user_label->Location = System::Drawing::Point(566, 343);
			this->user_label->Name = L"user_label";
			this->user_label->Size = System::Drawing::Size(0, 16);
			this->user_label->TabIndex = 10;
			// 
			// previous_button
			// 
			this->previous_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F));
			this->previous_button->ForeColor = System::Drawing::Color::DodgerBlue;
			this->previous_button->Location = System::Drawing::Point(248, 328);
			this->previous_button->Name = L"previous_button";
			this->previous_button->Size = System::Drawing::Size(238, 69);
			this->previous_button->TabIndex = 1;
			this->previous_button->Text = L"Назад";
			this->previous_button->UseVisualStyleBackColor = true;
			this->previous_button->Click += gcnew System::EventHandler(this, &Form4::previous_button_Click);
			this->previous_button->Enter += gcnew System::EventHandler(this, &Form4::previous_button_Enter);
			this->previous_button->Leave += gcnew System::EventHandler(this, &Form4::previous_button_Leave);
			// 
			// Form4
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(719, 424);
			this->Controls->Add(this->previous_button);
			this->Controls->Add(this->user_label);
			this->Controls->Add(this->name_label);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Form4";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Form4";
			this->TransparencyKey = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Form4::Form4_FormClosed);
			this->Load += gcnew System::EventHandler(this, &Form4::Form4_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void previous_button_Enter(System::Object^  sender, System::EventArgs^  e)
		 {
			 previous_button->ForeColor = Color::Green;
			 
			 previous_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				 static_cast<System::Byte>(204)));
		 }
private: System::Void previous_button_Leave(System::Object^  sender, System::EventArgs^  e) 
		 {
			previous_button->ForeColor = Color::DodgerBlue;
			 
			previous_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				 static_cast<System::Byte>(204)));
		 }
private: System::Void previous_button_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void Form4_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e);
private: System::Void Form4_Load(System::Object^  sender, System::EventArgs^  e)
		 {
			 user_label->Text = Form1::global_username;
		 }
};
}
