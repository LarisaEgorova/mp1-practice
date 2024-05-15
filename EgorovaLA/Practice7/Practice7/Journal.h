#pragma once
#include "Klass.h"

typedef struct {
	int count;
	Klass* klasses;
} Journal;

void allocateJournal(Journal* Kmass, int klasses);
int fillJournal(Journal* Kmass);
void first_inf_nosort(Klass* Klass);
void first_inf_sort(Klass* Klassmass, int* support);