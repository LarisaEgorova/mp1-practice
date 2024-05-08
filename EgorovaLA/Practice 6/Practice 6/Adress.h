#pragma once

#include <iostream>
#include <locale.h>
#include <string>
#include <fstream>

using namespace std;

class Adress {

public:
	int indx;
	string country;
	string region;
	string city;
	string district;
	string street;
	int house;
	int flat;

	Adress(int, string, string, string,
		string, string, int, int);
	Adress(const Adress&);
	Adress();

	friend ifstream& operator >>(ifstream& in, Adress& ad);
	friend ostream& operator <<(ostream& out, const Adress& ad);
};

