#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define max_bill 20
#define len_bar 4
#define k 10 //кол-во товаров

int i = 0;
int flag = 1;
int mode = 0;
int bill[max_bill];
float final_price = 0, price_dis[max_bill], final_price_no_dis = 0;;
int pos = 1;

struct product
{
    char* barcode;
    char* names;
    float prices;
    int discount;
};

struct product product[] = { {"0000", "Хлеб", 40, 10}, {"0001", "Молоко 0,9 л.", 74, 15},
   {"0011", "Крупа гречневая", 101,3},{"0111", "Кекс", 25,6},
   {"1111", "Яйцо куриное", 90, 9}, {"1000", "Сосиски сливочные", 156, 20},
   {"1100", "Картофель фас.", 41, 2},{"1110", "Шампунь", 251, 50},
   {"1010","Вода негаз. 0,5 л.", 15, 1}, {"0101", "Консервы рыбные", 113, 12} };

int chek_product() {
    int i, j, n=1, position=0;
    char barcode_pols[len_bar+1];
    do {
        printf("Введите штрих код ");
        scanf("%s", &barcode_pols);
        for (i = 0; i < k; i++) {
            n = strcmp(product[i].barcode, barcode_pols);
            if (n == 0) {
                position = i;
                break;
            }
        }
        if (n != 0) {
            printf("Товара не существует\n");
        }
    } while (n != 0);
    return position;
}

int start() {
    setlocale(LC_ALL, "rus");
   
    printf("Вас приветствует кассовый аппарат '10023', начнем работу\n");
    printf("Отсканируйте первый товар\n");
    bill[0] = chek_product(&product);
  
    final_price_no_dis = final_price_no_dis + product[bill[0]].prices;
    price_dis[0] = (product[bill[0]].prices) * (((float)(100 - product[bill[0]].discount)) / 100);
    final_price = final_price + price_dis[0];

    printf("%s %.2f руб. %d процентов скидка\n", product[bill[0]].names, product[bill[0]].prices, product[bill[0]].discount);

    while (flag) {
        do {
            printf("Выберете режим. (1) Сканировать новый товар. (2) Закрыть чек\n");
            scanf("%d", &mode);
            if (mode != 1 && mode != 2) printf("Выберете один из доступных режимов\n");
        } while (mode != 1 && mode != 2);

        switch (mode) {
        case 1:
            bill[pos] = chek_product(&product);
            printf("%s %.2f руб. %d процентов скидка\n", product[bill[pos]].names, product[bill[pos]].prices, product[bill[pos]].discount);
            final_price_no_dis = final_price_no_dis + product[bill[pos]].prices;
            price_dis[pos] = (product[bill[pos]].prices) * ( ((float)(100 - product[bill[pos]].discount)) / 100);
            final_price = final_price + price_dis[pos];
            pos++;
            break;
        case 2:
            flag = 0;
            break;
        }
    }   
}

int print_bill() {
    printf("Ваш чек:\n");
    for (i = 0; i < pos; i++) {
        printf("%s %.2f руб. со скидкой %.2f руб.\n", product[bill[i]].names, product[bill[i]].prices, price_dis[i]);
    }
    printf("\n");
    printf("Итоговая сумма без скидки %.2f руб.\n", final_price_no_dis);
    printf("Итоговая сумма со скидкой %.2f руб.\n", final_price);
}

void main() {
    while (flag == 1) {
        do {
            start();
            print_bill();
            printf("Пробиваем следущий чек? (1) - да, (0) - нет\n");
            scanf("%d", &flag);
            if (flag != 0 && flag != 1) printf("Выберете один из доступных режимов\n");
        } while (flag != 0 && flag != 1);
    }
    return;
}