#include "Klass.h"
#include "Function.h"
#include <string.h>
#include <stdlib.h>


void main() {

	int klases = 0; int flag = 0;
	Klass* Klassmass;

	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);

	Klassmass = (Klass*)malloc(klases * sizeof(Klass));

	klases = work_base(&Klassmass);
	menu(Klassmass, klases);

	/*for (int i = 0; i < klases; i++) {
		for (int j = 0; j < Klassmass[i].count; j++) {
			deleteStudent(&Klassmass[i].students[j]);
		}
		free(&Klassmass[i].students);
	}
	free(Klassmass);*/
	return;
}

