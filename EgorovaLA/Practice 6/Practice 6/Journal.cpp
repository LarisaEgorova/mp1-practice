#include "Journal.h"

Journal :: Journal(int count) {
	this->count = count;
	this->klasses = new Klass[this->count];
}

Journal::~Journal() {
	delete[] this->klasses;
}
int Journal::GetCount() const {
	return this->count;

}
void Journal::SetCount(int count) {
	this->count = count;
}
Klass Journal::GetKlass(int i) const {
	return this->klasses[i];
}
void Journal::SetKlass(int i, Klass& klass) {
	this->klasses[i] = klass;
}

void first_inf_nosort(Journal& Kmass, int choice) {
	for (int i = 0; i < Kmass.GetKlass(choice - 1).GetCount(); i++) {
		cout << "ID: " << i + 1 << " ÔÈÎ: " << Kmass.GetKlass(choice - 1).GetStudents(i).GetFIO() << endl <<
			"Êëàññ: " << Kmass.GetKlass(choice - 1).GetStudents(i).GetNum() << "\n";
	}
	return;
}

void first_inf_sort(Journal& Kmass, int* support, int choice) {
	for (int i = 0; i < Kmass.GetKlass(choice - 1).GetCount(); i++) {
		cout << "ID: " << support[i] + 1 << " ÔÈÎ: " << Kmass.GetKlass(choice - 1).GetStudents(support[i]).GetFIO() << "\n" <<
			"Êëàññ: " << Kmass.GetKlass(choice - 1).GetStudents(support[i]).GetNum() << "\n";
	}
	return;
}