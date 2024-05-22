#include "Journal.h"
#include "Function.h"
#include <string.h>
#include <stdlib.h>


void main() {

	int klases = 0;
	Journal Kmass;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("¬ведите количество классов\n");
	scanf("%d", &klases);

	allocateJournal(&Kmass, klases);

	if (fillJournal(&Kmass) == -1) return;

	menu(&Kmass);

	return;
}

