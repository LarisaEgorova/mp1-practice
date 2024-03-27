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
}

int Adress :: GetIndx(){
	return this -> indx;
}
void Adress::SetIndx(int indx) {
	this->indx = indx;
}

string Adress::GetCountry() {
	return this->country;
}
void Adress::SetCountry(string country) {
	this->country = country;
}

string Adress::GetRegion() {
	return this->region;
}
void Adress::SetRegion(string region) {
	this->region = region;
}

string Adress::GetCity() {
	return this->city;
}
void Adress::SetCity(string city) {
	this->city = city;
}

string Adress::GetDistrict() {
	return this->district;
}
void Adress::SetDistrict(string district) {
	this->district = district;
}

string Adress::GetStreet() {
	return this->street;
}
void Adress::SetStreet(string street) {
	this->street = street;
}

int Adress::GetHouse() {
	return this->house;
}
void Adress::SetHouse(int house) {
	this->house = house;
}

int Adress::GetFlat() {
	return this->flat;
}
void Adress::SetFlat(int flat) {
	this->flat = flat;
}

const Adress& Adress :: operator= (const Adress&) {
	return *this;
}