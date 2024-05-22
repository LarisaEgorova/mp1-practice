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

Klass& Journal:: operator[](int idx) {
	return (idx >= 0 && idx < count) ? klasses[idx] : throw "Out of range";
}
Klass& Journal:: operator[](int idx) const {
	return (idx >= 0 && idx < count) ? klasses[idx] : throw "Out of range";
}

int Journal::fillJournal() {

	Klass klass;
	ifstream in;
	string file;

	for (int i = 0; i < this->GetCount(); i++) {
		file = to_string(i + 1) + ".txt";
		in.open(file);
		if (!in.is_open()) {
			cout << "Файла класса не существует\n";
			return -1;
		}
		in >> klass;
		(*this)[i] = klass;
		in.close();
	}
	return 0;
}

void Journal::first_inf_sort(int choice) {
	int* support = (*this)[choice - 1].SortIndeces();

	cout << "ID\t" << "Класс\t" << "ФИО" << endl;
	for (int i = 0; i < this->klasses[choice-1].GetCount(); i++) {
		cout << support[i]+1 << "\t" << (*this)[choice-1][support[i]].GetNum() << "\t" <<
			(*this)[choice - 1][support[i]].GetFIO() << endl;
	}

	delete[] support;
	return;
}