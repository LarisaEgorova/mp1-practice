#include "Student.h"

void fillStudent(Student* S,FIO*fio, int klass, char gender, Date*date, Adress*adress) {
	S->fio = *fio;
	S->numberK = klass;
	S->gender = gender;
	S->birth = *date;
	S->adress = *adress;
}