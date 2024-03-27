#pragma once

#include <iostream>
#include <locale.h>
#include <string>
#include <exception>

using namespace std;

class Adress
{
public:
	Adress(int, string, string, string,
		string, string, int, int);
	Adress(const Adress&);
	Adress();
	int GetIndx();
	void SetIndx(int indx);
	string GetCountry();
	void SetCountry(string country);
	string GetRegion();
	void SetRegion(string region);
	string GetCity();
	void SetCity(string city);
	string GetDistrict();
	void SetDistrict(string district);
	string GetStreet();
	void SetStreet(string street);
	int GetHouse();
	void SetHouse(int house);
	int GetFlat();
	void SetFlat(int flat);

	const Adress& operator= (const Adress&);

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

