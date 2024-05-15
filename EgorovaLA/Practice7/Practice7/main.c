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

	/*for (int i = 0; i < klases; i++) {
		for (int j = 0; j < Klassmass[i].count; j++) {
			deleteStudent(&Klassmass[i].students[j]);
		}
		free(&Klassmass[i].students);
	}
	free(Klassmass);*/

	return;
}

