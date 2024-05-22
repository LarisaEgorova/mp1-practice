#pragma once

#include "Adress.h"
#include "Date.h"
#include "FIO.h"

enum Gender { MALE = 0, FEMALE = 1 };

class Student {
public:
	Student(const FIO&,int,int,const Date&,const Adress&);
	Student(const Student&);
	Student();

	FIO GetFIO() const;
	void SetFIO(const FIO&);
	int GetNum()const;
	void SetNum(int);
	Gender GetG()const;
	void SetG(int);
	Adress GetAdress()const;
	void SetAdress(const Adress&);
	Date GetDate();
	void SetDate(const Date&);

	friend ifstream& operator >>(ifstream& in, Student& s);
	friend ifstream& operator >>(ifstream& in, Gender& G);
	friend ostream& operator <<(ostream& out, const Student& s);
	const Student& operator =(const Student&);


private:
	FIO fio;
	int numberK;
	Gender gender;
	Date birth;
	Adress adress;
};

