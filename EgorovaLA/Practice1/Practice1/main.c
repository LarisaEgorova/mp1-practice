#include <stdio.h>
#include <locale.h>

int main() {
	const int DSP = 650, DVP = 950, WOOD = 660; // ��������� ���/ ��������� ���/ ��������� ������ � ��/�3
	const double DisMP = 0.4;
	const double DSPT = 0.015, DVPT = 0.005, WOODT = 0.01; // ������� ������������ ���������� 
	double h, w, d, Massa, hbok, hbokf;
	int n = 0;
	int flag = 0;
	setlocale(LC_ALL, "Rus");
	while (flag == 0) {
		printf("������� ������ (180-220��) ������ ������ \n");
		scanf("%lf", &h);
		if (h < 180 || h>220) printf("������������ ������, ������� �������� �� ��������� ���������� � �������\n");
		else flag = 1;
	}
	flag = 0;
	while (flag == 0)
	{
		printf("������� ������ (80-120��) ������ ������ \n");
		scanf("%lf", &w);
		if (w < 80 || w>120) printf("������������ ������, ������� �������� �� ��������� ���������� � �������\n");
		else flag = 1;
	}
	flag = 0;
	while (flag == 0)
	{
		printf("������� ������� �������� (50-90)\n");
		scanf("%lf", &d);
		if (d < 50 || d>90) printf("������������ �������, ������� �������� �� ��������� ���������� � �������\n");
		else flag = 1;
	}
	h = h / 100; w = w / 100; d = d / 100;//������� � �����
	hbok = h - 2 * DSPT;
	hbokf = hbok;
	while (hbokf > DisMP)
	{
		hbokf -= DisMP;
		n++;
	}
	Massa = (h * w * DVPT * DVP) + //����� ������ ������
		(2 * hbok * d * DSPT * DSP) +//����� �������
		(2 * w * (d - WOODT) * DSPT * DSP) +//����� �������
		(h * w * WOOD * WOODT) +//����� ������
		(n * ((d - WOODT - DVPT) * (w - DSPT * 2) * DSP * DSPT));// ����� �����
	printf("����� ����� � ��������� ����������� = %lf ��", Massa);
	return 0;
}