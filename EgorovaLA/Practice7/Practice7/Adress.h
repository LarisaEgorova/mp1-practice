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