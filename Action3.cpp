#include "Form1.h"
#include "Form2.h"
#include "Form3.h"
#include <windows.h>

int xOffset2, yOffset2;
bool isMouseDown2 = false;

using namespace Action;
using namespace System::IO;
using namespace System::Runtime::InteropServices;
using namespace System::Security::Cryptography;

Void Form3::Form3_Load(System::Object^  sender, System::EventArgs^  e)
{
	user_label->Text = Form1::global_username;
}

Void Form3::write_action_button_Click(System::Object^  sender, System::EventArgs^  e)
{
	Form1^ Form1_ref       =       gcnew Form1;
	Form1_ref->Show();
	this->Hide();
}

Void Form3::Form3_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e)
{
	Form2^ Form2_ref       =       gcnew Form2;
	Form2_ref->Show();
	this->Hide();

	Form1::global_username = "";
	Form2::pass_textbox->Focus();
}

Void Form3::Form3_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	if (e->Button == Windows::Forms::MouseButtons::Left)
	{
		xOffset2 = - e->X - SystemInformation::FrameBorderSize.Width;
		yOffset2 = - e->Y - SystemInformation::FrameBorderSize.Height;
		mouseOffset2 = System::Drawing::Point(xOffset2, yOffset2);
		isMouseDown2 = true;
	}
}

Void Form3::Form3_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	if(isMouseDown2)
	{
		Point mousePos = Control::MousePosition;
		mousePos.Offset(mouseOffset2.X, mouseOffset2.Y);
		Location = mousePos;
	}
}

Void Form3::Form3_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	isMouseDown2 = false;
}
