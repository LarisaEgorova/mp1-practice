#pragma once

#include <iostream>
#include <locale.h>
#include <string>
#include <exception>

using namespace std;

class FIO
{
public:
	FIO(string, string, string);
	FIO(const FIO&);
	FIO();
	string GetName();
	string GetSurname();
	string GetFathersname();
	void SetName(string);
	void SetSurname(string);
	void SetFathersname(string);
	const FIO& operator =(const FIO&);
private:
	string Name;
	string Surname;
	string Fathersname;
};


