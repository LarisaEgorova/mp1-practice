#include "Function.h"

void quick_sort(FIO* arrs, int* support, int left, int right) {
	int centric = left + (right - left) / 2;
	FIO center_el = arrs[centric];
	int lt = left;
	int rt = right;
	FIO swap;
	int  swape;
	while (lt <= rt) {
		while (arrs[lt] < center_el) lt++;
		while (arrs[rt] > center_el) rt--;
		if (lt <= rt) {
			swap = arrs[lt];
			swape = support[lt];
			arrs[lt] = arrs[rt];
			support[lt] = support[rt];
			arrs[rt] = swap;
			support[rt] = swape;
			lt++;
			rt--;
		}
	}
	if (left < rt) quick_sort(arrs, support, left, rt);
	if (right > lt) quick_sort(arrs, support, lt, right);
}

void selection_sort(FIO* arrs, int* support, int len) {
	for (int i = 0; i < len; i++) {
		int min_ind = i;
		for (int j = i + 1; j < len; j++) {
			if (arrs[min_ind].GetSurname() > arrs[j].GetSurname())
				min_ind = j;
		}
		if (min_ind != i) {
			FIO n = arrs[min_ind];
			int ne = support[min_ind];
			arrs[min_ind] = arrs[i];
			support[min_ind] = support[i];
			arrs[i] = n;
			support[i] = ne;
		}
	}
}

ifstream work_with_base() {
	ifstream in;
	int f = 1;
	while (f) {
		cout << "Введите путь к базе данных\n";
			string way;
			cin >> way;
			in.open(way, ios_base::in);
			if (!in.is_open()) {
				cout<<"Неверный путь. Файла не существует\n";
				continue;
			}
			f = 0;
	}
	return in;
}

void changes(int ex, int i, Student &s) {
	cout << "У ученика " << i
		<< " некорректные данные, пожалуйста замените их на верные\n";
	Date d(s.GetDate());
	int change = 0;
	string changeS = "";
	switch (ex) {
	case 1:
		cout << "Сейчас " << d << "\n";
		cout << "Введите верный год" << "\n";
		cin >> change;
		d.SetYear(change);
		s.SetDate(d);
		break;
	case 2:
		cout << "Сейчас " << d << "\n";
		cout << "Введите верный месяц" << "\n";
		cin >> change;
		d.SetMonth(change);
		s.SetDate(d);
		break;
	case 3:
		cout << "Сейчас " << d << "\n";
		cout << "Введите верный день" << "\n";
		cin >> change;
		d.SetDay(change);
		s.SetDate(d);
		break;
	case 4:
		cout << "Сейчас " << s.GetG() << "\n";
		cout << "Введите верный пол " << "\n";
		cin >> changeS;
		s.SetG(changeS);
		break;
	case 5:
		cout << "Сейчас " << s.GetNum() << "\n";
		cout << "Введите верный класс " << "\n";
		cin >> change;
		s.SetNum(change);
	}
}
	
int* append_klassmass(ifstream &in, int count, int klases, Klass &Kmass) {
	Student s;
	int* quantity = new int[klases];
	for (int i = 0; i < klases; i++) {
		quantity[i] = 0;
	}
	for (int i = 0; i < count; i++) {
		in >> s;
		int f = 1;
		while (f) {
			try {
				f=check_student(s, klases);
			}
			catch (int ex) {
				changes(ex, i, s);
			}
		}
		int ks = s.GetNum();
		quantity[ks - 1] += 1;
		Kmass.SetStudents(i, s);
	}
	in.close();
	return quantity;
}

int check_student(Student &s, int klases) {
	Date d;
	d = s.GetDate();
	string G = s.GetG();
	int K = s.GetNum();
	if (K<1 || K>klases) throw 5;
	if (G != "Ж" && G != "М" && G != "ж" && G != "м") throw 4;
	if (d.GetYear() > 2024 || d.GetYear() < 2000) throw 1;
	if (d.GetMonth() > 12 || d.GetMonth() < 1) throw 2;
	if (d.GetDay() < 1 || d.GetDay() >31 ||
		((d.GetMonth() == 4 || d.GetMonth() == 6 || d.GetMonth() == 9 ||
			d.GetMonth() == 11) && d.GetDay() > 30) ||
		(d.GetMonth() == 2 && d.GetYear() % 4 == 0 && d.GetDay() > 29) ||
		(d.GetMonth() == 2 && d.GetYear() % 4 != 0 && d.GetDay() > 28)) throw 3;
	return 0;
}

void separate_klassmass(int* quantity, Klass* Lib,Klass Kmass, int klases, int count) {
	int* pos = new int[klases];
	Student s;
	for (int i = 0; i < klases; i++) {
		pos[i] = 0;
	}
	for (int i = 0; i < count; i++) {
		s = Kmass.GetStudents(i);
		int n = s.GetNum();
		Lib[n - 1].SetStudents(pos[n - 1]++, s);
	}
	delete[] pos;
	return;
}

int* sorted_klases(int* quantity, int *support, Klass* Lib, int choice) {
	FIO* fio = new FIO[quantity[choice - 1]];
	for (int i = 0; i < quantity[choice - 1]; i++) {
		support[i] = i;
		fio[i] = Lib[choice - 1].GetStudents(i).GetFIO();
	}
	int right = quantity[choice - 1]-1;
	quick_sort(fio, support, 0, right);
	delete[] fio;
	return support;
}

void first_inf_nosort(Klass* Lib, int* quantity, int choice) {
	for (int i = 0; i < quantity[choice - 1]; i++) {
		cout << "ID: " << i+1 << " ФИО: " << Lib[choice - 1].GetStudents(i).GetFIO() << "\n" <<
			"Класс: " << Lib[choice - 1].GetStudents(i).GetNum()<< "\n";
	}
	return;
}

void first_inf_sort(Klass* Lib, int* quantity, int *support, int choice) {
	for (int i = 0; i < quantity[choice - 1]; i++) {
		cout <<"ID: "<< support[i]+1 << " ФИО: " << Lib[choice - 1].GetStudents(support[i]).GetFIO() << "\n" <<
			"Класс: " << Lib[choice - 1].GetStudents(support[i]).GetNum() << "\n";
	}
	return;
}

void menu(Klass*Lib, int*quantity, int klases){
	cout << "Вас приветствует база школьников 'Будущее России'\n" <<
		"Вы можете ознакомиться с данными учеников со всей России\n" <<
		"Все они разделены на классы\n";
	int F = 1;
	while (F) {
		cout << "Какой класс хотите посмотреть? (1-" << klases << ")" << endl;
		int choice = 0;
		while (1) {
			cout << "Введите номер класса: ";
			cin >> choice;
			if (choice <= 0 || choice > klases) {
				cout << "Школьников такого класса в базе нет\n";
				continue;
			}
			break;
		}
		int* support = new int[quantity[choice - 1]];
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
			first_inf_nosort(Lib, quantity, choice);
			break;
		case 2:
			support=sorted_klases(quantity, support, Lib, choice);
			first_inf_sort(Lib, quantity, support, choice);
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
			if (f != -1 && f != 0 && f-1 <= quantity[choice-1]) {
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
				cout << "Неверный ввод\n";
				continue;
			}
		}
		delete[] support;
	}
}
