#include "Journal.h"

#define MaxcountF 7
#define Maxstrlen 150

void allocateJournal(Journal* Kmass, int klasses) {
	Kmass->count = klasses;
	Kmass->klasses = (Journal*)malloc(klasses * sizeof(Journal));
}

int fillJournal(Journal* Kmass) {
	char file[MaxcountF] = "*.txt";
	char str[Maxstrlen] = { 0 };
	int n = 0;

	for (int i = 0; i < Kmass->count; i++) {
		file[0] = i+1 + '0';
		FILE* f = fopen(file, "r+");
		if (!f) {
			printf("Файла класса не существует\n");
			return -1;
		}
		fillKlass(&Kmass->klasses[i], str, f);
	}
	return 1;
}

void first_inf_nosort(Klass* Klass) {
	for (int i = 0; i < Klass->count; i++) {
		printf("ID %d	", i + 1);
		printf("Класс: %d\n", Klass->students[i].numberK);
		printFIO(&Klass->students[i].fio);
	}
	return;
}

void first_inf_sort(Klass* Klass, int* support) {
	for (int i = 0; i < Klass->count; i++) {
		printf("ID %d	", support[i] + 1);
		printf("Класс: %d\n", Klass->students[support[i]].numberK);
		printFIO(&Klass->students[support[i]].fio);
	}
	return;
}
