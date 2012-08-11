#include "Form1.h"
#include "Form2.h"
#include "Form3.h"
#include "Form4.h"
#include <windows.h>

using namespace Action;

Void Form4::back_button_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 Form3^ Form3_ref       =       gcnew Form3;
			 Form3_ref->Show();
			 this->Hide();

			 Form3::priority_button->Focus();
		 }

Void Form4::Form4_Load(System::Object^  sender, System::EventArgs^  e)
{
	user_label->Text = Form1::global_username;

	dataGridView1->DefaultCellStyle->SelectionBackColor = System::Drawing::SystemColors::HighlightText;
	dataGridView1->DefaultCellStyle->SelectionForeColor = System::Drawing::SystemColors::Desktop;
}

Void Form4::set_msg_on_timer(String^ text)
{
	timer_msg->Interval = 3000;
	timer_msg->Enabled = true;
	msg_label->Text = text;
	msg_label->ForeColor = Color::DodgerBlue;
}

Void Form4::set_exe_on_timer(String^ text)
{
	timer_exe->Interval = 3000;
	timer_exe->Enabled = true;
	exe_label->Text = text;
}

Void Form4::query(String^ bar)
{
	char buf[50];

	GetPrivateProfileString("SETTINGS", "srv_global","192.168.1.100",buf,sizeof(buf),Form1::SystemStringToChar(Environment::CurrentDirectory+"\\config.ini"));

	String^ connStr = String::Format("server={0};uid={1};pwd={2};database={3};",
		Form1::CharToSystemString(buf), "admin", "12345", "ukmserver");

	conn = gcnew MySqlConnection(connStr);

	MySqlDataReader^ reader = nullptr;

	try
	{
		conn->Open();

		cmd = gcnew MySqlCommand("SELECT a.name \n"
			"FROM trm_in_var C \n"
			"LEFT JOIN trm_in_items A ON A.id=C.item \n"
			"LEFT JOIN trm_in_pricelist_items B ON B.item=c.item \n"
			"WHERE a.id='"+bar+"'\n"
			" AND (b.pricelist_id="+GetPrivateProfileInt("SETTINGS", "id_pricelist",1,Form1::SystemStringToChar(Environment::CurrentDirectory+"\\config.ini"))+")", conn);

		MySqlDataReader^ reader = cmd->ExecuteReader();

		if(reader->Read())
		{
			item_textbox->Text = reader->GetString(0);
			count_textbox->Focus();
		}
		else
		{
			msg_label->ForeColor = Color::Red;
			msg_label->Text = "Не найдено!";

			clean_textboxs();

			bar_textbox->Focus();
		}

	}
	catch (Exception^ exc)
	{
		set_exe_on_timer(exc->Message);

		clean_textboxs();

		bar_textbox->Focus();
	}
	finally
	{
		if (reader != nullptr)
			reader->Close();
	}
}

Void Form4::turn_insert_query()
{
	char buf[50];
	boolean stat = true;

	GetPrivateProfileString("SETTINGS", "srv_local","192.168.1.11",buf,sizeof(buf),Form1::SystemStringToChar(Environment::CurrentDirectory+"\\config.ini"));

	String^ connStr = String::Format("server={0};uid={1};pwd={2};database={3};",
		Form1::CharToSystemString(buf), "root", "***REMOVED***", "action");

	conn = gcnew MySqlConnection(connStr);

	MySqlDataReader^ reader = nullptr;

	try
	{
		conn->Open();

		cmd = gcnew MySqlCommand("DELETE FROM `action`.`priority` WHERE `barcode`='"+bar_textbox->Text+"'", conn);

		cmd->ExecuteNonQuery();

		conn->Close();
	}

	catch (Exception^ exc)
	{
		set_exe_on_timer(exc->Message);
	}

	try
	{
		conn->Open();

		cmd = gcnew MySqlCommand("INSERT INTO `action`.`priority`(`barcode`,`count`,`date`,`status`,`who`) VALUES ( '"+bar_textbox->Text+"','"+count_textbox->Text+"','"+dateTimePicker1->Text+"','1','"+user_label->Text+"')", conn);

		cmd->ExecuteNonQuery();
	}

	catch (Exception^ exc)
	{
		set_exe_on_timer(exc->Message);

		msg_label->ForeColor = Color::Red ;
		set_msg_on_timer("                Отклонено!");
		stat = false;
	}

	finally
	{
		if (reader != nullptr)
			reader->Close();

		if(stat)
		{
			msg_label->ForeColor = Color::Green;
			set_msg_on_timer("                Успешно");
		}

		clean_textboxs();

		bar_textbox->Focus();
	}
}

Void Form4::Form4_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e)
		 {
			 Form3^ Form3_ref       =       gcnew Form3;
			 Form3_ref->Show();
			 this->Hide();

			 Form3::priority_button->Focus();
		 }

Void Form4::load_list_panel()
{
	char buf[50];

	GetPrivateProfileString("SETTINGS", "srv_local","192.168.1.11",buf,sizeof(buf),Form1::SystemStringToChar(Environment::CurrentDirectory+"\\config.ini"));

	String^ connStr = String::Format("server={0};uid={1};pwd={2};database={3};",
		Form1::CharToSystemString(buf), "root", "***REMOVED***", "action");

	conn = gcnew MySqlConnection(connStr);

	MySqlDataReader^ reader = nullptr;

	try
	{
		conn->Open();

		cmd = gcnew MySqlCommand("SELECT * FROM priority", conn);

		MySqlDataReader^ reader = cmd->ExecuteReader();

		dataGridView1->Rows->Clear();

		while(reader->Read())
		{
			dataGridView1->Rows->Add(reader->GetString(0),reader->GetString(1),reader->GetString(2),reader->GetString(3),reader->GetString(4));
		}
	}

	catch (Exception^ exc)
	{
		//TODO
		MessageBox::Show("Exception: " + exc->Message);
	}

	finally
	{
		if (reader != nullptr)
			reader->Close();
	}
}

Void Form4::query_delete(String^ val)
{
	char buf[50];
	boolean stat = true;

	GetPrivateProfileString("SETTINGS", "srv_local","192.168.1.11",buf,sizeof(buf),Form1::SystemStringToChar(Environment::CurrentDirectory+"\\config.ini"));

	String^ connStr = String::Format("server={0};uid={1};pwd={2};database={3};",
		Form1::CharToSystemString(buf), "root", "***REMOVED***", "action");

	conn = gcnew MySqlConnection(connStr);

	MySqlDataReader^ reader = nullptr;

	try
	{
		conn->Open();

		cmd = gcnew MySqlCommand("DELETE FROM `action`.`priority` WHERE `barcode`='"+val+"'", conn);

		cmd->ExecuteNonQuery();

		conn->Close();
	}

	catch (Exception^ exc)
	{
		MessageBox::Show("Exception: " + exc->Message);

		stat = false;
	}

	finally
	{
		if (reader != nullptr)
			reader->Close();

		if(stat)
		{
			set_exe_on_timer("                Удалено!");
			load_list_panel();
		}

	}
}

Void Form4::dataGridView1_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
{
	if (e->RowIndex < 0 || e->ColumnIndex != dataGridView1->Columns["comm"]->Index)
		return;
	else
	{
		String^ val = Convert::ToString(this->dataGridView1->CurrentRow->Cells[0]->Value);

		if((Convert::ToInt32(this->dataGridView1->CurrentRow->Cells[3]->Value)) == 1)
		{
			String^ message = "Товар еще не продан,вы действительно хотите снять его с очереди?";
			String^ caption = "Внимание";

			MessageBoxButtons buttons = MessageBoxButtons::YesNo;
			System::Windows::Forms::DialogResult result;

			result = MessageBox::Show( this, message, caption, buttons );

			if ( result == ::DialogResult::Yes )
			{
				query_delete(val);
			}
			else
			{
				//TODO
				return;
			}
		}
		else
			query_delete(val);
	}
}

Void Form4::clean_textboxs()
{
	count_textbox->Text = "";
	bar_textbox->Text = "";
	item_textbox->Text = "";
}