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
	private: MySqlConnection^	conn;
	private: MySqlCommand^	cmd;
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
	private: System::Windows::Forms::Label^  exe_label;
	private: System::Windows::Forms::Panel^  list_panel;
	private: System::Windows::Forms::Label^  msg_label;
	private: System::Windows::Forms::Timer^  timer_msg;
	private: System::Windows::Forms::Timer^  timer_exe;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Barcode;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Count;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  date;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  status;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  whois;
	private: System::Windows::Forms::DataGridViewButtonColumn^  comm;
	private: System::Windows::Forms::Button^  check_button;
	private: System::Windows::Forms::Button^  hide_button;
	private: System::Windows::Forms::NotifyIcon^  action_ico;
	private: System::Windows::Forms::Timer^  check_turn_timer;
	private: Point mouseOffset;

	private: System::ComponentModel::IContainer^  components;
	private: 

	protected: 

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
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form4::typeid));
			this->bar_textbox = (gcnew System::Windows::Forms::TextBox());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->count_textbox = (gcnew System::Windows::Forms::TextBox());
			this->item_textbox = (gcnew System::Windows::Forms::TextBox());
			this->turn_button = (gcnew System::Windows::Forms::Button());
			this->insert_turn_panel = (gcnew System::Windows::Forms::Panel());
			this->msg_label = (gcnew System::Windows::Forms::Label());
			this->item_name_label = (gcnew System::Windows::Forms::Label());
			this->count_label = (gcnew System::Windows::Forms::Label());
			this->date_label = (gcnew System::Windows::Forms::Label());
			this->bar_label = (gcnew System::Windows::Forms::Label());
			this->list_panel = (gcnew System::Windows::Forms::Panel());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Barcode = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Count = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->date = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->status = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->whois = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->comm = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->name_label = (gcnew System::Windows::Forms::Label());
			this->add_turn_button = (gcnew System::Windows::Forms::Button());
			this->list_button = (gcnew System::Windows::Forms::Button());
			this->back_button = (gcnew System::Windows::Forms::Button());
			this->user_label = (gcnew System::Windows::Forms::Label());
			this->exe_label = (gcnew System::Windows::Forms::Label());
			this->timer_msg = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer_exe = (gcnew System::Windows::Forms::Timer(this->components));
			this->check_button = (gcnew System::Windows::Forms::Button());
			this->hide_button = (gcnew System::Windows::Forms::Button());
			this->action_ico = (gcnew System::Windows::Forms::NotifyIcon(this->components));
			this->check_turn_timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->insert_turn_panel->SuspendLayout();
			this->list_panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
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
			this->dateTimePicker1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form4::dateTimePicker1_KeyDown);
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
			this->count_textbox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form4::count_textbox_KeyDown);
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
			this->turn_button->Click += gcnew System::EventHandler(this, &Form4::turn_button_Click);
			this->turn_button->Enter += gcnew System::EventHandler(this, &Form4::turn_button_Enter);
			this->turn_button->Leave += gcnew System::EventHandler(this, &Form4::turn_button_Leave);
			// 
			// insert_turn_panel
			// 
			this->insert_turn_panel->BackColor = System::Drawing::Color::Black;
			this->insert_turn_panel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->insert_turn_panel->Controls->Add(this->msg_label);
			this->insert_turn_panel->Controls->Add(this->item_name_label);
			this->insert_turn_panel->Controls->Add(this->count_label);
			this->insert_turn_panel->Controls->Add(this->date_label);
			this->insert_turn_panel->Controls->Add(this->bar_label);
			this->insert_turn_panel->Controls->Add(this->turn_button);
			this->insert_turn_panel->Controls->Add(this->dateTimePicker1);
			this->insert_turn_panel->Controls->Add(this->count_textbox);
			this->insert_turn_panel->Controls->Add(this->item_textbox);
			this->insert_turn_panel->Controls->Add(this->bar_textbox);
			this->insert_turn_panel->Location = System::Drawing::Point(705, 44);
			this->insert_turn_panel->Name = L"insert_turn_panel";
			this->insert_turn_panel->Size = System::Drawing::Size(515, 309);
			this->insert_turn_panel->TabIndex = 4;
			this->insert_turn_panel->Visible = false;
			this->insert_turn_panel->VisibleChanged += gcnew System::EventHandler(this, &Form4::insert_turn_panel_VisibleChanged);
			// 
			// msg_label
			// 
			this->msg_label->AutoSize = true;
			this->msg_label->ForeColor = System::Drawing::Color::Red;
			this->msg_label->Location = System::Drawing::Point(186, 20);
			this->msg_label->Name = L"msg_label";
			this->msg_label->Size = System::Drawing::Size(0, 13);
			this->msg_label->TabIndex = 8;
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
			// list_panel
			// 
			this->list_panel->BackColor = System::Drawing::Color::Black;
			this->list_panel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->list_panel->Controls->Add(this->dataGridView1);
			this->list_panel->Location = System::Drawing::Point(118, 30);
			this->list_panel->Name = L"list_panel";
			this->list_panel->Size = System::Drawing::Size(515, 323);
			this->list_panel->TabIndex = 8;
			this->list_panel->Visible = false;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToOrderColumns = true;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::Black;
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {this->Barcode, 
				this->Count, this->date, this->status, this->whois, this->comm});
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle4->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle4->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::Color::DodgerBlue;
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle4;
			this->dataGridView1->GridColor = System::Drawing::Color::Maroon;
			this->dataGridView1->Location = System::Drawing::Point(-1, -1);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(513, 307);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form4::dataGridView1_CellClick);
			// 
			// Barcode
			// 
			this->Barcode->HeaderText = L"Штрихкод";
			this->Barcode->MaxInputLength = 13;
			this->Barcode->Name = L"Barcode";
			this->Barcode->ReadOnly = true;
			this->Barcode->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			// 
			// Count
			// 
			this->Count->HeaderText = L"Количество";
			this->Count->MaxInputLength = 10;
			this->Count->Name = L"Count";
			this->Count->ReadOnly = true;
			this->Count->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Count->Width = 65;
			// 
			// date
			// 
			this->date->HeaderText = L"Дата";
			this->date->MaxInputLength = 8;
			this->date->Name = L"date";
			this->date->ReadOnly = true;
			this->date->Width = 110;
			// 
			// status
			// 
			this->status->HeaderText = L"Статус";
			this->status->MaxInputLength = 5;
			this->status->Name = L"status";
			this->status->ReadOnly = true;
			this->status->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->status->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Programmatic;
			this->status->Width = 65;
			// 
			// whois
			// 
			this->whois->HeaderText = L"Исполнитель";
			this->whois->MaxInputLength = 15;
			this->whois->Name = L"whois";
			this->whois->ReadOnly = true;
			this->whois->Width = 85;
			// 
			// comm
			// 
			this->comm->HeaderText = L"Действие";
			this->comm->Name = L"comm";
			this->comm->ReadOnly = true;
			this->comm->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->comm->Text = L"Удалить";
			this->comm->UseColumnTextForButtonValue = true;
			this->comm->Width = 84;
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
			this->add_turn_button->Location = System::Drawing::Point(13, 84);
			this->add_turn_button->Name = L"add_turn_button";
			this->add_turn_button->Size = System::Drawing::Size(100, 30);
			this->add_turn_button->TabIndex = 0;
			this->add_turn_button->Text = L"Добавить";
			this->add_turn_button->UseVisualStyleBackColor = true;
			this->add_turn_button->Click += gcnew System::EventHandler(this, &Form4::add_turn_button_Click);
			this->add_turn_button->Enter += gcnew System::EventHandler(this, &Form4::add_turn_button_Enter);
			this->add_turn_button->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form4::add_turn_button_KeyDown);
			this->add_turn_button->Leave += gcnew System::EventHandler(this, &Form4::add_turn_button_Leave);
			// 
			// list_button
			// 
			this->list_button->ForeColor = System::Drawing::Color::DodgerBlue;
			this->list_button->Location = System::Drawing::Point(12, 120);
			this->list_button->Name = L"list_button";
			this->list_button->Size = System::Drawing::Size(100, 30);
			this->list_button->TabIndex = 1;
			this->list_button->Text = L"Список";
			this->list_button->UseVisualStyleBackColor = true;
			this->list_button->Click += gcnew System::EventHandler(this, &Form4::list_button_Click);
			this->list_button->Enter += gcnew System::EventHandler(this, &Form4::list_button_Enter);
			this->list_button->Leave += gcnew System::EventHandler(this, &Form4::list_button_Leave);
			// 
			// back_button
			// 
			this->back_button->ForeColor = System::Drawing::Color::DodgerBlue;
			this->back_button->Location = System::Drawing::Point(13, 228);
			this->back_button->Name = L"back_button";
			this->back_button->Size = System::Drawing::Size(100, 30);
			this->back_button->TabIndex = 4;
			this->back_button->Text = L"Назад";
			this->back_button->UseVisualStyleBackColor = true;
			this->back_button->Click += gcnew System::EventHandler(this, &Form4::back_button_Click);
			this->back_button->Enter += gcnew System::EventHandler(this, &Form4::back_button_Enter);
			this->back_button->Leave += gcnew System::EventHandler(this, &Form4::back_button_Leave);
			// 
			// user_label
			// 
			this->user_label->AutoEllipsis = true;
			this->user_label->AutoSize = true;
			this->user_label->BackColor = System::Drawing::Color::Transparent;
			this->user_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->user_label->ForeColor = System::Drawing::Color::DodgerBlue;
			this->user_label->Location = System::Drawing::Point(605, 12);
			this->user_label->Name = L"user_label";
			this->user_label->Size = System::Drawing::Size(0, 16);
			this->user_label->TabIndex = 5;
			// 
			// exe_label
			// 
			this->exe_label->AutoEllipsis = true;
			this->exe_label->AutoSize = true;
			this->exe_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->exe_label->ForeColor = System::Drawing::Color::DodgerBlue;
			this->exe_label->Location = System::Drawing::Point(118, 375);
			this->exe_label->Name = L"exe_label";
			this->exe_label->Size = System::Drawing::Size(45, 16);
			this->exe_label->TabIndex = 6;
			this->exe_label->Text = L"label5";
			// 
			// timer_msg
			// 
			this->timer_msg->Tick += gcnew System::EventHandler(this, &Form4::timer_msg_Tick);
			// 
			// timer_exe
			// 
			this->timer_exe->Tick += gcnew System::EventHandler(this, &Form4::timer_exe_Tick);
			// 
			// check_button
			// 
			this->check_button->ForeColor = System::Drawing::Color::DodgerBlue;
			this->check_button->Location = System::Drawing::Point(13, 156);
			this->check_button->Name = L"check_button";
			this->check_button->Size = System::Drawing::Size(100, 30);
			this->check_button->TabIndex = 2;
			this->check_button->Text = L"Проверка";
			this->check_button->UseVisualStyleBackColor = true;
			this->check_button->Click += gcnew System::EventHandler(this, &Form4::check_button_Click);
			this->check_button->Enter += gcnew System::EventHandler(this, &Form4::check_button_Enter);
			this->check_button->Leave += gcnew System::EventHandler(this, &Form4::check_button_Leave);
			// 
			// hide_button
			// 
			this->hide_button->ForeColor = System::Drawing::Color::DodgerBlue;
			this->hide_button->Location = System::Drawing::Point(13, 192);
			this->hide_button->Name = L"hide_button";
			this->hide_button->Size = System::Drawing::Size(100, 30);
			this->hide_button->TabIndex = 3;
			this->hide_button->Text = L"Свернуть";
			this->hide_button->UseVisualStyleBackColor = true;
			this->hide_button->Click += gcnew System::EventHandler(this, &Form4::hide_button_Click);
			this->hide_button->Enter += gcnew System::EventHandler(this, &Form4::hide_button_Enter);
			this->hide_button->Leave += gcnew System::EventHandler(this, &Form4::hide_button_Leave);
			// 
			// action_ico
			// 
			this->action_ico->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"action_ico.Icon")));
			this->action_ico->Text = L"Action";
			this->action_ico->Visible = true;
			this->action_ico->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form4::action_ico_MouseDoubleClick);
			// 
			// check_turn_timer
			// 
			this->check_turn_timer->Enabled = true;
			this->check_turn_timer->Interval = 60000;
			this->check_turn_timer->Tick += gcnew System::EventHandler(this, &Form4::check_turn_timer_Tick);
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
			this->Controls->Add(this->hide_button);
			this->Controls->Add(this->check_button);
			this->Controls->Add(this->list_panel);
			this->Controls->Add(this->exe_label);
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
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Form4::Form4_FormClosed);
			this->Load += gcnew System::EventHandler(this, &Form4::Form4_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form4::Form4_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form4::Form4_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form4::Form4_MouseUp);
			this->insert_turn_panel->ResumeLayout(false);
			this->insert_turn_panel->PerformLayout();
			this->list_panel->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void clean_textboxs();
private: System::Void count_textbox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void load_list_panel();
private: System::Void back_button_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void add_turn_button_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if(insert_turn_panel->Visible == false)
			 {
				 insert_turn_panel->Visible = true;
				 insert_turn_panel->Location = System::Drawing::Point(118,44);
				 list_panel->Visible = false;

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

				 clean_textboxs();
			 }
		 }
private: System::Void Form4_Load(System::Object^  sender, System::EventArgs^  e);
private: System::Void list_button_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 insert_turn_panel->Visible =false;

			 list_panel->Location = System::Drawing::Point(118,44);
			
			 if(list_panel->Visible == true)
				 list_panel->Visible = false;
			 else
			 {
				 list_panel->Visible = true;
				 load_list_panel();
			 }

		 }
private: System::Void set_msg_on_timer(String^ text);
private: System::Void set_exe_on_timer(String^ text);
private: System::Void check_turn_circle();
private: System::Void warning_sale_final(String^ bar);
private: System::Void check_turn(String^ bar,String^ count,DateTime^ date);
private: System::Void query(String^ bar);
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

			 if(bar_textbox->Text == "" || count_textbox->Text == "" || item_textbox->Text == "")
			 {
				turn_button->ForeColor = Color::Red;
			 }

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
					set_msg_on_timer("Что-то цифр маловато!");
					return;
				}
				else
				{
					query(bar_textbox->Text);
				}

			 }


		 }
private: System::Void timer_msg_Tick(System::Object^  sender, System::EventArgs^  e) {
			 timer_msg->Enabled = false;
			 msg_label->Text = "";

		 }
private: System::Void timer_exe_Tick(System::Object^  sender, System::EventArgs^  e) {
			 timer_exe->Enabled = false;
			 exe_label->Text = "";
		 }
private: System::Void count_textbox_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			 if (e->KeyCode == Keys::Up)
			 {
				 dateTimePicker1->Focus();
			 }
			 if (e->KeyCode == Keys::Left)
			 {
				 bar_textbox->Focus();
			 }
			 if (e->KeyCode == Keys::Down || e->KeyCode == Keys::Right || e->KeyCode == Keys::Enter)
			 {
				 Int32 count;
				 
				 try
				 {
					 count = Convert::ToInt32(count_textbox->Text);
				 }
				 catch (Exception^ exc)
				 {
					 set_exe_on_timer(exc->Message);
					 set_msg_on_timer("Количество не верное!");
				 }

				 if(count_textbox->TextLength < 1 || count < 1)
				 {
					 set_msg_on_timer("Количество не верное!");
					 count_textbox->Text = "";
					 count_textbox->Focus();
					 return;
				 }
				 else
					 turn_button->Focus();
			 }
		 }
private: System::Void dateTimePicker1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
		 {
			 if (e->KeyCode == Keys::Enter)
			 {
				 count_textbox->Focus();
			 }
		 }
private: System::Void turn_button_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 if(bar_textbox->Text == "" || count_textbox->Text == "" || item_textbox->Text == "")
			 {
				 set_msg_on_timer("                Отклонено!");

				 clean_textboxs();

				 bar_textbox->Focus();
				 return;
			 }
			 else
			 {
				 turn_insert_query();
			 }
		 }
private: System::Void turn_insert_query();
private: System::Void query_delete(String^ val);
private: System::Void insert_turn_panel_VisibleChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if(insert_turn_panel->Visible == true)
			 {
				 dateTimePicker1->Format = DateTimePickerFormat::Custom;
				 dateTimePicker1->CustomFormat = "yyyy-MM-dd";
			 }
		 }
private: System::Void Form4_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e);
private: System::Void add_turn_button_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
		 {
			  if (e->KeyCode == Keys::Right)
			  {
				  insert_turn_panel->Visible = true;
			  }
		 }
private: System::Void dataGridView1_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);
private: System::Void action_ico_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
		 {
			 this->Show();
			 action_ico->Visible = false;
		 }
private: System::Void hide_button_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 this->Hide();
			 action_ico->Visible = true;
		 }
private: System::Void check_button_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 check_turn_circle();
		 }
private: System::Void check_turn_timer_Tick(System::Object^  sender, System::EventArgs^  e) 
		 {
			 check_turn_circle();
		 }
private: System::Void Form4_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
private: System::Void Form4_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
private: System::Void Form4_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);

private: System::Void add_turn_button_Enter(System::Object^  sender, System::EventArgs^  e)
		 {
			 add_turn_button->ForeColor = Color::Green;

			 add_turn_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				 static_cast<System::Byte>(204)));
		 }

private: System::Void add_turn_button_Leave(System::Object^  sender, System::EventArgs^  e)
		 {
			 add_turn_button->ForeColor = Color::DodgerBlue;

			 add_turn_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				 static_cast<System::Byte>(204)));
		 }

private: System::Void list_button_Enter(System::Object^  sender, System::EventArgs^  e)
		 {
			 list_button->ForeColor = Color::Green;

			 list_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				 static_cast<System::Byte>(204)));
		 }

private: System::Void list_button_Leave(System::Object^  sender, System::EventArgs^  e)
		 {
			 list_button->ForeColor = Color::DodgerBlue;

			 list_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				 static_cast<System::Byte>(204)));
		 }

private: System::Void back_button_Enter(System::Object^  sender, System::EventArgs^  e)
		 {
			 back_button->ForeColor = Color::Green;

			 back_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				 static_cast<System::Byte>(204)));
		 }

private: System::Void back_button_Leave(System::Object^  sender, System::EventArgs^  e)
		 {
			 back_button->ForeColor = Color::DodgerBlue;

			 back_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				 static_cast<System::Byte>(204)));
		 }

private: System::Void hide_button_Enter(System::Object^  sender, System::EventArgs^  e)
		 {
			 hide_button->ForeColor = Color::Green;

			 hide_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				 static_cast<System::Byte>(204)));
		 }

private: System::Void hide_button_Leave(System::Object^  sender, System::EventArgs^  e)
		 {
			 hide_button->ForeColor = Color::DodgerBlue;

			 hide_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				 static_cast<System::Byte>(204)));
		 }

private: System::Void check_button_Enter(System::Object^  sender, System::EventArgs^  e)
		 {
			 check_button->ForeColor = Color::Green;

			 check_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				 static_cast<System::Byte>(204)));
		 }

private: System::Void check_button_Leave(System::Object^  sender, System::EventArgs^  e)
		 {
			 check_button->ForeColor = Color::DodgerBlue;

			 check_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				 static_cast<System::Byte>(204)));
		 }
};
}
