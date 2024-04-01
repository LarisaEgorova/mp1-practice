#include "Adress.h"

Adress::Adress(int indx, string country, string region, string city,
	string district, string street, int house, int flat)
{
	this->indx = indx;
	this->country = country;
	this->region = region;
	this->city = city;
	this->district = district;
	this->street = street;
	this->house = house;
	this->flat = flat;
}

Adress::Adress(const Adress& ad) {
	this->indx = ad.indx;
	this->country = ad.country;
	this->region = ad.region;
	this->city = ad.city;
	this->district = ad.district;
	this->street = ad.street;
	this->house = ad.house;
	this->flat = ad.flat;
}

Adress::Adress(){
	this->indx = 0;
	this->country = "";
	this->region = "";
	this->city = "";
	this->district = "";
	this->street = "";
	this->house = 0;
	this->flat = 0;
}

int Adress :: GetIndx() const {
	return this -> indx;
}
void Adress::SetIndx(int indx) {
	this->indx = indx;
}

string Adress::GetCountry() const {
	return this->country;
}
void Adress::SetCountry(string country) {
	this->country = country;
}

string Adress::GetRegion() const {
	return this->region;
}
void Adress::SetRegion(string region) {
	this->region = region;
}

string Adress::GetCity() const {
	return this->city;
}
void Adress::SetCity(string city) {
	this->city = city;
}

string Adress::GetDistrict() const {
	return this->district;
}
void Adress::SetDistrict(string district) {
	this->district = district;
}

string Adress::GetStreet() const {
	return this->street;
}
void Adress::SetStreet(string street) {
	this->street = street;
}

int Adress::GetHouse() const {
	return this->house;
}
void Adress::SetHouse(int house) {
	this->house = house;
}

int Adress::GetFlat() const {
	return this->flat;
}
void Adress::SetFlat(int flat) {
	this->flat = flat;
}

const Adress& Adress::operator= (const Adress& ad) {
	this->indx = ad.indx;
	this->country = ad.country;
	this->region = ad.region;
	this->city = ad.city;
	this->district = ad.district;
	this->street = ad.street;
	this->house = ad.house;
	this->flat = ad.flat;
	return *this;
}

ifstream& operator >>(ifstream& in, Adress& ad) {
	string n[9];
	for (int i = 0; i < 9; i++) {
		getline(in, n[i], '\t');
	}
	ad.indx = atoi(n[1].c_str());
	ad.country= n[2];
	ad.region= n[3];
	ad.city = n[4];
	ad.district = n[5];
	ad.street = n[6];
	ad.house = atoi(n[7].c_str());
	ad.flat = atoi(n[8].c_str());
	
	return in;
}

ostream& operator <<(ostream& out, const Adress& ad) {
	out<<"Индекс: " << ad.indx << "\nСтрана: " << ad.country 
		<< "\nРегион: " << ad.region << "\nГород: "
		<< ad.city << "\nРайон: "  << ad.district 
		<< "\nУлица: " << ad.street << "\nДом: "
		<< ad.house << "\nКвартира: " << ad.flat;
	return out;
}