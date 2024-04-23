#include "Klass.h"

void allocate(Klass* K, int n) {
	K->count = n;
	K->students = (Student*)malloc(n * sizeof(Student));
}

void fillKlass(Klass* K, Student *S2, int pos) {
	allocateStudent(&K->students[pos]);
	operatorEQS(&K->students[pos], S2);
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

int operatorMore(FIO* fio1, FIO* fio2) {
	if (strcmp(fio1->Surname, fio2->Surname) > 0) {
		return 1;
	}
	if (strcmp(fio1->Surname, fio2->Surname) == 0) {
		if (strcmp(fio1->Name, fio2->Name) > 0) {
			return 1;
		}
		if (strcmp(fio1->Name, fio2->Name) == 0) {
			if (strcmp(fio1->Fathersname, fio2->Fathersname) > 0) {
				return 1;
			}
		}
	}
	return 0;
}

int operatorLess(FIO* fio1, FIO* fio2) {
	if (strcmp(fio1->Surname, fio2->Surname)<0) {
		return 1;
	}
	if (strcmp(fio1->Surname, fio2->Surname) == 0) {
		if (strcmp(fio1->Name, fio2->Name) < 0) {
			return 1;
		}
		if (strcmp(fio1->Name, fio2->Name) == 0) {
			if (strcmp(fio1->Fathersname, fio2->Fathersname) < 0) {
				return 1;
			}
		}
	}
	return 0;
}
