#include "Form1.h"
#include "Form3.h"
#include <windows.h>

int xOffset, yOffset;
bool isMouseDown = false;

using namespace Action;
using namespace System::IO;
using namespace System::Runtime::InteropServices;
using namespace System::Security::Cryptography;

Void Form2::login_button_Enter(System::Object^  sender, System::EventArgs^  e)
{
		 check_save_login->Visible = true;

		 login_button->ForeColor = Color::Green;

		 login_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
			 static_cast<System::Byte>(204)));
}

Void Form2::login_button_Leave(System::Object^  sender, System::EventArgs^  e)
{
	login_button->ForeColor = Color::DodgerBlue;

	login_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
		static_cast<System::Byte>(204)));
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
				set_msg_on_timer("Готов к работе!");
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

