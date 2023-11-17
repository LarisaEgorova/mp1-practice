#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

struct product
{
	float price;
	int barcode;
	char name[10];
};
void main() {
	setlocale(LC_ALL, "rus");
	struct product bread = {40, 1234, "Хлеб"};
	print("%f %d %s", bread.price, bread.barcode,bread.name);

}
