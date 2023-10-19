#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>

void main() {
	int randchislK, chisloP, flag, mode, k=0;
	int num = 1;
	int Range = 1000;
	char ans = ".";
	char ans1 = ".";
	setlocale(LC_ALL, "rus");
	flag = 0;
	while (flag == 0) {
		printf("В какой режим сыграть? Загадывает компьютер(1) или вы (2)");
		scanf("%d", & mode);
		if ((mode == 1) || (mode == 2))
			flag = 1;
		else printf("Введите режим используя цифры в скобках\n");
	}
	flag = 0;
	if (mode == 1) {
		srand((unsigned int)time(0));
		randchislK = (rand() % Range) + num;
		k++;
		while (flag==0) {
			printf("Введите число (1,1000)");
			scanf("%d", &chisloP);
			if (chisloP == randchislK) {
				printf("Вы угадали!\n");
				printf("Колличество попыток %d", k);
				flag = 1;
			}
			else if (chisloP > randchislK)
				printf("Загаданное число меньше\n");
			else if (chisloP < randchislK)
				printf("Загаданное число больше\n");
		}
	}
	else {
		while (flag == 0) {
			printf("Введите число (1,1000)");
			scanf("%d", &chisloP);
			if ((chisloP > Range) || (chisloP < 1))
				printf("Введите число из нужного диапазона");
			else
				flag = 1;
		}
		flag = 0;
		while (flag == 0) {
			srand((unsigned int)time(0));
			randchislK =num+ rand() % Range;
			printf("Moe chislo %d\n", randchislK);
			while ((ans1!='<')|| (ans1 != '>')|| (ans1 != '=')) 
			{
				printf("Введите < > = ");
				scanf("%c",&ans);
				ans1 = ans;

			}
			if (ans == '=') {
				printf("YRA");
				flag = 1;
			}
			else if (ans == '>') {
				num = randchislK+1;
			}
			else if (ans == '<') {
				Range = randchislK;
			}
			printf("%d %d", num, Range);
		}


	}
	return;
	
}