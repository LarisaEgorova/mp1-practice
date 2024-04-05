#include "Klass.h"
#include "Function.h"

int main() {

	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);

	ifstream in;
	in=work_with_base();
	int count, klases=0;

	in >> count;
	in >> klases;

	Student s;
	Klass Kmass (count);

	int *quantity = append_klassmass(in, count, klases, Kmass);

	Klass* LibKlasses = (Klass*) operator new(sizeof(Klass)*klases);
	for (int j = 0; j < klases; j++) {
		new(&LibKlasses[j]) Klass(quantity[j]);
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