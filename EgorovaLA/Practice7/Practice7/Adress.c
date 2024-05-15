#include "Adress.h"

void fillAdress(Adress* adress,int indx, char* country, char* region,
	char* city, char* district, char* street, int house, int flat) {

	adress->indx = indx;
	strcpy(adress->country,country);
	strcpy(adress->region, region);
	strcpy(adress->city, city);
	strcpy(adress->district, district);
	strcpy(adress->street, street);
	adress->house = house;
	adress->flat = flat;
}

void operatorEQAdress(Adress* a1, Adress *a2) {
	allocateAdress(a1, strlen(a2->country), strlen(a2->region),
		strlen(a2->city), strlen(a2->district), strlen(a2->street));
	fillAdress(a1,a2->indx, a2->country, a2->region,
		a2->city, a2->district, a2->street,a2->house,a2->flat) ;
}

void allocateAdress(Adress*adress,int lencountry,int lenregion,
	int lencity, int lendis, int lenstreet) {

	adress->country = (char*)malloc(lencountry * sizeof(char));
	adress->region = (char*)malloc(lenregion * sizeof(char));
	adress->city = (char*)malloc(lencity * sizeof(char));
	adress->district = (char*)malloc(lendis * sizeof(char));
	adress->street = (char*)malloc(lenstreet * sizeof(char));

}

void printAdress(Adress*adress) {
	printf("Ïîëíûé àäğåñ\n");
	printf("Èíäåêñ: %d\nÑòğàíà: %s\nÑóáúåêò: %s\n"
		"Ãîğîä: %s\nĞàéîí: %s\nÓëèöà: %s\nÄîì: %d\nÊâàğòèğà: %d\n",
		adress->indx,adress->country,adress->region,
		adress->city,adress->district,adress->street,
		adress->house, adress->flat);
}

void deleteAdress(Adress* adress) {
	free(adress->country);
	free(adress->region);
	free(adress->city);
	free(adress->district);
	free(adress->street);
}