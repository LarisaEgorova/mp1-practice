#include <Windows.h>
#include "Journal.h"
#include "Function.h"

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int klases = 0; 

	cout << "Введите количество классов\n";
	cin >> klases;

	Journal Kmass(klases);
	if (Kmass.fillJournal() == -1) return 0;
	
	menu(Kmass);
	
	cout << "Завершение...";

	return 0;
}