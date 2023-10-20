#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>

void main() {
	int randchislK, chisloP, mode, k = 0;
	int num = 1;
	int Range = 1000;
	char ans;

	setlocale(LC_ALL, "rus");
	
	do {
		printf("� ����� ����� �������? ���������� ���������(1) ��� �� (2) ");
		scanf("%d", &mode);
	} while (mode != 1 && mode != 2);

	if (mode == 1) {
		srand((unsigned int)time(0));
		randchislK = (rand() % Range) + num;
		do {
			k++;
			printf("������� ����� (1,1000)");
			scanf("%d", &chisloP);
			if (chisloP == randchislK) {
				printf("�� �������!\n");
				printf("����������� ������� %d", k);
				break;
			}
			else if (chisloP > randchislK)
				printf("���������� ����� ������\n");
			else if (chisloP < randchislK)
				printf("���������� ����� ������\n");
		} while (1);
	}
	else {
		do {
			printf("��������� ����� (1,1000)");
			scanf("%d", &chisloP);			
		} while ((chisloP > Range) || (chisloP < 1));

		srand((unsigned int)time(0));

		do {			
			randchislK = num + rand() % (Range-num+1);
			printf("� ����� ��� %d\n", randchislK);
			k++;
			printf("� ������? ������� (<, >, =), ����� � ����� ");
			scanf("%*c%c", &ans);			
			if (ans == '=') {
				printf("� ������ �� %d �������", k);
				break;
			}
			else if (ans == '>') {
				num = randchislK + 1;
			}
			else if (ans == '<') {
				Range = randchislK - 1;
			}
		} while (1);
	}

	return;
}