#pragma once
#include "Klass.h"

class Journal {

private:
	int count;
	Klass* klasses;
public:
	Journal(int);
	~Journal();
	int GetCount() const;
	void SetCount(int);
	Klass GetKlass(int) const; // Klass& operator[](int idx)
	void SetKlass(int, Klass&); // Klass& operator[](int idx) const
	int fillJournal();
	void first_inf_nosort(int choice); // operator << для Klass
	void first_inf_sort(int choice); // int* indeces = klasses[i].Sort(); ...;  delete [] indeces;
};
