#pragma once

#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include <string.h>

typedef struct {
	char* Surname;
	char* Name;
	char* Fathersname;
} FIO;

void fillFIO(FIO*, char*, char*, char*);
void printFIO(FIO* fio);
void operatorEQFIO(FIO* fio1, FIO *fio2);
void allocateFIO(FIO* fio, int surname, int name, int fathersname);
//void reallocFIO(FIO* fio, int surname, int name, int fathersname);
void deleteFIO(FIO* fio);