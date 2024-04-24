#include "Function.h"

int work_with_base(int klases, string* massfile) {
	int count = 0;
	ifstream in;
	for (int i=1; i<klases+1; i++){
		string way = to_string(i) + ".txt";
		in.open(way, ios_base::in);
		if (!in.is_open()) {
			cout<<"�������� ����. ����� �� ����������\n";
			continue;
		}
		massfile[i-1] = way;
		count += 1;
	}
	in.close();
	return count;
}

void changes(int ex, int i, Student &s) {
	cout << "� ������� " << i
		<< " ������������ ������, ���������� �������� �� �� ������\n";
	Date d(s.GetDate());
	int change = 0;
	string changeS = "";
	switch (ex) {
	case 1:
		cout << "������ " << d << "\n";
		cout << "������� ������ ���" << "\n";
		cin >> change;
		d.SetYear(change);
		s.SetDate(d);
		break;
	case 2:
		cout << "������ " << d << "\n";
		cout << "������� ������ �����" << "\n";
		cin >> change;
		d.SetMonth(change);
		s.SetDate(d);
		break;
	case 3:
		cout << "������ " << d << "\n";
		cout << "������� ������ ����" << "\n";
		cin >> change;
		d.SetDay(change);
		s.SetDate(d);
		break;
	case 4:
		cout << "������ " << s.GetNum() << "\n";
		cout << "������� ������ ����� " << "\n";
		cin >> change;
		s.SetNum(change);
	}
}
	
void append_klassmass(string* massfile, int klases, Klass* Kmass) {

	Student s;
	ifstream in;
	int count;

	for (int i = 0; i < klases; i++) {
		in.open(massfile[i]);
		in >> count;
		Kmass[i].SetCount(count);
		Kmass[i].allocateK(count);

		for (int j = 0; j < count; j++) {
			in >> s;
			int f = 1;
			while (f) {
				try {
					f = check_student(s, klases);
				}
				catch (int ex) {
					changes(ex, j, s);
				}
			}
			Kmass[i].SetStudents(j, s);
		}
		in.close();
	}
	return ;
}

int check_student(Student &s, int klases) {
	Date d;
	d = s.GetDate();
	int K = s.GetNum();
	if (K<1 || K>klases) throw 4;
	if (d.GetYear() > 2024 || d.GetYear() < 2000) throw 1;
	if (d.GetMonth() > 12 || d.GetMonth() < 1) throw 2;
	if (d.GetDay() < 1 || d.GetDay() >31 ||
		((d.GetMonth() == 4 || d.GetMonth() == 6 || d.GetMonth() == 9 ||
			d.GetMonth() == 11) && d.GetDay() > 30) ||
		(d.GetMonth() == 2 && d.GetYear() % 4 == 0 && d.GetDay() > 29) ||
		(d.GetMonth() == 2 && d.GetYear() % 4 != 0 && d.GetDay() > 28)) throw 3;
	return 0;
}

int* sorted_klases( int *support, Klass* Lib, int choice) {
	FIO* fio = new FIO[Lib[choice - 1].GetCount()];
	for (int i = 0; i < Lib[choice - 1].GetCount(); i++) {
		support[i] = i;
		fio[i] = Lib[choice - 1].GetStudents(i).GetFIO();
	}
	int right = Lib[choice - 1].GetCount() - 1;
	quick_sort(fio, support, 0, right);
	delete[] fio;
	return support;
}

void first_inf_nosort(Klass* Lib,  int choice) {
	for (int i = 0; i < Lib[choice - 1].GetCount(); i++) {
		cout << "ID: " << i+1 << " ���: " << Lib[choice - 1].GetStudents(i).GetFIO() << endl <<
			"�����: " << Lib[choice - 1].GetStudents(i).GetNum()<<"\n";
	}
	return;
}

void first_inf_sort(Klass* Lib, int *support, int choice) {
	for (int i = 0; i < Lib[choice - 1].GetCount(); i++) {
		cout <<"ID: "<< support[i]+1 << " ���: " << Lib[choice - 1].GetStudents(support[i]).GetFIO() << "\n" <<
			"�����: " << Lib[choice - 1].GetStudents(support[i]).GetNum() << "\n";
	}
	return;
}

void menu(Klass*Lib, int klases){
	cout << "��� ������������ ���� ���������� '������� ������'\n" <<
		"�� ������ ������������ � ������� �������� �� ���� ������\n" <<
		"��� ��� ��������� �� ������\n";
	int F = 1;
	while (F) {
		cout << "����� ����� ������ ����������? (1-" << klases << ")" << endl;
		int choice = 0;
		while (1) {
			cout << "������� ����� ������: ";
			cin >> choice;
			if (choice <= 0 || choice > klases) {
				cout << "���������� ������ ������ � ���� ���\n";
				continue;
			}
			break;
		}
		int* support = new int[Lib[choice - 1].GetCount()];
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
			first_inf_nosort(Lib, choice);
			break;
		case 2:
			support=sorted_klases(support, Lib, choice);
			first_inf_sort(Lib, support, choice);
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
			if (f != -1 && f != 0 && f-1 <= Lib[choice - 1].GetCount()) {
				cout << Lib[choice - 1].GetStudents(f-1)<<"\n";
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
