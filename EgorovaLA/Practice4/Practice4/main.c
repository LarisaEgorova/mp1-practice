#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define max_bill 20
#define len_bar 4
#define k 10 //���-�� �������

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

struct product product[] = { {"0000", "����", 40, 10}, {"0001", "������ 0,9 �.", 74, 15},
   {"0011", "����� ���������", 101,3},{"0111", "����", 25,6},
   {"1111", "���� �������", 90, 9}, {"1000", "������� ���������", 156, 20},
   {"1100", "��������� ���.", 41, 2},{"1110", "�������", 251, 50},
   {"1010","���� �����. 0,5 �.", 15, 1}, {"0101", "�������� ������", 113, 12} };

int chek_product() {
    int i, j, n=1, position=0;
    char barcode_pols[len_bar+1];
    do {
        printf("������� ����� ��� ");
        scanf("%s", &barcode_pols);
        for (i = 0; i < k; i++) {
            n = strcmp(product[i].barcode, barcode_pols);
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
   
    printf("��� ������������ �������� ������� '10023', ������ ������\n");
    printf("������������ ������ �����\n");
    bill[0] = chek_product(&product);
  
    final_price_no_dis = final_price_no_dis + product[bill[0]].prices;
    price_dis[0] = (product[bill[0]].prices) * (((float)(100 - product[bill[0]].discount)) / 100);
    final_price = final_price + price_dis[0];

    printf("%s %.2f ���. %d ��������� ������\n", product[bill[0]].names, product[bill[0]].prices, product[bill[0]].discount);

    while (flag) {
        do {
            printf("�������� �����. (1) ����������� ����� �����. (2) ������� ���\n");
            scanf("%d", &mode);
            if (mode != 1 && mode != 2) printf("�������� ���� �� ��������� �������\n");
        } while (mode != 1 && mode != 2);

        switch (mode) {
        case 1:
            bill[pos] = chek_product(&product);
            printf("%s %.2f ���. %d ��������� ������\n", product[bill[pos]].names, product[bill[pos]].prices, product[bill[pos]].discount);
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
    printf("��� ���:\n");
    for (i = 0; i < pos; i++) {
        printf("%s %.2f ���. �� ������� %.2f ���.\n", product[bill[i]].names, product[bill[i]].prices, price_dis[i]);
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
            if (flag != 0 && flag != 1) printf("�������� ���� �� ��������� �������\n");
        } while (flag != 0 && flag != 1);
    }
    return;
}