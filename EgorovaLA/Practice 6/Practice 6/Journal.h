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
	Klass GetKlass(int) const;
	void SetKlass(int, Klass&);
};

void first_inf_nosort(Journal& Kmass, int choice);
void first_inf_sort(Journal& Kmass, int* support, int choice);