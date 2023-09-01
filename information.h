#pragma once
#include"Date.h"

class information {
private:
	char firstname[100];// array of 100 chaachters since name wouldnt be longer 
	char lastname[100];
	Date dateOfBirth;
public:
	information();
	information(char f[],char l[],const Date& d); // gets the first name and las name array and data reference
	~information();
	void SetFirstName(char f[]);
	void SetLastName(char l[]);
	void SetDateOfBirth(const Date& d);
	const char* GetFirstName() const;
	const char* GetLastName() const;
	const Date& GetDateOfBirth() const;
};