#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

#define max_bill 20
#define len_bar 4
#define k 10 //кол-во товаров

struct product
{
    int barcode[len_bar];
    char* names;
    int prices;
};

int discount(float price) {
    int percent;
    float price_dis = 0;
    srand((unsigned int)time(0));
    percent = 1 + (rand() % 51);
    price_dis = price - ((price / 100) * percent);
    return price_dis;
};

int chek_product(struct product* obj) {
    int i, j, el_obj, el_pols, n, position, help_p;
    int barcode_pols[len_bar];
    do {
        printf("Введите штрих код ");
        for (i = 0; i < len_bar; i++) {
            scanf("%d", &barcode_pols[i]);
        }
        for (i = 0; i < k; i++) {
            n = 0;
            for (j = 0; j < len_bar; j++) {
                el_obj = (obj + i)->barcode[j];
                el_pols = barcode_pols[j];
                if (el_obj == el_pols) n++;
            }
            if (n == len_bar) {
                position = i;
                break;
            }
        }
        if (n != len_bar) {
            printf("Товара не существует\n");
        }
    } while (n != len_bar);
    return position;
}

int main() {

    setlocale(LC_ALL, "rus");
    int i = 0;
    int flag = 1;
    int pos = 1, mode = 0, final_price_no_dis = 0;
    int bill[max_bill];
    float final_price = 0, price_dis[max_bill];

    struct product product[] = { {{0,0,0,0}, "Хлеб", 40},{{0,0,0,1}, "Молоко 0,9 л.", 74},
    {{0,0,1,1}, "Крупа гречневая", 101},{{0,1,1,1}, "Кекс", 25},
    {{1,1,1,1}, "Яйцо куриное", 90}, {{1,1,0,0}, "Сосиски сливочные", 156},
    {{1,1,1,0}, "Картофель фас.", 41},{{1,0,1,0}, "Шампунь", 251},
    {{1,0,0,1},"Вода негаз. 0,5 л.", 15}, {{1,0,0,0}, "Консервы рыбные", 113} };

    while (flag) {
        printf("Вас приветствует кассовый аппарат 10023, начнем работу\n");
        printf("Отсканируйте первый товар\n");
        bill[0] = chek_product(&product);

        final_price_no_dis = final_price_no_dis + product[bill[0]].prices;
        price_dis[0] = discount(product[bill[0]].prices);
        final_price = final_price + price_dis[0];

        printf("%s %d руб.\n", product[bill[0]].names, product[bill[0]].prices);

        while (flag) {
            do {
                printf("Выберете режим. (1) Сканировать новый товар. (2) Закрыть чек\n");
                scanf("%d", &mode);
                if (mode != 1 && mode != 2) printf("Выберете один из доступных режимов\n");
            } while (mode != 1 && mode != 2);

            switch (mode) {
            case 1:
                bill[pos] = chek_product(&product);
                printf("%s %d руб.\n", product[bill[pos]].names, product[bill[pos]].prices);
                final_price_no_dis = final_price_no_dis + product[bill[pos]].prices;
                price_dis[pos] = discount(product[bill[pos]].prices);
                final_price = final_price + price_dis[pos];
                pos++;
                break;
            case 2:
                flag = 0;
                break;
            }
        }
        printf("Ваш чек:\n");

        for (i = 0; i < pos; i++) {
            printf("%s %d руб. со скидкой %.2f руб.\n", product[bill[i]].names, product[bill[i]].prices, price_dis[i]);
        }

        printf("Итоговая сумма без скидки %d руб.\n", final_price_no_dis);
        printf("Итоговая сумма со скидкой %.2f руб.\n", final_price);

        do {
            printf("Пробиваем следущий чек? (1) - да, (0) - нет\n");
            scanf("%d", &flag);
            if (flag != 0 && flag != 1) printf("Выберете один из доступных режимов\n");
        } while (flag != 0 && flag != 1);
    }
    return 0;
}

