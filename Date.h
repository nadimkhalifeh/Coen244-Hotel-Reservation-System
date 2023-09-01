#pragma once

class Date {
private:
	int day;  
	int month;
	int year; // private data members for class dare
public:
	Date();
	Date(int d, int m, int y);
	~Date();
	void SetDay(int d); 
	void SetMonth(int m);
	void SetYear(int y);
	const int GetDay() const;
	const int GetMonth() const;
	const int GetYear() const; //constructors 
};