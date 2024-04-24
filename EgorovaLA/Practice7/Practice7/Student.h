#pragma once

#include "Adress.h"
#include "Date.h"
#include "FIO.h"

typedef enum {
	MALE = 0,
	FEMALE = 1
} Gender;

typedef struct {
	FIO fio;
	int numberK;
	Gender G;
	Date birth;
	Adress adress;
} Student;

void fillStudent(Student*,FIO*, int, char, Date*, Adress*);
void inf_Student(Student* S);
void operatorEQS(Student* s1, Student* s2);
void allocateStudent(Student* S);
void deleteStudent(Student* S);