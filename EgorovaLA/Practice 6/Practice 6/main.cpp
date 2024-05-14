#include "Journal.h"
#include "Function.h"

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int klases = 0; 

	cout << "Введите количество классов\n";
	cin >> klases;

	Student s;
	Journal Kmass(klases);

	if (append_klassmass(Kmass) == -1) return 0;
	
	menu(Kmass);
	
	cout << "Завершение...";

	return 0;
}