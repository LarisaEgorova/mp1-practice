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
}

int Date :: GetDay() {
	return this->day;
}
void Date::SetDay(int day) {
	this->day = day;
}
int Date::GetMonth() {
	return this->month;
}
void Date::SetMonth(int month) {
	this->month = month;
}
int Date::GetYear() {
	return this->year;
}
void Date::SetYear(int year) {
	this->year = year;
}