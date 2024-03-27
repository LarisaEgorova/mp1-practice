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

FIO::FIO() {}

string FIO :: GetName() {
	return this->Name;
}
string FIO::GetSurname(){
	return this->Surname;
}
string FIO::GetFathersname(){
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

const FIO& FIO :: operator =(const FIO&fio) {
	this->Name = fio.Name;
	this->Surname = fio.Surname;
	this->Fathersname = fio.Fathersname;
	return *this;
}