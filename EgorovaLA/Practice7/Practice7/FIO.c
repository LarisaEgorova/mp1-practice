#include "FIO.h"

void fillFIO(FIO* fio , char* surname, char* name, char* fathersname) {
	strcpy(fio->Surname, surname);
	strcpy(fio->Name, name);
	strcpy(fio->Fathersname, fathersname);
}

void operatorEQFIO(FIO* fio1, FIO *fio2) {
	allocateFIO(fio1, strlen(fio2->Surname),
		strlen(fio2->Name), strlen(fio2->Fathersname));
	fillFIO(fio1, fio2->Surname, fio2->Name,fio2->Fathersname);
}

void allocateFIO(FIO* fio, int surname, int name, int fathersname) {
	fio->Surname = (char*)malloc(surname * sizeof(char));
	fio->Name = (char*)malloc(name * sizeof(char));
	fio->Fathersname = (char*)malloc(fathersname * sizeof(char));
}

/*void reallocFIO(FIO* fio, int surname, int name, int fathersname) {
	fio->Surname = realloc(fio->Surname, surname * sizeof(char));
	fio->Name = realloc(fio->Name, name * sizeof(char));
	fio->Fathersname = realloc(fio->Fathersname, fathersname * sizeof(char));
}*/

void printFIO(FIO* fio) {
	printf("ÔÈÎ: %s %s %s\n", fio->Surname, fio->Name, fio->Fathersname);
}

void deleteFIO(FIO* fio) {
	free(fio->Surname);
	free(fio->Name);
	free(fio->Fathersname);
}