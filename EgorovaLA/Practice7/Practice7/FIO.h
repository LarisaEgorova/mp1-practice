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
void allocateFIO(FIO* fio, int , int , int );
int operatorMore(FIO* fio1, FIO* fio2);
int operatorLess(FIO* fio1, FIO* fio2);
void deleteFIO(FIO* fio);