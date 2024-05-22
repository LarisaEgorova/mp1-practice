#include "Klass.h"

void allocate(Klass* K, int n) {
	K->count = n;
	K->students = (Student*)malloc(n * sizeof(Student));
}

void append_student(Klass* K, Student *S2, int pos) {
	allocateStudent(&K->students[pos]);
	operatorEQS(&K->students[pos], S2);
}

void fillKlass(Klass* klass, char* str, FILE* f) {

	char* s1[16];
	char* strpart;
	int gender; int n;

	FIO fio;
	Date date;
	Adress adress;
	Student student;

	fgets(str, 4, f);
	n = atoi(str);
	allocate(klass, n);

	for (int i = 0; i < klass->count; i++) {
		fgets(str, 150, f);
		strpart = strtok(str, "\t");
		for (int j = 0; j < 16; j++) {
			s1[j] = strpart;
			strpart = strtok(NULL, "\t");
		}
		allocateFIO(&fio, strlen(s1[0]) + 1, strlen(s1[1]) + 1, strlen(s1[2]) + 1);
		fillFIO(&fio, s1[0], s1[1], s1[2]);

		fillDate(&date, atoi(s1[5]), atoi(s1[6]), atoi(s1[7]));

		allocateAdress(&adress, strlen(s1[9]) + 1, strlen(s1[10]) + 1,
			strlen(s1[11]) + 1, strlen(s1[12]) + 1, strlen(s1[13]) + 1);
		fillAdress(&adress, atoi(s1[8]), s1[9], s1[10],
			s1[11], s1[12], s1[13], atoi(s1[14]), atoi(s1[15]));

		if (strcmp(s1[4], "Æ") == 0) gender = 1;
		else gender = 0;

		fillStudent(&student, &fio, atoi(s1[3]), gender, &date, &adress);

		append_student(klass, &student, i);

		deleteFIO(&fio);
		deleteAdress(&adress);
		deleteStudent(&student);
	}
}

void Sort(int* support, Klass* klass) {

	int count = 0;
	int right = 0;

	FIO* massfio;
	FIO center_el;
	FIO swap;

	count = klass->count;
	massfio = (FIO*)malloc(count * sizeof(FIO));

	for (int i = 0; i < count; i++) {
		support[i] = i;
		operatorEQFIO(&massfio[i], &(klass->students[i].fio));
	}
	right = count - 1;
	quick_sort(massfio, &center_el, &swap, support, 0, right);

	for (int i = 0; i < count; i++) {
		deleteFIO(&massfio[i]);
	}
	free(massfio);
	deleteFIO(&center_el);
	deleteFIO(&swap);
}

void quick_sort(FIO* arrs, FIO* center_el, FIO* swap, int* support, int left, int right) {
	int centric = left + (right - left) / 2;
	operatorEQFIO(center_el, &arrs[centric]);
	int lt = left;
	int rt = right;
	int  swape;
	while (lt <= rt) {
		while (operatorLess(&arrs[lt],center_el)) lt++;
		while (operatorMore(&arrs[rt], center_el)) rt--;
		if (lt <= rt) {
			operatorEQFIO(swap, &arrs[lt]);
			swape = support[lt];
			operatorEQFIO(&arrs[lt], &arrs[rt]);
			support[lt] = support[rt];
			operatorEQFIO(&arrs[rt], swap);
			support[rt] = swape;
			lt++;
			rt--;
		}
	}
	if (left < rt) quick_sort(arrs, center_el, swap, support, left, rt);
	if (right > lt) quick_sort(arrs, center_el, swap, support, lt, right);
}
