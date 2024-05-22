#include "Function.h"

void menu(Journal& Kmass){
	cout << "��� ������������ ���� ���������� '������� ������'\n" <<
		"�� ������ ������������ � ������� �������� �� ���� ������\n" <<
		"��� ��� ��������� �� ������\n";
	int F = 1;
	while (F) {
		cout << "����� ����� ������ ����������? (1-" << Kmass.GetCount() << ")" << endl;
		int choice = 0;
		while (1) {
			cout << "������� ����� ������: ";
			cin >> choice;
			if (choice <= 0 || choice > Kmass.GetCount()) {
				cout << "���������� ������ ������ � ���� ���\n";
				continue;
			}
			break;
		}
		cout << "������� ������ ��� � ���� ��� ���������������?\n";
		int type;
		while (1) {
			cout << "��� � ���� - 1, ��������������� -2\n";
			cin >> type;
			if ((type != 1) && (type != 2)) {
				cout << "�������� ����\n";
				continue;
			}
			break;
		}
		switch (type) {
		case 1:
			cout << Kmass[choice-1];
			break;
		case 2:
			Kmass.first_inf_sort(choice);
			break;
		default:
			break;
		}
		int f = 0;
		while (1){
			cout << "������ ������ ������?\n" <<
				"������� ���������� ID �������\n"
				<< "����� ������ ���������� ������ ����� - (-1) ��� ��������� ������ (0)\n";
			cin >> f;
			if (f != -1 && f != 0 && f <= Kmass[choice - 1].GetCount()) {
				cout << Kmass[choice-1][f-1]<<"\n";
				continue;
			}
			if (f == -1) {
				break;
			}
			if (f == 0) {
				F = 0;
				break;
			}
			else{
				cout << "�������� ����\n";
				continue;
			}
		}
	}
}
