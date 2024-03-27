#include <iostream>
#include <locale.h>
#include <string>
#include <exception>
#include <fstream>
#include "Student.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	ifstream in;
	in.open("base.txt");
	string n[16];
	for (int i = 0; i < 16; i++) {
		getline(in, n[i], '\t');
	}
	for (int i = 0; i < 16; i++) {
		cout << n[i] << " ";
	}
	in.close();

	Date d (stoi(n[5]), stoi(n[6]), stoi(n[7]));
	Adress a(stoi(n[8]), n[9], n[10], n[11], n[12], n[13], stoi(n[14]), stoi(n[15]));
	FIO fio(n[0],n[1], n[2]);
	Student st(d, fio, a, stoi(n[3]), n[4]);

	string name = fio.GetName();
	int day = d.GetDay();
	string f = a.GetDistrict();
	

	
}