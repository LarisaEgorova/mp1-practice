#include <stdio.h>
#include <locale.h>
#include<time.h>
#include<stdlib.h>

#define len 5

void main() {
	int const low_line = 2, up_line = 5;
	int n,i,j,number,pep_chiclo;
	int k = 0;
	int bull = 0, cow = 0;
	int chislok[len] = {0};
	int chislop[len] = {0};

	setlocale(LC_ALL, "rus");

	do {
		printf("Введите длину числа в диапазоне (2..5) ");
		scanf("%d", &n);
	} while ((n < low_line) || (n > up_line));

	srand((unsigned int)time(0));

	for (i = 0; i < n; i++) {
		if (i == 0) {
			number = 1 + rand() % (10 - 1);
			chislok[i] = number;
			continue;
		}

		do{
			k = 0;
			number = rand() % 10;
			for (j = 0; j < i; j++) {
				if (chislok[j] == number)
					break;
				k++;
			}
			if (k == i) {
				chislok[i] = number;
				break;
			}
		} while (1);
	}

	/*for (i = 0; i < n; i++) {
			printf("%d", chislok[i]);
		}//test
	printf("\n");*/

	do {
		bull = 0;
		cow = 0;
		printf("Введите свою отгадку ");
		scanf("%d", &pep_chiclo);

		for (i = n-1; i >=0; i--) {
			chislop[i] = pep_chiclo % 10;
			pep_chiclo = pep_chiclo / 10;
		}

		for (i = 0; i < n; i++) { 
			for (j = 0; j<n; j++) { 
				if (chislop[i] == chislok[j]) {
					cow += 1;
					if (i == j) {
						bull += 1;
						cow -= 1;
					}
					break;
				}
			}
		}
		if (bull != n)
			printf("В вашей отгадке: коров %d быков %d\n", cow, bull);
		else {
			printf("Вы угадали, поздравляю!");
			break;
		}
	} while (1);

	return;
}