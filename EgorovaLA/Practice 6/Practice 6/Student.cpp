#include "Student.h"

Student::Student(){
	this -> numberK = 0;
	this-> gender = "none";
}

Student :: Student(FIO &FIO,int numberK, string gender, Date &birth, Adress &adress) {
	this->fio = FIO;
	this->numberK = numberK;
	this->gender = gender;
	this->birth = birth;
	this->adress = adress;
}

Student::Student(const Student& s) {
	this->fio = s.fio;
	this->birth = s.birth;
	this->numberK = s.numberK;
	this->gender = s.gender;
	this->adress = s.adress;
}
	
const Student& Student :: operator =(const Student&st) {
	this->fio = st.fio;
	this->numberK = st.numberK;
	this->gender = st.gender;
	this->birth = st.birth;
	this->adress = st.adress;
	return *this;
}



