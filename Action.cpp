#include "Form1.h"
#include <windows.h>

using namespace Action;
using namespace System::Runtime::InteropServices;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	Application::Run(gcnew Form1());
	return 0;
}

Void Form1::Form1_Load(System::Object^  sender, System::EventArgs^  e)
{
	if(mysqlcheck())
	{
		status_label->Text = "Онлайн";
		status_label->ForeColor = Color::Green ;
	}
	else
	{
		status_label->ForeColor = Color::Red ;
		status_label->Text = "Оффлайн";
	}

	send_label->Text = "";
	dateTimePicker1->Format = DateTimePickerFormat::Custom;
	dateTimePicker2->Format = DateTimePickerFormat::Custom;
	dateTimePicker1->CustomFormat = "yyyy-MM-dd";
	dateTimePicker2->CustomFormat = "yyyy-MM-dd";

	char buf[50];
	GetPrivateProfileString("SETTINGS", "date_start","2012, 8 ,1",buf,sizeof(buf),SystemStringToChar(Environment::CurrentDirectory+"\\config.ini"));
	
	dateTimePicker1->Value = System::DateTime(Convert::ToDateTime(CharToSystemString(buf)));
	
	GetPrivateProfileString("SETTINGS", "date_end","2012, 8 ,1",buf,sizeof(buf),SystemStringToChar(Environment::CurrentDirectory+"\\config.ini"));

	dateTimePicker2->Value = System::DateTime(Convert::ToDateTime(CharToSystemString(buf)));
}

Void Form1::bar_box_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (bar_box->TextLength == bar_box->MaxLength)
	{
		query(bar_box->Text);
		old_price_box->Focus();
	}
}

Void Form1::bar_box_KeyDown_1(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
{
	if (e->KeyCode == Keys::Enter || e->KeyCode == Keys::Right || e->KeyCode == Keys::Down ) 
	{
		query(bar_box->Text);
		old_price_box->Focus();
	}
}

Void Form1::old_price_box_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
{
	if (e->KeyCode == Keys::Enter || e->KeyCode == Keys::Right || e->KeyCode == Keys::Down)
	{
		if(old_price_box->TextLength < 3)
		{
			String^ message = "Оставить пустое значение старой цены?";
			String^ caption = "Внимание";

			MessageBoxButtons buttons = MessageBoxButtons::YesNo;
			System::Windows::Forms::DialogResult result;

			result = MessageBox::Show( this, message, caption, buttons );

			if ( result == ::DialogResult::Yes )
			{
				new_price_box->Focus();
				old_price_box->Text = "";
			}
			else
			{
				old_price_box->Focus();
			}
		}
		else
			new_price_box->Focus();
	}
}

Void Form1::new_price_box_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
{
	if (e->KeyCode == Keys::Enter || e->KeyCode == Keys::Right || e->KeyCode == Keys::Down)
	{
		if(new_price_box->TextLength < 3)
		{

		}
		else
			send_button->Focus();
	}
}

Void Form1::send_button_Click(System::Object^  sender, System::EventArgs^  e)
{
	if(bar_box->Text == "" || true_bar_box->Text == "" || name_box->Text == "" || true_bar_box->Text == "" || new_price_box->Text == "")
	{
		send_label->ForeColor = Color::Red ;
		send_label->Text = "Отклонено";
		bar_box->Focus();
		return;	
	}

 	String^ connStr = String::Format("server={0};uid={1};pwd={2};database={3};",
 		"192.168.1.11", "root", "fallen", "action");
 
 	conn = gcnew MySqlConnection(connStr);
 
 	MySqlDataReader^ reader = nullptr;
 
	try
	{
		conn->Open();

		cmd = gcnew MySqlCommand("DELETE FROM `action`.`action_price` WHERE `barcode`='"+true_bar_box->Text+"'", conn);

		cmd->ExecuteNonQuery();

		conn->Close();
	}
	catch (Exception^ exc)
	{
		MessageBox::Show("Exception: " + exc->Message);

		send_label->ForeColor = Color::Red ;
		send_label->Text = "Отклонено";
		send_button->Focus();
	}
 	try
 	{
		conn->Open();

		cmd = gcnew MySqlCommand("INSERT INTO `action`.`action_price`(`barcode`,`price_old`,`price_new`,`start_action`,`stop_action`) VALUES ( '"+true_bar_box->Text+"','"+old_price_box->Text+"','"+new_price_box->Text+"','"+dateTimePicker1->Text+"','"+dateTimePicker2->Text+"')", conn);

		cmd->ExecuteNonQuery();
 	}
	catch (Exception^ exc)
	{
		MessageBox::Show("Exception: " + exc->Message);

		send_label->ForeColor = Color::Red ;
		send_label->Text = "Отклонено";
		send_button->Focus();
	}
 	finally
 	{
 		if (reader != nullptr)
 			reader->Close();

		send_label->ForeColor = Color::Green ;
		send_label->Text = "Успешно";

		s_status_timer->Enabled = true;

		bar_box->Text = "";
		name_box->Text = "";
		true_bar_box->Text = "";
		old_price_box->Text = "";
		new_price_box->Text = "";
		bar_box->Focus();
 	}
}

Boolean Form1::mysqlcheck()
{
	String^ connStr = String::Format("server={0};uid={1};pwd={2};database={3};",
		"192.168.1.100", "admin", "12345", "ukmserver");

	conn = gcnew MySqlConnection(connStr);

	MySqlDataReader^ reader = nullptr;

	try
	{
		conn->Open();
		return true;
	}
	catch (Exception^ exc)
	{
		MessageBox::Show("Exception: " + exc->Message);
		return false;
	}
	finally
	{
		if (reader != nullptr)
			reader->Close();
	}

}

Void Form1::exit_button_Click(System::Object^  sender, System::EventArgs^  e)
{
	Action->Visible = false;
	Application::Exit();
}

Void Form1::hide_button_Click(System::Object^  sender, System::EventArgs^  e)
{
	this->Hide();
	Action->Visible = true;
}

Void Form1::Action_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	this->Show();
	Action->Visible = false;
}

Void Form1::clean_button_Click(System::Object^  sender, System::EventArgs^  e)
{
	bar_box->Text = "";
	name_box->Text = "";
	true_bar_box->Text = "";
	old_price_box->Text = "";
	new_price_box->Text = "";
}

Void Form1::query(String^ bar)
{
	String^ connStr = String::Format("server={0};uid={1};pwd={2};database={3};",
		"192.168.1.100", "admin", "12345", "ukmserver");

	conn = gcnew MySqlConnection(connStr);

	MySqlDataReader^ reader = nullptr;

	try
	{
		conn->Open();

		cmd = gcnew MySqlCommand("SELECT a.name, b.price ,c.id,c.item \n"
			"FROM trm_in_var C \n"
			"LEFT JOIN trm_in_items A ON A.id=C.item \n"
			"LEFT JOIN trm_in_pricelist_items B ON B.item=c.item \n"
			"WHERE a.id='"+bar+"'\n"
			" AND (b.pricelist_id="+GetPrivateProfileInt("SETTINGS", "id_pricelist",1,SystemStringToChar(Environment::CurrentDirectory+"\\config.ini"))+")", conn);

		MySqlDataReader^ reader = cmd->ExecuteReader();

		if(reader->Read())
		{
			name_box->Text = reader->GetString(0);
			true_bar_box->Text = reader->GetString(2);
			new_price_box->Text = Convert::ToString(reader->GetInt32(1));
		}
		else
		{
			send_label->ForeColor = Color::Red;
			send_label->Text = "Не найдено!";
		}

	}
	catch (Exception^ exc)
	{
		MessageBox::Show("Exception: " + exc->Message);
	}
	finally
	{
		if (reader != nullptr)
			reader->Close();
	}
}

char* Form1::SystemStringToChar(System::String^ string)
{
	return (char*)(void*)Marshal::StringToHGlobalAnsi(string);
}

String^ Form1::CharToSystemString(char* ch)
{
	char * chr=new char[]=ch;
	System::String^ str;
	for(int i=0;chr[i]!='\0';i++)
	{
		str+=wchar_t(ch[i]);
	}
	return str;
}