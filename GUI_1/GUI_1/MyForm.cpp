#include "MyForm.h"
using namespace GUI_1;
[STAThreadAttribute]
int main(array<System::String ^> ^args){
	// Mengaktifkan efek visual Windows XP sebelum kontrol apa pun dibuat
		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false);
	// Membuat jendela utama dan menjalankannya
	Application::Run(gcnew MyForm()); //di mana MyForm() Masukkan nama formulir utama Anda dengan tanda()[Bracket]
		return 0;
}
