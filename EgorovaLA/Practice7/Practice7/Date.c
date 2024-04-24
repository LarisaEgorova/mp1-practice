#include "Date.h"

void fillDate(Date* date, int day, int month, int year) {
	while (1) {
		if (year > 2050 || year < 2000) {
			printf("� ������� �������� ������\n");
			printf("������ ���: %d\n", year);
			printf("������� ���������� ��������\n");
			scanf("%d", &year);
			continue;
		}
		date->year = year;
		if (month > 12 || month < 1) {
			printf("� ������� �������� ������\n");
			printf("������ �����: %d\n", month);
			printf("������� ���������� ��������\n");
			scanf("%d", &month);
			continue;
		}
		date->month = month;
		if (day < 1 || day > 31 ||
			((month == 4 || month == 6 || month == 9 ||
				month == 11) && day > 30) ||
			(month == 2 && year % 4 == 0 && day > 29) ||
			(month == 2 && year % 4 != 0 && day > 28)) {
			printf("� ������� �������� ������\n");
			printf("������ ����: %d\n", day);
			printf("������� ���������� ��������\n");
			scanf("%d", &day);
			continue;
		}
		date->day = day;
		break;
	}
}

void printDate(Date* date) {
	printf("���� ��������: %d.%d.%d\n", date->day,date->month, date->year);
}

void operatorEQDate(Date* d1, Date* d2) {
	d1->day = d2->day;
	d1->month = d2->month;
	d1->year = d2->year;
}