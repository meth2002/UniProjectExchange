#include "selectpage.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    UniProjectExchange::selectpage^ form = gcnew UniProjectExchange::selectpage();
    Application::Run(form);
    return 0;
}

