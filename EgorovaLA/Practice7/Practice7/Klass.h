#pragma once

#include "Student.h"

typedef struct {
	int count;
	Student* students;
} Klass;

void allocate(Klass* K, int n);
void append_student(Klass* K, Student* S2, int pos);
void fillKlass(Klass* klass, char* str, FILE* f);
void Sort(int* support, Klass* klass);
void quick_sort(FIO* arrs, FIO*, FIO*, int* support, int left, int right);