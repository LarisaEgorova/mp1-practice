#include "FIO.h"

FIO::FIO(string Surname , string Name, string Fathersname) {
	this->Surname = Surname;
	this->Name = Name;
	this->Fathersname = Fathersname;
}

FIO::FIO(const FIO& FIO) {
	this->Surname = FIO.Surname;
	this->Name = FIO.Name;
	this->Fathersname = FIO.Fathersname;
}

FIO::FIO() {
	this->Surname = "0";
	this->Name = "0";
	this->Fathersname = "0";
}

string FIO :: GetName() const {
	return this->Name;
}
string FIO::GetSurname() const {
	return this->Surname;
}
string FIO::GetFathersname() const {
	return this->Fathersname;
}
void FIO::SetName(string name){
	this->Name =name;
}
void FIO::SetSurname(string surname){
	this->Surname = surname;
}
void FIO::SetFathersname(string fathersname) {
	this->Fathersname = fathersname;
}

const FIO& FIO:: operator =(const FIO&FIO) {
	this->Surname = FIO.Surname;
	this->Name = FIO.Name;
	this->Fathersname = FIO.Fathersname;
	return *this;
}

bool FIO:: operator <(const FIO& fio) {
	return this->Surname < fio.Surname;
}

bool FIO:: operator >(const FIO& fio) {
	return this->Surname > fio.Surname;
}

ifstream& operator >>(ifstream& in, FIO& fio) {
	in >> fio.Surname;
	in >> fio.Name;
	in >> fio.Fathersname;
	return in;
}

ostream& operator <<(ostream& out, const FIO& fio) {
	out << fio.Surname <<" " << fio.Name<< " " << fio.Fathersname<<endl;
	return out;
}
