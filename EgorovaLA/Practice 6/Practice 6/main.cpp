#include "Klass.h"
#include "Function.h"

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ifstream in;
	int count=0, klases=0;
	while (1) {
		cout << "Введите количество классов\n";
		cin >> klases;
		in = work_with_base(klases, count);
		if (count != klases) {
			cout << "Неверное количество классов"
				<<"Не хватает баз данных\n";
			continue;
		}
		break;
	}

	Student s;
	Klass Kmass (count);

	int *quantity = append_klassmass(in, count, klases, Kmass);

	Klass* LibKlasses = (Klass*) operator new(sizeof(Klass)*klases);
	for (int j = 0; j < klases; j++) {
		LibKlasses[j] = Klass(quantity[j]);
	}
	
	separate_klassmass(quantity, LibKlasses, Kmass, klases, count);
	menu(LibKlasses, quantity, klases);

	cout << "Завершение...";

	delete[] quantity;
	for (int i = 0; i < klases; i++) {
		LibKlasses[i].~Klass();
	}
	operator delete(LibKlasses);
}