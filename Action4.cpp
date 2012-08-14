#include "Form1.h"
#include "Form2.h"
#include "Form3.h"
#include "Form4.h"
#include <windows.h>

int xOffset4, yOffset4;
bool isMouseDown4 = false;

using namespace Action;
using namespace System::Globalization;

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
	exe_label->Text = "";

	dataGridView1->DefaultCellStyle->SelectionBackColor = System::Drawing::SystemColors::HighlightText;
	dataGridView1->DefaultCellStyle->SelectionForeColor = System::Drawing::SystemColors::Desktop;
}

Void Form4::set_msg_on_timer(String^ text)
{
	timer_msg->Interval = 3000;
	timer_msg->Enabled = true;
	msg_label->Text = text;
}

Void Form4::set_exe_on_timer(String^ text)
{
	timer_exe->Interval = 3000;
	timer_exe->Enabled = true;
	exe_label->Text = text;

	Form1::log_write(text,"EXCEPTION","exception");
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

		//MB THIS NEED FOR CHECK COUNT NUBER IN `bar` 12 OR 13 (for 13 not work)
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
			set_msg_on_timer("              Не найдено!");

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

		if(conn->State  == ConnectionState::Open)
			conn->Close();
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

		if(conn->State  == ConnectionState::Open)
			conn->Close();

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
			dataGridView1->Rows->Add(reader->GetString(0),reader->GetString(1),reader->GetString(2),reader->GetInt32(3),reader->GetString(4));
		}
	}

	catch (Exception^ exc)
	{
		set_exe_on_timer(exc->Message);
	}

	finally
	{
		if (reader != nullptr)
			reader->Close();

		if(conn->State  == ConnectionState::Open)
			conn->Close();
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
		set_exe_on_timer(exc->Message);

		stat = false;
	}

	finally
	{
		if (reader != nullptr)
			reader->Close();

		if(conn->State  == ConnectionState::Open)
			conn->Close();

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

		//this need  to fxd
		if((Convert::ToString(this->dataGridView1->CurrentRow->Cells[3]->Value)) == "В очереди")
		{
			String^ message = "Товар еще не продан,вы действительно хотите снять его с очереди?";
			String^ caption = "Внимание";

			MessageBoxButtons buttons = MessageBoxButtons::YesNo;
			System::Windows::Forms::DialogResult result;

			result = MessageBox::Show( this, message, caption, buttons );

			if ( result == ::DialogResult::Yes )
			{
				query_delete(val);
				Form1::log_write(val,"DELETE","deleted");
			}
			else
				return;
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

Void Form4::check_turn_circle()
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

		cmd = gcnew MySqlCommand("SELECT barcode,count,date FROM priority WHERE status = '1'", conn);

		MySqlDataReader^ reader = cmd->ExecuteReader();

		while(reader->Read())
		{
			 check_turn(reader->GetString(0),reader->GetString(1),reader->GetDateTime(2));
		}
	}

	catch (Exception^ exc)
	{
		set_exe_on_timer(exc->Message);
	}

	finally
	{
		if (reader != nullptr)
			reader->Close();

		if(conn->State  == ConnectionState::Open)
			conn->Close();
	}
}

Void Form4::check_turn(String^ bar,String^ count,DateTime^ date)
{
	char buf[50];
	String^ sale;

	CultureInfo^ myCI = gcnew CultureInfo( "ja-JP",false );

	String^ EntryDate = (gcnew DateTime())->Now.ToString(myCI)->Replace("/","-");

	GetPrivateProfileString("SETTINGS", "srv_global","192.168.1.100",buf,sizeof(buf),Form1::SystemStringToChar(Environment::CurrentDirectory+"\\config.ini"));

	String^ connStr = String::Format("server={0};uid={1};pwd={2};database={3};",
		Form1::CharToSystemString(buf), "admin", "12345", "ukmserver");

	conn = gcnew MySqlConnection(connStr);

	MySqlDataReader^ reader = nullptr;

	try
	{
		conn->Open();

		cmd = gcnew MySqlCommand("SELECT \n"
			"SUM(IF(h.type IN (0,5), 1, -1) * i.quantity) quantity \n"
			"FROM trm_in_pos c INNER JOIN \n"
			"trm_out_receipt_header h ON h.cash_id = c.cash_id INNER JOIN \n"
			"trm_out_receipt_item i ON i.cash_id = h.cash_id AND i.receipt_header = h.id  LEFT JOIN \n"
			"trm_out_receipt_item i2 ON (h.cash_id = i2.cash_id AND h.id = i2.receipt_header AND i2.link_item = i.id) INNER JOIN \n"
			"trm_out_receipt_footer f ON f.cash_id = h.cash_id AND f.id = h.id \n"
			"WHERE i2.link_item IS NULL AND i.type = 0 AND \n"
			"h.type IN (0,5,1,4) AND f.result IN (0) AND 1001 = c.store_id AND i.item LIKE '"+bar+"%' AND (f.date >= '"+date->ToString(myCI)->Replace("/","-")+"' AND f.date <= '"+EntryDate+"' )", conn);

		MySqlDataReader^ reader = cmd->ExecuteReader();


		while(reader->Read())
		{
			if(reader->IsDBNull(0))
			{
				Form1::log_write(bar+" "+date->ToString(myCI)->Replace("/","-")+" "+EntryDate,"NOTSALE","notsale");
				    return;
			}

			sale = reader->GetString(0);
		}
	}

	catch (Exception^ exc)
	{
		set_exe_on_timer(exc->Message);
	}

	finally
	{
		if (reader != nullptr)
			reader->Close();

		if(conn->State  == ConnectionState::Open)
			conn->Close();

		if ((Convert::ToDouble(sale) >= Convert::ToDouble(count)))
		{
			warning_sale_final(bar);
		}
	}
}

Void Form4::warning_sale_final(String^ bar)
{
	MessageBox::Show("Внимание: товар "+bar+" продан!" );
	Form1::log_write(user_label->Text+"] Товар продан: "+bar,"SALE","sale");
};

Void Form4::Form4_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	if (e->Button == Windows::Forms::MouseButtons::Left)
	{
		xOffset4 = - e->X - SystemInformation::FrameBorderSize.Width;
		yOffset4 = - e->Y - SystemInformation::FrameBorderSize.Height;
		mouseOffset = System::Drawing::Point(xOffset4, yOffset4);
		isMouseDown4 = true;
	}
}

Void Form4::Form4_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	if(isMouseDown4)
	{
		Point mousePos = Control::MousePosition;
		mousePos.Offset(mouseOffset.X, mouseOffset.Y);
		Location = mousePos;
	}
}

Void Form4::Form4_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	isMouseDown4 = false;
}