#pragma once

#include <stdio.h>
#include <locale.h>
#include <malloc.h>

typedef struct {
	int indx;
	char* country;
	char* region;
	char* city;
	char* district;
	char* street;
	int house;
	int flat;
} Adress;

void fillAdress(Adress*,int, char*, char*, char*, char*, char*, int, int);
void printAdress(Adress*);
void operatorEQAdress(Adress* a1, Adress* a2);
void allocateAdress(Adress* a, int lencountry, int lenregion, int lencity, int lendis, int lenstreet);
//void reallocAdress(Adress* fio, int lencountry, int lenregion, int lencity, int lendis, int lenstreet);
void deleteAdress(Adress* adress);