#pragma once

#include <stdio.h>
#include <locale.h>
#include <malloc.h>

typedef struct {
	char*  Surname;
	char* Name;
	char* Fathersname;
} FIO;

void fillFIO(FIO*,char*, char*, char*);