#include "Date.h"

Date::Date(int day, int month, int year) {
	if (year > 2024 || year < 2000) throw 1;
	this->year = year;
	if (month > 12 || month < 1) throw 2;
	this->month = month;
	if ((day < 1 || day > 31 ||
		(month == 4 || month == 6 || month == 9 ||month == 11) && day > 30) ||
		(month == 2 && year % 4 == 0 && day > 29) ||
		(month == 2 && year % 4 != 0 && day > 28)) throw 3;
	this->day = day;
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

int Date::GetDay() const {
	return this->day;
}
void Date::SetDay(int day) {
	this->day = day;
}
int Date::GetMonth() const {
	return this->month;
}
void Date::SetMonth(int month) {
	this->month = month;
}
int Date::GetYear() const {
	return this->year;
}
void Date::SetYear(int year) {
	this->year = year;
}

ifstream& operator >>(ifstream& in, Date& date) {
	Date d;
	in >> d.day >>d.month >>d.year;
	while (1)
	{
		try {
			date = Date(d.day, d.month, d.year);
			break;
		}
		catch (int ex) {
			changes(ex, d);
		}
	}
	return in;
}

ostream& operator <<(ostream& out, const Date& date) {
	out << date.day << "." << date.month << "." << date.year<<endl;
	return out;
}

void changes(int ex, Date& d) {
	cout << "” ученика некорректные данные, пожалуйста замените их на верные\n";
	int change = 0;
	string changeS = "";
	switch (ex) {
	case 1:
		cout << "¬ведите верный год" << "\n";
		cin >> change;
		d.SetYear(change);
		break;
	case 2:
		cout << "¬ведите верный мес€ц" << "\n";
		cin >> change;
		d.SetMonth(change);
		break;
	case 3:
		cout << "¬ведите верный день" << "\n";
		cin >> change;
		d.SetDay(change);
		break;
	}
}