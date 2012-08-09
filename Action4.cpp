#include "Form1.h"
#include "Form3.h"
#include <windows.h>

using namespace Action;
using namespace System::IO;
using namespace System::Runtime::InteropServices;
using namespace System::Security::Cryptography;

Void Form4::previous_button_Click(System::Object^  sender, System::EventArgs^  e)
{
	Form3^ Form3_ref       =       gcnew Form3;
	Form3_ref->Show();
	this->Hide();

	Form3::settings_button->Focus();
}

Void Form4::Form4_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e)
{
	Form3^ Form3_ref       =       gcnew Form3;
	Form3_ref->Show();
	this->Hide();
}