#include "Student.h"

Student::Student(){
	this -> numberK = 0;
	this->gender = MALE;
}

Student::Student(FIO &FIO,int numberK, int gender, Date &birth, Adress &adress) {
	this->fio = FIO;
	this->numberK = numberK;
	if (gender==0) this->gender = MALE;
	else this->gender = FEMALE;
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

FIO Student :: GetFIO()const {
	return this->fio;
}
void Student::SetFIO(FIO &fio){
	this->fio = fio;
}
int Student::GetNum()const {
	return this->numberK;
}
void Student::SetNum(int num) {
	this->numberK = num;
}
Gender Student::GetG()const {
	return this->gender;
}
void Student::SetG(int G) {
	if (G == 0) this->gender = MALE;
	else this->gender = FEMALE;
}
Adress Student::GetAdress()const {
	return this->adress;
}
void Student::SetAdress(Adress &a) {
	this->adress = a;
}
Date Student::GetDate() {
	return this->birth;
}
void Student::SetDate(Date &b) {
	this->birth = b;
}

ifstream& operator >>(ifstream& in, Gender& G) {
	char g;
	in >> g;
	if (g == 'М') G = MALE;
	else G = FEMALE;
	return in;
}

ifstream& operator >>(ifstream& in, Student& s) {
	in >> s.fio;
	in >> s.numberK;
	in >> s.gender;
	in >> s.birth;
	in >> s.adress;
	return in;
}

ostream& operator <<(ostream& out, const Student& s) {
	out<<"ФИО: " << s.fio << "Класс: " << s.numberK << endl << "Пол: " <<
		s.gender << endl<<"Дата рождения: " << s.birth<<" Полный адрес \n" << s.adress;
	return out;
}