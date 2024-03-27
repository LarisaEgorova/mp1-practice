#pragma once

#include <iostream>
#include <locale.h>
#include <string>
#include <exception>

using namespace std;

class Date
{
public:
	Date(int, int, int);
	Date(const Date&);
	Date();
	int GetDay();
	void SetDay(int);
	int GetMonth();
	void SetMonth(int);
	int GetYear();
	void SetYear(int);
	const Date& operator =(const Date&);

private:
	int day;
	int month;
	int year;
};
