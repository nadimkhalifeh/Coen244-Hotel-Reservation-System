#define _CRT_SECURE_NO_WARNINGS
#include"information.h"
#include<iostream>

using namespace std;

information::information() {

}

information::information(char f[], char l[], const Date& d) {
	strcpy(firstname, f); // copies the array f to first name
	strcpy(lastname, l);
	dateOfBirth = d;
}
information::~information() {
	cout << "Information destructor" << endl;
} // destructor
void information::SetFirstName(char f[]) {
	strcpy(firstname, f);
} //sets the first name in the array
void information::SetLastName(char l[]) {
	strcpy(lastname, l);
}//sets the last name in the array
void information::SetDateOfBirth(const Date& d) {
	dateOfBirth = d;
} //sets the date of birth
const char* information::GetFirstName() const{
	return firstname;
}
const char* information::GetLastName() const {
	return lastname;
} 
const Date& information::GetDateOfBirth() const {
	return dateOfBirth; 
}
