#pragma once

#include "Student.h"

typedef struct {
	int count;
	Student* students;
} Klass;

void allocate(Klass* K, int n);
void fillKlass(Klass* K, Student* S, int pos);