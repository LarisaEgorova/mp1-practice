#include "Student.h"

void fillStudent(Student* S,FIO *fio, int klass, char gender, Date *date, Adress *adress) {
	operatorEQFIO(&S->fio, fio);
	S->numberK = klass;
	S->gender = gender;
	operatorEQDate(&S->birth, date);
	operatorEQAdress(&S->adress, adress);
}

void operatorEQS(Student* s1, Student *s2) {
	operatorEQFIO(&s1->fio, &s2->fio);
	s1->gender = s2->gender;
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
	printf("Êëàññ %d", S->numberK);
	printf("%c", S->gender);
	printDate(&S->birth);
	printAdress(&S->adress);
}