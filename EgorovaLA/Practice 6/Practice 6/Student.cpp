#include "Student.h"

Student :: Student(Date &birth, FIO &names, Adress &adress, int numberK, string &gender) {
	this->birth = birth;
	this->names = names;
	this->adress = adress;
	this->numberK = numberK;
	this->gender = gender;
}

Student :: Student(const Student& s) {
	this->birth = s.birth;
	this->names = s.names;
	this->adress = s.adress;
	this->numberK = s.numberK;
	this->gender = s.gender;
}

