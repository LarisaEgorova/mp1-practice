#include "FIO.h"

FIO::FIO(const string& Surname , const string& Name, const string &Fathersname) {
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

bool FIO:: operator <(const FIO& fio) const{
	if (this->Surname < fio.Surname) {
		return this->Surname < fio.Surname;
	}
	if (this->Surname == fio.Surname) {
		if (this->Name < fio.Name) {
			return this->Name < fio.Name;
		}
		if (this->Name == fio.Name) {
			if (this->Fathersname < fio.Fathersname) {
				return this->Fathersname < fio.Fathersname;
			}
		}
	}
	return 0;
}

bool FIO:: operator >(const FIO& fio) const {
	if (this->Surname > fio.Surname) {
		return this->Surname > fio.Surname;
	}
	if (this->Surname == fio.Surname) {
		if (this->Name > fio.Name) {
			return this->Name > fio.Name;
		}
		if (this->Name == fio.Name) {
			if (this->Fathersname > fio.Fathersname) {
				return this->Fathersname > fio.Fathersname;
			}
		}
	}
	return 0;
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
