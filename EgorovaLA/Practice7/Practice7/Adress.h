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
void allocateAdress(Adress*, int , int , int , int , int );
void deleteAdress(Adress* adress);