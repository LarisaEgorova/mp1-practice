#include "Klass.h"

Klass::Klass(int n) {
	this->count = n;
	this->students = new Student[n];
}

Klass::Klass() {
	this->count = 0;
	this->students = nullptr;
}

Klass::~Klass() {
	delete[] this->students;
}

Klass::Klass(const Klass&K) {
	this->count = K.count;
	this->students = new Student[this->count];
	for (int i = 0; i < this->count; i++) {
		this->students[i] = K.students[i];
	}
}

void Klass::SetStudents(int n, Student& s) {
	this->students[n] = s;
}
Student Klass::GetStudents(int n) const {
	return this->students[n];
}
void Klass::SetCount(int c) {
	this->count = c;
}
int Klass::GetCount() const {
	return this->count;
}

ifstream& operator >>(ifstream& in, Klass& K) {
	int count;
	Student s;
	in >> count;
	K = Klass(count);
	for (int j = 0; j < count; j++) {
		int f = 1;
		in >> s;
		K.SetStudents(j, s);
	}
	return in;
}

ostream& operator <<(ostream& out, const Klass& K) {
	for (int i = 0; i < K.count; i++) {
		out << K.students[i] << endl;
	}
	return out;
}

const Klass& Klass :: operator =(const Klass& K) {
	this->count = K.count;
	this->students = new Student[this->count];
	for (int i = 0; i < this->count; i++) {
		this->students[i] = K.students[i];
	}
	return *this;
}

void Klass:: Sort(int* support, int left, int right) {
	FIO* fio = new FIO[this->GetCount()];
	for (int i = 0; i < this->GetCount(); i++) {
		support[i] = i;
		fio[i] = this->GetStudents(i).GetFIO();
	}
	quick_sort(fio, support, 0, right);
	delete[] fio;
	return;
}

void quick_sort(FIO* arrs, int* support, int left, int right) {
	int centric = left + (right - left) / 2;
	FIO center_el = arrs[centric];
	int lt = left;
	int rt = right;
	FIO swap;
	int  swape;
	while (lt <= rt) {
		while (arrs[lt] < center_el) lt++;
		while (arrs[rt] > center_el) rt--;
		if (lt <= rt) {
			swap = arrs[lt];
			swape = support[lt];
			arrs[lt] = arrs[rt];
			support[lt] = support[rt];
			arrs[rt] = swap;
			support[rt] = swape;
			lt++;
			rt--;
		}
	}
	if (left < rt) quick_sort(arrs, support, left, rt);
	if (right > lt) quick_sort(arrs, support, lt, right);
}
