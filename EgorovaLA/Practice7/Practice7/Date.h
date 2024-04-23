#pragma once

#include <stdio.h>
#include <locale.h>
#include <malloc.h>

typedef struct {
	int day;
	int month;
	int year;
} Date;

void fillDate(Date*,int, int, int);
void printDate(Date* date);
void operatorEQDate(Date* d1, Date *d2);
