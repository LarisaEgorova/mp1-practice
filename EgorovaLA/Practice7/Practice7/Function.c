#include "Function.h"


#define MaxcountF 7
#define Maxstrlen 150

int work_base(Klass** Klassmass) {
	int klases = 0; int flag = 0;
	while (1) {
		printf("Введите количество классов\n");
		scanf("%d", &klases);
		*Klassmass = realloc(*Klassmass, klases * sizeof(Klass));
		for (int i = 1; i < klases + 1; i++) {
			flag += work_this_files(i, &Klassmass[0][i-1]);
		}
		if (flag != klases) {
			printf("Ошибка, некорректно введено колличество классов\n");
			continue;
		}
		break;
	}
	return klases;
}

void first_inf_nosort(Klass* Klass, int choice) {
	for (int i = 0; i < Klass->count; i++) {
		printf("ID %d\n", i+1);
		printf("Класс %d\n", Klass->students[i].numberK);
		printFIO(&Klass->students[i].fio);
	}
	return;
}

void first_inf_sort(Klass* Klass, int* support, int choice) {
	for (int i = 0; i < Klass->count; i++) {
		printf("ID %d\n", support[i]+1);
		printf("Класс %d\n", Klass->students[support[i]].numberK);
		printFIO(&Klass->students[support[i]].fio);
	}
	return;
}

void sorted_klases(int* support, Klass* Klass, int choice) {

	int count = 0;
	int right = 0;

	FIO* massfio;
	FIO center_el;
	FIO swap;

	count = Klass->count;
	massfio = (FIO*)malloc(count * sizeof(FIO));

	for (int i = 0; i < count; i++) {
		support[i] = i;
		operatorEQFIO(&massfio[i], &(Klass->students[i].fio));
	}
	right = count - 1;
	quick_sort(massfio, &center_el, &swap, support, 0, right);

	/*for (int i = 0; i < count; i++) {
		deleteFIO(&massfio[i]);
	}
	free(massfio);
	deleteFIO(&center_el);
	deleteFIO(&swap);*/

}

void menu(Klass* Klassmass, int klases) {

	int F = 1; int type; int f = 0;
	int* support;

	printf("Вас приветствует база школьников 'Будущее России'\n"
		"Вы можете ознакомиться с данными учеников со всей России\n"
		"Все они разделены на классы\n");

	while (F) {
		printf("Какой класс хотите посмотреть? (1-%d)", klases);
		int choice = 0;
		while (1) {
			printf("Введите номер класса: ");
			scanf("%d", &choice);
			if (choice <= 0 || choice > klases) {
				printf("Школьников такого класса в базе нет\n");
				continue;
			}
			break;
		}

		support = (int*)malloc(Klassmass[choice-1].count * sizeof(int));

		printf("Вывести список как в базе или отсортированный?\n");
		while (1) {
			printf("Как в базе - 1, отсортированный -2\n");
			scanf("%d", &type);
			if ((type != 1) && (type != 2)) {
				printf("Неверный ввод\n");
				continue;
			}
			break;
		}
		switch (type) {
		case 1:
			first_inf_nosort(&Klassmass[choice-1], choice);
			break;
		case 2:
			sorted_klases(support, &Klassmass[choice - 1], choice);
			first_inf_sort(&Klassmass[choice - 1], support, choice);
			break;
		default:
			break;
		}
		while (1) {
			printf("Хотите узнать больше?\n"
				"Введите уникальный ID ученика\n"
				"Также можете посмотреть другой класс - (-1) или завершить работу (0)\n");
			scanf("%d", &f);
			if (f != -1 && f != 0 && f - 1 <= Klassmass[choice - 1].count) {
				inf_Student(&Klassmass[choice - 1].students[f-1]);
				continue;
			}
			if (f == -1) {
				break;
			}
			if (f == 0) {
				F = 0;
				break;
			}
			else {
				printf("Неверный ввод\n");
				continue;
			}
		}
	}
	free(support);
}

int work_this_files(int klases, Klass* Klass) {
	char file[MaxcountF] = "*.txt";
	char str[Maxstrlen] = { 0 };
	int n = 0;
	file[0] = klases + '0';
	FILE* f = fopen(file, "r+");
	if (!f) {
		printf("Нет подходящей базы данных\n");
		return -1;
	}
	fgets(str, 4, f);
	n = atoi(str);
	allocate(Klass, n);
	append_students(Klass, str, f);
	return 1;
}

void append_students(Klass* Klass, char* str, FILE* f) {

	char* s1[16];
	char* strpart;
	int gender;

	FIO fio;
	Date date;
	Adress adress;
	Student student;

	for (int i = 0; i < Klass->count; i++) {
		fgets(str, 150, f);
		strpart = strtok(str, "\t");
		for (int j = 0; j < 16; j++) {
			s1[j] = strpart;
			strpart = strtok(NULL, "\t");
		}
		allocateFIO(&fio, strlen(s1[0]), strlen(s1[1]), strlen(s1[2]));
		fillFIO(&fio, s1[0], s1[1], s1[2]);

		fillDate(&date, atoi(s1[5]), atoi(s1[6]), atoi(s1[7]));

		allocateAdress(&adress, strlen(s1[9]), strlen(s1[10]), 
			strlen(s1[11]), strlen(s1[12]), strlen(s1[13]));
		fillAdress(&adress, atoi(s1[8]), s1[9], s1[10],
			s1[11], s1[12], s1[13], atoi(s1[14]), atoi(s1[15]));

		if (strcmp(s1[4], "Ж")==0) gender = 1;
		else gender = 0;

		fillStudent(&student, &fio, atoi(s1[3]), gender, &date, &adress);

		fillKlass(Klass, &student, i);

		//deleteFIO(&fio);
		//deleteAdress(&adress);
		//deleteStudent(&student);
	}
}
