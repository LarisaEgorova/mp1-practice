#include "Klass.h"

void allocate(Klass* K, int n) {
	K->count = n;
	K->students = (Student*)malloc(n * sizeof(Student));
}

void fillKlass(Klass* K, Student* S, int pos) {
	K->students[pos] = *S;
}