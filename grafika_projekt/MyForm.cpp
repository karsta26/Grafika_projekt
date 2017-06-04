#include "MyForm.h"
// elo elo trzy dwa zero

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	grafika_projekt::MyForm form;
	Application::Run(%form);
}
