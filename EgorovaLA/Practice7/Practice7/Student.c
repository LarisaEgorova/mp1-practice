#include "Student.h"

void fillStudent(Student* S,FIO *fio, int klass, int gender, Date *date, Adress *adress) {
	operatorEQFIO(&S->fio, fio);
	S->numberK = klass;
	S->G = gender;
	operatorEQDate(&S->birth, date);
	operatorEQAdress(&S->adress, adress);
}

void operatorEQS(Student* s1, Student *s2) {
	operatorEQFIO(&s1->fio, &s2->fio);
	s1->G = s2->G;
	s1->numberK = s2->numberK;
	operatorEQDate(&s1->birth, &s2->birth);
	operatorEQAdress(&s1->adress, &s2->adress);
}

void allocateStudent(Student* S) {
	allocateFIO(&S->fio, 0, 0, 0);
	allocateAdress(&S->adress, 0, 0, 0, 0, 0);
}

void deleteStudent(Student* S) {
	deleteFIO(&S->fio);
	deleteAdress(&S->adress);
}

void inf_Student(Student* S) {
	printFIO(&S->fio);
	printf("����� %d\n", S->numberK);
	if (S->G == 0) {
		printf("���: �\n");
	}
	else printf("���: �\n");
	printDate(&S->birth);
	printAdress(&S->adress);
}