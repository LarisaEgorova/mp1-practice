#include "Date.h"

void fillDate(Date* date,int day, int month, int year) {
	date->day = day;
	date->month = month;
	date->year = year;
}

void printDate(Date* date) {
	printf("Дата рождения: %d.%d.%d\n", date->day,date->month, date->year);
}

void operatorEQDate(Date* d1, Date* d2) {
	d1->day = d2->day;
	d1->month = d2->month;
	d1->year = d2->year;
}