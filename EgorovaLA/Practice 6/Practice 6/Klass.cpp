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

Student* Klass::GetStudents() const {
	return this->students;
}

ostream& operator <<(ostream& out, const Klass& K) {
	for (int i = 0; i < K.count; i++) {
		out << K.students[i] << endl;
	}
	return out;
}
