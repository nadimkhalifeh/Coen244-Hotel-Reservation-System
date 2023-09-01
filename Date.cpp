#include<iostream>
#include "Date.h"

using namespace std;

Date::Date() {
	day = 0;
	month = 0;
	year = 0;
} //initiliazer

Date::Date(int d, int m, int y) {
	day = d;
	month = m;
	year = y;
}
void Date::SetDay(int d) {
	day = d;
} // Sets the day 
void Date::SetMonth(int m) {
	month = m;
} // Sets the month
void Date::SetYear(int y) {
	year = y;
} // Sets the year
const int Date::GetDay() const {
	return day;
}
const int Date::GetMonth() const {
	return month;
} 
const int Date::GetYear() const {
	return year;
}
Date::~Date() {
	cout << "Date destructor" << endl;
} // destructor