#pragma once

#include <iostream>
#include <locale.h>
#include <string>
#include <fstream>

using namespace std;

class Date
{
public:
	Date(int, int, int);
	Date(const Date&);
	Date();
	int GetDay();
	void SetDay(int) ;
	int GetMonth();
	void SetMonth(int) ;
	int GetYear();
	void SetYear(int);

	const Date& operator =(const Date&);
	friend ifstream& operator >>(ifstream& in, Date& date);
	friend ostream& operator <<(ostream& out, const Date& date);

private:
	int day;
	int month;
	int year;
};
