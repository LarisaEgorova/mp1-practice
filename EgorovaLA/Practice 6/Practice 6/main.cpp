#include "Journal.h"
#include "Function.h"

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string* massfile;
	int klases = 0; int count = 0;

	while (1) {
		cout << "������� ���������� �������\n";
		cin >> klases;
		massfile = new string[klases];
		count += work_with_base(klases, massfile);
		if (count != klases) {
			cout << "�������� ���������� �������"
				<<"�� ������� ��� ������\n";
			continue;
		}
		klases = count;
		break;
	}

	Student s;
	Journal Kmass(count);

	append_klassmass(massfile, Kmass);
	
	menu(Kmass);
	
	cout << "����������...";

	delete[] massfile;

	return 0;
}