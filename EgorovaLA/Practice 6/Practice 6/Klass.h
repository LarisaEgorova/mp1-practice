#pragma once

#include "Student.h"

class Klass {
public:
	Klass(Student*, int, int);
private:
	Student* students;
	int count;
	int number;
};
