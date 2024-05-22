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
	Klass& operator[](int idx); 
	Klass& operator[](int idx) const; 
	int fillJournal();
	void first_inf_sort(int choice); 
};
