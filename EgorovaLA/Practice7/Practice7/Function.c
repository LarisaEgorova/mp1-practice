#include "Function.h"

void menu(Journal* Kmass) {

	int F = 1; int type; int f = 0;
	int* support;

	printf("Вас приветствует база школьников 'Будущее России'\n"
		"Вы можете ознакомиться с данными учеников со всей России\n"
		"Все они разделены на классы\n");

	while (F) {
		printf("Какой класс хотите посмотреть? (1-%d)\n", Kmass->count);
		int choice = 0;
		while (1) {
			printf("Введите номер класса: ");
			scanf("%d", &choice);
			if (choice <= 0 || choice > Kmass->count) {
				printf("Школьников такого класса в базе нет\n");
				continue;
			}
			break;
		}

		support = (int*)malloc(Kmass->klasses[choice - 1].count * sizeof(int));

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
			first_inf_nosort(&Kmass->klasses[choice-1]);
			break;
		case 2:
			Sort(support, &Kmass->klasses[choice - 1]);
			first_inf_sort(&Kmass->klasses[choice - 1], support);
			break;
		default:
			break;
		}
		while (1) {
			printf("Хотите узнать больше?\n"
				"Введите уникальный ID ученика\n"
				"Также можете посмотреть другой класс - (-1) или завершить работу (0)\n");
			scanf("%d", &f);
			if (f != -1 && f != 0 && f  <= Kmass->klasses[choice - 1].count) {
				inf_Student(&Kmass->klasses[choice - 1].students[f-1]);
				continue;
			}
			if (f == -1) {
				break;
			}
			if (f == 0) {
				printf("Завершение..\n");
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
	deleteJournal(Kmass);
}
