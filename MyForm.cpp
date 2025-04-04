#include "MyForm.h"
#include <cliext/vector>
using namespace System;
using namespace System::Windows::Forms;
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	CodeBrain::MyForm form;
	Application::Run(% form);
}

