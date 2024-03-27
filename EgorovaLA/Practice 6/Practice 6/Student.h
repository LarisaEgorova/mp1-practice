#pragma once

#include "Adress.h"
#include "Date.h"
#include "FIO.h"

class Student {
public:
	Student(Date&, FIO&, Adress&, int, string&);
	Student(const Student&);
private:
	Date birth;
	FIO names;
	Adress adress;
	int numberK;
	string gender;
};

