#pragma once

#include "Adress.h"
#include "Date.h"
#include "FIO.h"

class Student {
public:
	Student(FIO&,int,string,Date&,Adress&);
	Student(const Student&);
	Student();
	//friend ifstream& operator >>(ifstream& in, Student& s);
	//friend ostream& operator <<(ostream& out, const Student& s);
	const Student& operator =(const Student&);
private:
	FIO fio;
	int numberK;
	string gender;
	Date birth;
	Adress adress;
};
