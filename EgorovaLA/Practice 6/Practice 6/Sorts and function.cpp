#include "Sorts and function.h"

void quick_sort(Student* arrs, int* support, int len, int left, int right) {
	if (len == 0 || left >= right) return;
	int centric = left + (right - left) / 2;
	FIO center_el = arrs[centric].GetFIO();
	int lt = left;
	int rt = right;
	FIO swap;
	int  swape;
	while (lt <= rt) {
		while (arrs[lt].GetFIO() < center_el) lt++;
		while (arrs[rt].GetFIO() > center_el) rt--;
		if (lt <= rt) {
			swap = arrs[lt].GetFIO();
			swape = support[lt];
			arrs[lt].GetFIO() = arrs[rt].GetFIO();
			support[lt] = support[rt];
			arrs[rt].GetFIO() = swap;
			support[rt] = swape;
			lt++;
			rt--;
		}
	}
	if (left < rt) quick_sort(arrs, support, len, left, rt);
	if (right > lt) quick_sort(arrs, support, len, lt, right);
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
			if (check_base() == 0) {
				cout<<"В базе некорректные данные\n";
				continue;
			}
			f = 0;
	}
	return in;
}

int check_base() {
	return 1;
}
	
int* append_klassmass(ifstream &in, int count, int klases, Student &s, Klass &Kmass) {
	int* quantity = new int[klases];
	for (int i = 0; i < klases; i++) {
		quantity[i] = 0;
	}
	for (int i = 0; i < count; i++) {
		in >> s;
		int ks = s.GetNum();
		quantity[ks - 1] += 1;
		Kmass.SetStudents(i, s);
	}
	in.close();
	return quantity;
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
	int len = quantity[choice - 1];
	selection_sort(fio, support, len);
	delete[] fio;
	return support;
}

void first_inf_nosort(Klass* Lib, int* quantity, int choice) {
	for (int i = 0; i < quantity[choice - 1]; i++) {
		cout << "ID: " << i << " ФИО: " << Lib[choice - 1].GetStudents(i).GetFIO() << "\n" <<
			"Класс: " << Lib[choice - 1].GetStudents(i).GetNum()<< "\n";
	}
	return;
}

void first_inf_sort(Klass* Lib, int* quantity, int *support, int choice) {
	for (int i = 0; i < quantity[choice - 1]; i++) {
		cout <<"ID: "<< support[i] << " ФИО: " << Lib[choice - 1].GetStudents(support[i]).GetFIO() << "\n" <<
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
			if (f != -1 && f != 0 && f <= quantity[choice-1]) {
				cout << Lib[choice - 1].GetStudents(f)<<"\n";
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
