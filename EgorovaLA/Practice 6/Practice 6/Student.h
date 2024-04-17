#pragma once

#include "Adress.h"
#include "Date.h"
#include "FIO.h"

class Student {
public:
	Student(FIO&,int,string,Date&,Adress&);
	Student(const Student&);
	Student();

	FIO GetFIO() const;
	void SetFIO(FIO&);
	int GetNum()const;
	void SetNum(int);
	string GetG()const;
	void SetG(string);
	Adress GetAdress()const;
	void SetAdress(Adress&);
	Date GetDate()const;
	void SetDate(Date&);

	friend ifstream& operator >>(ifstream& in, Student& s);
	friend ostream& operator <<(ostream& out, const Student& s);
	const Student& operator =(const Student&);

private:
	FIO fio;
	int numberK;
	Gender gender; // Gender
	Date birth;
	Adress adress;
};

enum Gender {MALE = 0,FEMALE = 1};
