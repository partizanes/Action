#pragma once
#include "Form1.h"
#include "Form2.h"
#include "Form3.h"
#include <windows.h>

namespace Action {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Form3
	/// </summary>
	public ref class Form3 : public System::Windows::Forms::Form
	{
	public:
		Form3(void)
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
		~Form3()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Label^  user_label;
	private: System::Windows::Forms::Button^  balance_button;
	private: System::Windows::Forms::Button^  priority_button;
	public: System::Windows::Forms::Button^  settings_button;
	private: 

	private: 

	public: 

	public: 

	public: 





	private: System::Windows::Forms::Button^  logout_button;


	private: System::Windows::Forms::Label^  name_label;
	public: static System::Windows::Forms::Button^  write_action_button;
	private: Point mouseOffset2;

	protected: 

	protected: 

	protected: 

	protected: 

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form3::typeid));
			this->user_label = (gcnew System::Windows::Forms::Label());
			this->balance_button = (gcnew System::Windows::Forms::Button());
			this->priority_button = (gcnew System::Windows::Forms::Button());
			this->settings_button = (gcnew System::Windows::Forms::Button());
			this->write_action_button = (gcnew System::Windows::Forms::Button());
			this->logout_button = (gcnew System::Windows::Forms::Button());
			this->name_label = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// user_label
			// 
			this->user_label->AutoEllipsis = true;
			this->user_label->AutoSize = true;
			this->user_label->BackColor = System::Drawing::Color::Transparent;
			this->user_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->user_label->ForeColor = System::Drawing::Color::DodgerBlue;
			this->user_label->Location = System::Drawing::Point(625, 19);
			this->user_label->Name = L"user_label";
			this->user_label->Size = System::Drawing::Size(0, 16);
			this->user_label->TabIndex = 0;
			// 
			// balance_button
			// 
			this->balance_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->balance_button->ForeColor = System::Drawing::Color::DodgerBlue;
			this->balance_button->Location = System::Drawing::Point(29, 28);
			this->balance_button->Name = L"balance_button";
			this->balance_button->Size = System::Drawing::Size(238, 69);
			this->balance_button->TabIndex = 1;
			this->balance_button->Text = L"Остатки";
			this->balance_button->UseVisualStyleBackColor = true;
			this->balance_button->Enter += gcnew System::EventHandler(this, &Form3::balance_button_Enter);
			this->balance_button->Leave += gcnew System::EventHandler(this, &Form3::balance_button_Leave);
			// 
			// priority_button
			// 
			this->priority_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F));
			this->priority_button->ForeColor = System::Drawing::Color::DodgerBlue;
			this->priority_button->Location = System::Drawing::Point(113, 103);
			this->priority_button->Name = L"priority_button";
			this->priority_button->Size = System::Drawing::Size(238, 69);
			this->priority_button->TabIndex = 2;
			this->priority_button->Text = L"Очерёдность";
			this->priority_button->UseVisualStyleBackColor = true;
			this->priority_button->Enter += gcnew System::EventHandler(this, &Form3::priority_button_Enter);
			this->priority_button->Leave += gcnew System::EventHandler(this, &Form3::priority_button_Leave);
			// 
			// settings_button
			// 
			this->settings_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F));
			this->settings_button->ForeColor = System::Drawing::Color::DodgerBlue;
			this->settings_button->Location = System::Drawing::Point(343, 253);
			this->settings_button->Name = L"settings_button";
			this->settings_button->Size = System::Drawing::Size(238, 69);
			this->settings_button->TabIndex = 4;
			this->settings_button->Text = L"Настройка";
			this->settings_button->UseVisualStyleBackColor = true;
			this->settings_button->Click += gcnew System::EventHandler(this, &Form3::settings_button_Click);
			this->settings_button->Enter += gcnew System::EventHandler(this, &Form3::settings_button_Enter);
			this->settings_button->Leave += gcnew System::EventHandler(this, &Form3::settings_button_Leave);
			// 
			// write_action_button
			// 
			this->write_action_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->write_action_button->ForeColor = System::Drawing::Color::DodgerBlue;
			this->write_action_button->Location = System::Drawing::Point(229, 178);
			this->write_action_button->Name = L"write_action_button";
			this->write_action_button->Size = System::Drawing::Size(238, 69);
			this->write_action_button->TabIndex = 3;
			this->write_action_button->Text = L"Акции";
			this->write_action_button->UseVisualStyleBackColor = true;
			this->write_action_button->Click += gcnew System::EventHandler(this, &Form3::write_action_button_Click);
			this->write_action_button->Enter += gcnew System::EventHandler(this, &Form3::write_action_button_Enter);
			this->write_action_button->Leave += gcnew System::EventHandler(this, &Form3::write_action_button_Leave);
			// 
			// logout_button
			// 
			this->logout_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F));
			this->logout_button->ForeColor = System::Drawing::Color::DodgerBlue;
			this->logout_button->Location = System::Drawing::Point(458, 328);
			this->logout_button->Name = L"logout_button";
			this->logout_button->Size = System::Drawing::Size(238, 69);
			this->logout_button->TabIndex = 5;
			this->logout_button->Text = L"Выйти";
			this->logout_button->UseVisualStyleBackColor = true;
			this->logout_button->Click += gcnew System::EventHandler(this, &Form3::logout_button_Click);
			this->logout_button->Enter += gcnew System::EventHandler(this, &Form3::logout_button_Enter);
			this->logout_button->Leave += gcnew System::EventHandler(this, &Form3::logout_button_Leave);
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
			this->name_label->TabIndex = 0;
			this->name_label->Text = L"ACTION";
			// 
			// Form3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(719, 424);
			this->Controls->Add(this->name_label);
			this->Controls->Add(this->logout_button);
			this->Controls->Add(this->write_action_button);
			this->Controls->Add(this->settings_button);
			this->Controls->Add(this->priority_button);
			this->Controls->Add(this->balance_button);
			this->Controls->Add(this->user_label);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Form3";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Action";
			this->TransparencyKey = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Form3::Form3_FormClosed);
			this->Load += gcnew System::EventHandler(this, &Form3::Form3_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form3::Form3_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form3::Form3_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form3::Form3_MouseUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void Form3_Load(System::Object^  sender, System::EventArgs^  e);

private: System::Void write_action_button_Click(System::Object^  sender, System::EventArgs^  e);

private: System::Void write_action_button_Enter(System::Object^  sender, System::EventArgs^  e)
		 {
			 write_action_button->ForeColor = Color::Green;

			 write_action_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				 static_cast<System::Byte>(204)));
		 }
private: System::Void write_action_button_Leave(System::Object^  sender, System::EventArgs^  e)
		 {
			write_action_button->ForeColor = Color::DodgerBlue;

			write_action_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
		 }
private: System::Void balance_button_Enter(System::Object^  sender, System::EventArgs^  e) 
		 {
			 balance_button->ForeColor = Color::Green;
			 balance_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				 static_cast<System::Byte>(204)));
		 }
private: System::Void balance_button_Leave(System::Object^  sender, System::EventArgs^  e) 
		 { 
			 balance_button->ForeColor = Color::DodgerBlue;
			 balance_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				 static_cast<System::Byte>(204)));
		 }
private: System::Void logout_button_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 Form2^ Form2_ref       =       gcnew Form2;
			 Form2_ref->Show();
			 this->Hide();

			 Form1::global_username = "";
			 Form2::pass_textbox->Focus();

		 }
private: System::Void priority_button_Enter(System::Object^  sender, System::EventArgs^  e)
		 {
			 priority_button->ForeColor = Color::Green;

			 priority_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				 static_cast<System::Byte>(204)));

		 }
private: System::Void priority_button_Leave(System::Object^  sender, System::EventArgs^  e)
		 {
			 priority_button->ForeColor = Color::DodgerBlue;

			 priority_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				 static_cast<System::Byte>(204)));
		 }
private: System::Void settings_button_Enter(System::Object^  sender, System::EventArgs^  e)
		 {
			 settings_button->ForeColor = Color::Green;

			 settings_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				 static_cast<System::Byte>(204)));
		 }
private: System::Void settings_button_Leave(System::Object^  sender, System::EventArgs^  e)
		 {
			 settings_button->ForeColor = Color::DodgerBlue;

			 settings_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				 static_cast<System::Byte>(204)));
		 }
private: System::Void logout_button_Enter(System::Object^  sender, System::EventArgs^  e)
		 {
			 logout_button->ForeColor = Color::Green;

			 logout_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				 static_cast<System::Byte>(204)));
		 }
private: System::Void logout_button_Leave(System::Object^  sender, System::EventArgs^  e)
		 {
			 logout_button->ForeColor = Color::DodgerBlue;

			 logout_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				 static_cast<System::Byte>(204)));
		 }
private: System::Void settings_button_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if( settings_button->Text == "Настройка")
			 {
				 for(int i=0;i<96;i++)
				 {
					 this->settings_button->Location = System::Drawing::Point(343-i, 253);

					 Sleep(7/10);

					 if(i == 33)
						 balance_button->Visible = false;

					 if(i == 66)
						 logout_button->Visible = false;

					 if(i == 95)
						 priority_button->Visible = false;
				 }

				 for(int i=0;i<76;i++)
				 {
					 this->settings_button->Location = System::Drawing::Point(248, 253+i);

					 Sleep(7/10);

					 if(i == 33)
						 write_action_button->Visible = false;

					 if(i == 66)
						 user_label->Location = System::Drawing::Point(566, 343);

					 if(i == 75)
						 settings_button->Text = "Назад";
				 }
			 }
			 else
			 {
				 for(int i=0;i<76;i++)
				 {
					 this->settings_button->Location = System::Drawing::Point(248, 328-i);

					 Sleep(9/10);

					 if(i == 33)
						 balance_button->Visible = true;

					 if(i == 66)
						 logout_button->Visible = true;
				 }
				 for(int i=0;i<96;i++)
				 {
					 this->settings_button->Location = System::Drawing::Point(248+i, 253);

					 Sleep(9/10);

					 if(i == 33)
						 write_action_button->Visible = true;

					 if(i == 66)
						 user_label->Location = System::Drawing::Point(625,19);

					 if(i == 75)
						 settings_button->Text = "Настройка";

					 if(i == 95)
						 priority_button->Visible = true;
				 }
			 }
		 }
private: System::Void Form3_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e);
private: System::Void Form3_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
private: System::Void Form3_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
private: System::Void Form3_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
};
}
