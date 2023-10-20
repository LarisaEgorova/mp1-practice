# include <stdio.h> 
# include <locale.h>
# include <math.h>

int main() {
	float x1, y1, R1, x2, y2, R2, D; 
	setlocale(LC_ALL, "Rus");

	printf("������� ���������� ������ 1�� ���������� � � ������\n");
	printf("x1 y1 R1 = ");
	scanf("%f %f %f", &x1, &y1, &R1);

	if (R1 <= 0) {
		printf("�.� ������ 1�� ���������� <=0 ��� �� ����������");
		return 0;
	}

	printf("������� ���������� ������ 2�� ���������� � � ������\n");
	printf("x2 y2 R2 = ");
	scanf("%f %f %f", &x2, &y2, &R2);

	if (R2 <= 0) {
		printf("�.� ������ 2�� ���������� <= 0 ��� �� ����������"); 
		return 0;
	}
	if (R1 == R2 && x1 == x2 && y1 == y2) {
		printf("���������� ���������");
		return 0;
	}

	D = sqrt( (abs(x1 - x2))*(abs(x1 - x2)) + 
		(abs(y1 - y2)) * (abs(y1 - y2)));

	if (D < abs(R1 - R2)) {
		printf("���������� ������� � �� ����������");
		return 0;
	}
	if (D > R1 + R2) {
		printf("���������� �� ������������");
		return 0;
	}
	if (D == R1 + R2) {
		printf("���������� �������� �������");
		return 0;
	}
	if (D == R1 - R2) {
		printf("���������� ������������� ������");
		return 0;
	}
	printf("���������� ������������ � ���� ������");
	return 0;
}
