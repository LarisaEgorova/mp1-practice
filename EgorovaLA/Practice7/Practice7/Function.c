#include "Function.h"

void menu(Klass* Lib, int* quantity, int klases) {
	int F = 1; int type; int f = 0;
	printf("Вас приветствует база школьников 'Будущее России'\n"
		"Вы можете ознакомиться с данными учеников со всей России\n"
		"Все они разделены на классы\n");
	
	while (F) {
		printf("Какой класс хотите посмотреть? (1-%d)", klases);
		int choice = 0;
		while (1) {
			printf("Введите номер класса: ");
			scanf("%d",&choice);
			if (choice <= 0 || choice > klases) {
				printf("Школьников такого класса в базе нет\n");
				continue;
			}
			break;
		}
		//int* support = new int[quantity[choice - 1]];
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
			first_inf_nosort(Lib, quantity, choice);
			break;
		case 2:
			support = sorted_klases(quantity, support, Lib, choice);
			first_inf_sort(Lib, quantity, support, choice);
			break;
		default:
			break;
		}
		while (1) {
			printf("Хотите узнать больше?\n"
				"Введите уникальный ID ученика\n"
				"Также можете посмотреть другой класс - (-1) или завершить работу (0)\n");
			scanf("%d",&f);
			if (f != -1 && f != 0 && f - 1 <= quantity[choice - 1]) {
				//cout << Lib[choice - 1].GetStudents(f - 1) << "\n";
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
		//delete[] support;
	}
}
