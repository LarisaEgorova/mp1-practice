#pragma once

#include <iostream>
#include <locale.h>
#include <string>
#include <fstream>

using namespace std;

class FIO
{
public:
	FIO(string, string, string);
	FIO(const FIO&);
	FIO();
	string GetName() const;
	string GetSurname() const;
	string GetFathersname() const;
	void SetName(string);
	void SetSurname(string);
	void SetFathersname(string);

	friend ifstream& operator >>(ifstream& in, FIO& fio);
	friend ostream& operator <<(ostream& out, const FIO& fio);
	const FIO& operator =(const FIO&);
	bool operator <(const FIO&);
	bool operator >(const FIO&);
private:
	string Surname;
	string Name;
	string Fathersname;
};


