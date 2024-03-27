#include <iostream>
#include <locale.h>
#include <string>
#include <exception>
#include <fstream>
#include "Student.h"

using namespace std;

void definition() {
	;
}

int main() {
	setlocale(LC_ALL, "ru");
	ifstream in;
	in.open("base.txt");
	Student s1;

	string n[16];
	for (int i = 0; i < 16; i++) {
		getline(in, n[i], '\t');
	}
	for (int i = 0; i < 16; i++) {
		cout << n[i] << " ";
	}
	in.close();


	

	
}