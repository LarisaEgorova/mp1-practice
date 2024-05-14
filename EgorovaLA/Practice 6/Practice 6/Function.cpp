#include "Function.h"

int append_klassmass(Journal& Kmass) {

	Klass klass;
	ifstream in;
	string file;
	int count;

	for (int i = 0; i < Kmass.GetCount(); i++) {
		file = to_string(i+1) + ".txt";
		in.open(file);
		if (!in.is_open()) {
			cout << "�������� ����. ����� �� ����������\n";
			return -1;
		}
		in >> klass;
		Kmass.SetKlass(i, klass);
		in.close();
	}
	return 0;
}

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
		int* support = new int[Kmass.GetKlass(choice - 1).GetCount()];
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
			Kmass.first_inf_nosort(choice);
			break;
		case 2:
			Kmass.GetKlass(choice - 1)
				.Sort(support, 0, Kmass.GetKlass(choice - 1).GetCount()-1);
			Kmass.first_inf_sort(support, choice);
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
			if (f != -1 && f != 0 && f-1 <= Kmass.GetKlass(choice - 1).GetCount()) {
				cout << Kmass.GetKlass(choice-1).GetStudents(f-1)<<"\n";
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
		delete[] support;
	}
}
