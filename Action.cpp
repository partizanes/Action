#include "Form1.h"
#include "Form2.h"
#include "Form3.h"
#include <windows.h>

int xOffset, yOffset;
bool isMouseDown = false;

using namespace Action;
using namespace System::IO;
using namespace System::Runtime::InteropServices;
using namespace System::Security::Cryptography;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	Application::Run(gcnew Form2());
	return 0;
}

Void Form1::Form1_Load(System::Object^  sender, System::EventArgs^  e)
{
	status_label->Text = "";
	backgroundWorker1->RunWorkerAsync();

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

	user_label->Text = Form1::global_username;
}

Void Form1::bar_box_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (bar_box->TextLength == bar_box->MaxLength)
	{
		query(bar_box->Text);
	}
}

Void Form1::bar_box_KeyDown_1(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
{
	if (e->KeyCode == Keys::Enter || e->KeyCode == Keys::Right || e->KeyCode == Keys::Down ) 
	{
		query(bar_box->Text);
	}

	if (e->KeyCode == Keys::Escape)
	{
		clean_button->PerformClick();
		bar_box->Focus();
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

	if (e->KeyCode == Keys::Up || e->KeyCode == Keys::Left )
	{
		bar_box->Focus();
	}

	if (e->KeyCode == Keys::Escape)
	{
		clean_button->PerformClick();
		bar_box->Focus();
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

	if (e->KeyCode == Keys::Up || e->KeyCode == Keys::Left )
	{
		old_price_box->Focus();
	}

	if (e->KeyCode == Keys::Escape)
	{
		clean_button->PerformClick();
		bar_box->Focus();
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

    char buf[50];
    boolean stat = true;

    GetPrivateProfileString("SETTINGS", "srv_local","192.168.1.11",buf,sizeof(buf),SystemStringToChar(Environment::CurrentDirectory+"\\config.ini"));

    String^ connStr = String::Format("server={0};uid={1};pwd={2};database={3};",
    CharToSystemString(buf), "root", "fallen", "action");

 	conn = gcnew MySqlConnection(connStr);
 
 	MySqlDataReader^ reader = nullptr;
 
	try
	{
		conn->Open();

		if(bar_box->TextLength == 5)
			cmd = gcnew MySqlCommand("DELETE FROM `action`.`action_price` WHERE `barcode`='"+bar_box->Text+"'", conn);
		else
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

		int i;

		if (active_check->Checked == true)
			i = 1 ;
		else
			i = 0 ;

		if(old_price_box->Text == "")
			old_price_box->Text = "0";
		if(bar_box->TextLength == 5)
			cmd = gcnew MySqlCommand("INSERT INTO `action`.`action_price`(`barcode`,`price_old`,`price_new`,`start_action`,`stop_action`,`active`) VALUES ( '"+bar_box->Text+"','"+old_price_box->Text+"','"+new_price_box->Text+"','"+dateTimePicker1->Text+"','"+dateTimePicker2->Text+"','"+i+"')", conn);
		else
			cmd = gcnew MySqlCommand("INSERT INTO `action`.`action_price`(`barcode`,`price_old`,`price_new`,`start_action`,`stop_action`,`active`) VALUES ( '"+true_bar_box->Text+"','"+old_price_box->Text+"','"+new_price_box->Text+"','"+dateTimePicker1->Text+"','"+dateTimePicker2->Text+"','"+i+"')", conn);

		cmd->ExecuteNonQuery();
 	}

	catch (Exception^ exc)
	{
		MessageBox::Show("Exception: " + exc->Message);

		send_label->ForeColor = Color::Red ;
		send_label->Text = "Отклонено";
		send_button->Focus();
		stat = false;
	}

 	finally
 	{
 		if (reader != nullptr)
 			reader->Close();

		send_label->ForeColor = Color::Green ;
		send_label->Text = "Успешно";

		if(stat)
		{
			log_write(bar_box->Text+"  "+true_bar_box->Text+"  "+name_box->Text+"  "+old_price_box->Text+"  "+new_price_box->Text+"  "+dateTimePicker1->Text+"  "+dateTimePicker2->Text+"  "+"Успешно","query","Action");
			listBox1->Items->Add (bar_box->Text+"  "+true_bar_box->Text+"  "+name_box->Text+"  "+old_price_box->Text+"  "+new_price_box->Text+"  "+dateTimePicker1->Text+"  "+dateTimePicker2->Text+"  "+"Успешно");
		}
		else
		{
			log_write(bar_box->Text+"  "+true_bar_box->Text+"  "+name_box->Text+"  "+old_price_box->Text+"  "+new_price_box->Text+"  "+dateTimePicker1->Text+"  "+dateTimePicker2->Text+"  "+"Отклонено","query","Action");
			listBox1->Items->Add (bar_box->Text+"  "+true_bar_box->Text+"  "+name_box->Text+"  "+old_price_box->Text+"  "+new_price_box->Text+"  "+dateTimePicker1->Text+"  "+dateTimePicker2->Text+"  "+"Отклонено");
		}
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
	char buf[50];

	GetPrivateProfileString("SETTINGS", "srv_global","192.168.1.100",buf,sizeof(buf),SystemStringToChar(Environment::CurrentDirectory+"\\config.ini"));

	String^ connStr = String::Format("server={0};uid={1};pwd={2};database={3};",
		CharToSystemString(buf), "admin", "12345", "ukmserver");

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

	Form3^ Form3_ref       =       gcnew Form3;
	Form3_ref->Show();
	this->Hide();

	Form3::write_action_button->Focus();
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
	char buf[50];

	GetPrivateProfileString("SETTINGS", "srv_global","192.168.1.100",buf,sizeof(buf),SystemStringToChar(Environment::CurrentDirectory+"\\config.ini"));

	String^ connStr = String::Format("server={0};uid={1};pwd={2};database={3};",
		CharToSystemString(buf), "admin", "12345", "ukmserver");

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
			old_price_box->Focus();
		}
		else
		{
			send_label->ForeColor = Color::Red;
			send_label->Text = "Не найдено!";

			clean_button->PerformClick();
			bar_box->Text = "";
			bar_box->Focus();
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

Void Form1::send_button_Enter(System::Object^  sender, System::EventArgs^  e)
{
	if(name_box->Text == "" || bar_box->Text == "" || true_bar_box->Text == "" || new_price_box->Text == "" || old_price_box->Text == "" || active_check->Checked == false)
	{
		send_button->ForeColor = Color::Red ;
	}
	else
	{
		send_button->ForeColor = Color::Green ;
	}
}

Void Form1::send_button_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
{
	if (e->KeyCode == Keys::Up || e->KeyCode == Keys::Left )
	{
		new_price_box->Focus();
	}

	if (e->KeyCode == Keys::Right || e->KeyCode == Keys::Down )
	{
		send_button->PerformClick();
	}

	if (e->KeyCode == Keys::Multiply || e->KeyCode == Keys::Add)
	{
		if(active_check->Checked == true)
		{
			active_check->Checked = false;
		}
		else
		{
			active_check->Checked = true;
		}
	}

	if (e->KeyCode == Keys::Escape)
	{
		clean_button->PerformClick();
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

Void Form1::log_write(String^ str,String^ reason,String^ logname)
{
	String^ EntryTime = (gcnew DateTime())->Now.ToLongTimeString();
	String^ EntryDate = (gcnew DateTime())->Today.ToShortDateString();
	if(!Directory::Exists(Environment::CurrentDirectory+"/log/"))
	{
		Directory::CreateDirectory((Environment::CurrentDirectory+"/log/"));
	}
	String^ fileName = "log/"+logname+".log";
	StreamWriter^ sw = gcnew StreamWriter(fileName,true,System::Text::Encoding::UTF8);
	sw->WriteLine("["+EntryDate+"]["+EntryTime+"]["+reason+"]"+" "+str);
	sw->Close();
}

Void Form1::backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e)
{
	if(mysqlcheck())
		status_label->ForeColor = Color::Green ;
	else
		status_label->ForeColor = Color::Red ;

}

Void Form1::backgroundWorker1_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e)
{
	if(status_label->ForeColor == Color::Green)
		status_label->Text = "Онлайн";
	else
		status_label->Text = "Оффлайн";
}

Void Form2::pass_textbox_Enter(System::Object^  sender, System::EventArgs^  e)
{
	if(login_textbox->TextLength < 3)
	{
		set_msg_on_timer("Сначало логин!");
		login_textbox->Focus();
	}
	else
	{
		check_save_login->Visible = true;
	}
}

Void Form2::login_button_Enter(System::Object^  sender, System::EventArgs^  e)
{
		 check_save_login->Visible = true;
}

Void Form2::pass_textbox_Leave(System::Object^  sender, System::EventArgs^  e)
{
	check_save_login->Visible = true;
}

Void Form2::login_textbox_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
{
	if (e->KeyCode == Keys::Right || e->KeyCode == Keys::Down || e->KeyCode == Keys::Enter || e->KeyCode == Keys::Tab )
	{
		if(login_textbox->TextLength < 3)
		{
			Random^ rnd=gcnew Random();
			int i = rnd->Next(3);
			switch (i)
			{
			case 0:
				set_msg_on_timer("Логин кто вводить будет?");
				break;
			case 1:
				set_msg_on_timer("Так дело не пойдёт...Логин?");
				break;
			case 2:
				set_msg_on_timer("Так сложно представиться?");
				break;
			default:
				break;
			}
		}
		else
		{
			check_save_login->Visible = true;
			pass_textbox->Focus();

			Random^ rnd=gcnew Random();
			int i = rnd->Next(3);
			switch (i)
			{
			case 0:
				set_msg_on_timer("Очень приятно ;) я Action!");
				break;
			case 1:
				set_msg_on_timer("Привет "+login_textbox->Text +"!");
				break;
			case 2:
				set_msg_on_timer("Мне скучно!Давай поиграем!");
				break;
			default:
				break;
			}
		}
	}

	if (e->KeyCode == Keys::Escape)
	{
		Application::Exit();
	}
}

Void Form2::pass_textbox_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
{
	if (e->KeyCode == Keys::Right || e->KeyCode == Keys::Down || e->KeyCode == Keys::Enter || e->KeyCode == Keys::Tab)
	{
		if(pass_textbox->TextLength < 3)
		{
			Random^ rnd=gcnew Random();
			int i = rnd->Next(3);

			switch (i)
			{
			case 0:
				set_msg_on_timer("Издеваетесь?без пароля не пущу");
				break;
			case 1:
				set_msg_on_timer("Забыли?Не верю!");
				break;
			case 2:
				set_msg_on_timer("Увы,без пароля нельзя!");
				break;
			default:
				break;
			}
		}
		else
		{
			check_save_login->Focus();
		}
	}

	if (e->KeyCode == Keys::Left || e->KeyCode == Keys::Up)
	{
		login_textbox->Focus();
	}

	if (e->KeyCode == Keys::Escape)
	{
		Application::Exit();
	}
}

Void Form2::check_save_login_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
{
	if (e->KeyCode == Keys::Right || e->KeyCode == Keys::Down || e->KeyCode == Keys::Enter || e->KeyCode == Keys::Tab)
	{
		login_button->Focus();
	}
	if (e->KeyCode == Keys::Left || e->KeyCode == Keys::Up)
	{
		pass_textbox->Focus();
	}
	if (e->KeyCode == Keys::Escape)
	{
		Application::Exit();
	}
}

Void Form2::login_button_Click(System::Object^  sender, System::EventArgs^  e)
{
	if(check_save_login->Checked)
	{
		WritePrivateProfileString("SETTINGS","save_login",Form1::SystemStringToChar(" true"),Form1::SystemStringToChar(Environment::CurrentDirectory+"\\config.ini"));
		WritePrivateProfileString("SETTINGS","client_login",Form1::SystemStringToChar(" "+login_textbox->Text),Form1::SystemStringToChar(Environment::CurrentDirectory+"\\config.ini"));
	}
	else
	{
		WritePrivateProfileString("SETTINGS","save_login",Form1::SystemStringToChar(" false"),Form1::SystemStringToChar(Environment::CurrentDirectory+"\\config.ini"));
		WritePrivateProfileString("SETTINGS","client_login",Form1::SystemStringToChar(""),Form1::SystemStringToChar(Environment::CurrentDirectory+"\\config.ini"));
	}

	if(Auth(login_textbox->Text,getMD5String(getMD5String("135a" + pass_textbox->Text + "a531"))))
	{
		Form3^ Form3_ref       =       gcnew Form3;
		Form3_ref->Show();
		this->Hide();
	}
}

bool Form2::Auth(String^ login, String^ pass)
{
	char buf[50];

	GetPrivateProfileString("SETTINGS", "srv_local","192.168.1.11",buf,sizeof(buf),Form1::SystemStringToChar(Environment::CurrentDirectory+"\\config.ini"));

	String^ connStr = String::Format("server={0};uid={1};pwd={2};database={3}",
		 Form1::CharToSystemString(buf), "root", "***REMOVED***", "action");

	conn = gcnew MySqlConnection(connStr);

	MySqlDataReader^ reader = nullptr;

	bool authok = false;

	try
	{
		conn->Open();

		cmd = gcnew MySqlCommand("SELECT name,password,online FROM users WHERE `name` ='"+login+"'", conn);

		MySqlDataReader^ reader = cmd->ExecuteReader();
		if(reader->Read())
		{

			if(login == reader->GetString(0) && pass == reader->GetString(1))
			{
				authok = true;

				if (reader->GetInt32(2)>0)
				{
					authok = false;
					set_msg_on_timer(login+" уже в авторизован");
				}

				Form1::global_username = reader->GetString(0);
				Form1::log_write(Form1::global_username +" авторизован успешно","AUTH","Action");
			}

			else
			{
				authok = false;
				set_msg_on_timer("Неверные данные");
				pass_textbox->Text = "";
				pass_textbox->Focus();
				Form1::log_write(login + " отказано в авторизации","AUTH","Action");
			}
		}
		else
		{
			authok = false;
			set_msg_on_timer("Неверные данные");
			pass_textbox->Text = "";
			pass_textbox->Focus();
		}
	}
	catch (Exception^ exc)
	{

		set_exe_on_timer("Exception: " + exc->Message);
	}
	finally
	{
		if (reader != nullptr)
			reader->Close();
	}
	return authok;
}

String^ Form2::getMD5String(String^ data)
{
	MD5^ md5 = gcnew MD5CryptoServiceProvider;
	array<Byte>^ result = md5->ComputeHash(System::Text::Encoding::UTF8->GetBytes(data));
	return BitConverter::ToString(result)->Replace("-", String::Empty)->ToLower();;
}

Void Form2::login_button_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
{
	if (e->KeyCode == Keys::Left || e->KeyCode == Keys::Up)
	{
		check_save_login->Focus();
	}
	if (e->KeyCode == Keys::Escape)
	{
		Application::Exit();
	}
}

void Form2::LastLogin(System::Object^  sender, System::EventArgs^  e)
{
	char buf[15];

	GetPrivateProfileString("SETTINGS", "save_login","false",buf,sizeof(buf),Form1::SystemStringToChar(Environment::CurrentDirectory+"\\config.ini"));

	if(Form1::CharToSystemString(buf) == "true")
	{
		check_save_login->Checked = true;
		GetPrivateProfileString("SETTINGS", "client_login","",buf,sizeof(buf),Form1::SystemStringToChar(Environment::CurrentDirectory+"\\config.ini"));

		login_textbox->Text = Form1::CharToSystemString(buf);
		login_textbox->Select(login_textbox->TextLength,login_textbox->TextLength);
	}

	Form1::log_write("Форма авторизации успешно загружена","SYSTEM","action");

	pass_textbox->Text = "";
}

Void Form2::set_msg_on_timer(String^ text)
{
	msg_label_timer->Interval = 3000;
	msg_label_timer->Enabled = true;
	msg_label->Text = text;
}

Void Form2::msg_exe_timer_Tick(System::Object^  sender, System::EventArgs^  e)
{
	msg_exe_timer->Enabled = false;
	exe_label->Text = "";
}

Void Form2::set_exe_on_timer(String^ text)
{
	msg_exe_timer->Interval = 7000;
	msg_exe_timer->Enabled = true;

	exe_label->Text = text;

	Form1::log_write(text,"EXCEPTION","Action");
}

Void Form2::msg_label_timer_Tick(System::Object^  sender, System::EventArgs^  e)
{
	msg_label_timer->Enabled = false;
	msg_label->Text = "";
}

Void Form2::Form2_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	if (e->Button == Windows::Forms::MouseButtons::Left)
	{
		xOffset = - e->X - SystemInformation::FrameBorderSize.Width;
		yOffset = - e->Y - SystemInformation::FrameBorderSize.Height;
		mouseOffset = System::Drawing::Point(xOffset, yOffset);
		isMouseDown = true;
	}
}

Void Form2::Form2_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	if(isMouseDown)
	{
		Point mousePos = Control::MousePosition;
		mousePos.Offset(mouseOffset.X, mouseOffset.Y);
		Location = mousePos;
	}
}

Void Form2::Form2_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	isMouseDown = false;
}

Void Form2::name_label_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
		 {
			 if (e->Button == Windows::Forms::MouseButtons::Left)
			 {
				 xOffset = - e->X - name_label->Location.X;
				 yOffset = - e->Y - name_label->Location.Y;
				 mouseOffset = System::Drawing::Point(xOffset, yOffset);
				 isMouseDown = true;
			 }
		 }

Void Form2::name_label_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
		 {
			 if(isMouseDown)
			 {
				 Point mousePos = Control::MousePosition;
				 mousePos.Offset(mouseOffset.X, mouseOffset.Y);
				 Location = mousePos;
			 }
		 }

Void Form2::name_label_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
		 {
			 isMouseDown = false;
		 }

Void Form2::login_panel_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	if (e->Button == Windows::Forms::MouseButtons::Left)
	{
		xOffset = - e->X - login_panel->Location.X;
		yOffset = - e->Y - login_panel->Location.Y;
		mouseOffset = System::Drawing::Point(xOffset, yOffset);
		isMouseDown = true;
	}
}

Void Form2::login_panel_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	if(isMouseDown)
	{
		Point mousePos = Control::MousePosition;
		mousePos.Offset(mouseOffset.X, mouseOffset.Y);
		Location = mousePos;
	}
}

Void Form2::login_panel_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	isMouseDown = false;
}

Void Form1::Form1_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e)
{
	Form3^ Form3_ref       =       gcnew Form3;
	Form3_ref->Show();
	this->Hide();

	Form3::write_action_button->Focus();
}
