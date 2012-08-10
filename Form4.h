#pragma once

namespace Action {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
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
	private: System::Windows::Forms::TextBox^  bar_textbox;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
	private: System::Windows::Forms::TextBox^  count_textbox;
	private: System::Windows::Forms::TextBox^  item_textbox;
	private: System::Windows::Forms::Button^  turn_button;
	private: System::Windows::Forms::Panel^  insert_turn_panel;
	private: System::Windows::Forms::Button^  add_turn_button;

	private: System::Windows::Forms::Button^  list_button;
	private: System::Windows::Forms::Label^  name_label;
	private: System::Windows::Forms::Button^  back_button;
	private: System::Windows::Forms::Label^  item_name_label;

	private: System::Windows::Forms::Label^  count_label;
	private: System::Windows::Forms::Label^  date_label;


	private: System::Windows::Forms::Label^  bar_label;

	public: System::Windows::Forms::Label^  user_label;
	private: System::Windows::Forms::Label^  info_label;
	public: 
	private: System::Windows::Forms::Panel^  list_panel;
	private: System::Windows::Forms::ListBox^  turn_listBox;
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
			this->bar_textbox = (gcnew System::Windows::Forms::TextBox());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->count_textbox = (gcnew System::Windows::Forms::TextBox());
			this->item_textbox = (gcnew System::Windows::Forms::TextBox());
			this->turn_button = (gcnew System::Windows::Forms::Button());
			this->insert_turn_panel = (gcnew System::Windows::Forms::Panel());
			this->item_name_label = (gcnew System::Windows::Forms::Label());
			this->count_label = (gcnew System::Windows::Forms::Label());
			this->date_label = (gcnew System::Windows::Forms::Label());
			this->bar_label = (gcnew System::Windows::Forms::Label());
			this->name_label = (gcnew System::Windows::Forms::Label());
			this->add_turn_button = (gcnew System::Windows::Forms::Button());
			this->list_button = (gcnew System::Windows::Forms::Button());
			this->back_button = (gcnew System::Windows::Forms::Button());
			this->user_label = (gcnew System::Windows::Forms::Label());
			this->info_label = (gcnew System::Windows::Forms::Label());
			this->list_panel = (gcnew System::Windows::Forms::Panel());
			this->turn_listBox = (gcnew System::Windows::Forms::ListBox());
			this->insert_turn_panel->SuspendLayout();
			this->list_panel->SuspendLayout();
			this->SuspendLayout();
			// 
			// bar_textbox
			// 
			this->bar_textbox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->bar_textbox->Location = System::Drawing::Point(83, 124);
			this->bar_textbox->MaxLength = 13;
			this->bar_textbox->Name = L"bar_textbox";
			this->bar_textbox->Size = System::Drawing::Size(178, 35);
			this->bar_textbox->TabIndex = 0;
			this->bar_textbox->Enter += gcnew System::EventHandler(this, &Form4::bar_textbox_Enter);
			this->bar_textbox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form4::bar_textbox_KeyDown);
			this->bar_textbox->Leave += gcnew System::EventHandler(this, &Form4::bar_textbox_Leave);
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->CalendarFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->dateTimePicker1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->dateTimePicker1->Location = System::Drawing::Point(164, 63);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(200, 22);
			this->dateTimePicker1->TabIndex = 1;
			this->dateTimePicker1->TabStop = false;
			this->dateTimePicker1->Enter += gcnew System::EventHandler(this, &Form4::dateTimePicker1_Enter);
			this->dateTimePicker1->Leave += gcnew System::EventHandler(this, &Form4::dateTimePicker1_Leave);
			// 
			// count_textbox
			// 
			this->count_textbox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->count_textbox->Location = System::Drawing::Point(304, 124);
			this->count_textbox->Name = L"count_textbox";
			this->count_textbox->Size = System::Drawing::Size(88, 35);
			this->count_textbox->TabIndex = 1;
			this->count_textbox->TextChanged += gcnew System::EventHandler(this, &Form4::count_textbox_TextChanged);
			this->count_textbox->Enter += gcnew System::EventHandler(this, &Form4::count_textbox_Enter);
			this->count_textbox->Leave += gcnew System::EventHandler(this, &Form4::count_textbox_Leave);
			// 
			// item_textbox
			// 
			this->item_textbox->Enabled = false;
			this->item_textbox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->item_textbox->Location = System::Drawing::Point(23, 201);
			this->item_textbox->MaxLength = 50;
			this->item_textbox->Name = L"item_textbox";
			this->item_textbox->ReadOnly = true;
			this->item_textbox->Size = System::Drawing::Size(461, 26);
			this->item_textbox->TabIndex = 2;
			this->item_textbox->Enter += gcnew System::EventHandler(this, &Form4::item_textbox_Enter);
			this->item_textbox->Leave += gcnew System::EventHandler(this, &Form4::item_textbox_Leave);
			// 
			// turn_button
			// 
			this->turn_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->turn_button->ForeColor = System::Drawing::Color::DodgerBlue;
			this->turn_button->Location = System::Drawing::Point(164, 257);
			this->turn_button->Name = L"turn_button";
			this->turn_button->Size = System::Drawing::Size(200, 29);
			this->turn_button->TabIndex = 3;
			this->turn_button->TabStop = false;
			this->turn_button->Text = L"Поставить в очередь";
			this->turn_button->UseVisualStyleBackColor = true;
			this->turn_button->Enter += gcnew System::EventHandler(this, &Form4::turn_button_Enter);
			this->turn_button->Leave += gcnew System::EventHandler(this, &Form4::turn_button_Leave);
			// 
			// insert_turn_panel
			// 
			this->insert_turn_panel->BackColor = System::Drawing::Color::Black;
			this->insert_turn_panel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->insert_turn_panel->Controls->Add(this->item_name_label);
			this->insert_turn_panel->Controls->Add(this->count_label);
			this->insert_turn_panel->Controls->Add(this->date_label);
			this->insert_turn_panel->Controls->Add(this->bar_label);
			this->insert_turn_panel->Controls->Add(this->turn_button);
			this->insert_turn_panel->Controls->Add(this->dateTimePicker1);
			this->insert_turn_panel->Controls->Add(this->count_textbox);
			this->insert_turn_panel->Controls->Add(this->item_textbox);
			this->insert_turn_panel->Controls->Add(this->bar_textbox);
			this->insert_turn_panel->Location = System::Drawing::Point(118, 44);
			this->insert_turn_panel->Name = L"insert_turn_panel";
			this->insert_turn_panel->Size = System::Drawing::Size(515, 309);
			this->insert_turn_panel->TabIndex = 4;
			this->insert_turn_panel->Visible = false;
			// 
			// item_name_label
			// 
			this->item_name_label->AutoSize = true;
			this->item_name_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->item_name_label->ForeColor = System::Drawing::Color::DodgerBlue;
			this->item_name_label->Location = System::Drawing::Point(219, 182);
			this->item_name_label->Name = L"item_name_label";
			this->item_name_label->Size = System::Drawing::Size(107, 16);
			this->item_name_label->TabIndex = 7;
			this->item_name_label->Text = L"Наименование";
			// 
			// count_label
			// 
			this->count_label->AutoSize = true;
			this->count_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->count_label->ForeColor = System::Drawing::Color::DodgerBlue;
			this->count_label->Location = System::Drawing::Point(306, 105);
			this->count_label->Name = L"count_label";
			this->count_label->Size = System::Drawing::Size(86, 16);
			this->count_label->TabIndex = 6;
			this->count_label->Text = L"Количество";
			// 
			// date_label
			// 
			this->date_label->AutoSize = true;
			this->date_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->date_label->ForeColor = System::Drawing::Color::DodgerBlue;
			this->date_label->Location = System::Drawing::Point(239, 44);
			this->date_label->Name = L"date_label";
			this->date_label->Size = System::Drawing::Size(40, 16);
			this->date_label->TabIndex = 5;
			this->date_label->Text = L"Дата";
			// 
			// bar_label
			// 
			this->bar_label->AutoSize = true;
			this->bar_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->bar_label->ForeColor = System::Drawing::Color::DodgerBlue;
			this->bar_label->Location = System::Drawing::Point(137, 103);
			this->bar_label->Name = L"bar_label";
			this->bar_label->Size = System::Drawing::Size(75, 16);
			this->bar_label->TabIndex = 4;
			this->bar_label->Text = L"Штрих-код";
			// 
			// name_label
			// 
			this->name_label->AutoSize = true;
			this->name_label->BackColor = System::Drawing::Color::Transparent;
			this->name_label->Font = (gcnew System::Drawing::Font(L"Mistral", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->name_label->ForeColor = System::Drawing::Color::DodgerBlue;
			this->name_label->Location = System::Drawing::Point(15, 351);
			this->name_label->Name = L"name_label";
			this->name_label->Size = System::Drawing::Size(97, 38);
			this->name_label->TabIndex = 4;
			this->name_label->Text = L"ACTION";
			// 
			// add_turn_button
			// 
			this->add_turn_button->ForeColor = System::Drawing::Color::DodgerBlue;
			this->add_turn_button->Location = System::Drawing::Point(12, 105);
			this->add_turn_button->Name = L"add_turn_button";
			this->add_turn_button->Size = System::Drawing::Size(100, 30);
			this->add_turn_button->TabIndex = 0;
			this->add_turn_button->Text = L"Добавить";
			this->add_turn_button->UseVisualStyleBackColor = true;
			this->add_turn_button->Click += gcnew System::EventHandler(this, &Form4::add_turn_button_Click);
			// 
			// list_button
			// 
			this->list_button->ForeColor = System::Drawing::Color::DodgerBlue;
			this->list_button->Location = System::Drawing::Point(12, 140);
			this->list_button->Name = L"list_button";
			this->list_button->Size = System::Drawing::Size(100, 30);
			this->list_button->TabIndex = 1;
			this->list_button->Text = L"Список";
			this->list_button->UseVisualStyleBackColor = true;
			this->list_button->Click += gcnew System::EventHandler(this, &Form4::list_button_Click);
			// 
			// back_button
			// 
			this->back_button->ForeColor = System::Drawing::Color::DodgerBlue;
			this->back_button->Location = System::Drawing::Point(12, 176);
			this->back_button->Name = L"back_button";
			this->back_button->Size = System::Drawing::Size(100, 30);
			this->back_button->TabIndex = 2;
			this->back_button->Text = L"Назад";
			this->back_button->UseVisualStyleBackColor = true;
			this->back_button->Click += gcnew System::EventHandler(this, &Form4::back_button_Click);
			// 
			// user_label
			// 
			this->user_label->AutoEllipsis = true;
			this->user_label->AutoSize = true;
			this->user_label->BackColor = System::Drawing::Color::Transparent;
			this->user_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->user_label->ForeColor = System::Drawing::Color::DodgerBlue;
			this->user_label->Location = System::Drawing::Point(604, 18);
			this->user_label->Name = L"user_label";
			this->user_label->Size = System::Drawing::Size(0, 16);
			this->user_label->TabIndex = 5;
			// 
			// info_label
			// 
			this->info_label->AutoSize = true;
			this->info_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->info_label->ForeColor = System::Drawing::Color::DodgerBlue;
			this->info_label->Location = System::Drawing::Point(118, 375);
			this->info_label->Name = L"info_label";
			this->info_label->Size = System::Drawing::Size(45, 16);
			this->info_label->TabIndex = 6;
			this->info_label->Text = L"label5";
			this->info_label->Visible = false;
			// 
			// list_panel
			// 
			this->list_panel->BackColor = System::Drawing::Color::Black;
			this->list_panel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->list_panel->Controls->Add(this->turn_listBox);
			this->list_panel->Location = System::Drawing::Point(580, 375);
			this->list_panel->Name = L"list_panel";
			this->list_panel->Size = System::Drawing::Size(515, 309);
			this->list_panel->TabIndex = 8;
			this->list_panel->Visible = false;
			// 
			// turn_listBox
			// 
			this->turn_listBox->FormattingEnabled = true;
			this->turn_listBox->Location = System::Drawing::Point(1, 1);
			this->turn_listBox->Name = L"turn_listBox";
			this->turn_listBox->Size = System::Drawing::Size(507, 303);
			this->turn_listBox->TabIndex = 0;
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
			this->Controls->Add(this->list_panel);
			this->Controls->Add(this->info_label);
			this->Controls->Add(this->user_label);
			this->Controls->Add(this->name_label);
			this->Controls->Add(this->back_button);
			this->Controls->Add(this->list_button);
			this->Controls->Add(this->add_turn_button);
			this->Controls->Add(this->insert_turn_panel);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Form4";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Action";
			this->TransparencyKey = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->Load += gcnew System::EventHandler(this, &Form4::Form4_Load);
			this->insert_turn_panel->ResumeLayout(false);
			this->insert_turn_panel->PerformLayout();
			this->list_panel->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void count_textbox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void back_button_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void add_turn_button_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if(insert_turn_panel->Visible == false)
			 {
				 insert_turn_panel->Visible = true;

				 bar_textbox->Focus();

				 add_turn_button->TabStop = false;
				 back_button->TabStop = false;
				 list_button->TabStop = false;

				 bar_textbox->TabStop = true;
				 count_textbox->TabStop = true;
				 turn_button->TabStop = true;
			 }
			 else
			 {
				 insert_turn_panel->Visible = false;

				 add_turn_button->TabStop = true;
				 back_button->TabStop = true;
				 list_button->TabStop = true;
			 }
		 }
private: System::Void Form4_Load(System::Object^  sender, System::EventArgs^  e);
private: System::Void list_button_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 insert_turn_panel->Visible =false;

			 if(list_panel->Visible == true)
				 list_panel->Visible = false;
			 else
				 list_panel->Visible = true;

		 }
private: System::Void bar_textbox_Enter(System::Object^  sender, System::EventArgs^  e) {
			 bar_label->ForeColor = Color::Green;
		 }
private: System::Void bar_textbox_Leave(System::Object^  sender, System::EventArgs^  e) {
			 bar_label->ForeColor = Color::DodgerBlue;
		 }
private: System::Void dateTimePicker1_Enter(System::Object^  sender, System::EventArgs^  e) {
			 date_label->ForeColor = Color::Green;
		 }
private: System::Void dateTimePicker1_Leave(System::Object^  sender, System::EventArgs^  e) {
			 date_label->ForeColor = Color::DodgerBlue;
		 }
private: System::Void count_textbox_Enter(System::Object^  sender, System::EventArgs^  e) {
			 count_label->ForeColor = Color::Green;
		 }
private: System::Void count_textbox_Leave(System::Object^  sender, System::EventArgs^  e) {
			 count_label->ForeColor = Color::DodgerBlue;
		 }
private: System::Void item_textbox_Enter(System::Object^  sender, System::EventArgs^  e) {
			 item_name_label->ForeColor = Color::Green;
		 }
private: System::Void item_textbox_Leave(System::Object^  sender, System::EventArgs^  e) {
			 item_name_label->ForeColor = Color::DodgerBlue;
		 }
private: System::Void turn_button_Enter(System::Object^  sender, System::EventArgs^  e) {
			 turn_button->ForeColor = Color::Green;
		 }
private: System::Void turn_button_Leave(System::Object^  sender, System::EventArgs^  e) {
			 turn_button->ForeColor = Color::DodgerBlue;
		 }

private: System::Void bar_textbox_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

			 if (e->KeyCode == Keys::Left || e->KeyCode == Keys::Escape)
			 {
				 insert_turn_panel->Visible = false;
				 add_turn_button->Focus();
			 }

			 if (e->KeyCode == Keys::Right || e->KeyCode == Keys::Enter || e->KeyCode == Keys::Down)
			 {
				if(bar_textbox->TextLength < 3)
				{
					//TODO Добавить функцию временного сообщения
					return;
				}
				else
				{
					//TODO Запрос имени товара и проверка на валидность
				}

			 }


		 }
};
}
