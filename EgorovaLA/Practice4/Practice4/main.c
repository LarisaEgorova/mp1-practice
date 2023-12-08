#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

#define max_bill 20
#define len_bar 4
#define k 10 //���-�� �������

int i = 0;
int flag = 1;
int mode = 0;
int bill[max_bill];
float final_price = 0.f, price_dis[max_bill], final_price_no_dis = 0.f;
int pos = 1;

struct product
{
    char* barcode;
    char* names;
    float prices;
    int discount;
};

struct product products[] = { 
   {"0000", "����", 40.f, 10}, {"0001", "������ 0,9 �.", 74.f, 15},
   {"0011", "����� ���������", 101.f, 3},{"0111", "����", 25.f, 6},
   {"1111", "���� �������", 90.f, 9}, {"1000", "������� ���������", 156.f, 20},
   {"1100", "��������� ���.", 41.f, 2},{"1110", "�������", 251.f, 50},
   {"1010","���� �����. 0,5 �.", 15.f, 1},
   {"0101", "�������� ������", 113.f, 12}
};

int chek_product() {
    int i, j, n=1, position=0;
    char barcode_pols[10];
    do {
        printf("������� ����� ��� ");
        scanf("%s", barcode_pols);
        for (i = 0; i < k; i++) {
            n = strcmp(products[i].barcode, barcode_pols);
            if (n == 0) {
                position = i;
                break;
            }
        }
        if (n != 0) {
            printf("������ �� ����������\n");
        }
    } while (n != 0);
    return position;
}

int start() {
    setlocale(LC_ALL, "rus");
   
    printf("��� ������������ �������� ������� '10023'\n");
    printf("������ ������\n");
    printf("������������ ������ �����\n");
    bill[0] = chek_product();
  
    final_price_no_dis += products[bill[0]].prices;
    price_dis[0] = (products[bill[0]].prices) *
        (((float)(100 - products[bill[0]].discount)) / 100);
    final_price += price_dis[0];

    printf("%s %.2f ���. %d ��������� ������\n", products[bill[0]].names,
        products[bill[0]].prices, products[bill[0]].discount);

    while (flag) {
        do {
            printf("�������� �����.\n");
            printf("(1) ����������� ����� �����. (2) ������� ���\n");
            scanf("%d", &mode);
            if (mode != 1 && mode != 2)
                printf("�������� ���� �� ��������� �������\n");
        } while (mode != 1 && mode != 2);

        switch (mode) {
        case 1:
            bill[pos] = chek_product();
            printf("%s %.2f ���. %d ��������� ������\n",
                products[bill[pos]].names, products[bill[pos]].prices,
                products[bill[pos]].discount);

            final_price_no_dis += products[bill[pos]].prices;

            price_dis[pos] = (products[bill[pos]].prices) *
                (((float)(100 - products[bill[pos]].discount)) / 100);

            final_price += price_dis[pos];
            pos++;
            break;
        case 2:
            flag = 0;
            break;
        }
    }   
}

int print_bill() {
    printf("��� ���:\n");
    for (i = 0; i < pos; i++) {
        printf("%s %.2f ���. �� ������� %.2f ���.\n", 
            products[bill[i]].names, products[bill[i]].prices, price_dis[i]);
    }
    printf("\n");
    printf("�������� ����� ��� ������ %.2f ���.\n", final_price_no_dis);
    printf("�������� ����� �� ������� %.2f ���.\n", final_price);
}

void main() {
    while (flag == 1) {
        do {
            start();
            print_bill();
            printf("��������� �������� ���? (1) - ��, (0) - ���\n");
            scanf("%d", &flag);
            if (flag != 0 && flag != 1)
                printf("�������� ���� �� ��������� �������\n");
        } while (flag != 0 && flag != 1);
    }
    return;
}