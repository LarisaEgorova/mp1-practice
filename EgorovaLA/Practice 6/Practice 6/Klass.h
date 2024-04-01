#pragma once

#include "Student.h"

class Klass {
public:
	Klass(int n);
	Klass(const Klass&);
	Klass();
	~Klass();
	void SetStudents(int, Student&);
	Student GetStudents(int) const;
	Student* GetStudents() const;
	friend ostream& operator <<(ostream& out, const Klass& K);
private:
	int count;
	Student* students;
};
