#pragma once

#include "Student.h"

class Klass {
public:
	Klass(int n);
	Klass(const Klass&);
	Klass();
	~Klass();

	void SetCount(int);
	int GetCount() const;

	Student& operator[](int idx); 
	Student& operator[](int idx) const;
	const Klass& operator =(const Klass&);
	friend ifstream& operator >>(ifstream& in, Klass& K);
	friend ostream& operator <<(ostream& out, const Klass& K);
	int* SortIndeces() const;

private:
	void quick_sort(FIO* arrs, int* support, int left, int right) const;
	int count;
	Student* students;
};
