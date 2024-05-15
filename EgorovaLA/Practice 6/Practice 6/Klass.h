#pragma once

#include "Student.h"

class Klass {
public:
	Klass(int n);
	Klass(const Klass&);
	Klass();
	~Klass();
	Student& operator[](int idx) // class[i]=student;
	{
		return (idx >= 0 && idx < count) ? students[idx] : throw "Out of range";
	};
	Student& operator[](int idx) const // cout << class[i];
	{
		return (idx >= 0 && idx < count) ? students[idx] : throw "Out of range";
	};
	//void SetStudents(int, const Student&);
	//Student GetStudents(int) const;
	void SetCount(int);
	int GetCount() const;

	const Klass& operator =(const Klass&);
	friend ifstream& operator >>(ifstream& in, Klass& K);
	friend ostream& operator <<(ostream& out, const Klass& K);
	int* SortIndeces() const;
	//void Sort(int* support, int left, int right);

private:
	void quick_sort(FIO* arrs, int* support, int left, int right) const;

	int count;
	Student* students;
};

//void quick_sort(FIO* arrs, int* support, int left, int right);