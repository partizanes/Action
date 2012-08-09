#pragma once

namespace Action {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
    using namespace MySql::Data::MySqlClient;


	public ref class Form2 : public System::Windows::Forms::Form
	{
	public:
		Form2(void)
		{
			InitializeComponent();
		}

	protected:
		~Form2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  login_textbox;
	public: static System::Windows::Forms::TextBox^  pass_textbox;
	private: 

	private: 

	private: System::Windows::Forms::Label^  login_label;
	private: Point mouseOffset;
	protected: 

	private: System::Windows::Forms::Label^  pass_label;
	private: System::Windows::Forms::Panel^  login_panel;
	private: System::Windows::Forms::Button^  login_button;
	private: System::Windows::Forms::CheckBox^  check_save_login;
	private: System::Windows::Forms::Label^  name_label;
	private: System::Windows::Forms::Label^  ver_label;
	private: System::Windows::Forms::Label^  msg_label;
	private: System::Windows::Forms::Timer^  msg_label_timer;
	private: System::ComponentModel::IContainer^  components;
	private: MySqlConnection^	conn;
	private: System::Windows::Forms::Label^  exe_label;
	private: System::Windows::Forms::Timer^  msg_exe_timer;

	private: MySqlCommand^	cmd;
	private:


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form2::typeid));
			this->login_textbox = (gcnew System::Windows::Forms::TextBox());
			this->pass_textbox = (gcnew System::Windows::Forms::TextBox());
			this->login_label = (gcnew System::Windows::Forms::Label());
			this->pass_label = (gcnew System::Windows::Forms::Label());
			this->login_panel = (gcnew System::Windows::Forms::Panel());
			this->login_button = (gcnew System::Windows::Forms::Button());
			this->check_save_login = (gcnew System::Windows::Forms::CheckBox());
			this->name_label = (gcnew System::Windows::Forms::Label());
			this->ver_label = (gcnew System::Windows::Forms::Label());
			this->msg_label = (gcnew System::Windows::Forms::Label());
			this->msg_label_timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->exe_label = (gcnew System::Windows::Forms::Label());
			this->msg_exe_timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->login_panel->SuspendLayout();
			this->SuspendLayout();
			// 
			// login_textbox
			// 
			this->login_textbox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->login_textbox->Location = System::Drawing::Point(91, 73);
			this->login_textbox->MaxLength = 10;
			this->login_textbox->Name = L"login_textbox";
			this->login_textbox->Size = System::Drawing::Size(196, 22);
			this->login_textbox->TabIndex = 0;
			this->login_textbox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form2::login_textbox_KeyDown);
			// 
			// pass_textbox
			// 
			this->pass_textbox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->pass_textbox->Location = System::Drawing::Point(91, 113);
			this->pass_textbox->MaxLength = 15;
			this->pass_textbox->Name = L"pass_textbox";
			this->pass_textbox->PasswordChar = '*';
			this->pass_textbox->Size = System::Drawing::Size(196, 22);
			this->pass_textbox->TabIndex = 1;
			this->pass_textbox->Enter += gcnew System::EventHandler(this, &Form2::pass_textbox_Enter);
			this->pass_textbox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form2::pass_textbox_KeyDown);
			this->pass_textbox->Leave += gcnew System::EventHandler(this, &Form2::pass_textbox_Leave);
			// 
			// login_label
			// 
			this->login_label->AutoSize = true;
			this->login_label->BackColor = System::Drawing::Color::Transparent;
			this->login_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->login_label->ForeColor = System::Drawing::Color::DodgerBlue;
			this->login_label->Location = System::Drawing::Point(30, 77);
			this->login_label->Name = L"login_label";
			this->login_label->Size = System::Drawing::Size(55, 18);
			this->login_label->TabIndex = 0;
			this->login_label->Text = L"Логин";
			// 
			// pass_label
			// 
			this->pass_label->AutoSize = true;
			this->pass_label->BackColor = System::Drawing::Color::Transparent;
			this->pass_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->pass_label->ForeColor = System::Drawing::Color::DodgerBlue;
			this->pass_label->Location = System::Drawing::Point(18, 113);
			this->pass_label->Name = L"pass_label";
			this->pass_label->Size = System::Drawing::Size(67, 18);
			this->pass_label->TabIndex = 0;
			this->pass_label->Text = L"Пароль";
			// 
			// login_panel
			// 
			this->login_panel->BackColor = System::Drawing::Color::Black;
			this->login_panel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"login_panel.BackgroundImage")));
			this->login_panel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->login_panel->Controls->Add(this->login_button);
			this->login_panel->Controls->Add(this->login_textbox);
			this->login_panel->Controls->Add(this->pass_textbox);
			this->login_panel->Controls->Add(this->login_label);
			this->login_panel->Controls->Add(this->pass_label);
			this->login_panel->Controls->Add(this->check_save_login);
			this->login_panel->ForeColor = System::Drawing::SystemColors::ControlText;
			this->login_panel->Location = System::Drawing::Point(181, 76);
			this->login_panel->Name = L"login_panel";
			this->login_panel->Size = System::Drawing::Size(362, 242);
			this->login_panel->TabIndex = 4;
			this->login_panel->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form2::login_panel_MouseDown);
			this->login_panel->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form2::login_panel_MouseMove);
			this->login_panel->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form2::login_panel_MouseUp);
			// 
			// login_button
			// 
			this->login_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->login_button->ForeColor = System::Drawing::Color::DodgerBlue;
			this->login_button->Location = System::Drawing::Point(109, 187);
			this->login_button->Name = L"login_button";
			this->login_button->Size = System::Drawing::Size(153, 23);
			this->login_button->TabIndex = 3;
			this->login_button->Text = L"Войти";
			this->login_button->UseVisualStyleBackColor = true;
			this->login_button->Click += gcnew System::EventHandler(this, &Form2::login_button_Click);
			this->login_button->Enter += gcnew System::EventHandler(this, &Form2::login_button_Enter);
			this->login_button->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form2::login_button_KeyDown);
			this->login_button->Leave += gcnew System::EventHandler(this, &Form2::login_button_Leave);
			// 
			// check_save_login
			// 
			this->check_save_login->AutoSize = true;
			this->check_save_login->BackColor = System::Drawing::Color::Transparent;
			this->check_save_login->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->check_save_login->ForeColor = System::Drawing::Color::DodgerBlue;
			this->check_save_login->Location = System::Drawing::Point(146, 155);
			this->check_save_login->Name = L"check_save_login";
			this->check_save_login->Size = System::Drawing::Size(92, 19);
			this->check_save_login->TabIndex = 2;
			this->check_save_login->Text = L"Запомнить";
			this->check_save_login->UseVisualStyleBackColor = false;
			this->check_save_login->Visible = false;
			this->check_save_login->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form2::check_save_login_KeyDown);
			// 
			// name_label
			// 
			this->name_label->AutoSize = true;
			this->name_label->BackColor = System::Drawing::Color::Black;
			this->name_label->Font = (gcnew System::Drawing::Font(L"Mistral", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->name_label->ForeColor = System::Drawing::Color::DodgerBlue;
			this->name_label->Location = System::Drawing::Point(320, 22);
			this->name_label->Name = L"name_label";
			this->name_label->Size = System::Drawing::Size(97, 38);
			this->name_label->TabIndex = 5;
			this->name_label->Text = L"ACTION";
			this->name_label->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form2::name_label_MouseDown);
			this->name_label->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form2::name_label_MouseMove);
			this->name_label->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form2::name_label_MouseUp);
			// 
			// ver_label
			// 
			this->ver_label->AutoSize = true;
			this->ver_label->BackColor = System::Drawing::Color::Black;
			this->ver_label->Font = (gcnew System::Drawing::Font(L"Mistral", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->ver_label->ForeColor = System::Drawing::Color::DodgerBlue;
			this->ver_label->Location = System::Drawing::Point(660, 399);
			this->ver_label->Name = L"ver_label";
			this->ver_label->Size = System::Drawing::Size(33, 16);
			this->ver_label->TabIndex = 6;
			this->ver_label->Text = L"V: 0.1";
			// 
			// msg_label
			// 
			this->msg_label->AutoSize = true;
			this->msg_label->BackColor = System::Drawing::Color::Transparent;
			this->msg_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->msg_label->ForeColor = System::Drawing::Color::DodgerBlue;
			this->msg_label->Location = System::Drawing::Point(287, 339);
			this->msg_label->Name = L"msg_label";
			this->msg_label->Size = System::Drawing::Size(0, 16);
			this->msg_label->TabIndex = 7;
			// 
			// msg_label_timer
			// 
			this->msg_label_timer->Interval = 3000;
			this->msg_label_timer->Tick += gcnew System::EventHandler(this, &Form2::msg_label_timer_Tick);
			// 
			// exe_label
			// 
			this->exe_label->AutoEllipsis = true;
			this->exe_label->AutoSize = true;
			this->exe_label->BackColor = System::Drawing::Color::Transparent;
			this->exe_label->ForeColor = System::Drawing::Color::DodgerBlue;
			this->exe_label->Location = System::Drawing::Point(22, 400);
			this->exe_label->Name = L"exe_label";
			this->exe_label->Size = System::Drawing::Size(0, 13);
			this->exe_label->TabIndex = 0;
			// 
			// msg_exe_timer
			// 
			this->msg_exe_timer->Interval = 5000;
			this->msg_exe_timer->Tick += gcnew System::EventHandler(this, &Form2::msg_exe_timer_Tick);
			// 
			// Form2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(719, 424);
			this->Controls->Add(this->exe_label);
			this->Controls->Add(this->msg_label);
			this->Controls->Add(this->ver_label);
			this->Controls->Add(this->name_label);
			this->Controls->Add(this->login_panel);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Form2";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Action";
			this->TransparencyKey = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form2::Form2_FormClosing);
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Form2::Form2_FormClosed);
			this->Load += gcnew System::EventHandler(this, &Form2::LastLogin);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form2::Form2_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form2::Form2_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form2::Form2_MouseUp);
			this->login_panel->ResumeLayout(false);
			this->login_panel->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void Form2_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
private: System::Void Form2_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
private: System::Void Form2_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
private: System::Void name_label_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
private: System::Void name_label_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
private: System::Void name_label_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
private: System::Void login_panel_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
private: System::Void login_panel_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
private: System::Void login_panel_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
private: System::Void login_textbox_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
private: System::Void msg_label_timer_Tick(System::Object^  sender, System::EventArgs^  e);
private: System::Void Form2::set_msg_on_timer(String^ text);
private: System::Void pass_textbox_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
private: System::Void pass_textbox_Enter(System::Object^  sender, System::EventArgs^  e);
private: System::Void pass_textbox_Leave(System::Object^  sender, System::EventArgs^  e);
private: System::Void login_button_Enter(System::Object^  sender, System::EventArgs^  e);
private: System::Void login_button_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
private: System::Void login_button_Click(System::Object^  sender, System::EventArgs^  e);
private: System::String^ getMD5String(String^ data);
private: System::Boolean Auth(String^ login, String^ pass);
private: System::Void msg_exe_timer_Tick(System::Object^  sender, System::EventArgs^  e);
private: System::Void set_exe_on_timer(String^ text);
private: System::Void check_save_login_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
private: System::Void LastLogin(System::Object^  sender, System::EventArgs^  e);
private: System::Void Form2_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
			 Application::Exit();
		 }
private: System::Void Form2_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
			 Application::Exit();
		 }
private: System::Void login_button_Leave(System::Object^  sender, System::EventArgs^  e);
};
}
