#pragma once

#include <iostream>
#include <locale.h>
#include <string>
#include <fstream>

using namespace std;

class Adress
{
public:
	Adress(int, string, string, string,
		string, string, int, int);
	Adress(const Adress&);
	Adress();
	int GetIndx() const;
	void SetIndx(int indx);
	string GetCountry() const;
	void SetCountry(string country);
	string GetRegion() const;
	void SetRegion(string region);
	string GetCity() const;
	void SetCity(string city);
	string GetDistrict() const;
	void SetDistrict(string district);
	string GetStreet() const;
	void SetStreet(string street);
	int GetHouse()const;
	void SetHouse(int house);
	int GetFlat()const;
	void SetFlat(int flat);

	const Adress& operator = (const Adress&);
	friend ifstream& operator >>(ifstream& in, Adress& ad);
	friend ostream& operator <<(ostream& out, const Adress& ad);
private:
	int indx;
	string country;
	string region;
	string city;
	string district;
	string street;
	int house;
	int flat;
};

