#include "Function.h"

int work_with_base(int klases, string* massfile) {
	int count = 0;
	ifstream in;
	for (int i=1; i<klases+1; i++){
		string way = to_string(i) + ".txt";
		in.open(way, ios_base::in);
		if (!in.is_open()) {
			cout<<"Неверный путь. Файла не существует\n";
			continue;
		}
		massfile[i-1] = way;
		count += 1;
	}
	in.close();
	return count;
}

void append_klassmass(string* massfile, Journal& Kmass) {

	Klass klass;
	Student s;
	ifstream in;
	int count;

	for (int i = 0; i < Kmass.GetCount(); i++) {
		in.open(massfile[i]);
		in >> count;
		klass = Klass(count);
		for (int j = 0; j < count; j++) {
			int f = 1;
			in >> s;
			klass.SetStudents(j, s);
		}

		Kmass.SetKlass(i, klass);

		in.close();
	}
	return ;
}

int* sorted_klases( int *support, Journal& Kmass, int choice) {
	FIO* fio = new FIO[Kmass.GetKlass(choice - 1).GetCount()];
	for (int i = 0; i < Kmass.GetKlass(choice - 1).GetCount(); i++) {
		support[i] = i;
		fio[i] = Kmass.GetKlass(choice - 1).GetStudents(i).GetFIO();
	}
	int right = Kmass.GetKlass(choice - 1).GetCount() - 1;
	quick_sort(fio, support, 0, right);
	delete[] fio;
	return support;
}

void menu(Journal& Kmass){
	cout << "Вас приветствует база школьников 'Будущее России'\n" <<
		"Вы можете ознакомиться с данными учеников со всей России\n" <<
		"Все они разделены на классы\n";
	int F = 1;
	while (F) {
		cout << "Какой класс хотите посмотреть? (1-" << Kmass.GetCount() << ")" << endl;
		int choice = 0;
		while (1) {
			cout << "Введите номер класса: ";
			cin >> choice;
			if (choice <= 0 || choice > Kmass.GetCount()) {
				cout << "Школьников такого класса в базе нет\n";
				continue;
			}
			break;
		}
		int* support = new int[Kmass.GetKlass(choice - 1).GetCount()];
		cout << "Вывести список как в базе или отсортированный?\n";
		int type;
		while (1) {
			cout << "Как в базе - 1, отсортированный -2\n";
			cin >> type;
			if ((type != 1) && (type != 2)) {
				cout << "Неверный ввод\n";
				continue;
			}
			break;
		}
		switch (type) {
		case 1:
			first_inf_nosort(Kmass, choice);
			break;
		case 2:
			support=sorted_klases(support, Kmass, choice);
			first_inf_sort(Kmass, support, choice);
			break;
		default:
			break;
		}
		int f = 0;
		while (1){
			cout << "Хотите узнать больше?\n" <<
				"Введите уникальный ID ученика\n"
				<< "Также можете посмотреть другой класс - (-1) или завершить работу (0)\n";
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
				cout << "Неверный ввод\n";
				continue;
			}
		}
		delete[] support;
	}
}
