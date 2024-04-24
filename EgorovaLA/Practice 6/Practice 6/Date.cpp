#include "Date.h"

Date::Date(int day, int month, int year) {
	this->day = day;
	this->month = month;
	this->year = year;
}

Date::Date(const Date& date) {
	this->day = date.day;
	this->month = date.month;
	this->year = date.year;
}

Date::Date() {
	this->day = 0;
	this->month = 0;
	this->year = 0;
}

int Date::GetDay ()  {
	return this->day;
}
void Date::SetDay(int day) {
	this->day = day;
}
int Date::GetMonth()  {
	return this->month;
}
void Date::SetMonth(int month) {
	this->month = month;
}
int Date::GetYear()  {
	return this->year;
}
void Date::SetYear(int year) {
	this->year = year;
}

const Date& Date :: operator =(const Date& date) {
	this->day = date.day;
	this->month = date.month;
	this->year = date.year;
	return *this;
}

ifstream& operator >>(ifstream& in, Date& date) {
	in >> date.day >>date.month >>date.year;
	return in;
}

ostream& operator <<(ostream& out, const Date& date) {
	out << date.day << "." << date.month << "." << date.year<<endl;
	return out;
}
