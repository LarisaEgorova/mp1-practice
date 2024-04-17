#include "Klass.h"
#include "Function.h"
#include <string.h>
#include<stdlib.h>

#define MaxL 7

void main() {
	int klases = 0; int n = 0; int pos = 0;
	char file [MaxL] = "*.txt";
	char s[150] = { 0 };
	char*s1[16];
	char *str;
	Klass* Klassmass = {0};
	FIO fio;
	Date date;
	Adress adress;
	Student student;
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);

	while (1) {
		printf("Введите количество классов\n");
		scanf("%d", &klases);
		Klassmass = (Klass*)malloc(klases * sizeof(Klass));
		for (int i = 1; i < klases + 1; i++) {
			file[0] = i+'0';
			FILE* f = fopen(file, "r+");
			if (!f) {
				printf("Некорректное кол-во классов, нет подходящей базы данных\n");
				continue;
			}
			fgets(s, 4, f);//изменить строку не s
			n=atoi(s);
			allocate(&Klassmass[i], n);
			for (int j = 0; j < n; j++) {
				fgets(s, 150, f);
				str = strtok(s, "\t");
				for (int z = 0; z < 16; z++) {
					s1[z] = str;
					str = strtok(NULL, "\t");
				}
				fillFIO(&fio, s1[0], s1[1], s1[2]);
				fillDate(&date, atoi(s1[5]), atoi(s1[6]), atoi(s1[7]));
				fillAdress(&adress, atoi(s1[8]), s1[9], s1[10], s1[11], s1[12], s1[13], atoi(s1[14]), atoi(s1[15]));
				fillStudent(&student, &fio, atoi(s1[3]), s1[4], &date, &adress);
				fillKlass(&Klassmass[i], &student, j);
			}
		}

		break;
	}
	
	return;
}

