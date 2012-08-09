#include "Form1.h"
#include "Form3.h"
#include <windows.h>

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

