#pragma once

#include "Student.h"

class Klass {
public:
	Klass(int n);
	Klass(const Klass&);
	Klass();
	~Klass();
	void SetStudents(int, Student&);
	Student GetStudents(int) const;
	void SetCount(int);
	int GetCount() const;

	const Klass& operator =(const Klass&);
	friend ifstream& operator >>(ifstream& in, Klass& K);
	friend ostream& operator <<(ostream& out, const Klass& K);
	void Sort(int* support, int left, int right);

private:
	int count;
	Student* students;
};

void quick_sort(FIO* arrs, int* support, int left, int right);