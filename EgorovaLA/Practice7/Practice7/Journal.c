#include "Journal.h"

#define MaxcountF 7
#define Maxstrlen 150

void allocateJournal(Journal* Kmass, int klasses) {
	Kmass->count = klasses;
	Kmass->klasses = (Klass*)malloc(klasses * sizeof(Klass));
}

void deleteJournal(Journal* Kmass) {
	for (int i = 0; i < Kmass->count; i++) {
		for (int j = 0; j < Kmass->klasses[i].count; j++) {
			deleteStudent(&Kmass->klasses[i].students[j]);
		}
	}
}

int fillJournal(Journal* Kmass) {
	char file[MaxcountF] = "*.txt";
	char str[Maxstrlen] = { 0 };
	int n = 0;

	for (int i = 0; i < Kmass->count; i++) {
		FILE* f;
		file[0] = i+1 + '0';
		f = fopen(file, "r+");
		if (!f) {
			printf("����� ������ �� ����������\n");
			return -1;
		}
		fillKlass(&Kmass->klasses[i], str, f);
	}
	return 1;
}

void first_inf_nosort(Klass* Klass) {
	printf("ID \t ����c\t ���\n");
	for (int i = 0; i < Klass->count; i++) {
		printf("%d\t", i + 1);
		printf("%d\t", Klass->students[i].numberK);
		printFIO(&Klass->students[i].fio);
	}
	return;
}

void first_inf_sort(Klass* Klass, int* support) {
	printf("ID \t ����c\t ���\n");
	for (int i = 0; i < Klass->count; i++) {
		printf("%d\t", support[i] + 1);
		printf("%d\t", Klass->students[support[i]].numberK);
		printFIO(&Klass->students[support[i]].fio);
	}
	return;
}
