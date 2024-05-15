#pragma once

#include <iostream>
#include <locale.h>
#include <string>
#include <fstream>

using namespace std;

class FIO {

public:
	string Surname;
	string Name;
	string Fathersname;

	FIO(const string&, const string&, const string&);
	FIO(const FIO&);
	FIO();

	friend ifstream& operator >>(ifstream& in, FIO& fio);
	friend ostream& operator <<(ostream& out, const FIO& fio);
	bool operator <(const FIO&) const;
	bool operator >(const FIO&) const;
};


