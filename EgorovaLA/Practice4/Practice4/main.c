#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

#define max_bill 20
#define len_bar 4
#define k 10 //���-�� �������

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
        printf("������� ����� ��� ");
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
            printf("������ �� ����������\n");
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

    struct product product[] = { {{0,0,0,0}, "����", 40},{{0,0,0,1}, "������ 0,9 �.", 74},
    {{0,0,1,1}, "����� ���������", 101},{{0,1,1,1}, "����", 25},
    {{1,1,1,1}, "���� �������", 90}, {{1,1,0,0}, "������� ���������", 156},
    {{1,1,1,0}, "��������� ���.", 41},{{1,0,1,0}, "�������", 251},
    {{1,0,0,1},"���� �����. 0,5 �.", 15}, {{1,0,0,0}, "�������� ������", 113} };

    while (flag) {
        printf("��� ������������ �������� ������� 10023, ������ ������\n");
        printf("������������ ������ �����\n");
        bill[0] = chek_product(&product);

        final_price_no_dis = final_price_no_dis + product[bill[0]].prices;
        price_dis[0] = discount(product[bill[0]].prices);
        final_price = final_price + price_dis[0];

        printf("%s %d ���.\n", product[bill[0]].names, product[bill[0]].prices);

        while (flag) {
            do {
                printf("�������� �����. (1) ����������� ����� �����. (2) ������� ���\n");
                scanf("%d", &mode);
                if (mode != 1 && mode != 2) printf("�������� ���� �� ��������� �������\n");
            } while (mode != 1 && mode != 2);

            switch (mode) {
            case 1:
                bill[pos] = chek_product(&product);
                printf("%s %d ���.\n", product[bill[pos]].names, product[bill[pos]].prices);
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
        printf("��� ���:\n");

        for (i = 0; i < pos; i++) {
            printf("%s %d ���. �� ������� %.2f ���.\n", product[bill[i]].names, product[bill[i]].prices, price_dis[i]);
        }

        printf("�������� ����� ��� ������ %d ���.\n", final_price_no_dis);
        printf("�������� ����� �� ������� %.2f ���.\n", final_price);

        do {
            printf("��������� �������� ���? (1) - ��, (0) - ���\n");
            scanf("%d", &flag);
            if (flag != 0 && flag != 1) printf("�������� ���� �� ��������� �������\n");
        } while (flag != 0 && flag != 1);
    }
    return 0;
}

