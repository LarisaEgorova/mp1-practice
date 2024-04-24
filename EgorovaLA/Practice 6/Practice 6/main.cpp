#include "Klass.h"
#include "Function.h"

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string* massfile;
	int klases = 0; int count = 0;

	while (1) {
		cout << "Введите количество классов\n";
		cin >> klases;
		massfile = new string[klases];
		count += work_with_base(klases, massfile);
		if (count != klases) {
			cout << "Неверное количество классов"
				<<"Не хватает баз данных\n";
			continue;
		}
		klases = count;
		break;
	}

	Student s;
	Klass *Kmass =new Klass[count];

	append_klassmass(massfile, klases, Kmass);
	
	menu(Kmass, klases);
	
	cout << "Завершение...";

	delete[] massfile;
	for (int i = 0; i < klases; i++) {
		Kmass[i].~Klass();
	}

	return 0;
}