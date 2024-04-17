#include "Adress.h"

void fillAdress(Adress*adress,int indx, char* country, char* region, char* city, char* district, char* street, int house, int flat) {
	adress->indx = indx;
	adress->country = country;
	adress->region = region;
	adress->city = city;
	adress->district = district;
	adress->street = street;
	adress->house = house;
	adress->flat = flat;
}