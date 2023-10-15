#include <stdio.h>
#include <locale.h>

int main() {
	const int DSP = 650, DVP = 950, WOOD = 660; // Плотность ДСП/ Плотность ДВП/ Плотность дерева в кг/м3
	const double DisMP = 0.4;
	const double DSPT = 0.015, DVPT = 0.005, WOODT = 0.01; // Толщина определенных материалов 
	double h, w, d, Massa, hbok, hbokf;
	int n = 0;
	int flag = 0;
	setlocale(LC_ALL, "Rus");
	while (flag == 0) {
		printf("Введите высоту (180-220см) задней стенки \n");
		scanf("%lf", &h);
		if (h < 180 || h>220) printf("Некорректная высота, введите значение из диапазона указанного в скобках\n");
		else flag = 1;
	}
	flag = 0;
	while (flag == 0)
	{
		printf("Введите ширину (80-120см) задней стенки \n");
		scanf("%lf", &w);
		if (w < 80 || w>120) printf("Некорректная ширина, введите значение из диапазона указанного в скобках\n");
		else flag = 1;
	}
	flag = 0;
	while (flag == 0)
	{
		printf("Введите глубину боковины (50-90)\n");
		scanf("%lf", &d);
		if (d < 50 || d>90) printf("Некорректная глубина, введите значение из диапазона указанного в скобках\n");
		else flag = 1;
	}
	h = h / 100; w = w / 100; d = d / 100;//перевод в метры
	hbok = h - 2 * DSPT;
	hbokf = hbok;
	while (hbokf > DisMP)
	{
		hbokf -= DisMP;
		n++;
	}
	Massa = (h * w * DVPT * DVP) + //масса задней стенки
		(2 * hbok * d * DSPT * DSP) +//масса боковых
		(2 * w * (d - WOODT) * DSPT * DSP) +//масса верхних
		(h * w * WOOD * WOODT) +//масса дверей
		(n * ((d - WOODT - DVPT) * (w - DSPT * 2) * DSP * DSPT));// масса полок
	printf("Масса шкафа с заданными параметрами = %lf кг", Massa);
	return 0;
}