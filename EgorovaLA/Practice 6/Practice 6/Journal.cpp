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

void Journal::first_inf_nosort(int choice) {
	for (int i = 0; i < this->GetKlass(choice - 1).GetCount(); i++) {
		cout << "ID: " << i + 1 << " ÔÈÎ: " << this->GetKlass(choice - 1).GetStudents(i).GetFIO() << endl <<
			"Êëàññ: " << this->GetKlass(choice - 1).GetStudents(i).GetNum() << "\n";
	}
	return;
}

void Journal::first_inf_sort( int* support, int choice) {
	for (int i = 0; i < this->GetKlass(choice - 1).GetCount(); i++) {
		cout << "ID: " << support[i] + 1 << " ÔÈÎ: " << this->GetKlass(choice - 1).GetStudents(support[i]).GetFIO() << "\n" <<
			"Êëàññ: " << this->GetKlass(choice - 1).GetStudents(support[i]).GetNum() << "\n";
	}
	return;
}