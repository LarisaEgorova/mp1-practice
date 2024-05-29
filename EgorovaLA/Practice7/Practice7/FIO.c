#include "FIO.h"

void fillFIO(FIO* fio , char* surname, char* name, char* fathersname) {
	strcpy(fio->Surname, surname);
	strcpy(fio->Name, name);
	strcpy(fio->Fathersname, fathersname);
}

void operatorEQFIO(FIO* fio1, FIO *fio2) {
	allocateFIO(fio1, strlen(fio2->Surname) + 1,
		strlen(fio2->Name) + 1, strlen(fio2->Fathersname) + 1);
	fillFIO(fio1, fio2->Surname, fio2->Name,fio2->Fathersname);
}

void allocateFIO(FIO* fio, int surname, int name, int fathersname) {
	fio->Surname = (char*)malloc(surname * sizeof(char));
	fio->Name = (char*)malloc(name * sizeof(char));
	fio->Fathersname = (char*)malloc(fathersname * sizeof(char));
}

int operatorMore(FIO* fio1, FIO* fio2) {
	if (strcmp(fio1->Surname, fio2->Surname) > 0) {
		return 1;
	}
	if (strcmp(fio1->Surname, fio2->Surname) == 0) {
		if (strcmp(fio1->Name, fio2->Name) > 0) {
			return 1;
		}
		if (strcmp(fio1->Name, fio2->Name) == 0) {
			if (strcmp(fio1->Fathersname, fio2->Fathersname) > 0) {
				return 1;
			}
		}
	}
	return 0;
}

int operatorLess(FIO* fio1, FIO* fio2) {
	if (strcmp(fio1->Surname, fio2->Surname) < 0) {
		return 1;
	}
	if (strcmp(fio1->Surname, fio2->Surname) == 0) {
		if (strcmp(fio1->Name, fio2->Name) < 0) {
			return 1;
		}
		if (strcmp(fio1->Name, fio2->Name) == 0) {
			if (strcmp(fio1->Fathersname, fio2->Fathersname) < 0) {
				return 1;
			}
		}
	}
	return 0;
}

void printFIO(FIO* fio) {
	printf("%s %s %s\n", fio->Surname, fio->Name, fio->Fathersname);
}

void deleteFIO(FIO* fio) {
	free(fio->Surname);
	free(fio->Name);
	free(fio->Fathersname);
}