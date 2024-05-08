#pragma once

#include <iostream>
#include <locale.h>
#include <string>
#include <fstream>

using namespace std;

class Date {

private:
	int day;
	int month;
	int year;
public:
	Date(int, int, int);
	Date(const Date&);
	Date();

	int GetDay() const;
	void SetDay(int);
	int GetMonth() const;
	void SetMonth(int);
	int GetYear() const;
	void SetYear(int);

	friend ifstream& operator >>(ifstream& in, Date& date);
	friend ostream& operator <<(ostream& out, const Date& date);
};

void changes(int ex, Date& d);