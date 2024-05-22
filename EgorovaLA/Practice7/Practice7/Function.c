#include "Function.h"

void menu(Journal* Kmass) {

	int F = 1; int type; int f = 0;
	int* support;

	printf("��� ������������ ���� ���������� '������� ������'\n"
		"�� ������ ������������ � ������� �������� �� ���� ������\n"
		"��� ��� ��������� �� ������\n");

	while (F) {
		printf("����� ����� ������ ����������? (1-%d)\n", Kmass->count);
		int choice = 0;
		while (1) {
			printf("������� ����� ������: ");
			scanf("%d", &choice);
			if (choice <= 0 || choice > Kmass->count) {
				printf("���������� ������ ������ � ���� ���\n");
				continue;
			}
			break;
		}

		support = (int*)malloc(Kmass->klasses[choice - 1].count * sizeof(int));

		printf("������� ������ ��� � ���� ��� ���������������?\n");
		while (1) {
			printf("��� � ���� - 1, ��������������� -2\n");
			scanf("%d", &type);
			if ((type != 1) && (type != 2)) {
				printf("�������� ����\n");
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
			printf("������ ������ ������?\n"
				"������� ���������� ID �������\n"
				"����� ������ ���������� ������ ����� - (-1) ��� ��������� ������ (0)\n");
			scanf("%d", &f);
			if (f != -1 && f != 0 && f  <= Kmass->klasses[choice - 1].count) {
				inf_Student(&Kmass->klasses[choice - 1].students[f-1]);
				continue;
			}
			if (f == -1) {
				break;
			}
			if (f == 0) {
				printf("����������..\n");
				F = 0;
				break;
			}
			else {
				printf("�������� ����\n");
				continue;
			}
		}
	}
	free(support);
	deleteJournal(Kmass);
}
