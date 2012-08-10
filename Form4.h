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
	private: System::Windows::Forms::Button^  Back_button;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	public: System::Windows::Forms::Label^  user_label;
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
			this->name_label = (gcnew System::Windows::Forms::Label());
			this->add_turn_button = (gcnew System::Windows::Forms::Button());
			this->list_button = (gcnew System::Windows::Forms::Button());
			this->Back_button = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->user_label = (gcnew System::Windows::Forms::Label());
			this->insert_turn_panel->SuspendLayout();
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
			this->turn_button->Text = L"Поставить в очередь";
			this->turn_button->UseVisualStyleBackColor = true;
			// 
			// insert_turn_panel
			// 
			this->insert_turn_panel->BackColor = System::Drawing::Color::Black;
			this->insert_turn_panel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->insert_turn_panel->Controls->Add(this->label4);
			this->insert_turn_panel->Controls->Add(this->label3);
			this->insert_turn_panel->Controls->Add(this->label2);
			this->insert_turn_panel->Controls->Add(this->label1);
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
			// 
			// Back_button
			// 
			this->Back_button->ForeColor = System::Drawing::Color::DodgerBlue;
			this->Back_button->Location = System::Drawing::Point(12, 176);
			this->Back_button->Name = L"Back_button";
			this->Back_button->Size = System::Drawing::Size(100, 30);
			this->Back_button->TabIndex = 2;
			this->Back_button->Text = L"Назад";
			this->Back_button->UseVisualStyleBackColor = true;
			this->Back_button->Click += gcnew System::EventHandler(this, &Form4::Back_button_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::DodgerBlue;
			this->label1->Location = System::Drawing::Point(137, 103);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(75, 16);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Штрих-код";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::Color::DodgerBlue;
			this->label2->Location = System::Drawing::Point(247, 44);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(40, 16);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Дата";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::Color::DodgerBlue;
			this->label3->Location = System::Drawing::Point(306, 105);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(86, 16);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Количество";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label4->ForeColor = System::Drawing::Color::DodgerBlue;
			this->label4->Location = System::Drawing::Point(219, 182);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(107, 16);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Наименование";
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
			// Form4
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(719, 424);
			this->Controls->Add(this->user_label);
			this->Controls->Add(this->name_label);
			this->Controls->Add(this->Back_button);
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
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void count_textbox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void Back_button_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void add_turn_button_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if(insert_turn_panel->Visible == false)
			 {
				 insert_turn_panel->Visible = true;
			 }
			 else
			 {
				 insert_turn_panel->Visible = false;
			 }
			 
		 }
private: System::Void Form4_Load(System::Object^  sender, System::EventArgs^  e);
};
}
