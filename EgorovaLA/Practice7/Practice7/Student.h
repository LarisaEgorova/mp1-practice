#pragma once

#include "Adress.h"
#include "Date.h"
#include "FIO.h"

typedef struct {
	FIO fio;
	int numberK;
	char gender;
	Date birth;
	Adress adress;
} Student;

void fillStudent(Student*,FIO*, int, char, Date*, Adress*);
void inf_Student(Student* S);
void operatorEQS(Student* s1, Student* s2);
void allocateStudent(Student* S);
void deleteStudent(Student* S);