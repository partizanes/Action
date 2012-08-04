#pragma once

namespace Action {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Сводка для Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  bar_label;
	protected: 
	private: System::Windows::Forms::Label^  true_bar_label;
	private: System::Windows::Forms::Label^  name_label;
	private: System::Windows::Forms::Label^  price_old_label;
	private: System::Windows::Forms::Label^  price_new_label;
	private: System::Windows::Forms::TextBox^  bar_box;
	private: System::Windows::Forms::TextBox^  true_bar_box;
	private: System::Windows::Forms::TextBox^  name_box;

	private: System::Windows::Forms::TextBox^  old_price_box;
	private: System::Windows::Forms::TextBox^  new_price_box;
	private: System::Windows::Forms::Button^  send_button;
	private: System::Windows::Forms::Button^  clean_button;
	private: System::Windows::Forms::ListBox^  listBox1;
	public: System::Windows::Forms::Label^  status_label;
	private: 

	private: System::Windows::Forms::Label^  send_label;


	private: System::ComponentModel::IContainer^  components;
	private: MySqlConnection^	conn;
	private: System::Windows::Forms::Button^  exit_button;
	private: System::Windows::Forms::Button^  hide_button;
	private: System::Windows::Forms::NotifyIcon^  Action;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Timer^  s_status_timer;
	private: MySqlCommand^	cmd;

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->bar_label = (gcnew System::Windows::Forms::Label());
			this->true_bar_label = (gcnew System::Windows::Forms::Label());
			this->name_label = (gcnew System::Windows::Forms::Label());
			this->price_old_label = (gcnew System::Windows::Forms::Label());
			this->price_new_label = (gcnew System::Windows::Forms::Label());
			this->bar_box = (gcnew System::Windows::Forms::TextBox());
			this->true_bar_box = (gcnew System::Windows::Forms::TextBox());
			this->name_box = (gcnew System::Windows::Forms::TextBox());
			this->old_price_box = (gcnew System::Windows::Forms::TextBox());
			this->new_price_box = (gcnew System::Windows::Forms::TextBox());
			this->send_button = (gcnew System::Windows::Forms::Button());
			this->clean_button = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->status_label = (gcnew System::Windows::Forms::Label());
			this->send_label = (gcnew System::Windows::Forms::Label());
			this->exit_button = (gcnew System::Windows::Forms::Button());
			this->hide_button = (gcnew System::Windows::Forms::Button());
			this->Action = (gcnew System::Windows::Forms::NotifyIcon(this->components));
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->s_status_timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// bar_label
			// 
			this->bar_label->AutoSize = true;
			this->bar_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->bar_label->Location = System::Drawing::Point(47, 67);
			this->bar_label->Name = L"bar_label";
			this->bar_label->Size = System::Drawing::Size(149, 16);
			this->bar_label->TabIndex = 0;
			this->bar_label->Text = L"Штрих-код(12цифр)";
			// 
			// true_bar_label
			// 
			this->true_bar_label->AutoSize = true;
			this->true_bar_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->true_bar_label->Location = System::Drawing::Point(47, 142);
			this->true_bar_label->Name = L"true_bar_label";
			this->true_bar_label->Size = System::Drawing::Size(149, 16);
			this->true_bar_label->TabIndex = 1;
			this->true_bar_label->Text = L"Штрих-код(13цифр)";
			// 
			// name_label
			// 
			this->name_label->AutoSize = true;
			this->name_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->name_label->Location = System::Drawing::Point(411, 67);
			this->name_label->Name = L"name_label";
			this->name_label->Size = System::Drawing::Size(119, 16);
			this->name_label->TabIndex = 2;
			this->name_label->Text = L"Наименование";
			// 
			// price_old_label
			// 
			this->price_old_label->AutoSize = true;
			this->price_old_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->price_old_label->Location = System::Drawing::Point(329, 142);
			this->price_old_label->Name = L"price_old_label";
			this->price_old_label->Size = System::Drawing::Size(102, 16);
			this->price_old_label->TabIndex = 3;
			this->price_old_label->Text = L"Старая Цена";
			// 
			// price_new_label
			// 
			this->price_new_label->AutoSize = true;
			this->price_new_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->price_new_label->Location = System::Drawing::Point(516, 142);
			this->price_new_label->Name = L"price_new_label";
			this->price_new_label->Size = System::Drawing::Size(95, 16);
			this->price_new_label->TabIndex = 4;
			this->price_new_label->Text = L"Новая Цена";
			// 
			// bar_box
			// 
			this->bar_box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->bar_box->Location = System::Drawing::Point(25, 86);
			this->bar_box->MaxLength = 12;
			this->bar_box->Name = L"bar_box";
			this->bar_box->Size = System::Drawing::Size(188, 26);
			this->bar_box->TabIndex = 0;
			this->bar_box->TextChanged += gcnew System::EventHandler(this, &Form1::bar_box_TextChanged);
			this->bar_box->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::bar_box_KeyDown_1);
			// 
			// true_bar_box
			// 
			this->true_bar_box->Enabled = false;
			this->true_bar_box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->true_bar_box->Location = System::Drawing::Point(25, 161);
			this->true_bar_box->MaxLength = 13;
			this->true_bar_box->Name = L"true_bar_box";
			this->true_bar_box->ReadOnly = true;
			this->true_bar_box->Size = System::Drawing::Size(188, 26);
			this->true_bar_box->TabIndex = 0;
			this->true_bar_box->TabStop = false;
			// 
			// name_box
			// 
			this->name_box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->name_box->Location = System::Drawing::Point(251, 86);
			this->name_box->MaxLength = 99;
			this->name_box->Name = L"name_box";
			this->name_box->ReadOnly = true;
			this->name_box->Size = System::Drawing::Size(437, 26);
			this->name_box->TabIndex = 0;
			this->name_box->TabStop = false;
			// 
			// old_price_box
			// 
			this->old_price_box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->old_price_box->Location = System::Drawing::Point(310, 161);
			this->old_price_box->MaxLength = 10;
			this->old_price_box->Name = L"old_price_box";
			this->old_price_box->Size = System::Drawing::Size(137, 26);
			this->old_price_box->TabIndex = 1;
			this->old_price_box->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::old_price_box_KeyDown);
			// 
			// new_price_box
			// 
			this->new_price_box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->new_price_box->Location = System::Drawing::Point(494, 161);
			this->new_price_box->MaxLength = 10;
			this->new_price_box->Name = L"new_price_box";
			this->new_price_box->Size = System::Drawing::Size(137, 26);
			this->new_price_box->TabIndex = 2;
			this->new_price_box->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::new_price_box_KeyDown);
			// 
			// send_button
			// 
			this->send_button->Location = System::Drawing::Point(560, 375);
			this->send_button->Name = L"send_button";
			this->send_button->Size = System::Drawing::Size(137, 30);
			this->send_button->TabIndex = 3;
			this->send_button->Text = L"Отправить";
			this->send_button->UseVisualStyleBackColor = true;
			this->send_button->Click += gcnew System::EventHandler(this, &Form1::send_button_Click);
			// 
			// clean_button
			// 
			this->clean_button->Location = System::Drawing::Point(25, 370);
			this->clean_button->Name = L"clean_button";
			this->clean_button->Size = System::Drawing::Size(65, 30);
			this->clean_button->TabIndex = 0;
			this->clean_button->TabStop = false;
			this->clean_button->Text = L"Очистить";
			this->clean_button->UseVisualStyleBackColor = true;
			this->clean_button->Click += gcnew System::EventHandler(this, &Form1::clean_button_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(25, 256);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(672, 108);
			this->listBox1->TabIndex = 0;
			this->listBox1->TabStop = false;
			// 
			// status_label
			// 
			this->status_label->AutoSize = true;
			this->status_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->status_label->Location = System::Drawing::Point(305, 9);
			this->status_label->Name = L"status_label";
			this->status_label->Size = System::Drawing::Size(73, 25);
			this->status_label->TabIndex = 12;
			this->status_label->Text = L"Status";
			// 
			// send_label
			// 
			this->send_label->AutoSize = true;
			this->send_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->send_label->Location = System::Drawing::Point(305, 375);
			this->send_label->Name = L"send_label";
			this->send_label->Size = System::Drawing::Size(93, 25);
			this->send_label->TabIndex = 13;
			this->send_label->Text = L"s_status";
			// 
			// exit_button
			// 
			this->exit_button->Location = System::Drawing::Point(167, 370);
			this->exit_button->Name = L"exit_button";
			this->exit_button->Size = System::Drawing::Size(65, 30);
			this->exit_button->TabIndex = 14;
			this->exit_button->TabStop = false;
			this->exit_button->Text = L"Выход";
			this->exit_button->UseVisualStyleBackColor = true;
			this->exit_button->Click += gcnew System::EventHandler(this, &Form1::exit_button_Click);
			// 
			// hide_button
			// 
			this->hide_button->Location = System::Drawing::Point(96, 370);
			this->hide_button->Name = L"hide_button";
			this->hide_button->Size = System::Drawing::Size(65, 30);
			this->hide_button->TabIndex = 15;
			this->hide_button->TabStop = false;
			this->hide_button->Text = L"Свернуть";
			this->hide_button->UseVisualStyleBackColor = true;
			this->hide_button->Click += gcnew System::EventHandler(this, &Form1::hide_button_Click);
			// 
			// Action
			// 
			this->Action->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"Action.Icon")));
			this->Action->Text = L"Action";
			this->Action->Visible = true;
			this->Action->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Action_MouseDoubleClick);
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->CustomFormat = L"";
			this->dateTimePicker1->Location = System::Drawing::Point(96, 214);
			this->dateTimePicker1->MaxDate = System::DateTime(2015, 12, 31, 0, 0, 0, 0);
			this->dateTimePicker1->MinDate = System::DateTime(2012, 1, 1, 0, 0, 0, 0);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker1->TabIndex = 16;
			this->dateTimePicker1->Value = System::DateTime(2012, 8, 1, 0, 0, 0, 0);
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->CustomFormat = L"";
			this->dateTimePicker2->Location = System::Drawing::Point(395, 214);
			this->dateTimePicker2->MaxDate = System::DateTime(2015, 12, 31, 0, 0, 0, 0);
			this->dateTimePicker2->MinDate = System::DateTime(2012, 1, 1, 0, 0, 0, 0);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker2->TabIndex = 17;
			this->dateTimePicker2->Value = System::DateTime(2012, 8, 1, 0, 0, 0, 0);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(34, 216);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(56, 15);
			this->label1->TabIndex = 18;
			this->label1->Text = L"Начало";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(310, 218);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(79, 15);
			this->label2->TabIndex = 19;
			this->label2->Text = L"Окончание";
			// 
			// s_status_timer
			// 
			this->s_status_timer->Interval = 1000;
			this->s_status_timer->Tick += gcnew System::EventHandler(this, &Form1::s_status_timer_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(719, 424);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dateTimePicker2);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->hide_button);
			this->Controls->Add(this->exit_button);
			this->Controls->Add(this->send_label);
			this->Controls->Add(this->status_label);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->clean_button);
			this->Controls->Add(this->send_button);
			this->Controls->Add(this->new_price_box);
			this->Controls->Add(this->old_price_box);
			this->Controls->Add(this->name_box);
			this->Controls->Add(this->true_bar_box);
			this->Controls->Add(this->bar_box);
			this->Controls->Add(this->price_new_label);
			this->Controls->Add(this->price_old_label);
			this->Controls->Add(this->name_label);
			this->Controls->Add(this->true_bar_label);
			this->Controls->Add(this->bar_label);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"Form1";
			this->Text = L"Action";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Form1::Form1_FormClosed);
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Boolean Form1::mysqlcheck();
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e);
private: System::Void exit_button_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void hide_button_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void Action_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
private: System::Void clean_button_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void Form1::query(String^ bar);
private: char* SystemStringToChar(System::String^ string);
private: String^ CharToSystemString(char* ch);
private: System::Void bar_box_TextChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void bar_box_KeyDown_1(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
private: System::Void old_price_box_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
private: System::Void new_price_box_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
private: System::Void send_button_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void Form1_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
			 Action->Visible = false;
		 }
private: System::Void s_status_timer_Tick(System::Object^  sender, System::EventArgs^  e) {
			 send_label->Text = "";
			 s_status_timer->Enabled = false;
		 }
private: System::Void Form1_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
			 Action->Visible = false;
		 }
};
}

