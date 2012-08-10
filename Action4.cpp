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
}